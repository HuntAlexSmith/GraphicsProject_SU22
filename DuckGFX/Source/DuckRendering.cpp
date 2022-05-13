//*****************************************************************************
//	File:   DuckRendering.cpp
//  Author: Hunter Smith
//  Date:   05/12/2022
//  Description: Implementation for the main Rendering Engine, named
//		DuckRendering
//*****************************************************************************

#include "WindowSystem.h"
#include "SceneSystem.h"
#include "InputSystem.h"
#include "GraphicsSystem.h"
#include "DuckRendering.h"

// Here we will allocate memory to all the necessary Systems and add them to the System List
// THEY ARE NOT INITIALIZED YET
DuckRendering::DuckRendering() : systemList_{ nullptr }, shouldShutdown_(false) {
	// Create a window system and add it to the render engine
	System* windowSys = new WindowSystem();
	System* sceneSys = new SceneSystem();
	System* inputSys = new InputSystem();
	System* graphicSys = new GraphicsSystem();
	AddSystem(windowSys);
	AddSystem(sceneSys);
	AddSystem(inputSys);
	AddSystem(graphicSys);
}

// Here we will create all the necessary Systems and add them to the System List
void DuckRendering::Initialize()
{
	for (System* system : systemList_)
	{
		if (system)
			system->Initialize();
	}
}

// Here we will update all the Systems that are a part of the Engine
void DuckRendering::Update(float dt)
{
	for (System* system : systemList_)
	{
		if (system)
			system->Update(dt);
	}
}

// Here we will shutdown the engine, making sure all systems initialized are shutdown
void DuckRendering::Shutdown()
{
	for (System* system : systemList_)
	{
		if (system)
			system->Shutdown();
	}
}

// Function for getting the engine ready for shutdown
void DuckRendering::SetShutdown(bool shutdown) {
	shouldShutdown_ = shutdown;
}

bool DuckRendering::IsFinished()
{
	return shouldShutdown_;
}

// Destructor will handle deleting all the data
DuckRendering::~DuckRendering() {
	for (System* system : systemList_)
	{
		if (system)
		{
			systemList_[system->GetType()] = nullptr;
			delete system;
		}
	}
}

// Helper function for adding new Systems
void DuckRendering::AddSystem(System* newSys)
{
	if (newSys)
	{
		systemList_[newSys->GetType()] = newSys;
		newSys->SetParent(this);
	}
}

// Get a system from the engine
System* DuckRendering::GetSystem(System::SysType type)
{
	return systemList_[type];
}