/*
 * Force.cpp
 *
 *  Created on: Jan 11, 2025
 *      Author: eslia
 */

#include "../Vector.h"

class Force : public Vector {

public:

	Force() : Vector() {};

	Force(int x, int y) : Vector(x, y) {};
	Force(double x, double y) : Vector(x, y) {};

	Force(int x, int y, int z) : Vector(x, y, z) {};
	Force(double x, double y, double z) : Vector(x, y, z) {};

	Force(Vector v) : Vector(v.x, v.y, v.z) {};

};
