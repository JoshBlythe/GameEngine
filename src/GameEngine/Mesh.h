/**
* Included Libraries.
*/
#include <vector>

/**
* Forward declaration Class's used within the Class
*/
class ModelCollider;
struct CollisionTrig;

/**
* Class includes.
*/
#include "Resource.h"
#include "RendInc.h"

/**
* Initalisation of the class.
*/
class Mesh : public Resource
{
public:
	Mesh();
	~Mesh();

	std::shared_ptr<rend::Mesh> _internal; /*!< Pointer to Rend Mesh. */

	//std::vector<CollisionTrig>& _out
	/**
	* This function gets all the Mesh Faces and pushes them back into the vector passed into the function.
	.
	*/
	void getFaces(std::vector<CollisionTrig>& _out);

	/**
	* This function Loads the Mesh (Model) from the path passed into it.
	* It gets the local path from the enviroment class. It also overwrites the Resource onLoad. 
	*/
	void onLoad(const std::string& _fileName);

	//std::vector<CollisionTrig> m_modelFaces;
};
