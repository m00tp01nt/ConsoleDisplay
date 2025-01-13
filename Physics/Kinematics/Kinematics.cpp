/*
 * Kinematics.cpp
 *
 *  Created on: Jan 8, 2025
 *      Author: eslia
 */

#include <cmath>

#include "../../Classes/Point/Point.h"
#include "../Vector/Velocity/Velocity.h"
#include "../Vector/Acceleration/Acceleration.h"


class Kinematics {
public:

	static double constexpr deltaT = .00000166;

	static Velocity finalVelocity(Acceleration a, Velocity initialVelocity) {
		Velocity v;

		double x = finalVelocity(a.x, initialVelocity.x);
		double y = finalVelocity(a.y, initialVelocity.y);
		double z = finalVelocity(a.z, initialVelocity.z);

		v = Velocity(x, y, z);

		return v;
	}


	static Point changeInPosition(Acceleration a, Velocity v, Point initialPosition) {
		Point position;

		double x = finalPosition(a.x, v.x, initialPosition.x);
		double y = finalPosition(a.y, v.y, initialPosition.y);
		double z = finalPosition(a.z, v.z, initialPosition.z);

		position = Point(x, y, z);

		return position;
	}

	static Velocity changeInVelocity(Acceleration a, Velocity initialVelocity, Vector distanceTraveled) {
		Velocity v;

		double x = finalVelocity(a.x, initialVelocity.x, distanceTraveled.x);
		double y = finalVelocity(a.y, initialVelocity.y, distanceTraveled.y);
		double z = finalVelocity(a.z, initialVelocity.z, distanceTraveled.z);

		v = Velocity(x, y, z);

		return v;
	}

	static Acceleration newtonsSecond(Vector force, Point mass) {
		Acceleration a;

		if (mass.mass <= 0) {
			a = Acceleration(-1, -1, -1);
		}
		else {
			a = Acceleration(force * (1 / mass.mass));
		}

		return a;
	}


private:
	static double finalVelocity(double a, double initialVelocity) {
		double answer;

		answer = (a * deltaT) + initialVelocity;

		return answer;
	}

	static double finalPosition(double acceleration, double velocity, double initialPosition) {
		double answer;

		answer = ((velocity * deltaT) + (0.5 * acceleration * deltaT * deltaT));

		return answer;
	}

	static double finalVelocity(double acceleration, double initialVelocity, double distance) {
		double answer;

		answer = pow(((initialVelocity * initialVelocity) + (2 * acceleration * distance)), 0.5);

		return answer;
	}
};
