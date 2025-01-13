/*
 * Vector.cpp
 *
 *  Created on: Jan 7, 2025
 *      Author: eslia
 */

#include <iostream>
#include <cmath>

class Vector {

public:

	double x;
	double y;
	double z;

	Vector() : x(0), y(0), z(0) {};

	Vector(double x, double y) : x(x), y(y), z(0) {};
	Vector(int x, int y) : x((double)x), y((double)y), z(0) {};

	Vector(double x, double y, double z) : x(x), y(y), z(z) {};
	Vector(int x, int y, int z) : x((double)x), y((double)y), z((double)z) {};

	double length() {
		return pow(((x * x) + (y * y) + (z * z)), 0.5);
	}

	void reset() {
		x = 0;
		y = 0;
		z = 0;
	}

	void print() {
		std::cout << "< " << x << " , " << y << " , " << z << " >" << std::endl;
	}

	Vector add(const Vector& v) {
		return Vector(x + v.x, y + v.y, z + v.z);
	}
	void addToSelf(const Vector& v) {
		x += v.x;
		y += v.y;
		z += v.z;
	}

	Vector subtract(const Vector& v) {
		return Vector(x - v.x, y - v.y, z - v.z);
	}
	void subtractFromSelf(const Vector& v) {
		x -= v.x;
		y -= v.y;
		z -= v.z;
	}

	Vector scale(int scalar) {
		return Vector(x * scalar, y * scalar, z * scalar);
	}
	Vector scale(float scalar) {
		return Vector(x * scalar, y * scalar, z * scalar);
	}
	Vector scale(double scalar) {
		return Vector(x * scalar, y * scalar, z * scalar);
	}
	void scaleSelf(int scalar) {
		x *= scalar;
		y *= scalar;
		z *= scalar;
	}
	void scaleSelf(float scalar) {
		x *= scalar;
		y *= scalar;
		z *= scalar;
	}
	void scaleSelf(double scalar) {
		x *= scalar;
		y *= scalar;
		z *= scalar;
	}


	Vector operator+(const Vector& v) {
		return add(v);
	}
	void operator+=(const Vector& v) {
		addToSelf(v);
	}

	Vector operator-(const Vector& v) {
		return subtract(v);
	}
	void operator-=(const Vector& v) {
		subtractFromSelf(v);
	}

	Vector operator*(int scalar) {
		return scale(scalar);
	}
	Vector operator*(float scalar) {
		return scale(scalar);
	}
	Vector operator*(double scalar) {
		return scale(scalar);
	}
	void operator*=(int scalar) {
		scaleSelf(scalar);
	}
	void operator*=(float scalar) {
		scaleSelf(scalar);
	}
	void operator*=(double scalar) {
		scaleSelf(scalar);
	}
};
