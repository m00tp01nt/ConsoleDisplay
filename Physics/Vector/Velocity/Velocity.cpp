/*
 * Velocity.cpp
 *
 *  Created on: Jan 7, 2025
 *      Author: eslia
 */

#include "../Vector.h"

class Velocity : public Vector {
public:

	Velocity() : Vector() {};

	Velocity(int x, int y) : Vector(x, y) {};
	Velocity(double x, double y) : Vector(x, y) {};

	Velocity(int x, int y, int z) : Vector(x, y, z) {};
	Velocity(double x, double y, double z) : Vector(x, y, z) {};

	Velocity(Vector v) : Vector(v.x, v.y, v.z) {};
};
