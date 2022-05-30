#include <string>

class Pyramid {
private:
	//Flags
	bool pointsBuilded = false;
	bool linesBuilded = false;
	
	//Constructor defaults
	std::string name{ "my_pyramid" };
	int x{ 0 };
	int y{ 0 };
	int z{ 0 };
	int base{ 10 };
	int height{ 10 };

public:
	Pyramid(std::string _name, int _x, int _y, int _z, int _base, int _height)
		: name(_name), x(_x), y(_y), z(_z), base(_base), height(_height)
	{}
	
	void init();
	void buildPoints();
	void buildLines();
	void buildSurfaces();
	void build();

};

void gmshInit();


