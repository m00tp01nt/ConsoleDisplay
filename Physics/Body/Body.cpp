/*
 * Body.cpp
 *
 *  Created on: Jan 8, 2025
 *      Author: eslia
 */

#include "../../Classes/Point/Point.h"

#include "../Vector/Vector.h"
#include "../Vector/Velocity/Velocity.h"
#include "../Vector/Acceleration/Acceleration.h"
#include "../Vector/Force/Force.h"

#include "../Kinematics/Kinematics.h"

class Body {
public:

	Point p;
	Velocity v;
	Acceleration a;

	Force totalForce = Force();

	double mass = 1;

	Body() {
		p = Point();
		v = Velocity();
		a = Acceleration();
	}
	Body(Point _p) {
		p = Point(_p.x, _p.y, _p.z);
		v = Velocity();
		a = Acceleration();
	}
	Body (Point _p, Velocity _v) {
		p = Point(_p.x, _p.y, _p.z);
		v = Velocity(_v.x, _v.y, _v.z);
	}
	Body (Point _p, Velocity _v, Acceleration _a) {
		p = Point(_p.x, _p.y, _p.z);
		v = Velocity(_v.x, _v.y, _v.z);
		a = Acceleration(_a.x, _a.y, _a.z);
	}

	void update() {

		a = (totalForce * (1 / mass));

		Point change = Kinematics::changeInPosition(a, v, p);
		Vector changeIn = Vector(change.x, change.y, change.z);
		p.addVector(changeIn);

		v = Kinematics::finalVelocity(a, v);

		totalForce.reset();
	}

	void addForce(Force f) {
		totalForce += f;
	}

};

