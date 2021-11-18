#pragma once
#include "World.h"
#include "PlayerCamera.h"
#include "Light.h"
#include "OBJMesh.h"
#include "Cube.h"
#include "Quad.h"

class DragonWorld : public World
{
public:
	void onStart() override;
	void onEnd() override;

private:
	PlayerCamera* m_camera = nullptr;

	Light* m_light1 = nullptr;
	Light* m_light2 = nullptr;
	Light* m_light3 = nullptr;

	OBJMesh* m_bunny = nullptr;
	Cube* m_cube = nullptr;
	Quad* m_quad = nullptr;
};
