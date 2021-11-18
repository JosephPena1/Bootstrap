#include "Light.h"
#include "gl_core_4_4.h"
#include <string>

Light::Light(glm::vec3 direction, glm::vec4 ambient, glm::vec4 diffuse, glm::vec4 specular)
	: Light()
{
	setDirection(direction);
	m_ambient = ambient;
	m_diffuse = diffuse;
	m_specular = specular;

	m_isRed = (getDiffuse().x == 1);
	m_isGreen = (getDiffuse().y == 1);
	m_isBlue = (getDiffuse().z == 1);
}

void Light::onUpdate(float deltaTime)
{
	//Rotates the light in the scene
	m_lightRotationSpeed = 1.0f;
	if (getTransform()->getRotation().y >= 360)
		m_lightRotationSpeed = -360.0f;

	getTransform()->rotate({ 0, m_lightRotationSpeed, 0 });
}

void Light::onDraw()
{
	//Checks if index is out of bounds
	if (m_index < 0)
	{
		printf("Light::setIndex less than zero");
		return;
	}
	else if (m_index > 2)
	{
		printf("Light::setIndex exceeds maximum of 2");
		return;
	}

	int program = -1;
	glGetIntegerv(GL_CURRENT_PROGRAM, &program);

	//Checks if a shader was bound
	if (program == -1) 
	{
		printf("No shader bound!\n");
		return;
	}

	//Create int variables for light
	int lightDirection = 0, lightAmbient = 0, 
		lightDiffuse = 0, lightSpecular = 0;

	//Set Light variables using strings
	std::string str = ("iDirection" + std::to_string(m_index));
	lightDirection = glGetUniformLocation(program, str.c_str());

	str = ("iAmbient" + std::to_string(m_index));
	lightAmbient = glGetUniformLocation(program, str.c_str());

	str = ("iDiffuse" + std::to_string(m_index));
	lightDiffuse = glGetUniformLocation(program, str.c_str());

	str = ("iSpecular" + std::to_string(m_index));
	lightSpecular = glGetUniformLocation(program, str.c_str());

	if (lightDirection >= 0) 
	{
		glm::vec3 direction = getDirection();
		glUniform3f(lightDirection, direction.x, direction.y, direction.z);
	}
	if (lightAmbient >= 0) 
		glUniform3f(lightAmbient, m_ambient.x, m_ambient.y, m_ambient.z);

	if (lightDiffuse >= 0) 
		glUniform3f(lightDiffuse, m_diffuse.x, m_diffuse.y, m_diffuse.z);

	if (lightSpecular >= 0) 
		glUniform3f(lightSpecular, m_specular.x, m_specular.y, m_specular.z);
}

glm::vec3 Light::getDirection()
{
	return getTransform()->getForward();
}

void Light::setDirection(glm::vec3 direction)
{
	getTransform()->setForward(direction);
}
