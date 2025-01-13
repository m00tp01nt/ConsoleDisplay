/*
 * Shape.cpp
 *
 * Manages a collection of points as a Shape
 *
 *  Created on: Jul 10, 2024
 *      Author: eslia
 *
 *
 *     i should really start commenting what my stuff does
 */

#include <string>
#include <math.h>

#include <iostream>

#include <vector>

#include "../Point/Point.h"

class Shape : public Point {
private:
	Point* pointArr;
	Point center;
	int points;
	double scale;
	std::string description;
	std::vector<Shape*> ties;
	double pi = 3.14159265;
	bool isGlued;
	int iterations;

public:
	/**
	 * Constructs the object. Various inputs control different things.
	 * Constructor parameters needed are:
	 * 		shape
	 */
	Shape(std::string shape, double _scale=1, Point _center=Point(0.0, 0.0, 0.0), int _iterations=3, double arg1=0, double arg2=0)
	: Point(center.getX(), center.getY(), center.getZ(), center.getColor()) {
		description = shape;
		scale = _scale;
		isGlued = false;
		iterations = _iterations;

		/**
		 * Creates a cube.
		 * Constructor parameters needed:
		 * 		_scale
		 * 			The side length of the cube
		 */
		if (description.compare("cube") == 0) {
			points = 8;
			pointArr = new Point[points];

			pointArr[0] = Point(0, 0, 0);
			pointArr[1] = Point(scale, 0, 0);
			pointArr[2] = Point(scale, scale, 0);
			pointArr[3] = Point(0, scale, 0);
			pointArr[4] = Point(0, 0, scale);
			pointArr[5] = Point(scale, 0, scale);
			pointArr[6] = Point(scale, scale, scale);
			pointArr[7] = Point(0, scale, scale);
		}
		/**
		 * Creates a square.
		 * Constructor parameters needed:
		 * 		_scale
		 * 			The side length of the square
		 */
		else if (description.compare("square") == 0) {
			points = 4;
			pointArr = new Point[points];

			pointArr[0] = Point(0, 0, 0);
			pointArr[1] = Point(scale, 0, 0);
			pointArr[2] = Point(scale, scale, 0);
			pointArr[3] = Point(0, scale, 0);
		}
		/**
		 * Creates a pyramid with a square base
		 * Constructor parameters needed:
		 * 		_scale
		 * 			The height and side length of the pyramid
		 */
		else if (description.compare("squarepyramid") == 0) {
			points = 5;
			pointArr = new Point[points];

			pointArr[0] = Point(0, 0, 0);
			pointArr[1] = Point(scale, 0, 0);
			pointArr[2] = Point(scale, 0, scale);
			pointArr[3] = Point(0, 0, scale);
			pointArr[4] = Point(.5 * scale, scale, .5 * scale);
		}
		/**
		 * Creates a pyramid with a base that has n number of sides
		 * Constructor parameters needed:
		 * 		_scale
		 * 			The distance from the center of the base to any of the points
		 */
		else if (description.compare("npyramid") == 0) {
			points = iterations + 1;
			pointArr = new Point[points];
			for (int i = 0; i < iterations; i++) {
		        pointArr[i] = Point((scale * cos((2 * pi * i) / iterations)) + scale, 0, (scale * sin((2 * pi * i) / iterations)) + scale);
			}
			pointArr[iterations] = Point(scale, (2 * scale), scale);
		}
		/**
		 * Creates an ngon
		 * Constructor parameters needed:
		 * 		_scale
		 * 			The distance from the cener to any of the points
		 */
		else if (description.compare("ngon") == 0) {
			points = iterations;
			pointArr = new Point[points];
			for (int i = 0; i < iterations; i++) {
		        pointArr[i] = Point((scale * cos((2 * pi * i) / iterations)) + scale, (scale * sin((2 * pi * i) / iterations)) + scale, 0);
			}
		}
		/**
		 * Creates a globe by gluing
		 * Constructor parameters needed:
		 * 		_scale
		 * 			The radius of the globe
		 * 			The number of sides on the ngon used in construction
		 */
		else if (description.compare("sphere") == 0) {
			points = 1;
			pointArr = new Point[points];

			pointArr[0] = Point(0, 0, 0);

			for (int i = 0; i < iterations; i++) {
				Shape* buffer = new Shape("ngon", scale, Point(0, 0, 0), iterations);
				buffer->rotateY((pi * i) / iterations);
				glue(buffer);
			}
			Shape* buffer = new Shape("ngon", scale, Point(0, 0, 0), iterations);
			buffer->rotateY(pi);
			glue(buffer);

			double xBuf = 0, yBuf = 0, zBuf = 0;
			int points = 0;
			for (int i = 0; i < (int)ties.size(); i++) {
				for (int j = 0; j < ties.at(i)->getPoints(); j++) {
					xBuf += ties.at(i)->getVertex(j).getX();
					yBuf += ties.at(i)->getVertex(j).getY();
					zBuf += ties.at(i)->getVertex(j).getZ();
					points++;
				}
			}

			center = Point(xBuf / points, yBuf / points, zBuf / points);
			moveTo(_center);
			setCenter(_center);
			return;
		}
		else if (description.compare("ncylinder") == 0) {
			Shape* top = new Shape("ngon", scale, Point(0, 0, 0), iterations);
			top->rotateX(pi / 2);
			Shape* bottom = new Shape("ngon", scale, Point(0, 0, 0), iterations);
			bottom->rotateX(pi / 2);
			top->translateY(scale);
			glue(top);
			glue(bottom);
			points = 0;

			double xBuf = 0, yBuf = 0, zBuf = 0;
			int points = 0;
			for (int i = 0; i < (int)ties.size(); i++) {
				for (int j = 0; j < ties.at(i)->getPoints(); j++) {
					xBuf += ties.at(i)->getVertex(j).getX();
					yBuf += ties.at(i)->getVertex(j).getY();
					zBuf += ties.at(i)->getVertex(j).getZ();
					points++;
				}
			}

			center = Point(xBuf / points, yBuf / points, zBuf / points);
			moveTo(_center);
			setCenter(_center);
			return;
		}
		else if (description.compare("torus") == 0) {
			points = 0;

			for (int i = 0; i < iterations; i++) {
				Shape* buffer = new Shape("ngon", arg2, Point(arg1 + (arg2 / 2), 0, 0), iterations);
				buffer->setCenter(Point(0, 0, 0));
				buffer->rotateY((2 * pi * i) / iterations);
				glue(buffer);
			}
			Shape* buffer = new Shape("ngon", arg2, Point(arg1 + (arg2 / 2), 0, 0), iterations);
			buffer->setCenter(Point(0, 0, 0));
			buffer->rotateY(2 * pi);
			glue(buffer);

			double xBuf = 0, yBuf = 0, zBuf = 0;
			int points = 0;
			for (int i = 0; i < (int)ties.size(); i++) {
				for (int j = 0; j < ties.at(i)->getPoints(); j++) {
					xBuf += ties.at(i)->getVertex(j).getX();
					yBuf += ties.at(i)->getVertex(j).getY();
					zBuf += ties.at(i)->getVertex(j).getZ();
					points++;
				}
			}

			center = Point(xBuf / points, yBuf / points, zBuf / points);
			moveTo(_center);
			setCenter(_center);


			return;
		}

		// Move the shape to the given center
		for (int i = 0; i < points; i++) {
			pointArr[i].setX(pointArr[i].getX() + _center.getX());
			pointArr[i].setY(pointArr[i].getY() + _center.getY());
			pointArr[i].setZ(pointArr[i].getZ() + _center.getZ());
			pointArr[i].setColor(_center.getColor());
		}
		// Calculate Center Point
		double xBuf = 0, yBuf = 0, zBuf = 0;
		for (int i = 0; i < points; i++) {
			xBuf += pointArr[i].getX();
			yBuf += pointArr[i].getY();
			zBuf += pointArr[i].getZ();
		}

		setX(xBuf / points);
		setY(yBuf / points);
		setZ(zBuf / points);

		center = Point(xBuf / points, yBuf / points, zBuf / points, 'C');
	}

	// Getters
	int getPoints() {
		return points;
	}

	int getIterations() {
		return iterations;
	}

	Point getVertex(int i) {
		return pointArr[i];
	}

	Shape* getAttatchedShape(int i) {
		return ties.at(i);
	}
	int shapesAttatched() {
		return ties.size();
	}

	Point getCenter() {
		return center;
	}

	double getScale() {
		return scale;
	}

	std::string getDescription() {
		return description;
	}

	// Setters
	void setCenter(Point _center) {
		center = _center;

		for (int i = 0; i < (int)ties.size(); i++)
			ties.at(i)->setCenter(_center);
	}

	void setCenter(Point* _center) {
		center.setX(_center->getX());
		center.setY(_center->getY());
		center.setZ(_center->getZ());
		for (int i = 0; i < (int)ties.size(); i++)
			ties.at(i)->setCenter(_center);
	}

	// Methods
	// ROTATE
	void rotateX(Point center, double theta) {
		for (int i = 0; i < points; i++)
			pointArr[i].rotateX(center, theta);

		for (int i = 0; i < (int)ties.size(); i++)
			ties.at(i)->rotateX(center, theta);
	}
	void rotateY(Point center, double theta) {
		for (int i = 0; i < points; i++)
			pointArr[i].rotateY(center, theta);

		for (int i = 0; i < (int)ties.size(); i++)
			ties.at(i)->rotateY(center, theta);
	}
	void rotateZ(Point center, double theta) {
		for (int i = 0; i < points; i++)
			pointArr[i].rotateZ(center, theta);

		for (int i = 0; i < (int)ties.size(); i++)
			ties.at(i)->rotateZ(center, theta);
	}

	void rotateX(double theta) {
		rotateX(center, theta);
	}
	void rotateY(double theta) {
		rotateY(center, theta);
	}
	void rotateZ(double theta) {
		rotateZ(center, theta);
	}
	void rotate(double x, double y, double z) {
		rotateX(x);
		rotateY(y);
		rotateZ(z);
	}

	// TRANSLATE
	void translateX(double delta, bool cont=true) {
		for (int i = 0; i < points; i++) {
			pointArr[i].setX(pointArr[i].getX() + delta);
		}
		for (int i = 0; i < (int)ties.size(); i++) {
			ties.at(i)->setX(ties.at(i)->getX() + delta);
		}
	}
	void translateY(double delta) {
		for (int i = 0; i < points; i++)
			pointArr[i].setY(pointArr[i].getY() + delta);

		for (int i = 0; i < (int)ties.size(); i++)
			ties.at(i)->setY(ties.at(i)->getY() + delta);
	}
	void translateZ(double delta) {
		for (int i = 0; i < points; i++)
			pointArr[i].setZ(pointArr[i].getZ() + delta);

		for (int i = 0; i < (int)ties.size(); i++)
			ties.at(i)->setZ(ties.at(i)->getZ() + delta);
	}
	void translate(double dX, double dY, double dZ) {
		translateX(dX);
		translateY(dY);
		translateZ(dZ);
	}
	void translate(double dX, double dY) {
		translateX(dX);
		translateY(dY);
	}
	void moveTo(Point vertex, Point point, bool cont=true) {
		translateX(point.getX() - vertex.getX());
		translateY(point.getY() - vertex.getY());
		translateZ(point.getZ() - vertex.getZ());
		if (cont) {
			for (int i = 0; i < (int)ties.size(); i++) {
				ties.at(i)->moveTo(vertex, point, false);
			}
		}
	}
	void moveTo(Point point) {
		moveTo(center, point);
	}
	void glue(Shape* shape) {
		ties.push_back(shape);
		shape->setCenter(getCenter());
		isGlued = true;
	}

	// SCALE
	void rescale(double factor, bool cont=true) {
		for (int i = 0; i < points; i++) {
			pointArr[i].setX(((pointArr[i].getX() - center.getX()) * factor) + center.getX());
			pointArr[i].setY(((pointArr[i].getY() - center.getY()) * factor) + center.getY());
			pointArr[i].setZ(((pointArr[i].getZ() - center.getZ()) * factor) + center.getZ());
		}
		if (cont)
			for (int i = 0; i < (int)ties.size(); i++)
				ties.at(i)->rescale(factor);
	}

};
