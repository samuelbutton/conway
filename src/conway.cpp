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

int main() {
	srand(time(NULL));

//	runTests();

	Board halfBoard(50, 200, 0.3);
	halfBoard.toString();

	while (true) {
		halfBoard.prettyPrint();
		halfBoard.update();
	}
	halfBoard.prettyPrint();

	return 0;
}

void runTests() {
	// Test 1
	Board deadBoard(3, 3, 0);
	deadBoard.toString();
	deadBoard.prettyPrint();
	deadBoard.update();
	deadBoard.prettyPrint();

	// Test 2
	int testBoardVals[] = { 0, 0, 1, 0, 1, 1, 0, 0, 0 };
	Board testBoard(3, 3, 0);
	testBoard.setBoard(testBoardVals);
	testBoard.toString();
	testBoard.prettyPrint();
	testBoard.update();
	testBoard.prettyPrint();

}
