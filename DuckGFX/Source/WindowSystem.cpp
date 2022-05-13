//*****************************************************************************
//	File:   WindowSystem.cpp
//  Author: Hunter Smith
//  Date:   05/12/2022
//  Description: This is the System that will manage the Window from SDL
//*****************************************************************************

#include "WindowSystem.h"
#include "DuckRendering.h"

WindowSystem::WindowSystem() : System(SysType::WindowSys), windowHandle_(nullptr), windowContext_(nullptr), windowFlags_(0) {

}

// Initialize SDL and the Window System
void WindowSystem::Initialize() {
	// Try to Initialize SDL. If fail, throw an error
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
		return;

	// For simplicity, set all flags desired here
	windowFlags_ = SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL;

	// SDL has initialized successfully, now create the window
	windowHandle_ = SDL_CreateWindow("DuckRenderer", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1280, 720, windowFlags_);
	windowContext_ = SDL_GL_CreateContext(windowHandle_);
}

void WindowSystem::Update(float dt) {
	// For now, just watch for if the window is about to close
	SDL_Event currentEvent;
	while (SDL_PollEvent(&currentEvent)) {
		switch (currentEvent.type) {
			case SDL_QUIT:
				GetParent()->SetShutdown(true);
				break;
		}
	}
}

void WindowSystem::Shutdown() {
	SDL_GL_DeleteContext(windowContext_);
	windowContext_ = nullptr;

	SDL_DestroyWindow(windowHandle_);
	windowHandle_ = nullptr;
}

WindowSystem::~WindowSystem() {

}