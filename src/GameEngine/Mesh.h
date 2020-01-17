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
	/**
	* This class inherits from Resources, it is used to load a 3D Model.
	* it also has a context to rend Mesh to allow the mesh data loaded to be processed and then later drawn.
	*/
	Mesh();
	virtual ~Mesh();

	/**
	* This function gets all the Mesh Faces and pushes them back into the vector passed into the function.
	@param _out is a vector that will be passed into the funciton its purpose is to store the faces of the current model into that vector.
	*/
	void getFaces(std::vector<CollisionTrig>& _out);

	/**
	* This function Loads the Mesh (Model) from the path passed into it.
	* It gets the local path from the enviroment class. It also overwrites the Resource onLoad. 
	@param _fileName takes in a string, this will be the file name and the folder it is inside of.
	*/
	void onLoad(const std::string& _fileName);

	std::shared_ptr<rend::Mesh> _internal; /*!< Pointer to Rend Mesh. */
};
