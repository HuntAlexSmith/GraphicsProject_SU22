//*****************************************************************************
//	File:   GraphicsSystem.cpp
//  Author: Hunter Smith
//  Date:   05/12/2022
//  Description: The System for handling the OpenGL Graphics API, not for
//		actual rendering
//*****************************************************************************

#include "GraphicsSystem.h"
#include "DuckRendering.h"
#include "glad/glad.h"
#include "SDL_H/SDL.h"

GraphicsSystem::GraphicsSystem() : System(SysType::GraphicsSys), backColor(0, 0, 0, 1),
	redIncreasing(true),
	greenIncreasing(true),
	blueIncreasing(true)
{
}

void GraphicsSystem::Initialize() {
	if (!gladLoadGLLoader(reinterpret_cast<GLADloadproc>(SDL_GL_GetProcAddress)))
	{
		GetParent()->SetShutdown(true);
		return;
	}
}

void GraphicsSystem::Update(float dt) {
	// Some quick funky background stuff to make sure everything is working
	if (redIncreasing)
	{
		backColor.r += 0.2f * dt;
		if (backColor.r >= 1.0f)
			redIncreasing = false;
	}
	else
	{
		backColor.r -= 0.2f * dt;
		if (backColor.r <= 0.0f)
			redIncreasing = true;
	}

	if (greenIncreasing)
	{
		backColor.g += 0.15f * dt;
		if (backColor.g >= 1.0f)
			greenIncreasing = false;
	}
	else
	{
		backColor.g -= 0.15f * dt;
		if (backColor.g <= 0.0f)
			greenIncreasing = true;
	}

	if (blueIncreasing)
	{
		backColor.b += 0.1f * dt;
		if (backColor.b >= 1.0f)
			blueIncreasing = false;
	}
	else
	{
		backColor.b -= 0.1f * dt;
		if (backColor.b <= 0.0f)
			blueIncreasing = true;
	}

	glClearColor(backColor.r, backColor.g, backColor.b, backColor.a);
	glClearDepth(1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void GraphicsSystem::Shutdown() {

}

GraphicsSystem::~GraphicsSystem() {

}