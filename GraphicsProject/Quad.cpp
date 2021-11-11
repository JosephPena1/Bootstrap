#include "Quad.h"
#include "gl_core_4_4.h"

Quad::Quad(const char* fileName, glm::vec4 color) : Quad::Quad()
{
	m_file = fileName;
	m_color = color;
}

void Quad::onStart()
{
	Mesh::onStart();
	if (!m_texture.load(m_file))
		printf("Failed to load texture.\n");
}

void Quad::onDraw()
{
	int program = -1;
	glGetIntegerv(GL_CURRENT_PROGRAM, &program);

	if (program == -1)
		printf("No shader bound.\n");

	int diffuseTextureUniform = glGetUniformLocation(program, "diffuseTexture");
	if (diffuseTextureUniform >= 0)
		glUniform1i(diffuseTextureUniform, 0);

	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, m_texture.getHandle());

	Mesh::onDraw();
}

Quad::Vertex* Quad::generateVertices(unsigned int& vertexCount)
{
	//Set the number of vertices
	vertexCount = 6;

	//Define the vertices for a quad
	Vertex* vertices = new Vertex[vertexCount];

	vertices[0].position = { -0.5f, 0.0f,  1.0f, 1.0f };
	vertices[1].position = {  0.5f, 0.0f,  1.0f, 1.0f };
	vertices[2].position = { -0.5f, 0.0f, -0.5f, 1.0f };
	vertices[3].position = {  0.5f, 0.0f, -0.5f, 1.0f };

	vertices[0].texCoord = { 0.0f, 0.0f };
	vertices[1].texCoord = { 0.0f, 1.0f };
	vertices[2].texCoord = { 1.0f, 0.0f };
	vertices[3].texCoord = { 1.0f, 1.0f };

	for (int i = 0; i < vertexCount; i++) 
	{
		vertices[i].normal = { 0.0f, 1.0f, 0.0f, 0.0f };
		vertices[i].color = m_color;
	}

	return vertices;
}

unsigned int* Quad::generateIndices(unsigned int& indexCount)
{
	//Set the number of indices
	indexCount = 6;

	unsigned int* indices = new unsigned int[indexCount]
	{
		0, 1, 2,
		2, 1, 3
	};

	return indices;
}