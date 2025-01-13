/*
 * ConsoleDisplayPoint.h
 *
 *  Created on: Jul 10, 2024
 *      Author: eslia
 */

#include "../../Classes/ConsoleDisplay/ConsoleDisplay.h"
#include "../../Classes/Point/Point.h"

#ifndef FUNCTIONS_CONSOLEDISPLAYPOINT_CONSOLEDISPLAYPOINT_H_
#define FUNCTIONS_CONSOLEDISPLAYPOINT_CONSOLEDISPLAYPOINT_H_

double min(double, double);
double max(double, double);
void drawPoint(ConsoleDisplay, Point);
void drawPoint(ConsoleDisplay, Point, char);
void drawLine(ConsoleDisplay, Point, Point);
void drawTriangle(ConsoleDisplay, Point, Point, Point);
void drawRectangle(ConsoleDisplay, Point, Point, Point, Point);
void drawPrism(ConsoleDisplay, Point, Point, Point, Point, Point, Point, Point, Point);

#endif /* FUNCTIONS_CONSOLEDISPLAYPOINT_CONSOLEDISPLAYPOINT_H_ */
