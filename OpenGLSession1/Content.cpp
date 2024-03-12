#include "Content.h"

#include <iostream>

#include "MeshImporter.h"

std::vector<std::shared_ptr<Mesh>> Content::CreateContent()
{
	std::vector<std::shared_ptr<Mesh>> NewMesh;
	MeshImporter mesh_importer;


	std::shared_ptr<Mesh> FelixCube = mesh_importer.LoadMesh("C:/Users/soroe/Documents/FelixCube.fbx");
	//std::shared_ptr<Mesh> FelixCube = mesh_importer.LoadMesh("C:/Users/soroe/Documents/CubeNoTexture.fbx");
	FelixCube->displayName = "FelixCubeMesh";
	NewMesh.push_back(FelixCube);















	std::cout << std::endl << "-------------" << std::endl;
	std::cout << "Loaded " << NewMesh.size() << " meshes." << std::endl;
	std::cout << "-------------" << std::endl;

	return NewMesh;
}
