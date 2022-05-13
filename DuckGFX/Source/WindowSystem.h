#pragma once
//*****************************************************************************
//	File:   WindowSystem.h
//  Author: Hunter Smith
//  Date:   05/12/2022
//  Description: This is the System that will manage the window from SDL
//*****************************************************************************

#include "System.h"
#include "SDL_H/SDL.h"

class WindowSystem : public System {
public:

	WindowSystem();

	void Initialize() override;
	void Update(float dt) override;
	void Shutdown() override;

	~WindowSystem();

private:

	SDL_Window* windowHandle_;
	SDL_GLContext windowContext_;
	int windowFlags_;

};