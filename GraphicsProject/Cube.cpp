#include "Cube.h"

void Cube::onUpdate(float deltaTime)
{
	//Rotation
	getTransform()->rotate({0,0.2f,0});

	//Up and down
	float FloatingSpeed = 0.2f;
	if (!m_goingDown)
	{
		getTransform()->translate({ 0, -FloatingSpeed * deltaTime, 0 });
		m_height -= FloatingSpeed * deltaTime;
		m_goingDown = (m_height <= -1);
	}

	if (m_goingDown)
	{
		getTransform()->translate({ 0, FloatingSpeed * deltaTime, 0 });
		m_height += FloatingSpeed * deltaTime;
		m_goingDown = !(m_height >= 0);
	}

	Entity::onUpdate(deltaTime);
}

Cube::Vertex* Cube::generateVertices(unsigned int& vertexCount)
{
	Vertex* vertices = nullptr;
	vertexCount = 8;

	vertices = new Vertex[vertexCount];

	//x right
	//z forward

	//Bottom corners
	vertices[0].position = {  0.5f, 0.0f, -0.5f, 1.0f };//BL
	vertices[1].position = {  0.5f, 0.0f,  0.5f, 1.0f };//TL
	vertices[2].position = { -0.5f, 0.0f,  0.5f, 1.0f };//TR
	vertices[3].position = { -0.5f, 0.0f, -0.5f, 1.0f };//BR
	//Top corners
	vertices[4].position = {  0.5f, 1.0f, -0.5f, 1.0f };//BL
	vertices[5].position = {  0.5f, 1.0f,  0.5f, 1.0f };//TL
	vertices[6].position = { -0.5f, 1.0f,  0.5f, 1.0f };//TR
	vertices[7].position = { -0.5f, 1.0f, -0.5f, 1.0f };//BR

	vertices[0].normal = { 0.5f, 0.0f, -0.5f, 0.0f };
	vertices[1].normal = { 0.5f, 0.0f, 0.5f, 0.0f };
	vertices[2].normal = { -0.5f, 0.0f, 0.5f, 0.0f };
	vertices[3].normal = { -0.5f, 0.0f, -0.5f, 0.0f };

	vertices[4].normal = { 0.5f, 1.0f, -0.5f, 0.0f };
	vertices[5].normal = { 0.5f, 1.0f, 0.5f, 0.0f };
	vertices[6].normal = { -0.5f, 1.0f, 0.5f, 0.0f };
	vertices[7].normal = { -0.5f, 1.0f, -0.5f, 0.0f };

	//Set color for each corner
	vertices[0].color = { 1.0f, 0.0f, 0.0f, 1.0f };
	vertices[1].color = { 0.0f, 1.0f, 0.0f, 1.0f };
	vertices[2].color = { 0.0f, 0.0f, 1.0f, 1.0f };
	vertices[3].color = { 0.0f, 1.0f, 0.0f, 1.0f };
	vertices[4].color = { 0.0f, 0.0f, 1.0f, 1.0f };
	vertices[5].color = { 0.0f, 1.0f, 0.0f, 1.0f };
	vertices[6].color = { 1.0f, 0.0f, 0.0f, 1.0f };
	vertices[7].color = { 0.0f, 1.0f, 0.0f, 1.0f };

	return vertices;
}

unsigned int* Cube::generateIndices(unsigned int& indexCount)
{
	indexCount = 36;

	//Create a triangle in each row based on position
	unsigned int* indices = new unsigned int[indexCount]
	{
		1, 2, 0, //Bottom plane
		3, 0, 2,

		1, 0, 5, //Left plane
		4, 5, 0,

		3, 2, 7, //Right plane
		6, 7, 2,

		2, 1, 6, //Back plane
		5, 6, 1,

		3, 0, 7, //Front plane
		4, 7, 0,

		7, 4, 6, //Top plane
		5, 6, 4 
	};

	return indices;
}

void Cube::initializeCorner(Vertex* vertices, unsigned int vertexCount, int index, glm::vec3 coordinates)
{
	for (int i = index; i < vertexCount; i += 8)
	{
		vertices[i].position = glm::vec4(coordinates, 1.0f);
		vertices[i].normal = glm::vec4(coordinates, 0.0f);
		vertices[i].color = m_color;
	}
}
