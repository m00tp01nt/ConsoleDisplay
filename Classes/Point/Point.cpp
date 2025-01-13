/*
 * Point.cpp
 *
 *  Created on: Jul 9, 2024
 *      Author: eslia
 */


#include <cmath> // sin(), cos()

#include "../../Physics/Vector/Vector.h"

/**
 * Encapsulates a point in 3D space.
 */
class Point {
public:
	/**
	 * The X coordinate of the point
	 */
	double x;
	/**
	 * The Y coordinate of the point
	 */
	double y;
	/**
	 * The Z coordinate of the point
	 */
	double z;
	/**
	 * What character should represent the poinnt
	 */
	char color;

	double mass = (double)1;

	/**
	 * Constructors
	 */
	Point() : x(0), y(0), z(0), color('!') {};

	Point(double _x, double _y) : x(_x), y(_y), z(0), color('!') {};

	Point(double _x, double _y, double _z) : x(_x), y(_y), z(_z), color('!') {};

	Point(double _x, double _y, double _z, char _color) : x(_x), y(_y), z(_z), color(_color) {};

	// Getters
	double getX() {
		return x;
	}
	double getY() {
		return y;
	}
	double getZ() {
		return z;
	}
	char getColor() {
		return color;
	}

	// Setters
	void setX(double newX) {
		x = newX;
	}
	void setY(double newY) {
		y = newY;
	}
	void setZ(double newZ) {
		z = newZ;
	}
	void setColor(char newColor) {
		color = newColor;
	}

	// Methods
	/**
	 * These methods apply the appropriate rotation matrix to itself
	 */
	void rotateX(Point about, double theta) {
		double bufferY = (cos(theta) * (y - about.getY())) - (sin(theta) * (z - about.getZ())) + about.getY();
		double bufferZ = (sin(theta) * (y - about.getY())) + (cos(theta) * (z - about.getZ())) + about.getZ();

		y = bufferY;
		z = bufferZ;
	}

	void rotateY(Point about, double theta) {
		double bufferX = (cos(theta) * (x - about.getX())) + (sin(theta) * (z - about.getZ())) + about.getX();
		double bufferZ = (-sin(theta) * (x - about.getX())) + (cos(theta) * (z - about.getZ())) + about.getZ();

		x = bufferX;
		z = bufferZ;
	}

	void rotateZ(Point about, double theta) {
		double bufferX = (cos(theta) * (x - about.getX())) - (sin(theta) * (y - about.getY())) + about.getX();
		double bufferY = (sin(theta) * (x - about.getX())) + (cos(theta) * (y - about.getY())) + about.getY();

		x = bufferX;
		y = bufferY;
	}


	// Apply a vector transformation
	void addVector(Vector v) {
		x += v.x;
		y += v.y;
		z += v.z;
	}
};
