#pragma once
#include "World.h"
#include "PlayerCamera.h"
#include "Light.h"
#include "OBJMesh.h"
#include "Cube.h"
#include "Texture.h"

class DragonWorld : public World
{
public:
	void onStart() override;
	void onEnd() override;
	void onUpdate(float deltaTime) override;
	void onDraw() override;

private:
	PlayerCamera* m_camera = nullptr;

	Light* m_light1 = nullptr;
	Light* m_light2 = nullptr;
	Light* m_light3 = nullptr;
	float m_lightRotationSpeed = 0.0f;

	OBJMesh* m_bunny = nullptr;
	Cube* m_cube = nullptr;
	aie::Texture m_diffuseTexture;
};
