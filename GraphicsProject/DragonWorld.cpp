#include "DragonWorld.h"
#include "gl_core_4_4.h"

void DragonWorld::onStart()
{
	//Camera
	m_camera = new PlayerCamera(45.0f, 0.001f, 1000.0f);
	m_camera->getTransform()->setPosition(-5.0f, 5.0f, 0.0f);
	m_camera->getTransform()->rotate(-40.0f, 0.0f, 0.0f);
	setCamera(m_camera);
	add(m_camera);

	if (!m_diffuseTexture.load("earth_diffuse.jpg"))
		printf("Failed to load texture.\n");

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
	m_quad = new Quad();
	m_quad->setColor({1,1,1,1});
	m_quad->getTransform()->setPosition({2,0,0});
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
}

void DragonWorld::onUpdate(float deltaTime)
{
	//Rotates every light in the scene
	m_lightRotationSpeed = 1.0f;
	if (m_light1->getTransform()->getRotation().y >= 360)
		m_lightRotationSpeed = -360.0f;

	m_light1->getTransform()->setRotation({ 0, m_light1->getTransform()->getRotation().y + m_lightRotationSpeed, 0 });
	m_light2->getTransform()->setRotation({ 0, m_light2->getTransform()->getRotation().y + m_lightRotationSpeed, 0 });
	m_light3->getTransform()->setRotation({ 0, m_light3->getTransform()->getRotation().y + m_lightRotationSpeed, 0 });
}

void DragonWorld::onDraw()
{
	int program = -1;
	glGetIntegerv(GL_CURRENT_PROGRAM, &program);

	if (program == -1)
		printf("No shader bound.\n");

	int diffuseTextureUniform = glGetUniformLocation(program, "diffuseTexture");
	if (diffuseTextureUniform >= 0)
		glUniform1i(diffuseTextureUniform, 0);

	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, m_diffuseTexture.getHandle());

	m_quad->draw();
}
