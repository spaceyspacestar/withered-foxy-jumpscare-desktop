#include "main.hpp"
#include "jumpscare.hpp"



bool init() {
    bool success = true;

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
#ifdef DEBUG
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
#endif
        success = false;
    }
    else {
        window = SDL_CreateWindow("", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, screen_width, screen_height, SDL_WINDOW_ALWAYS_ON_TOP | SDL_WINDOW_BORDERLESS);
        
        if (window == nullptr) {
#ifdef DEBUG
            printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
#endif
            success = false;
        } 
        else window_surface = SDL_GetWindowSurface(window);
    }

    //Initialize miniaudio engine
    result = ma_engine_init(NULL, &engine);
    if (result != MA_SUCCESS) {
#ifdef DEBUG
        printf("Failed to initialize audio engine.\n");
#endif
        success = false;
    }

    result = ma_sound_init_from_file(&engine, "assets/five-nights-at-freddys-2-full-scream-sound.mp3", 0, NULL, NULL, &sound);

    if (result != MA_SUCCESS) {
#ifdef DEBUG
        printf("Failed to load sound file.\n");
#endif
        success = false;
        return -1;
    }

    return success;
}

void close() {
    //Uninit miniaudio engine
    ma_sound_uninit(&sound);
    ma_engine_uninit(&engine);

    //Destroy window and quit SDL
    SDL_DestroyWindow(window);
    SDL_Quit();
}

//Taken from: https://stackoverflow.com/questions/23048993/sdl-fullscreen-translucent-background
bool MakeWindowTransparent(SDL_Window* window, COLORREF colorKey) {
	SDL_SysWMinfo wmInfo;
	SDL_VERSION(&wmInfo.version) //init wmInfo
	SDL_GetWindowWMInfo(window, &wmInfo);
	HWND hWnd = wmInfo.info.win.window;
	//Change window type to layered
	SetWindowLong(hWnd, GWL_EXSTYLE, GetWindowLong(hWnd, GWL_EXSTYLE) | WS_EX_LAYERED);

	//Set transparency color
	return SetLayeredWindowAttributes(hWnd, colorKey, 0, LWA_COLORKEY);
}


void UpdateLogic() {
    switch (current_state) {
        case IDLE:
            AttemptJumpscare();
            break;
        case JUMPSCARE_PLAYING:
            UpdateJumpscare();
            break;
        case JUMPSCARE_FINISHED:
            FinishJumpscare();
            break;
    }
}

void AttemptJumpscare() {
    if (rng == 5000) {
        TriggerJumpscare();
        current_state = JUMPSCARE_PLAYING;
    } else {
#ifdef DEBUG
        printf("Random number was %d, retrying...\n", rng);
#endif
        rng = rand() % 10000;
        SDL_Delay(33); // Wait 30 frames
    }
}

void TriggerJumpscare() {
    foxy.set_sprite_column(0);
    SDL_Delay(10); // Ensure window is ready
    SDL_ShowWindow(window);
    ma_sound_start(&sound);
#ifdef DEBUG
    printf("Jumpscare Triggered!\n");
#endif
}

void UpdateJumpscare() {
    foxy.update(0.16);

    //Finish Jumpscare and reset sprite
    if (foxy.get_sprite_column() == 13) {
        current_state = JUMPSCARE_FINISHED;
    }
}

void FinishJumpscare() {
    SDL_HideWindow(window);
    rng = rand() % 10000;
    current_state = IDLE;
    foxy.set_sprite_column(0);
#ifdef DEBUG
    printf("Jumpscare Finished!\n");
#endif
}

void RenderJumpscare() {
    SDL_FillRect(window_surface, NULL, SDL_MapRGB(window_surface->format, 255, 255, 255)); //Clear with white (transparent color)
    foxy.render(window_surface);
}

void HandleTray() {
    Tray::Tray tray("My Tray", "icon.ico");

    tray.addEntry(Tray::Label("Withered Foxy Monitor"));
    tray.addEntry(Tray::Button("Exit", [&] {
        quit = true;
        tray.exit();
    }));
    
    tray.run();
}

int main(int argc, char* argv[]) {
    if (!init()) {
#ifdef DEBUG
        printf("Failed to initialize!\n");
#endif
        return -1;
    }

    MakeWindowTransparent(window, RGB(255, 255, 255)); //Transparent white

    //Center Foxy
    foxy.get_position()->w = screen_width;
    foxy.get_position()->h = screen_height;

    std::thread bgtray(HandleTray);

#ifdef DEBUG
    printf("Withered Foxy Jumpscare has been initalised\n");
#endif
    SDL_HideWindow(window);
    while(!quit){
    
        UpdateLogic();
        
        if (current_state == JUMPSCARE_PLAYING) {
            RenderJumpscare();
        } else {
            SDL_FillRect(window_surface, NULL, SDL_MapRGB(window_surface->format, 255, 255, 255)); //Clear with white (transparent color)
        }
        
        SDL_UpdateWindowSurface(window);
    }

    close();
}
