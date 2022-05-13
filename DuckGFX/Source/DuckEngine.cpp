//*****************************************************************************
//	File:   DuckEngine.cpp
//  Author: Hunter Smith
//  Date:   05/12/2022
//  Description: This will be the wrapper for interacting with the rendering
//		engine. This allows for limitation of what users can do with it.
//*****************************************************************************

#include "DuckRendering.h"
#include "DuckEngine.h"
#include "SceneSystem.h"
#include "InputSystem.h"
#include "GraphicsSystem.h"
#include <stdexcept>

static DuckRendering* engine;

void DuckInitialize()
{
	engine = new DuckRendering();
	if (engine)
	{
		engine->Initialize();
	}
	else
	{
		throw std::runtime_error("Duck Rendering failed to initialize");
	}
}

void DuckUpdate(float dt)
{
	if (engine)
		engine->Update(dt);
}

void DuckShutdown()
{
	if (engine)
	{
		engine->Shutdown();
		delete engine;
	}
}

bool DuckIsFinished()
{
	if (engine)
		return engine->IsFinished();
	return true;
}

void DuckBackgroundColor(glm::vec4 backColor)
{
	GraphicsSystem* graphics = dynamic_cast<GraphicsSystem*>(engine->GetSystem(System::SysType::GraphicsSys));
	if (graphics)
		graphics->SetBackgroundColor(backColor);
}

void DuckSetNextScene(SceneID id)
{
	SceneSystem* sceneSys = dynamic_cast<SceneSystem*>(engine->GetSystem(System::SysType::SceneSys));
	if (sceneSys)
		sceneSys->SetNextScene(id);
}

bool DuckInputIsTriggered(SDL_Keycode key)
{
	InputSystem* inputSys = dynamic_cast<InputSystem*>(engine->GetSystem(System::SysType::InputSys));
	if (inputSys)
		return inputSys->IsTriggered(key);
	return false;
}

bool DuckInputIsDown(SDL_Keycode key)
{
	InputSystem* inputSys = dynamic_cast<InputSystem*>(engine->GetSystem(System::SysType::InputSys));
	if (inputSys)
		return inputSys->IsDown(key);
	return false;
}

bool DuckInputIsReleased(SDL_Keycode key)
{
	InputSystem* inputSys = dynamic_cast<InputSystem*>(engine->GetSystem(System::SysType::InputSys));
	if (inputSys)
		return inputSys->IsReleased(key);
	return false;
}