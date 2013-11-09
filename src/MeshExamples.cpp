#include "MeshExamples.hpp"

bool MeshExamples::generated = false;

std::vector<Mesh*> MeshExamples::meshes = std::vector<Mesh*>(10);

Mesh& MeshExamples::get(size_t index)
{
	generate(index);
	Mesh* m = meshes.at(index);
	return *m;
}

void MeshExamples::generate(size_t index)
{
	Mesh* mesh = nullptr;

	switch(index)
	{
	case 0:
		mesh = static_cast<Mesh*>(new RectangularMesh(3, 3,
				Point3D(0, 0, 0), Point3D(1, 1, 2), true));
		mesh->pt(0).z = 1.5;
		mesh->pt(1).z = 1.5;
		mesh->pt(2).z = 1.5;
		mesh->pt(3).z = 1.5;
		mesh->pt(4).z = 0.0;
		mesh->pt(5).z = 1.5;
		mesh->pt(6).z = 0.5;
		mesh->pt(7).z = 0.5;
		mesh->pt(8).z = 0.5;
		mesh->recalculate();
		break;

	case 1:
		mesh = static_cast<Mesh*>(new RectangularMesh(10, 5,
				Point3D(-10, -5, -2), Point3D(10, 5, 2), false));
		mesh->pt(0).boundary = true;
		mesh->pt(0).z = -2.0;
		mesh->pt(10).boundary = true;
		mesh->pt(10).z = -2.0;
		mesh->pt(20).boundary = true;
		mesh->pt(20).z = -2.0;
		mesh->pt(30).boundary = true;
		mesh->pt(30).z = -2.0;
		mesh->pt(40).boundary = true;
		mesh->pt(40).z = -2.0;

		mesh->pt(9).boundary = true;
		mesh->pt(9).z = 2.0;
		mesh->pt(19).boundary = true;
		mesh->pt(19).z = 2.0;
		mesh->pt(29).boundary = true;
		mesh->pt(29).z = 2.0;
		mesh->pt(39).boundary = true;
		mesh->pt(39).z = 2.0;
		mesh->pt(49).boundary = true;
		mesh->pt(49).z = 2.0;

		mesh->recalculate();
		break;

	case 2:
		mesh = static_cast<Mesh*>(new RectangularMesh(3, 3,
				Point3D(-1, -1, 0), Point3D(1, 1, 2), true));
		mesh->pt(0).z = 1.5;
		mesh->pt(1).z = 1.5;
		mesh->pt(2).z = 1.5;
		mesh->pt(3).boundary = false;
		mesh->pt(3).z = 0.0;
		mesh->pt(4).z = 0.0;
		mesh->pt(5).boundary = false;
		mesh->pt(5).z = 0.0;
		mesh->pt(6).z = 0.5;
		mesh->pt(7).z = 0.5;
		mesh->pt(8).z = 0.5;
		mesh->recalculate();
		break;

	case 3:
		mesh = static_cast<Mesh*>(new TriangularMesh(3, 3,
				Point3D(-1, -1, 0), Point3D(1, 1, 2), true));
		mesh->pt(0).z = 1.5;
		mesh->pt(1).z = 1.5;
		mesh->pt(2).boundary = false;
		mesh->pt(2).z = 0.0;
		mesh->pt(3).z = 0.0;
		mesh->pt(4).boundary = false;
		mesh->pt(4).z = 0.0;
		mesh->pt(5).z = 0.5;
		mesh->pt(6).z = 0.5;
		mesh->recalculate();
		break;

	case 4:
		mesh = static_cast<Mesh*>(new TriangularMesh(2, 2,
				Point3D(-1, -1, 0), Point3D(1, 1, 2), true));
		mesh->pt(0).z = 1.0;
		mesh->pt(1).z = 2.0;
		mesh->pt(2).boundary = false;
		mesh->pt(2).z = 0.0;
		mesh->recalculate();
		break;

	case 5:
		mesh = static_cast<Mesh*>(new TriangularMesh(7, 7,
				Point3D(-12, -10, -3), Point3D(12, 10, 3), false));

		mesh->pt(0).boundary = true;
		mesh->pt(0).z = -3.0;
		mesh->pt(6).boundary = true;
		mesh->pt(6).z = -3.0;

		mesh->pt(5).boundary = true;
		mesh->pt(5).z = 3.0;
		mesh->pt(12).boundary = true;
		mesh->pt(12).z = 3.0;

		mesh->pt(32).boundary = true;
		mesh->pt(32).z = 3.0;
		mesh->pt(39).boundary = true;
		mesh->pt(39).z = 3.0;

		mesh->pt(38).boundary = true;
		mesh->pt(38).z = -3.0;
		mesh->pt(44).boundary = true;
		mesh->pt(44).z = -3.0;

		mesh->recalculate();
		break;
	}

	meshes[index] = mesh;
}

MeshExamples::MeshExamples() { }
