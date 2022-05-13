#pragma once
//*****************************************************************************
//	File:   DuckRendering.h
//  Author: Hunter Smith
//  Date:   05/12/2022
//  Description: Header for the main Rendering Engine, DuckRendering
//*****************************************************************************

#include "System.h"

class DuckRendering {
public:

	DuckRendering();

	void Initialize();
	void Update(float dt);
	void Shutdown();

	void SetShutdown(bool shutdown);
	bool IsFinished();

	System* GetSystem(System::SysType type);

	~DuckRendering();

private:

	void AddSystem(System* newSys);

	System* systemList_[System::SysType::SystemCount];
	bool shouldShutdown_;

};