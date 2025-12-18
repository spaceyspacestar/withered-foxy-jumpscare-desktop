#pragma once
#include "foxy.hpp"
#include "SDL2/SDL.h"

bool activate_jumpscare = false;
bool jumpscare_finished = false;
WitheredFoxy foxy;
int rng = rand() % 10000;

enum JumpscareState {
    IDLE,
    JUMPSCARE_PLAYING,
    JUMPSCARE_FINISHED
};

JumpscareState current_state = IDLE;

//for main.cpp
void UpdateLogic();

//Trigger the jumpscare if threshold is met
void TriggerJumpscare();

//Rng shit
void AttemptJumpscare();

//Finish up the jumpscare before returning to idle
void FinishJumpscare();

//Update jumpscare logic
void UpdateJumpscare();

//Renders the foxy jumpscare
void RenderJumpscare();
