#pragma once
#include <SDL2/SDL.h>

class SpriteSheet {
    public: 
        SpriteSheet(char const *path, int spriteWidth, int spriteHeight);
        ~SpriteSheet();

        void selectSprite(int x, int y);
        void renderSprite(SDL_Surface *Window_surface, SDL_Rect *position);
        SDL_Rect getSpriteWidthHeight() const { return m_clip; }
    private:
        SDL_Rect m_clip;
        SDL_Surface *m_spritesheet_image;
};
