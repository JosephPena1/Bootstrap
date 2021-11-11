#pragma once
#include "Mesh.h"
#include "Texture.h"

class Quad : public Mesh
{
public:
	Quad() : Mesh() {}
	Quad(const char* fileName, glm::vec4 color);

	void onStart() override;
	void onDraw() override;

	Vertex* generateVertices(unsigned int& vertexCount) override;
	unsigned int* generateIndices(unsigned int& indexCount) override;

	glm::vec4 getColor() { return m_color; }
	void setColor(glm::vec4 color) { m_color = color; }

private:
	const char* m_file = nullptr;
	glm::vec4 m_color = glm::vec4(1.0f);
	aie::Texture m_texture;
};

