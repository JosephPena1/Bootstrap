#include "DragonWorld.h"

void DragonWorld::onStart()
{
	//Camera
	m_camera = new PlayerCamera(45.0f, 0.001f, 1000.0f);
	m_camera->getTransform()->setPosition(5.0f, 5.0f, 5.0f);
	m_camera->getTransform()->rotate(-40.0f, -135.0f, 0.0f);
	setCamera(m_camera);
	add(m_camera);

	//Light
	m_light = new Light(
		{ 1.0f, 1.0f, 1.0f },
		{ 0.5f, 0.5f, 0.5f, 1.0f },
		{ 1.0f, 1.0f, 1.0f, 1.0f },
		{ 1.0f, 1.0f, 1.0f, 1.0f }
	);
	add(m_light);

	//Dragon
	m_dragon = new OBJMesh();
	m_dragon->load("Dragon.obj");
	add(m_dragon);
}

void DragonWorld::onEnd()
{
	destroy(m_camera);
	destroy(m_light);
	destroy(m_dragon);
}
