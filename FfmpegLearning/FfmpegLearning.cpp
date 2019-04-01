﻿#include "pch.h"
#include<iostream>

extern "C" {
#include "libavcodec/avcodec.h";
#include "SDL/SDL.h"
}
int main(int argv, char* argc[]) {

	SDL_Window *window;                    // Declare a pointer

	// 07-14-2018: Modified by ZDH
	// SDL_Init(SDL_INIT_VIDEO);              // Initialize SDL2
	SDL_Init(SDL_INIT_EVERYTHING);              // Initialize SDL2
										   // Create an application window with the following settings:
	window = SDL_CreateWindow(
		avcodec_configuration(),                  // window title
		SDL_WINDOWPOS_UNDEFINED,           // initial x position
		SDL_WINDOWPOS_UNDEFINED,           // initial y position
		640,                               // width, in pixels
		480,                               // height, in pixels
		SDL_WINDOW_OPENGL                  // flags - see below
	);

	// Check that the window was successfully created
	if (window == NULL) {
		// In the case that the window could not be made...
		printf("Could not create window: %s\n", SDL_GetError());
		return 1;
	}

	// The window is open: could enter program loop here (see SDL_PollEvent())

	SDL_Delay(3000);  // Pause execution for 3000 milliseconds, for example

	// Close and destroy the window
	SDL_DestroyWindow(window);

	// Clean up
	SDL_Quit();
	return 0;
}
