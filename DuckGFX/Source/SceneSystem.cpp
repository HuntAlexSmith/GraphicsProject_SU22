//*****************************************************************************
//	File:   SceneSystem.cpp
//  Author: Hunter Smith
//  Date:   05/12/2022
//  Description: This System will manage all the scenes that the renderer can
//		render to.
//*****************************************************************************

#include "SceneSystem.h"
#include "Scene1.h"
#include "Scene2.h"

SceneSystem::SceneSystem() : System(SysType::SceneSys),
	sceneList_{ {nullptr} },
	currentScene_(SceneID::sInvalid),
	nextScene_(SceneID::sInvalid)
{
}

void SceneSystem::Initialize()
{
	// Make sure the Scene manager can access the scene functions
	sceneList_[SceneID::sScene1] = {
		Scene1Load, Scene1Init, Scene1Update, Scene1Shutdown, Scene1Unload
	};
	sceneList_[SceneID::sScene2] = {
		Scene2Load, Scene2Init, Scene2Update, Scene2Shutdown, Scene2Unload
	};

	// Initialize what scene we are starting with
	nextScene_ = SceneID::sScene1;
}

void SceneSystem::Update(float dt)
{
	// Edge case of system starting up
	if (currentScene_ == SceneID::sInvalid)
	{
		currentScene_ = nextScene_;
		sceneList_[currentScene_].Load();
		sceneList_[currentScene_].Init();
	}

	// If next scene is not equal to current scene, scenes are swapping
	if (currentScene_ != nextScene_)
	{
		// Shutdown current scene
		sceneList_[currentScene_].Shutdown();

		// If we are not restarting, then we need to unload current scene and load next scene
		if (nextScene_ != SceneID::sRestart)
		{
			sceneList_[currentScene_].Unload();
			currentScene_ = nextScene_;
			sceneList_[currentScene_].Load();
		}

		// Initialize the current scene
		sceneList_[currentScene_].Init();
	}

	// Update the scene
	sceneList_[currentScene_].Update(dt);
}

void SceneSystem::Shutdown()
{
	// Need to unload and shutdown the current scene
	sceneList_[currentScene_].Shutdown();
	sceneList_[currentScene_].Unload();
}

SceneSystem::~SceneSystem()
{
}

void SceneSystem::SetNextScene(SceneID nextScene)
{
	nextScene_ = nextScene;
}