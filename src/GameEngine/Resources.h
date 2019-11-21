#include <memory>
#include <list>
#include <string>

class Resource;

class Resources
{
public:
	Resources() {};
	~Resources() {};

	template<typename T>
	std::shared_ptr<T> loadResource(std::string _path)
	{
		std::shared_ptr<T> t_rtn = std::make_shared<T>();

		for (auto it = _resources.begin(); it != _resources.end(); it++)
		{
			t_rtn = std::dynamic_pointer_cast<T>(*it);
			if (t_rtn)
			{
				return t_rtn;
			}
		}

		throw Exception("Specified Type was not found");
	}

	template<typename T>
	std::shared_ptr<T> createResource()
	{
		std::shared_ptr<T> t_rtn = std::make_shared<T>();

		_resources.push_back(t_rtn);

		return t_rtn;

	}


private:
	std::list<std::shared_ptr<Resource>> _resources;

};
