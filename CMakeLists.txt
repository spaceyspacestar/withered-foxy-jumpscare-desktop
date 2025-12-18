cmake_minimum_required(VERSION 3.10) #Minimum CMake Version

project(WitheredFoxyDesktopJumpscare) #Project Name

set(SDL2_ROOT "C:/vcdeps/SDL2-2.30.9/x86_64-w64-mingw32") #Path to SDL2

include_directories(${SDL2_ROOT}/include)

link_directories((${SDL2_ROOT}/lib))

set(CMAKE_WIN32_EXECUTABLE ON) # Comment this line for console

add_subdirectory("./src/traypp" EXCLUDE_FROM_ALL)

add_executable(WitheredFoxy WIN32 src/sprite.cpp src/foxy.cpp src/main.cpp resource.o) #Define Executable

target_link_libraries(WitheredFoxy SDL2main SDL2 tray) #Link Libraries