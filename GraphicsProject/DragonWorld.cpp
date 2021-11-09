#include "DragonWorld.h"

void DragonWorld::onStart()
{
	//Camera
	m_camera = new PlayerCamera(45.0f, 0.001f, 1000.0f);
	m_camera->getTransform()->setPosition(-5.0f, 5.0f, 0.0f);
	m_camera->getTransform()->rotate(-40.0f, 0.0f, 0.0f);
	setCamera(m_camera);
	add(m_camera);

	//Lights
	m_light1 = new Light
	(
		{ -0.5f, 0.0f, 0.5f },
		{ 0.2f, 0.2f, 0.2f, 1.0f },
		{ 1.0f, 0.0f, 0.0f, 1.0f },
		{ 1.0f, 1.0f, 1.0f, 1.0f }
	);
	m_light1->setIndex(0);
	add(m_light1);

	m_light2 = new Light
	(
		{ -0.5f, 0.0f, -0.5f },
		{ 0.2f, 0.2f, 0.2f, 1.0f },
		{ 0.0f, 1.0f, 0.0f, 1.0f },
		{ 1.0f, 1.0f, 1.0f, 1.0f }
	);
	m_light2->setIndex(1);
	add(m_light2);

	m_light3 = new Light
	(
		{ 0.5f, 0.0f, 0.0f },
		{ 0.2f, 0.2f, 0.2f, 1.0f },
		{ 0.0f, 0.0f, 1.0f, 1.0f },
		{ 1.0f, 1.0f, 1.0f, 1.0f }
	);
	m_light3->setIndex(2);
	add(m_light3);

	//Dragon
	m_dragon = new OBJMesh();
	m_dragon->load("Bunny.obj");
	m_dragon->getTransform()->setPosition({ 0.0f, -2.0f, 0.0f});
	m_dragon->getTransform()->setScale(glm::vec3(0.2f));
	add(m_dragon);

	//Cube
	m_cube = new Cube();
	m_cube->setColor({ 0.6f, 0.2f, 0.4f, 1.0f });
	m_cube->getTransform()->scale(glm::vec3(1.0f));
	add(m_cube);
}

void DragonWorld::onEnd()
{
	destroy(m_camera);
	destroy(m_light1);
	destroy(m_dragon);
	destroy(m_cube);
}

void DragonWorld::onUpdate(float deltaTime)
{
	//Rotates the lights in the scene
	m_lightRotation = 1.0f;
	if (m_light1->getTransform()->getRotation().y >= 360)
		m_lightRotation = -360.0f;

	m_light1->getTransform()->setRotation({ 0, m_light1->getTransform()->getRotation().y + m_lightRotation, 0 });
	m_light2->getTransform()->setRotation({ 0, m_light2->getTransform()->getRotation().y + m_lightRotation, 0 });
	m_light3->getTransform()->setRotation({ 0, m_light3->getTransform()->getRotation().y + m_lightRotation, 0 });
}
