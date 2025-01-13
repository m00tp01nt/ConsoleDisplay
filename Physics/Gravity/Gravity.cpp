/*
 * Gravity.cpp
 *
 *  Created on: Jan 7, 2025
 *      Author: eslia
 */

#include <cmath>

#include "../Body/Body.h"

#include "../Vector/Force/Force.h"
#include "../Tolerance/Tolerance.h"

class Gravity {

public:

	static double constexpr gravitationalConstant = (6.6743 * pow(10, -11));

	/**
	 * Calculates the Force of Gravity acting on point1
	 */
	static Force forceOfGravity(Body point1, Body point2) {
		Force answer;

		Vector v1 = Vector(point1.p.x, point1.p.y, point1.p.z);
		Vector v2 = Vector(point2.p.x, point2.p.y, point2.p.z);

		double radiusLength = (v1 - v2).length();

		double force = forceOfGravity(radiusLength, point1.mass, point2.mass);

		answer = (v1 - v2) * (1 / radiusLength);

		answer *= -force;

		return answer;
	}

	static double forceOfGravity(double radius, double mass1, double mass2) {
		double answer;

		if (radius < DOUBLE_TOLERANCE) {
			std::cout << "TOLERANCE KICKED IN" << std::endl;
			answer = 0;
		}
		else {
			answer = (Gravity::gravitationalConstant * ((mass1 * mass2) / pow(radius, 2)));
		}

		// Since it is calculated RELATIVE to point1 and therefore pos1,
		// we need to make sure the force is facing the right way.

		return answer;
	}

};
