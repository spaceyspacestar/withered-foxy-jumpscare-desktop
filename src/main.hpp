#pragma once
#define SDL_MAIN_HANDLED
#define MINIAUDIO_IMPLEMENTATION
#include <stdio.h>
#include <thread>
#include <SDL2/SDL.h>
#include <SDL2/SDL_syswm.h>
#include <windows.h>
#include <winuser.h>
#include <winternl.h>
#include "miniaudio/miniaudio.h"
#include "traypp/tray/include/tray.hpp"

SDL_Window* window;

SDL_Surface* window_surface;

const int screen_width = GetSystemMetrics(SM_CXSCREEN);
const int screen_height = GetSystemMetrics(SM_CYSCREEN);

//Miniaudio Stuff
ma_result result;
ma_engine engine;
ma_sound sound;

bool quit = false;

//Startup
bool init();

//Frees up Miniaudio and SDL2 resources
void close();

//Make the window transparent
bool MakeWindowTransparent(SDL_Window* window, COLORREF colorKey);