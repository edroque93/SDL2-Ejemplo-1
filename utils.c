#include "utils.h"

void _print_error(char *msg, int ecode){
	fprintf(stderr, "%s: %s\n", msg, SDL_GetError());
	exit(ecode);	
}

void _clean(){
	SDL_DestroyWindow(window);
}

// Actualizando función para usar PNGs...

SDL_Texture* LoadImage(char* file, SDL_Renderer* renderer) {
	return IMG_LoadTexture(renderer, file);
	
	SDL_Surface* loaded_image;
	SDL_Texture* texture;
	
	loaded_image = SDL_LoadBMP(file);
	
	if (loaded_image != NULL) {
		texture = SDL_CreateTextureFromSurface(renderer, loaded_image);
		SDL_FreeSurface(loaded_image);
	} else
		_print_error("Can't load image", 3);
		
	return texture;
}
