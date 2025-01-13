/*
 * ConsoleDisplay.cpp
 *
 *  Created on: Jul 10, 2024
 *      Author: eslia
 */

#include <iostream>

#include "../../Classes/ConsoleDisplay/ConsoleDisplay.h"

/**
 * Clears the screen by printing a special code
 */
void clearScreen() {
	std::printf("\033[H\033[J");
}

/**
 * Dynamically prints out each character in the given ConsoleDisplay object using .getPixel.
 */
void print(ConsoleDisplay what) {
	clearScreen();
	for (int i = (what.getHeight() - 1); i >= 0; i--) {
		for (int j = 0; j < what.getLength(); j++) {
			std::printf("%c", what.getPixel(j, i));
		}
		std::printf("\n");
	}
}
