cmake_minimum_required(VERSION 3.10) #Minimum CMake Version
set(CMAKE_CONFIGURATIOHN_TYPES "Release" CACHE STRING "" FORCE) #Set Build Type to Release

project(WitheredFoxyDesktopJumpscare) #Project Name

set(SDL2_ROOT "C:/vcdeps/SDL2-2.30.9") #Path to SDL2

include_directories(${SDL2_ROOT}/include)

link_directories((${SDL2_ROOT}/lib/x64))


set(CMAKE_WIN32_EXECUTABLE ON) # Comment this line for console

add_subdirectory("./src/traypp" EXCLUDE_FROM_ALL)

add_executable(WitheredFoxy WIN32 src/sprite.cpp src/foxy.cpp src/main.cpp resource.o) #Define Executable

target_link_libraries(WitheredFoxy SDL2main SDL2 tray) #Link Libraries