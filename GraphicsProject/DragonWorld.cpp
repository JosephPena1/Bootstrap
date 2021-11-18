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
	m_bunny = new OBJMesh();
	m_bunny->load("Bunny.obj");
	m_bunny->getTransform()->setPosition({ 0.0f, -2.0f, 0.0f});
	m_bunny->getTransform()->setScale(glm::vec3(0.2f));
	add(m_bunny);

	//Cube
	m_cube = new Cube();
	m_cube->setColor({ 0.6f, 0.2f, 0.4f, 1.0f });
	m_cube->getTransform()->scale(glm::vec3(1.0f));
	add(m_cube);

	//Quad
	m_quad = new Quad("earth_diffuse.jpg", { 0.25f, 0.25f, 0.25f, 1 });
	m_quad->getTransform()->setRotation({ 0,90,0 });
	m_quad->getTransform()->setPosition({0,-2,3});
	add(m_quad);
}

void DragonWorld::onEnd()
{
	destroy(m_camera);
	destroy(m_light1);
	destroy(m_light2);
	destroy(m_light3);
	destroy(m_bunny);
	destroy(m_cube);
	destroy(m_quad);
}
