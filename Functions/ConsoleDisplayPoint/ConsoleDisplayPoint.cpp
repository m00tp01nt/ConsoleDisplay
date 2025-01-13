/*
 * ConsoleDisplayPoint.cpp
 *
 * Functions that manage communication between ConsoleDisplay and Point objects
 *
 *  Created on: Jul 10, 2024
 *      Author: eslia
 */

#include "../../Classes/ConsoleDisplay/ConsoleDisplay.h"
#include "../../Classes/Point/Point.h"

/**
 * Returns the minimum of two values
 */
double min(double val1, double val2) {
	if (val1 < val2) {
		return val1;
	}
	return val2;
}

/**
 * Returns the maximum of two values
 */
double max(double val1, double val2) {
	if (val1 > val2) {
		return val1;
	}
	return val2;
}

/**
 * Draw a point on the ConsoleDisplay
 */
void drawPoint(ConsoleDisplay to, Point pt1) {
	to.updatePixel(pt1.getX(), pt1.getY(), pt1.getColor());
}

/**
 * Draws a point on the ConsoleDisplay with the given character
 */
void drawPoint(ConsoleDisplay to, Point pt1, char color) {
	to.updatePixel(pt1.getX(), pt1.getY(), color);
}

/**
 * Draws a between two points. First draws the line with respect to X for horizontal pixels, then with respect to Y for vertical pixels
 */
void drawLine(ConsoleDisplay to, Point pt1, Point pt2) {

	// X
	// Y = MX + B

	double m, b;

	if ((pt2.getX() - pt1.getX()) != 0) {

		m = ((pt2.getY() - pt1.getY()) / (pt2.getX() - pt1.getX()));
		b = (pt1.getY() - (m * pt1.getX()));

		if (pt1.getX() < pt2.getX()) {
			for (int i = round(pt1.getX()) + 1; i < round(pt2.getX()); i++) {
				to.updatePixel((double)i, (m * i) + b, to.getDefaultOn());
			}
		}
		else {
			for (int i = round(pt2.getX()) + 1; i < round(pt1.getX()); i++) {
				to.updatePixel((double)i, (m * i) + b, to.getDefaultOn());
			}
		}
	}

	// Y
	// (Y - B) / M = X

	if ((pt2.getY() - pt1.getY()) == 0)
		return;

	m = ((pt2.getX() - pt1.getX()) / (pt2.getY() - pt1.getY()));
	b = (pt1.getX() - (m * pt1.getY()));

	if (pt1.getY() < pt2.getY()) {
		for (int i = round(pt1.getY()) + 1; i < round(pt2.getY()); i++) {
			to.updatePixel((m * i) + b, (double)i, to.getDefaultOn());
		}
	}
	else {
		for (int i = round(pt2.getY()) + 1; i < round(pt1.getY()); i++) {
			to.updatePixel((m * i) + b, (double)i, to.getDefaultOn());
		}
	}

	to.updatePixel(pt1.getX(), pt1.getY(), to.getDefaultOn());
	to.updatePixel(pt2.getX(), pt2.getY(), to.getDefaultOn());
}

/**
 * Draws a triangle with three points0
 */
void drawTriangle(ConsoleDisplay to, Point pt1, Point pt2, Point pt3) {
	drawLine(to, pt1, pt2);
	drawLine(to, pt2, pt3);
	drawLine(to, pt3, pt1);
}

/**
 * Draws a rectangle with four points
 */
void drawRectangle(ConsoleDisplay to, Point pt1, Point pt2, Point pt3, Point pt4) {
	drawLine(to, pt1, pt2);
	drawLine(to, pt2, pt3);
	drawLine(to, pt3, pt4);
	drawLine(to, pt4, pt1);
}

/**
 * Draws a prism with eight points
 */
void drawPrism(ConsoleDisplay to, Point pt1, Point pt2, Point pt3, Point pt4, Point pt5, Point pt6, Point pt7, Point pt8) {
	drawRectangle(to, pt1, pt2, pt3, pt4);
	drawRectangle(to, pt5, pt6, pt7, pt8);
	drawLine(to, pt1, pt5);
	drawLine(to, pt2, pt6);
	drawLine(to, pt3, pt7);
	drawLine(to, pt4, pt8);
}
