#pragma once
#include "World.h"
#include "PlayerCamera.h"
#include "Light.h"
#include "OBJMesh.h"
#include "Cube.h"

class DragonWorld : public World
{
public:
	void onStart() override;
	void onEnd() override;
	void onUpdate(float deltaTime) override;

private:
	PlayerCamera* m_camera = nullptr;

	Light* m_light1 = nullptr;
	Light* m_light2 = nullptr;
	Light* m_light3 = nullptr;
	float m_lightRotation = 0.0f;

	OBJMesh* m_dragon = nullptr;
	Cube* m_cube = nullptr;
};
