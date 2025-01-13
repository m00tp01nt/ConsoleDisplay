/*
 * Acceleration.cpp
 *
 *  Created on: Jan 7, 2025
 *      Author: eslia
 */

#include "../Vector.h"

class Acceleration : public Vector {
public:

	Acceleration() : Vector() {};

	Acceleration(int x, int y) : Vector(x, y) {};
	Acceleration(double x, double y) : Vector(x, y) {};

	Acceleration(int x, int y, int z) : Vector(x, y, z) {};
	Acceleration(double x, double y, double z) : Vector(x, y, z) {};

	Acceleration(Vector v) : Vector(v.x, v.y, v.z) {};

};
