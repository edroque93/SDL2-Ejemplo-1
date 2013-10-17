#ifndef MAIN_H
#define MAIN_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "utils.h"

void _setup();
void _game_loop();
bool _poll_events();

SDL_Window* window;

#endif
