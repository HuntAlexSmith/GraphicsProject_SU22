//*****************************************************************************
//	File:   Main.cpp
//	Author: Hunter Smith
//	Date:	05/12/2022
//	Description: This is the main function file, where the program starts.
//		Nothing too fancy should really be happening here
//*****************************************************************************

#include "SDL_H/SDL.h"
#undef main
#include "DuckRendering.h"

static DuckRendering* duckRender;
static Uint64 lastTickCount;

int main() {
	// Create a new rendering engine and try to initialize it
	duckRender = new DuckRendering();
	if (duckRender)
		duckRender->Initialize();

	// If it wasn't made, exit
	else
		return 1;

	// Get the current tick count
	lastTickCount = SDL_GetTicks64();

	// Main loop
	while (!duckRender->IsFinished())
	{
		Uint64 currentTickCount = SDL_GetTicks64();
		float dt = 0.001f * static_cast<float>(currentTickCount - lastTickCount);
		lastTickCount = currentTickCount;
		duckRender->Update(dt);
	}

	// Out of main loop, shut the engine down
	duckRender->Shutdown();

	// Delete the render engine
	delete duckRender;

	// Return
	return 0;
}