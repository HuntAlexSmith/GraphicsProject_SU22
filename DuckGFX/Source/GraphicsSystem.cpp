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

//*****************************************************************************
// Brief: Constructor for the Graphics System, which handles initializing
//	values and setting the base System type
//*****************************************************************************
GraphicsSystem::GraphicsSystem() : System(SysType::GraphicsSys), backColor(0, 0, 0, 1),
	redIncreasing(true),
	greenIncreasing(true),
	blueIncreasing(true)
{
}

//*****************************************************************************
// Brief: Function for Initializing the Graphics System, which is mainly to
//	handle loading glad as well as setting OpenGL options
//*****************************************************************************
void GraphicsSystem::Initialize() {
	if (!gladLoadGLLoader(reinterpret_cast<GLADloadproc>(SDL_GL_GetProcAddress)))
	{
		GetParent()->SetShutdown(true);
		return;
	}
}

//*****************************************************************************
// Brief: Function for Updating the Graphics System. Not much needs to be
//	updated here.
//*****************************************************************************
void GraphicsSystem::Update(float dt) {
	// Clear the background color here for now, the renderer should probably handle this though
	glClearColor(backColor.r, backColor.g, backColor.b, backColor.a);
	glClearDepth(1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

//*****************************************************************************
// Brief: Function for Shuting the Graphics System down. Nothing needs to be
//	done here
//*****************************************************************************
void GraphicsSystem::Shutdown() {

}

//*****************************************************************************
// Brief: Destructor for the graphics system
//*****************************************************************************
GraphicsSystem::~GraphicsSystem() {

}

//*****************************************************************************
// Brief: Function for setting the background color for OpenGL Clear
//*****************************************************************************
void GraphicsSystem::SetBackgroundColor(glm::vec4 newBackColor)
{
	backColor = newBackColor;
}