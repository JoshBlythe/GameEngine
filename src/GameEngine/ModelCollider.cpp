#include "ModelCollider.h"
#include "MeshRender.h"
#include "Entity.h"
//#include "Model.h"
//#include "MaterialGroup.h"
//#include "Part.h"

#include <glm/glm.hpp>
#include <glm/ext.hpp>
#include <cmath>

int triBoxOverlap(float boxcenter[3],
	float boxhalfsize[3], float triverts[3][3]);

bool ColliderColumn::isColliding(glm::vec3 _position, glm::vec3 _size)
{
	//glm::vec3 _currentPos = getEntity()->getTransform()->getPosition();

	for (std::vector<CollisionTrig>::iterator i = faces.begin(); i != faces.end(); i++)
	{
		float f[3][3] = { 0 };
		f[0][0] = i->a.x;
		f[0][1] = i->a.y;
		f[0][2] = i->a.z;
		f[1][0] = i->b.x;
		f[1][1] = i->b.y;
		f[1][2] = i->b.z;
		f[2][0] = i->c.x;
		f[2][1] = i->c.y;
		f[2][2] = i->c.z;

		float bc[3] = { 0 };
		bc[0] = _position.x;
		bc[1] = _position.y;
		bc[2] = _position.z;
		
		float bhs[3] = { 0 };
		bhs[0] = _size.x / 2.0f;
		bhs[1] = _size.y / 2.0f;
		bhs[2] = _size.z / 2.0f;

		if (triBoxOverlap(bc, bhs, f))
		{
			return true;
		}
	}

	return false;
}

void ColliderColumn::getColliding(glm::vec3 _position, glm::vec3 _size,
	std::vector<CollisionTrig>& _collisions)
{
	for (std::vector<CollisionTrig>::iterator i = faces.begin(); i != faces.end(); i++)
	{
		float f[3][3] = { 0 };
		f[0][0] = i->a.x;
		f[0][1] = i->a.y;
		f[0][2] = i->a.z;
		f[1][0] = i->b.x;
		f[1][1] = i->b.y;
		f[1][2] = i->b.z;
		f[2][0] = i->c.x;
		f[2][1] = i->c.y;
		f[2][2] = i->c.z;

		float bc[3] = { 0 };
		bc[0] = _position.x;
		bc[1] = _position.y;
		bc[2] = _position.z;
		float bhs[3] = { 0 };
		bhs[0] = _size.x / 2.0f;
		bhs[1] = _size.y / 2.0f;
		bhs[2] = _size.z / 2.0f;

		if (triBoxOverlap(bc, bhs, f))
		{
			_collisions.push_back(*i);
		}
	}
}

void ModelCollider::getColliding(glm::vec3 _position, glm::vec3 _size,
	std::vector<CollisionTrig>& _collisions)
{
    for (std::vector<CollisionTrig>::iterator i = m_allFaces.begin(); i != m_allFaces.end(); i++)
	{
		float f[3][3] = { 0 };
		f[0][0] = i->a.x;
		f[0][1] = i->a.y;
		f[0][2] = i->a.z;
		f[1][0] = i->b.x;
		f[1][1] = i->b.y;
		f[1][2] = i->b.z;
		f[2][0] = i->c.x;
		f[2][1] = i->c.y;
		f[2][2] = i->c.z;

		float bc[3] = { 0 };
		bc[0] = _position.x;
		bc[1] = _position.y;
		bc[2] = _position.z;
		float bhs[3] = { 0 };
		bhs[0] = _size.x / 2.0f;
		bhs[1] = _size.y / 2.0f;
		bhs[2] = _size.z / 2.0f;

		if (triBoxOverlap(bc, bhs, f))
		{
			_collisions.push_back(*i);
		}
	}
}
bool ModelCollider::isColliding(CollisionTrig& _face,
	glm::vec3 _position, glm::vec3 _size)
{
	float f[3][3] = { 0 };
	f[0][0] = _face.a.x;
	f[0][1] = _face.a.y;
	f[0][2] = _face.a.z;
	f[1][0] = _face.b.x;
	f[1][1] = _face.b.y;
	f[1][2] = _face.b.z;
	f[2][0] = _face.c.x;
	f[2][1] = _face.c.y;
	f[2][2] = _face.c.z;

	float bc[3] = { 0 };
	bc[0] = _position.x;
	bc[1] = _position.y;
	bc[2] = _position.z;
	float bhs[3] = { 0 };
	bhs[0] = _size.x / 2.0f;
	bhs[1] = _size.y / 2.0f;
	bhs[2] = _size.z / 2.0f;

	if (triBoxOverlap(bc, bhs, f))
	{
		return true;
	}

	return false;
}

bool ModelCollider::isColliding(glm::vec3 _position,
	glm::vec3 _size)
{
	for (std::vector<CollisionTrig>::iterator i = collisions.begin();
		i != collisions.end(); i++)
	{
		float f[3][3] = { 0 };
		f[0][0] = i->a.x;
		f[0][1] = i->a.y;
		f[0][2] = i->a.z;
		f[1][0] = i->b.x;
		f[1][1] = i->b.y;
		f[1][2] = i->b.z;
		f[2][0] = i->c.x;
		f[2][1] = i->c.y;
		f[2][2] = i->c.z;

		float bc[3] = { 0 };
		bc[0] = _position.x;
		bc[1] = _position.y;
		bc[2] = _position.z;
		float bhs[3] = { 0 };
		bhs[0] = _size.x / 2.0f;
		bhs[1] = _size.y / 2.0f;
		bhs[2] = _size.z / 2.0f;

		if (triBoxOverlap(bc, bhs, f))
		{
			return true;
		}
	}

	return false;
}

void ModelCollider::getColliding(glm::vec3 _position,
	glm::vec3 _size)
{
	glm::vec3 _pos = _position - extent.min;
	size_t x = (size_t)(_pos.x / cols.at(0)->size.x);
	size_t y = (size_t)(_pos.z / cols.at(0)->size.z);
	size_t idx = y * resolution + x;

	if (idx >= cols.size()) return;
	//getColliding(position, size, allFaces);
    cols.at(idx)->getColliding(_position, _size, collisions);
    //getColliding(position, size, collisions);
	//collisions.at(idx);
	//std::cout << idx << std::endl;
}

glm::vec3 ModelCollider::faceNormal(CollisionTrig& _face)
{
	// Winding for CCW?
	//qsoft::Vector3 N = qsoft::Vector3::cross(
	//  qsoft::Vector3(face.b.position) - qsoft::Vector3(face.a.position),
	//  qsoft::Vector3(face.c.position) - qsoft::Vector3(face.a.position));

	glm::vec3 N = glm::cross(
		glm::vec3(_face.b) - glm::vec3(_face.c),
		glm::vec3(_face.a) - glm::vec3(_face.c));

	return N;
}

glm::vec3 ModelCollider::getCollisionResponse(
	glm::vec3 _position, glm::vec3 _size, bool& _solved)
{
	glm::vec3 _solve = _position;
	_solved = false;

	collisions.clear();
	getColliding(_solve, _size);

	if (!isColliding(_solve, _size))
	{
		_solved = true;
		return _solve;
	}

	// Favour Y faces first.
	for (std::vector<CollisionTrig>::iterator it = collisions.begin();
		it != collisions.end(); it++)
	{
		if (!isColliding(*it, _solve, _size))
		{
			continue;
		}

		glm::vec3 n = faceNormal(*it);
		//n = n.normalize();
		n = glm::normalize(n);
		//std::cout << n.x << " " << n.y << " " << n.z << std::endl;
		if (n.y < fabs(n.x) + fabs(n.z)) continue;

		float amount = tryStep;

		while (true)
		{
			_solve = _solve + n * amount;

			if (!isColliding(*it, _solve, _size))
			{
				break;
			}

			_solve = _solve - n * amount;
			amount += tryStep;

			if (amount > maxStep)
			{
				break;
			}
		}
	}

	if (!isColliding(_solve, _size))
	{
		_solved = true;
		return _solve;
	}

	float amount = tryInc;

	while (true)
	{
		glm::vec3 total;

		// Try to uncollide using face normals
		for (std::vector<CollisionTrig>::iterator it = collisions.begin();
			it != collisions.end(); it++)
		{
			glm::vec3 n = faceNormal(*it);
			//n = n.normalize();
			n = glm::normalize(n);
			total = total + n;
			_solve = _solve + n * amount;

			if (!isColliding(_solve, _size))
			{
				_solved = true;
				return _solve;
			}

			_solve = _solve - n * amount;
		}

		// Try to uncollide using averaged face normals
		//total = total.normalize();
		total = glm::normalize(total);
		_solve = _solve + total * amount;

		if (!isColliding(_solve, _size))
		{
			_solved = true;
			return _solve;
		}

		_solve = _solve - total * amount;
		amount += tryInc;

		if (amount > maxInc)
		{
			break;
		}
	}

	_solved = false;
	return _position;
}

void ModelCollider::generateExtent()
{
	std::vector<glm::vec3> _positions;
    //std::sr1::shared_ptr<MeshRender> mr = getEntity()->getComponent<MeshRender>();
    //std::sr1::shared_ptr<Mesh> model = mr->getMesh();

	//model->getFaces();
   //model->getFaces(m_allFaces);

    for (size_t f = 0; f < m_allFaces.size(); f++)
	{
        CollisionTrig face = m_allFaces.at(f);
		_positions.push_back(face.a);
		_positions.push_back(face.b);
		_positions.push_back(face.c);
	}

	extent.max = _positions.at(0);
	extent.min = _positions.at(0);

	for (size_t i = 1; i < _positions.size(); i++)
	{
		if (_positions.at(i).x > extent.max.x) extent.max.x = _positions.at(i).x;
		if (_positions.at(i).y > extent.max.y) extent.max.y = _positions.at(i).y;
		if (_positions.at(i).z > extent.max.z) extent.max.z = _positions.at(i).z;
		if (_positions.at(i).x < extent.min.x) extent.min.x = _positions.at(i).x;
		if (_positions.at(i).y < extent.min.y) extent.min.y = _positions.at(i).y;
		if (_positions.at(i).z < extent.min.z) extent.min.z = _positions.at(i).z;
	}

	extent.min = extent.min -= 1;
	extent.max = extent.max += 1;

	/*
	  std::cout << "World Bounds: " << path << std::endl;
	  std::cout << "Size: " << extent.max.x - extent.min.x;
	  std::cout << ", " << extent.max.y - extent.min.y;
	  std::cout << ", " << extent.max.z - extent.min.z << std::endl;
	  std::cout << "Min: " << extent.min.x;
	  std::cout << ", " << extent.min.y;
	  std::cout << ", " << extent.min.z << std::endl;
	  std::cout << "Max: " << extent.max.x;
	  std::cout << ", " << extent.max.y;
	  std::cout << ", " << extent.max.z << std::endl;
	*/

}

void ModelCollider::onInitalise()
{
    resolution = 10.0f;
	tryStep = 0.001f;
	maxStep = 1.0f;
	tryInc = 0.01f;
	maxInc = 0.5f;

    std::sr1::shared_ptr<MeshRender> _mr = getEntity()->getComponent<MeshRender>();
    std::sr1::shared_ptr<Mesh> _model = _mr->getMesh();
	
    _model->getFaces(m_allFaces);
	
    generateExtent();

	// Create collision columns
	glm::vec3 size = extent.max - extent.min;
    //TODO: The /= could be wrong
    glm::vec3 colSize = size /= resolution;
	colSize.y = size.y;

	for (size_t y = 0; y < resolution; y++)
	{
		glm::vec3 pos = extent.min + colSize / 2.0f;
		pos.z += (float)y * colSize.z;

		for (size_t x = 0; x < resolution; x++)
		{
			std::sr1::shared_ptr<ColliderColumn> cc = std::sr1::make_shared<ColliderColumn>();
			cc->size = colSize;

			// Overlap columns for sub column collision
			//cc->size.x += 1.0f;
			//cc->size.z += 1.0f;
			// Conflicts with x / y index generation when matching column to collide with.
			// Done when adding face instead.

			cc->position = pos;
			cols.push_back(cc);
			pos.x += colSize.x;
		}
	}

    for (size_t f = 0; f < m_allFaces.size(); f++)
	{
        CollisionTrig face = m_allFaces.at(f);
		
		addFace(face);
		//allFaces.push_back(face);
	}
}

Extent ModelCollider::getExtent()
{
	return extent;
}

void ModelCollider::addFace(CollisionTrig _face)
{
	float f[3][3] = { 0 };
	f[0][0] = _face.a.x;
	f[0][1] = _face.a.y;
	f[0][2] = _face.a.z;
	f[1][0] = _face.b.x;
	f[1][1] = _face.b.y;
	f[1][2] = _face.b.z;
	f[2][0] = _face.c.x;
	f[2][1] = _face.c.y;
	f[2][2] = _face.c.z;

	bool found = false;

	for (size_t i = 0; i < cols.size(); i++)
	{
		float bc[3] = { 0 };
		bc[0] = cols.at(i)->position.x;
		bc[1] = cols.at(i)->position.y;
		bc[2] = cols.at(i)->position.z;

		// Overlap columns for sub column collision
		glm::vec3 s = cols.at(i)->size;
		s.x += 1;
		s.z += 1;

		float bhs[3] = { 0 };
		bhs[0] = s.x / 2.0f;
		bhs[1] = s.y / 2.0f;
		bhs[2] = s.z / 2.0f;

		if (triBoxOverlap(bc, bhs, f))
		{
			cols.at(i)->faces.push_back(_face);
			//std::cout << "Pushing face into " << i << std::endl;
			found = true;
		}
	}

	if (!found)
	{
 		//throw Exception("Face not assigned spatial partition");
	}

	
	 // if(!found)
	 // {
		//std::cout << "Assertion failed: Face not in spacial partition" << std::endl;
		//std::cout << f[0][0] << ", " << f[0][1] << ", " << f[0][2] << std::endl;
		//std::cout << f[1][0] << ", " << f[1][1] << ", " << f[1][2] << std::endl;
		//std::cout << f[2][0] << ", " << f[2][1] << ", " << f[2][2] << std::endl;
		//std::cout << "Expect collision errors" << std::endl;

		////throw Exception("Face not assigned spatial partition");
		////abort();
	 // }
	
}
