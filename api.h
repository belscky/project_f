#include <string>

class Pyramid {
public:
	Pyramid(string _name, int _x, int _y, int _z, int _base, int _height)
		: name(_name) x(_x), y(_y), z(_z), base(_base), height(_height)
	{}
	
	void init();
	void buildPoints();
	void buildLines();
	void buildSurfaces();
	void build();

	//TODO:
	//animation and volume
	void animate();
	double volume();

private:
	//Flags
	bool pointsBuilded = false;
	bool linesBuilded = false;
	
	//Constructor defaults
	string name{ "my_pyramid" }
	int x{ 0 };
	int y{ 0 };
	int z{ 0 };
	int base{ 10 };
	int height{ 10 };
};

void gmshInit();


