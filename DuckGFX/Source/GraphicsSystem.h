#pragma once
//*****************************************************************************
//	File:   Stub.h
//  Author: Hunter Smith
//  Date:   05/12/2022
//  Description: The System that will handle the OpenGL Graphics API, not for
//		actual rendering
//*****************************************************************************

#include "System.h"
#include "glm/glm.hpp"

//*****************************************************************************
// Brief: This class is the Graphics System class, which mainly handles any
//	OpenGL API stuff like loading GLAD and handling Shader Programs
//*****************************************************************************
class GraphicsSystem : public System {
public:

	GraphicsSystem();

	void Initialize() override;
	void Update(float dt) override;
	void Shutdown() override;

	void SetBackgroundColor(glm::vec4 newBackColor);

	~GraphicsSystem();

private:

	glm::vec4 backColor;
	bool redIncreasing;
	bool greenIncreasing;
	bool blueIncreasing;

};