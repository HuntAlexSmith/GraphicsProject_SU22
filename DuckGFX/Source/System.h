#pragma once
//*****************************************************************************
//	File:   Stub.h
//  Author: Hunter Smith
//  Date:   05/12/2022
//  Description: Base class for any System that will be added to the Rendering
//		Engine.
//*****************************************************************************

typedef class DuckRendering DuckRendering;

class System {
public:

	enum SysType {
		WindowSys,
		SceneSys,
		InputSys,
		CameraSys,
		GraphicsSys,
		RenderingSys,
		SystemCount
	};

	// Constructor
	System(SysType type) : type_(type), parent_(nullptr) {}

	// Functions that every system needs
	virtual void Initialize() = 0;
	virtual void Update(float dt) = 0;
	virtual void Shutdown() = 0;

	SysType GetType() { return type_; }
	DuckRendering* GetParent() { return parent_; }
	void SetParent(DuckRendering* parent) { parent_ = parent; }

	// Destructor
	~System() {}

private:

	SysType type_;
	DuckRendering* parent_;

};