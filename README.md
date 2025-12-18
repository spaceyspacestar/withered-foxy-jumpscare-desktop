# Ten thousand in one chance Withered Foxy Jumpscares You for Windows 10/11
#### Inspired by the countless Withered Foxy jumpscare mods, but mainly [The real OG.](https://steamcommunity.com/sharedfiles/filedetails/?id=3481943642)

This is a SDL2 written program in C++ built using CMAKE where there's a 10000 in 1 chance where Withered Foxy jumpscares you on your windows desktop. (Sorry linux users I'll get to creating a linux version soon. or feel free to create a linux version before me, that works too.)

## Libraries used for this project
[SDL2](https://www.libsdl.org/) for creating the window and rendering Foxy.

[Miniaudio](https://miniaud.io/) for audio playback.

[Traypp](https://github.com/Soundux/traypp) for initalising it to the tray.

### How to build (to contribute into a throwaway joke)
1. Download SDL2 2.30.9 (or later, I don't think it necessarily matters unless it's SDL3)
2. Clone this repository using CMD
3. do `cd withered-foxy-jumpscare-desktop`
4. Update line 5 in CMakeLists.txt: ```set(SDL2_ROOT "C:/vcdeps/SDL2-2.30.9/x86_64-w64-mingw32") #Path to SDL2``` to change to your SDL2 installation.
5. do `mkdir build` and cd into the build directory.
6. run `cmake ..` and it'll create a build list (there's only really one)
7. finally, run `cmake --build .` and it'll compile successfully.

### How to contribute?
Fork and make a pull request!
