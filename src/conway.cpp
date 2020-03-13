//============================================================================
// Name        : conway.cpp
// Author      : Sam Button
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Board.h"
using namespace std;
using namespace samsPackage;

void static runTests() {
	// Test 1
	Board deadBoard(3, 3, 0.0);
	deadBoard.toString();
	deadBoard.prettyPrint();
	deadBoard.update();
	deadBoard.prettyPrint();

	// Test 2
	int testBoardVals[] = { 0, 0, 1, 0, 1, 1, 0, 0, 0 };
	Board testBoard(3, 3, testBoardVals);
	testBoard.toString();
	testBoard.prettyPrint();
	testBoard.update();
	testBoard.prettyPrint();

}

int main() {
	srand(time(NULL));

	runTests();

	char *filename = (char*) "ggg.txt";
	Board randBoard(filename);
	randBoard.toString();

	while (true) {
		randBoard.prettyPrint();
		randBoard.update();
	}
	randBoard.prettyPrint();

//	Board randBoard(50, 200, 0.3);
//	randBoard.toString();
//
//	while (true) {
//		randBoard.prettyPrint();
//		randBoard.update();
//	}
//	randBoard.prettyPrint();

	return 0;
}

