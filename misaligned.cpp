#include <iostream>
#include <assert.h>
#include <string.h>

const char* majorColor[] = { "White", "Red", "Black", "Yellow", "Violet" };
const char* minorColor[] = { "Blue", "Orange", "Green", "Brown", "Slate" };

std::string formatColorPairEntry(int majorColorIndex, int minorColorIndex) {
	int pairId = majorColorIndex * 5 + minorColorIndex;
	std::string pairIdString = std::to_string(pairId);
	std::string seperator = " | ";
	std::string formattedColorPairEntry = pairIdString + seperator + majorColor[majorColorIndex] + seperator + minorColor[majorColorIndex];
	return formattedColorPairEntry;
}

void printOnConsole(std::string ColorPairEntry)
{
	std::cout << ColorPairEntry << std::endl;
}

int printColorMap() {
	int i = 0, j = 0;
	for (i = 0; i < 5; i++) {
		for (j = 0; j < 5; j++) {
			std::string ColorPairEntry = formatColorPairEntry(i, j);
			printOnConsole(ColorPairEntry);
		}
	}
	return i * j;
}

void testColorPairEntry(std::string actualColorPairEntry, std::string expectedColorPairEntry)
{
	assert(expectedColorPairEntry.compare(actualColorPairEntry) == 0);
}

int main() {
	int result = printColorMap();
	assert(result == 25);
	testColorPairEntry(formatColorPairEntry(0, 0), " 1 | White  | Blue");
	testColorPairEntry(formatColorPairEntry(0, 2), " 3 | White  | Green");
	testColorPairEntry(formatColorPairEntry(1, 1), " 7 | Red    | Orange ");
	testColorPairEntry(formatColorPairEntry(1, 4), "10 | Red    | Slate");
	testColorPairEntry(formatColorPairEntry(2, 2), "13 | Black  | Green");
	testColorPairEntry(formatColorPairEntry(2, 3), "14 | Black  | Brown");
	testColorPairEntry(formatColorPairEntry(3, 0), "16 | Yellow | Blue");
	testColorPairEntry(formatColorPairEntry(3, 2), "18 | Yellow | Green");
	testColorPairEntry(formatColorPairEntry(4, 2), "23 | Violet | Green");
	testColorPairEntry(formatColorPairEntry(4, 4), "25 | Violet | Slate");
	std::cout << "All is well (maybe!)\n";
	return 0;
}
