#include <gmsh.h>
#include <string>

namespace factory = gmsh::model::geo;

void Init() {
	gmsh::initialize();
}

void CreatePyramid(std::string name, int x, int y, int z, int height, int width) {
	//Adding a model
	gmsh::model::add(name);
	
	//Verticies
	int left_up_base_vertex = factory::addPoint(x, y, z);
	int right_up_base_vertex = factory::addPoint(x + width, y, z);
	int right_down_base_vertex = factory::addPoint(x + width, y + width, z);
	int left_down_base_vertex = factory::addPoint(x, y + width, z);
	int up_vertex = factory::addPoint(x / 2, y / 2, z + height);
	
	//Lines
	//Base lines
	int up_base_line = factory::addLine(left_up_base_vertex, right_up_base_vertex);
	int right_base_line = factory::addLine(right_up_base_vertex, right_down_base_vertex);
	int down_base_line = factory::addLine(right_down_base_vertex, left_down_base_vertex);
	int left_base_line = factory::addLine(left_down_base_vertex, left_up_base_vertex);
	//Border lines
	int left_up_corner_line = factory::addLine(left_up_base_vertex, up_vertex);
	int right_up_corner_line = factory::addLine(right_up_base_vertex, up_vertex);
	int right_down_corner_line = factory::addLine(right_down_base_vertex, up_vertex);
	int left_down_corner_line = factory::addLine(left_down_base_vertex, up_vertex);
	
	//Surfaces
	//Curve loops
	int base_curve_loop = factory::addCurveLoop({up_base_line, right_base_line, down_base_line, left_base_line});
	int up_border_loop = factory::addCurveLoop({up_base_line, right_up_corner_line, -left_up_corner_line});
	int right_border_loop = factory::addCurveLoop({right_base_line, right_down_corner_line, -right_up_corner_line});
	int down_border_loop = factory::addCurveLoop({down_base_line, left_down_corner_line, -right_down_corner_line});
	int left_border_loop = factory::addCurveLoop({left_base_line, left_down_corner_line, -left_up_corner_line});
	//Surfaces from loops
	int base_surface = factory::addPlaneSurface({base_curve_loop});
	int up_border_surface = factory::addPlaneSurface({up_border_loop});
	int right_border_surface = factory::addPlaneSurface({right_border_loop});
	int down_border_surface = factory::addPlaneSurface({down_border_loop});
	int left_border_surface = factory::addPlaneSurface({left_border_loop});
	
}

