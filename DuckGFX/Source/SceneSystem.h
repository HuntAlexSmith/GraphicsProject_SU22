#pragma once
//*****************************************************************************
//	File:   SceneSystem.h
//  Author: Hunter Smith
//  Date:   05/12/2022
//  Description: This System will manage all the scenes that the renderer can
//		render to.
//*****************************************************************************

#include "System.h"
#include "SceneTable.h"

typedef void (*vFunc)();
typedef void (*uFunc)(float);

class SceneSystem : public System {
public:

	struct Scene {
		vFunc Load;
		vFunc Init;
		uFunc Update;
		vFunc Shutdown;
		vFunc Unload;
	};

	SceneSystem();

	void Initialize() override;
	void Update(float dt) override;
	void Shutdown() override;

	void SetNextScene(SceneID nextScene);

	~SceneSystem();

private:

	Scene sceneList_[SceneID::sSceneCount];
	SceneID currentScene_;
	SceneID nextScene_;

};