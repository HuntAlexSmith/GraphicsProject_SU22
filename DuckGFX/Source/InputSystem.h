#pragma once
//*****************************************************************************
//	File:   InputSystem.h
//  Author: Hunter Smith
//  Date:   05/12/2022
//  Description: This System will handle processing input from the user
//*****************************************************************************

#include "System.h"
#include "SDL_H/SDL.h"
#include <map>

class InputSystem : public System {
public:

	enum KeyState {
		None,
		Triggered,
		Down,
		Released
	};

	InputSystem();

	void Initialize() override;
	void Update(float dt) override;
	void Shutdown() override;

	bool IsTriggered(SDL_Keycode key);
	bool IsDown(SDL_Keycode key);
	bool IsReleased(SDL_Keycode key);

	~InputSystem();

private:

	std::map<SDL_Keycode, KeyState> keyMap_;
	SDL_Event inputEvent_;

};