/*
 * Board.h
 *
 *  Created on: Mar 11, 2020
 *      Author: sambutton
 */

#ifndef BOARD_H_
#define BOARD_H_

namespace samsPackage {

class Board {
public:
	int *m_board;
	int *m_copy;
	int m_rows;
	int m_cols;
private:
	void copyBoard();
public:
	Board(int rows, int cols, double chanceOfLife);
	Board(int rows, int cols, int *board);
	Board(char *filename);
	void update();
//	void setDead(int row, int col);
//	void setAlive(int row, int col);
	void toString();
	void prettyPrint();
	virtual ~Board();
private:
	void setRandBoard(double chanceOfLife);
};

} /* namespace samsPackage */

#endif /* BOARD_H_ */
