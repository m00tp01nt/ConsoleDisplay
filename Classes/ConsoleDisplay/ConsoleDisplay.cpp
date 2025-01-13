//============================================================================
// Name        : ConsoleDisplay.cpp
// Author      : Andy Eslick
// Version     : 1.0
// Copyright   : GNU
// Description : A class for managing a console display
//============================================================================

#include <math.h>

/**
 * Encapsulates a frame buffer.
 */
class ConsoleDisplay {
private:
	/**
	 * The length of the display
	 */
	int length;
	/**
	 * The height of the display
	 */
	int height;
	/**
	 * The default on / off characters
	 */
	char defaultOn, defaultOff;
	/**
	 * The start of the memory chunk that contains the frame
	 */
	char *display;
	/**
	 * Could be used for retrieving any errors
	 */
	int errorCode;

	/**
	 * Uses pointer arithmatic to get the address at a given coordinate
	 */
	char* indexAddress(int x, int y) {
		return (display + calculateIndex(x, y));
	}

	/**
	 * Gets the character at a given coordinate, after performing bounds checking
	 */
	char accessDisplayCoordinate(int x, int y) {
		if ((x > length) || (y > height) || (x < 0) || (y < 0)) {
			if (x > length)
				errorCode = -1;
			if (y > height)
				errorCode = -2;
			if (x < 0)
				errorCode = -3;
			if (y < 0)
				errorCode = -4;
			return '\0';
		}
		else {
			return *indexAddress(x, y);
		}
	}

	/**
	 * Changes the character at the given coordinate, after performing bounds checking.
	 * If no character is provided, flip the character from defaultOff to defaultOn or vice-versa
	 */
	int manipulateDisplayCoordinate(int x, int y, char updated) {
		if ((x >= length) || (y >= height) || (x < 0) || (y < 0)) {
			if (x > length)
				errorCode = -5;
			if (y > height)
				errorCode = -6;
			if (x < 0)
				errorCode = -7;
			if (y < 0)
				errorCode = -8;
			return -1;
		}
		else if (accessDisplayCoordinate(x, y) == updated) {
			return 1;
		}
		else if (updated == '\0') {
			if (accessDisplayCoordinate(x, y) == defaultOff) {
				manipulateDisplayCoordinate(x, y, defaultOn);
				return 1;
			}
			else if (accessDisplayCoordinate(x, y) == defaultOn) {
				manipulateDisplayCoordinate(x, y, defaultOff);
				return 1;
			}
			else {
				return -1;
			}
		}
		else {
			*indexAddress(x, y) = updated;
			return 1;
		}
	}

protected:
	/**
	 * Calculates the index of the desired coordinate in an array
	 */
	int calculateIndex(int x, int y) {
		return ((length * y) + x);
	}

	/**
	 * Gets the x value of an index
	 */
	int calculateXFromIndex(int index) {
		if ((index < 0) || (index >= (getLength() * getHeight()))) {
			if (index < 0)
				errorCode = -9;
			if ((index >= (getLength() * getHeight())))
				errorCode = -10;
			return -1;
		}
		return (index % getLength());
	}

	/**
	 * Gets the y value of an index
	 */
	int calculateYFromIndex(int index) {
		return (int)(index / getLength());
	}

public:
	/**
	 * Constructor. Allocates a square of memory for the object to use.
	 */
	ConsoleDisplay(int _length, int _height, char _defaultOff=' ', char _defaultOn='O') {
		errorCode 	= 0;
		length 		= _length;
		height 		= _height;
		defaultOff 	= _defaultOff;
		defaultOn 	= _defaultOn;
		display = new char[length * height];
		for (int i = 0; i < (length * height); i++) {
			*(display + i) = defaultOff;
		}
	}

	// Getters
	int getLength() {
		return length;
	}
	int getHeight() {
		return height;
	}
	int getMaxLength() {
		return (length - 1);
	}
	int getMaxHeight() {
		return (height - 1);
	}
	/**
	 * Returns the address of the head of the memory square
	 */
	char* getPointer() {
		return display;
	}
	char getPixel(int x, int y) {
		return accessDisplayCoordinate(x, y);
	}
	char getDefaultOff() {
		return defaultOff;
	}
	char getDefaultOn() {
		return defaultOn;
	}
	int getErrorCode() {
		return errorCode;
	}

	// Setter
	/**
	 * Writes a character to a pixel
	 */
	int updatePixel(int x, int y, char updated='\0') {
		return manipulateDisplayCoordinate(x, y, updated);
	}
	/**
	 * Rounds off a double type number, then Writes a character to a pixel
	 */
	int updatePixel(double x, double y, char updated='\0') {
		return manipulateDisplayCoordinate(round(x), round(y), updated);
	}
	/**
	 * Sets the defaultOff character, and replaces all the old defaultOff characters with the new defaultOff character in the memory square.
	 */
	int setDefaultOff(char _defaultOff) {
		if ((defaultOff == _defaultOff) || (_defaultOff == defaultOn)) {
			if (defaultOff == _defaultOff)
				errorCode = -11;
			if (_defaultOff == defaultOn)
				errorCode = -12;
			return 0;
		}
		findAndReplace(defaultOff, _defaultOff);
		defaultOff = _defaultOff;
		return 1;
	}
	/**
	 * Sets the defaultOn character, and replaces all the old defaultOn characters with the new defaultOn character in the memory square.
	 */
	int setDefaultOn(char _defaultOn) {
		if ((defaultOn == _defaultOn) || (_defaultOn == defaultOff)){
			if (defaultOn == _defaultOn)
				errorCode = -13;
			if (_defaultOn == defaultOff)
				errorCode = -14;
			return 0;
		}
		findAndReplace(defaultOn, _defaultOn);
		defaultOn = _defaultOn;
		return 1;
	}

	// Methods
	/**
	 * Deletes and creates a new memory square with the given dimensions
	 */
	int rescale(int _length, int _height) {
		if ((_length <= 0) || (_height <= 0)) {
			if (_height <= 0)
				errorCode = -15;
			if (_length <= 0)
				errorCode = -16;
			return -1;
		}
		else if ((length == _length) && (height == _height)) {
			errorCode = -17;
			return reset();
		}
		else {
			length = _length;
			height = _height;
			delete display;
			display = new char[length * height];
			for (int i = 0; i < (length * height); i++) {
				*(display + i) = defaultOff;
			}
			return 1;
		}
	}

	/**
	 * Resets ht ememory square to the given value, or defaultOff is none is given
	 */
	int reset(char toWhat='\0') {
		if (toWhat == '\0') {
			toWhat = defaultOff;
		}
		for (int i = 0; i < (length * height); i++) {
			*(display + i) = toWhat;
		}
		return 1;
	}

	/**
	 * Loads the data from a different buffer into this one if the dimensions match
	 */
	int loadBuffer(char *_display, int _length, int _height) {
		if ((_length != getLength()) || (_height != getHeight())) {
			if (_length != getLength())
				errorCode = -18;
			if (_height != getHeight())
				errorCode = -19;
			return -1;
		}
		for (int i = 0; i < _height; i++) {
			for (int j = 0; j < _length; j++) {
				if (*(_display + calculateIndex(j, i)) != getDefaultOff()) {
					updatePixel(j, i, *(_display + calculateIndex(j, i)));
				}
			}
		}
		return 1;
	}

	/**
	 * Looks for the given character and replaces it with the given character
	 */
	int findAndReplace(char lookingFor, char replaceWith) {
		if (lookingFor == replaceWith) {
			return 1;
		}
		for (int i = 0; i < (getLength() * getHeight()); i++) {
			if (*(display + i) == lookingFor) {
				*(display + i) = replaceWith;
			}
		}
		return 1;
	}
};
