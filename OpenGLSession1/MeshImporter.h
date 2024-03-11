#pragma once

#include <memory>
#include <assimp/Importer.hpp>
#include <assimp/scene.h>


#include "mesh.h"

class MeshImporter
{
	std::vector<Texture> textures_loaded;
	std::string directory;
	std::shared_ptr<Mesh> LastLoadedMesh;
public:
	MeshImporter() = default;

	std::shared_ptr<Mesh> LoadMesh(std::string path);

	void processNode(aiNode* node, const aiScene* scene);
	std::shared_ptr<Mesh> processMesh(aiMesh* mesh, const aiScene* scene);

	std::vector<Texture> loadMaterialTextures(aiMaterial* mat, aiTextureType type, std::string typeName);

	unsigned int TextureFromFile(std::string path);

	std::vector<std::shared_ptr<Mesh>> Meshes;
};

