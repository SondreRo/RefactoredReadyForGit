#include "MeshComponent.h"

#include <glm/gtc/type_ptr.hpp>

#include "glad/glad.h"

void MeshComponent::Draw(unsigned shader) const
{
    if (mesh->textures.empty())
    {
        glBindTexture(GL_TEXTURE_2D, -1);
    }
    else
    {
        for (unsigned int i = 0; i < mesh->textures.size(); i++)
        {
            glBindTexture(GL_TEXTURE_2D, mesh->textures[0].id);
        }
    }

    unsigned int modelMemoryLocation = glGetUniformLocation(shader, "model");
	glUniformMatrix4fv(modelMemoryLocation, 1, GL_FALSE, glm::value_ptr(DrawTransform.GetTransformMatrix()));

    glBindVertexArray(mesh->VAO);
    //glDrawElements(GL_TRIANGLES, static_cast<GLsizei>(mesh->indices.size()), GL_UNSIGNED_INT, 0);
    glDrawElements(GL_TRIANGLES, static_cast<GLsizei>(mesh->indices.size()), GL_UNSIGNED_INT, 0);

    glActiveTexture(GL_TEXTURE0);
    glActiveTexture(GL_TEXTURE1);

    glBindVertexArray(0);
}
