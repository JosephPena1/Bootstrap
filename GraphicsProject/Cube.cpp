#include "Cube.h"

Cube::Vertex* Cube::generateVertices(unsigned int& vertexCount)
{
	Vertex* vertices = nullptr;
	vertexCount = 8;

	vertices = new Vertex[vertexCount];

	//x left
	//z up

	//Bottom corners
	vertices[0].position = { 0.5f, 0.0f, -0.5f, 1.0f }; //BL
	vertices[1].position = { 0.5f, 0.0f, 0.5f, 1.0f };	//TL
	vertices[2].position = { -0.5f, 0.0f, 0.5f, 1.0f };	//TR
	vertices[3].position = { -0.5f, 0.0f, -0.5f, 1.0f };//BR
	//Top corners
	vertices[4].position = { 0.5f, 1.0f, -0.5f, 1.0f };	//BL
	vertices[5].position = { 0.5f, 1.0f, 0.5f, 1.0f };	//TL
	vertices[6].position = { -0.5f, 1.0f, 0.5f, 1.0f };	//TR
	vertices[7].position = { -0.5f, 1.0f, -0.5f, 1.0f };//BR

	/*
	for (int i = 0; i < vertexCount; i++)
		vertices[i].color = { 0.0f, 0.0f, 0.0f, 1.0f };
	*/
	vertices[0].color = { 1.0f, 0.0f, 0.0f, 1.0f };
	vertices[6].color = { 0.0f, 0.0f, 1.0f, 1.0f };
	vertices[1].color = { 0.0f, 1.0f, 0.0f, 1.0f };
	vertices[7].color = { 0.0f, 1.0f, 0.0f, 1.0f };
	vertices[2].color = { 0.0f, 1.0f, 1.0f, 1.0f };
	vertices[4].color = { 1.0f, 1.0f, 0.0f, 1.0f };
	vertices[3].color = { 1.0f, 0.5f, 1.0f, 1.0f };

	return vertices;
}

unsigned int* Cube::generateIndices(unsigned int& indexCount)
{
	indexCount = 36;

	unsigned int* indices = new unsigned int[indexCount]
	{
		0, 1, 2,
		3, 0, 2, //Bottom plane
		1, 0, 5,
		4, 5, 0, //Left plane
		3, 2, 7,
		6, 7, 2, //Right plane
		2, 1, 6,
		5, 6, 1, //Back plane
		3, 0, 7,
		4, 7, 0, //Front plane
		7, 4, 6,
		5, 6, 4  //Top plane
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
