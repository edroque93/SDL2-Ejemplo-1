#include "main.h"

int main(){
	_setup();
	_game_loop();
	_clean();
	
	return 0;
}

void _setup(){
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
		_print_error("Can't initialize SDL", 1);

	atexit(SDL_Quit); // SDL will safely exit

	window = SDL_CreateWindow("Ejemplo 1",
				SDL_WINDOWPOS_UNDEFINED,
				SDL_WINDOWPOS_UNDEFINED,
				640,
				480,
				SDL_WINDOW_OPENGL);
				
	if (window == NULL)
		_print_error("Can't create window", 2);
	
	SDL_Renderer* bg_render;
		
	bg_render = SDL_CreateRenderer(window,
					-1,
					SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
					
	if (bg_render == NULL) 
		_print_error("Can't create renderer", 3);
	
	/*
		### PROVISIONAL ###
	*/
	SDL_Rect dest;
	dest.y = 0;
	dest.x = 0;
	dest.w = 640;
	dest.h = 480;
	
	int i;
	for (i = 0; i<640; i++) {	
		dest.x++;
		//SDL_RenderClear(bg_render); // do NOT clear, I want this awesome effect :D
		SDL_RenderCopy(bg_render, LoadImage("./res/bg.bmp", bg_render), NULL, &dest);
		SDL_RenderPresent(bg_render);
	}
	/*
		### PROVISIONAL ###
	*/
}

void _game_loop(){
	bool loop = true;
	
	while (loop) {
		loop = _poll_events();
		
		// Blabla render
	}
}

bool _poll_events(){
	SDL_Event event;
	
	while (SDL_PollEvent(&event))
		switch (event.type) {
			case SDL_KEYUP:
				printf("%s\n", SDL_GetKeyName(event.key.keysym.sym));
				break;
			case SDL_QUIT:
				return false;
			default:
				break;
		}
	
	return true;
}
