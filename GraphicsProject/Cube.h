#pragma once
#include "Mesh.h"

class Cube : public Mesh
{
public:
	Cube() : Mesh() {}
	~Cube() {}

	void onUpdate(float deltaTime) override;

	Vertex* generateVertices(unsigned int& vertexCount) override;
	unsigned int* generateIndices(unsigned int& indexCount) override;

	glm::vec4 getColor() { return m_color; }
	void setColor(glm::vec4 color) { m_color = color; }

private:
	void initializeCorner(Vertex* vertices, unsigned int vertexCount, int index, glm::vec3 position);

private:
	glm::vec4 m_color = glm::vec4(1.0f);
	bool m_goingDown = false;
	float m_height = 0.0f;

};
