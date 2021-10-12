#include "Cube.h"

Cube::Vertex* Cube::generateVertices(unsigned int& vertexCount, unsigned int& triCount)
{
	Vertex* vertices = nullptr;
	triCount = 12;
	vertexCount = 36;

	vertices = new Vertex[vertexCount];

	//Set Vertex Positions
	setVertexPosition(vertices, vertexCount, 0, { -0.5f,  0.5f, -0.5 });//A
	setVertexPosition(vertices, vertexCount, 0, {  0.5f,  0.5f,  0.5 });//B
	setVertexPosition(vertices, vertexCount, 0, {  0.5f, -0.5f, -0.5 });//C
	setVertexPosition(vertices, vertexCount, 0, { -0.5f, -0.5f,  0.5 });//D
	setVertexPosition(vertices, vertexCount, 0, {  0.5f,  0.5f, -0.5 });//E
	setVertexPosition(vertices, vertexCount, 0, { -0.5f,  0.5f,  0.5 });//F
	setVertexPosition(vertices, vertexCount, 0, { -0.5f, -0.5f, -0.5 });//G
	setVertexPosition(vertices, vertexCount, 0, {  0.5f, -0.5f,  0.5 });//H



	return nullptr;
}

void Cube::setVertexPosition(Vertex* vertices, unsigned int vertexCount, int index, glm::vec3 position)
{
	for (int index = 0; index <= vertexCount; index += 8)
		vertices[index].position = glm::vec4(position, 1.0f);
}
