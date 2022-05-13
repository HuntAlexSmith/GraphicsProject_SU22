//*****************************************************************************
//	File:   Scene1.cpp
//  Author: Hunter Smith
//  Date:   05/12/2022
//  Description: The functions for Scene 1
//*****************************************************************************

#include "Scene2.h"
#include "DuckEngine.h"

static glm::vec4 red(1, 0, 0, 1);

void Scene1Load()
{

}

void Scene1Init()
{
	DuckBackgroundColor(red);
}

void Scene1Update(float dt)
{
	if (DuckInputIsTriggered(SDLK_2))
		DuckSetNextScene(SceneID::sScene2);
}

void Scene1Shutdown()
{

}

void Scene1Unload()
{

}
