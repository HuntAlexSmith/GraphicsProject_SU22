//*****************************************************************************
//	File:   InputSystem.cpp
//  Author: Hunter Smith
//  Date:   05/12/2022
//  Description: This system will handle input from the user
//*****************************************************************************

#include "InputSystem.h"
#include "DuckRendering.h"

InputSystem::InputSystem() : System(SysType::InputSys), keyMap_(), inputEvent_()
{
}

// Here we will fill the map with any keys we want to look for
void InputSystem::Initialize()
{
	std::pair<SDL_Keycode, KeyState> key1(SDLK_1, KeyState::None);
	std::pair<SDL_Keycode, KeyState> key2(SDLK_2, KeyState::None);
	keyMap_.insert(key1);
	keyMap_.insert(key2);
}

void InputSystem::Update(float dt)
{
	// Update any other keys from being triggered / released
	for (std::pair<SDL_Keycode, KeyState> key : keyMap_)
	{
		if (key.second == KeyState::Triggered)
			keyMap_[key.first] = KeyState::Down;
		else if (key.second == KeyState::Released)
			keyMap_[key.first] = KeyState::None;
	}
	
	// Process all input events from SDL
	while (SDL_PollEvent(&inputEvent_))
	{
		// Get the current Key and make sure we have a map for it
		SDL_Keycode currentKey = inputEvent_.key.keysym.sym;
		if (keyMap_.find(currentKey) != keyMap_.end())
		{
			switch (inputEvent_.type)
			{
				case SDL_KEYDOWN:
					keyMap_[currentKey] = KeyState::Triggered;
					break;
				case SDL_KEYUP:
					keyMap_[currentKey] = KeyState::Released;
					break;
			}
		}

		// Small edge case for if we want to quit
		if (inputEvent_.type == SDL_QUIT)
			GetParent()->SetShutdown(true);
	}
}

void InputSystem::Shutdown()
{

}

bool InputSystem::IsTriggered(SDL_Keycode key)
{
	KeyState stateOfKey = keyMap_[key];
	if (stateOfKey == KeyState::Triggered)
		return true;
	return false;
}

bool InputSystem::IsDown(SDL_Keycode key)
{
	KeyState stateOfKey = keyMap_[key];
	if (stateOfKey == KeyState::Down)
		return true;
	return false;
}

bool InputSystem::IsReleased(SDL_Keycode key)
{
	KeyState stateOfKey = keyMap_[key];
	if (stateOfKey == KeyState::Released)
		return true;
	return false;
}

InputSystem::~InputSystem()
{
}