//*****************************************************************************
//	File:   Scene2.cpp
//  Author: Hunter Smith
//  Date:   05/12/2022
//  Description: The functions for Scene 2
//*****************************************************************************

#include "Scene2.h"
#include "DuckEngine.h"

static glm::vec4 blue(0, 0, 1, 1);

void Scene2Load()
{

}

void Scene2Init()
{
	DuckBackgroundColor(blue);
}

void Scene2Update(float dt)
{
	if (DuckInputIsTriggered(SDLK_1))
		DuckSetNextScene(SceneID::sScene1);
}

void Scene2Shutdown()
{

}

void Scene2Unload()
{

}