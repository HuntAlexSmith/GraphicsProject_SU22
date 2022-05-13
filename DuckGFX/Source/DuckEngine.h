#pragma once
//*****************************************************************************
//	File:   DuckEngine.h
//  Author: Hunter Smith
//  Date:   05/12/2022
//  Description: This will be the wrapper for interacting with the rendering
//		engine. This allows for limitation of what users can do with it.
//*****************************************************************************

#include "glm/glm.hpp"
#include "SDL_H/SDL.h"
#include "SceneTable.h"

// Initialize, Update, and Shutdown for Engine
void DuckInitialize();
void DuckUpdate(float dt);
void DuckShutdown();

// Set the background color
void DuckBackgroundColor(glm::vec4 backColor);

// Set the next scene
void DuckSetNextScene(SceneID id);

// Input checks
bool DuckInputIsTriggered(SDL_Keycode key);
bool DuckInputIsDown(SDL_Keycode key);
bool DuckInputIsReleased(SDL_Keycode key);

bool DuckIsFinished();