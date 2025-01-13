/*
 * ConsoleDisplayShape.cpp
 *
 *  Created on: Jul 10, 2024
 *      Author: eslia
 */

#include <string>
#include <iostream>

#include "../../Classes/ConsoleDisplay/ConsoleDisplay.h"
#include "../../Classes/Shape/Shape.h"

#include "../ConsoleDisplayPoint/ConsoleDisplayPoint.h"

void drawShape(ConsoleDisplay to, Shape shape) {

	if ((shape.getDescription().compare("cube") == 0) && (shape.getPoints() == 8)) {
		drawPrism(to, shape.getVertex(0), shape.getVertex(1), shape.getVertex(2), shape.getVertex(3), shape.getVertex(4), shape.getVertex(5), shape.getVertex(6), shape.getVertex(7));
	}
	else if ((shape.getDescription().compare("square") == 0) && (shape.getPoints() == 4)) {
		drawRectangle(to, shape.getVertex(0), shape.getVertex(1), shape.getVertex(2), shape.getVertex(3));
	}
	else if ((shape.getDescription().compare("triangle") == 0) && (shape.getPoints() == 3)) {
		drawTriangle(to, shape.getVertex(0), shape.getVertex(1), shape.getVertex(2));
	}
	else if ((shape.getDescription().compare("squarepyramid") == 0) && (shape.getPoints() == 5)) {
		drawRectangle(to, shape.getVertex(0), shape.getVertex(1), shape.getVertex(2), shape.getVertex(3));
		drawLine(to, shape.getVertex(0), shape.getVertex(4));
		drawLine(to, shape.getVertex(1), shape.getVertex(4));
		drawLine(to, shape.getVertex(2), shape.getVertex(4));
		drawLine(to, shape.getVertex(3), shape.getVertex(4));
	}
	else if (shape.getDescription().compare("npyramid") == 0) {
		for (int i = 0; i < shape.getPoints() - 2; i++) {
			drawTriangle(to, shape.getVertex(i), shape.getVertex(i + 1), shape.getVertex(shape.getPoints() - 1));
		}
		drawLine(to, shape.getVertex(0), shape.getVertex(shape.getPoints() - 2));
	}
	else if (shape.getDescription().compare("ngon") == 0) {
		for (int i = 0; i < shape.getPoints() - 1; i++) {
			drawLine(to, shape.getVertex(i), shape.getVertex(i + 1));
		}
		drawLine(to, shape.getVertex(shape.getPoints() - 1), shape.getVertex(0));
	}
	else if (shape.getDescription().compare("sphere") == 0) {
		for (int i = 0; i < shape.shapesAttatched(); i++) {
			drawShape(to, *shape.getAttatchedShape(i));
		}
		for (int i = 0; i < shape.shapesAttatched() - 1; i++) {
			for (int j = 0; j < shape.getAttatchedShape(i)->getPoints(); j++) {
				drawLine(to, shape.getAttatchedShape(i)->getVertex(j), shape.getAttatchedShape(i + 1)->getVertex(j));
			}
		}
	}
	else if (shape.getDescription().compare("ncylinder") == 0)  {
		drawShape(to, *shape.getAttatchedShape(0));
		drawShape(to, *shape.getAttatchedShape(1));
		for (int i = 0; i < shape.getAttatchedShape(0)->getPoints(); i++) {
			drawLine(to, shape.getAttatchedShape(0)->getVertex(i), shape.getAttatchedShape(1)->getVertex(i));
		}
	}
	else if (shape.getDescription().compare("torus") == 0) {
		for (int i = 0; i < shape.shapesAttatched(); i++) {
			drawShape(to, *shape.getAttatchedShape(i));
		}
		for (int i = 0; i < shape.shapesAttatched() - 1; i++) {
			for (int j = 0; j < shape.getAttatchedShape(i)->getPoints(); j++) {
				drawLine(to, shape.getAttatchedShape(i)->getVertex(j), shape.getAttatchedShape(i + 1)->getVertex(j));
			}
		}
	}
}
