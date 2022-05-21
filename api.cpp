#include "api.h"
#include <gmsh>
#include <string>
#include <vector>
#include <iostream>

namespace factory = gmsh::model::geo;

void gmshInit() {
	gmsh::initialize();
}

void Pyramid::init() {
	gmsh::model::add(this->name);
}

void Pyramid::buildPoints() {
	//Left up point
	factory::addPoint(x, y, z);
	//Right up point
	factory::addPoint(x + this->base, y, z);
	//Right down point
	factory::addPoint(x + this->base, y + this->base, z);
	//Left down point
	factory::addPoint(x, y + this->base, z);
	//Up point
	factory::addPoint(x + (this->base / 2), y + (this->base / 2), z + this->height);
	
	//Set flag
	this->pointsBuilded = true;
}

void Pyramid::buildLines() {
	if (this->pointsBuilded) {
		//Up base line
		factory::addLine(1, 2);
		//Right base line
		factory::addLine(2, 3);
		//Down base line
		factory::addLine(3, 4);
		//Left base line
		factory::addLine(4, 1);
		//Left up border line
		factory::addLine(1, 5);
		//Right up border line
		factory::addLine(2, 5);
		//Right down border line
		factory::addLine(3, 5);
		//Left down border line
		factory::addLine(4, 5);

		//Set flag
		this->linesBuilded = true;
	}
	else {
		std::cout << "Points should be builded before lines." << std::endl;
	}
}

void Pyramid::buildSurfaces() {
	if (this->linesBuilded) {
		//Base surface
		factory::addCurveLoop({1, 2, 3, 4});
		factory::addSurface({1});
		//Up border surface
		factory::addCurveLoop({1, 6, -5});
		factory::addSurface({2});
		//Right border surface
		factory::addCurveLoop({2, 7, -6});
		factory::addSurface({3});
		//Down border surface
		factory::addCurveLoop({3, 8, -7});
		factory::addSurface({4});
		//Left border surface
		factory::addCurveLoop({4, 8, -7});
		factory::addSurface({5});
	}
	else {
		std::cout << "Lines should be builded before surfaces." << std::endl;
	}
}

void Pyramid::build() {
	this->buildPoints();
	this->buildLines();
	this->buildSurfaces();
}
