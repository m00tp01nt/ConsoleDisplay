/*
 * Main.cpp
 *
 *  Created on: May 13, 2024
 *      Author: eslia
 */

#include <iostream>
#include <unistd.h>
#include <stdlib.h>

#include <math.h>

#define PI 3.141592653

#include "Classes/ConsoleDisplay/ConsoleDisplay.h"
#include "Classes/Point/Point.h"
#include "Classes/Shape/Shape.h"

#include "Functions/ConsoleDisplayPoint/ConsoleDisplayPoint.h"
#include "Functions/ConsoleDisplay/ConsoleDisplay.h"
#include "Functions/ConsoleDisplayShape/ConsoleDisplayShape.h"

#include "Physics/Gravity/Gravity.h"
#include "Physics/Kinematics/Kinematics.h"
#include "Physics/Vector/Velocity/Velocity.h"
#include "Physics/Vector/Force/Force.h"

#include "Physics/Body/Body.h"


int main(void) {
	ConsoleDisplay output = ConsoleDisplay(100, 50, '.');

	/*
	Point pt1 = Point(25, 47, 0, '1');
	Point pt2 = Point(75, 47, 0, '2');
	Point pt3 = Point(75, 22, 0, '3');
	Point pt4 = Point(25, 22, 0, '4');

	Point pt5 = Point(25, 47, 50, '5');
	Point pt6 = Point(75, 47, 50, '6');
	Point pt7 = Point(75, 22, 50, '7');
	Point pt8 = Point(25, 22, 50, '8');

	Point center = Point(50, 35, 25, 'C');
	*/

	double theta = PI / 30;


	// DRAW A STRETCHING TRIANGLE
	/*
	for (int x = 10; x < 50; x++) {
		for (int y = 10; y < 50; y++) {
			pt1.setX(x);
			pt1.setY(y);
			drawTriangle(output, pt1, pt2, pt3);
			print(output);
			output.reset();
			usleep(500000);
		}
	}
	*/

	// ROTATE A TRIANGLE ABOUT A POINT
	/*
	while (true) {
		output.reset();
		pt1.rotateZ(center, theta);
		pt2.rotateZ(center, theta);
		pt3.rotateZ(center, theta);
		drawTriangle(output, pt1, pt2, pt3);
		print(output);
		usleep(100000);
	}
	*/

	// ROATATE A RECTANGLE ABOUT A POINT
	/*
	while (true) {
		output.reset();
		pt1.rotateZ(center, theta);
		pt2.rotateZ(center, theta);
		pt3.rotateZ(center, theta);
		pt4.rotateZ(center, theta);
		drawRectangle(output, pt1, pt2, pt3, pt4);
		print(output);
		usleep(100000);
	}
	*/

	// ROTATE A TRIANGLE IN 3D
	/*
	while (true) {
		for (int i = 0; i < 10; i++) {
			output.reset();
			pt1.rotateX(center, theta);
			pt2.rotateX(center, theta);
			pt3.rotateX(center, theta);
			drawTriangle(output, pt1, pt2, pt3);
			print(output);
			usleep(100000);
		}

		for (int i = 0; i < 10; i++) {
			output.reset();
			pt1.rotateY(center, theta);
			pt2.rotateY(center, theta);
			pt3.rotateY(center, theta);
			drawTriangle(output, pt1, pt2, pt3);
			print(output);
			usleep(100000);
		}

		for (int i = 0; i < 10; i++) {
			output.reset();
			pt1.rotateZ(center, theta);
			pt2.rotateZ(center, theta);
			pt3.rotateZ(center, theta);
			drawTriangle(output, pt1, pt2, pt3);
			print(output);
			usleep(100000);
		}
	}
	*/

	// ROTATE A CUBE IN 3D
	/*
	while (true) {
		for (int i = 0; i < 10; i++) {
			output.reset();
			pt1.rotateX(center, .5 * theta);
			pt2.rotateX(center, .5 * theta);
			pt3.rotateX(center, .5 * theta);
			pt4.rotateX(center, .5 * theta);
			pt5.rotateX(center, .5 * theta);
			pt6.rotateX(center, .5 * theta);
			pt7.rotateX(center, .5 * theta);
			pt8.rotateX(center, .5 * theta);
			drawPrism(output, pt1, pt2, pt3, pt4, pt5, pt6, pt7, pt8);
			print(output);
			usleep(100000);
		}

		for (int i = 0; i < 10; i++) {
			output.reset();
			pt1.rotateY(center, 2 * theta);
			pt2.rotateY(center, 2 * theta);
			pt3.rotateY(center, 2 * theta);
			pt4.rotateY(center, 2 * theta);
			pt5.rotateY(center, 2 * theta);
			pt6.rotateY(center, 2 * theta);
			pt7.rotateY(center, 2 * theta);
			pt8.rotateY(center, 2 * theta);
			drawPrism(output, pt1, pt2, pt3, pt4, pt5, pt6, pt7, pt8);
			print(output);
			usleep(100000);
		}
		for (int i = 0; i < 10; i++) {
			output.reset();
			pt1.rotateZ(center, theta);
			pt2.rotateZ(center, theta);
			pt3.rotateZ(center, theta);
			pt4.rotateZ(center, theta);
			pt5.rotateZ(center, theta);
			pt6.rotateZ(center, theta);
			pt7.rotateZ(center, theta);
			pt8.rotateZ(center, theta);
			drawPrism(output, pt1, pt2, pt3, pt4, pt5, pt6, pt7, pt8);
			print(output);
			usleep(100000);
		}
	}
	*/

	// DRAW COLLECTIONS OF POINTS USING Shape CLASS
	// CONNECT SHAPES TOGETHER (.stick, .glue)
	// DRAW A SPHERE
	// DRAW A TORUS
	/*
	//Shape square("ngon", 50, Point(50, 25), 5);
	//Shape cube("cube", 25, Point(25, 50));
	Shape pyramid("squarepyramid", 35, Point(100, 50));
	Shape npyramid("npyramid", 25, Point(150, 10), 25);
	Shape npyramid2("npyramid", 25, Point(175, 10), 25);
	//Shape ngon("ngon", 35, Point(250, 25), 9);

	Shape sphere("sphere", 35, Point(250, 50), 15);

	Shape ncylinder("ncylinder", 20, Point(100, 20), 5);

	Shape torus("torus", 1, Point(65, 60), 7, 10, 15);
	//torus.rotateX(PI / 2);

	npyramid.setCenter(npyramid.getVertex(npyramid.getPoints() - 1));
	npyramid2.rotateZ(PI);
	npyramid2.setCenter(npyramid.getCenter());
	npyramid2.moveTo(npyramid2.getVertex(npyramid2.getPoints() - 1), npyramid.getVertex(npyramid.getPoints() - 1));
	npyramid.glue(&npyramid2);
	//npyramid.moveTo(npyramid.getCenter(), Point(300, 50, 0));
	//npyramid.setCenter(Point(350, 50, 0));

	//double scaleFactor =  2;

	while (true) {
		output.reset();

		//square.rotate(theta / 4, theta / 5, theta / 6);

		//cube.rotate(theta / 4, theta / 5, theta / 6);

		//pyramid.rotate(theta / 4, theta / 5, theta / 6);

		npyramid.rotate(theta / 4, theta / 5, theta / 6);

		sphere.rotate(theta / 4, theta / 5, theta / 6);

		torus.rotate(theta / 4, theta / 5, theta / 6);

		ncylinder.rotate(theta / 4, theta / 5, theta / 6);

		//npyramid.rescale(scaleFactor);
		//cube.rescale(scaleFactor);

		//scaleFactor = 1 / scaleFactor;

		//ngon.rotate(theta / 4, theta / 5, theta / 6);

		drawShape(output, torus);
		//drawShape(output, square);
		//drawShape(output, cube);
		//drawShape(output, pyramid);
		drawShape(output, npyramid);
		drawShape(output, npyramid2);
		//drawShape(output, ngon);
		drawShape(output, sphere);
		drawShape(output, ncylinder);
		drawPoint(output, sphere.getCenter(), 'C');

		print(output);

		usleep(200000);
	}
	*/

	output.setDefaultOff(' ');

	std::vector<Body*> list = std::vector<Body*>();

	Body object = Body(Point(40, 35), Velocity(0, 0, 0));
	object.mass = 100000000000000;
	object.p.color = 'w';

	Body object2 = Body(Point(40, 15), Velocity(0, 0, 0));
	object2.mass = 100000000000000;
	object2.p.color = 'x';

	Body planet = Body(Point(50, 25), Velocity(0, -15));
	planet.mass = 100000000000000;
	planet.p.color = 'y';

	Body planet2 = Body(Point(30, 25), Velocity(0, 15));
	planet2.mass = 100000000000000;
	planet2.p.color = 'z';

	list.push_back(&object);
	list.push_back(&object2);
	list.push_back(&planet);
	list.push_back(&planet2);

	while (true) {
		//output.reset();

		drawPoint(output, planet.p);

		for (int i = 0; i < 10000; i++) {

			for (Body* i : list) {
				for (Body* j : list) {
					if (i == j) {
						continue;
					}
					else {
						i->addForce(Gravity::forceOfGravity(*i, *j));
					}
				}
			}
			for (Body* i : list) {
				i->update();
				output.updatePixel(i->p.getX(), i->p.getY(), '.');
			}

		}

		for (Body* i : list) {
			drawPoint(output, i->p);
		}

		print(output);

		std::cout << " w velocity - " << object.v.length() << std::endl;

		usleep(16667);
	}

	return 0;
}
