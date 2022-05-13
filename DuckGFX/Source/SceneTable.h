#pragma once
//*****************************************************************************
//	File:   SceneTable.h
//  Author: Hunter Smith
//  Date:   05/12/2022
//  Description: This includes all the enum values of the Scenes that can be
//		accessed (so that SceneSystem is not accessed from other files)
//*****************************************************************************

enum SceneID {
	sInvalid = -2,
	sRestart = -1,
	sScene1,
	sScene2,
	sSceneCount
};