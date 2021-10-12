#include "Cube.h"

Cube::Vertex* Cube::generateVertices(unsigned int& vertexCount, unsigned int& triCount)
{
	Vertex* vertices = nullptr;
	triCount = 12;
	vertexCount = 36;

	vertices = new Vertex[vertexCount];

	//Set Vertex Positions
	initializeCorner(vertices, vertexCount, 0, { -0.5f,  0.5f, -0.5 });//A
	initializeCorner(vertices, vertexCount, 1, {  0.5f,  0.5f,  0.5 });//B
	initializeCorner(vertices, vertexCount, 2, {  0.5f, -0.5f, -0.5 });//C
	initializeCorner(vertices, vertexCount, 3, { -0.5f, -0.5f,  0.5 });//D
	initializeCorner(vertices, vertexCount, 4, {  0.5f,  0.5f, -0.5 });//E
	initializeCorner(vertices, vertexCount, 5, { -0.5f,  0.5f,  0.5 });//F
	initializeCorner(vertices, vertexCount, 6, { -0.5f, -0.5f, -0.5 });//G
	initializeCorner(vertices, vertexCount, 7, {  0.5f, -0.5f,  0.5 });//H

	return vertices;
}

void Cube::initializeCorner(Vertex* vertices, unsigned int vertexCount, int index, glm::vec3 coordinates)
{
	for (int i = index; i < vertexCount; i += 8)
	{
		vertices[i].position = glm::vec4(coordinates * 0.5f, 1.0f);
		vertices[i].normal = glm::vec4(coordinates, 0.0f);
		vertices[i].color = m_color;
	}
}
