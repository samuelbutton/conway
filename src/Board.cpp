/*
 * Board.cpp
 *
 *  Created on: Mar 11, 2020
 *      Author: sambutton
 */

#include "Board.h"
#include <math.h>
#include <stdlib.h>
#include <iostream>

namespace samsPackage {

Board::Board(int rows, int cols, double chanceOfLife) {
	m_rows = rows;
	m_cols = cols;
	m_board = new int[rows * cols * sizeof(int)];
	m_copy = new int[rows * cols * sizeof(int)];
	setBoard(chanceOfLife);
}
void Board::setBoard(double chanceOfLife) {
	for (int i = 0; i < m_rows; i++) {
		for (int j = 0; j < m_cols; j++) {
			if ((rand() * (1.0)) / RAND_MAX < chanceOfLife)
				m_board[i * m_cols + j] = 1;
			else
				m_board[i * m_cols + j] = 0;
		}
	}
}

void Board::copyBoard() {
	for (int i = 0; i < m_rows; i++) {
		for (int j = 0; j < m_cols; j++) {
			m_copy[i * m_cols + j] = m_board[i * m_cols + j];
		}
	}
}

void Board::update() {
	copyBoard();
	for (int i = 0; i < m_rows; i++) {
		for (int j = 0; j < m_cols; j++) {
			int neighborCount = 0;
			if (i > 0) {
				neighborCount += m_board[(i - 1) * m_cols + j];
			}
			if (i < m_rows - 1) {
				neighborCount += m_board[(i + 1) * m_cols + j];
			}
			if (j > 0) {
				neighborCount += m_board[i * m_cols + j - 1];
			}
			if (j < m_cols - 1) {
				neighborCount += m_board[i * m_cols + j + 1];
			}
			if (i > 0 && j > 0) {
				neighborCount += m_board[(i - 1) * m_cols + j - 1];
			}
			if (i < m_rows - 1 && j > 0) {
				neighborCount += m_board[(i + 1) * m_cols + j - 1];
			}
			if (i > 0 && j < m_cols - 1) {
				neighborCount += m_board[(i - 1) * m_cols + j + 1];
			}
			if (i < m_rows - 1 && j < m_cols - 1) {
				neighborCount += m_board[(i + 1) * m_cols + j + 1];
			}
			if (m_board[i * m_cols + j] > 0) {
				// cell is alive
				if (neighborCount < 2) {
					m_copy[i * m_cols + j] = 0;
				} else if (neighborCount > 3) {
					m_copy[i * m_cols + j] = 0;
				}
			} else {
				//cell is dead
				if (neighborCount == 3) {
					m_copy[i * m_cols + j] = 1;
				}
			}
		}
	}
	int *temp = m_board;
	m_board = m_copy;
	m_copy = temp;
}

void Board::setBoard(int *newBoard) {
	for (int i = 0; i < m_rows; i++) {
		for (int j = 0; j < m_cols; j++) {
			m_board[i * m_cols + j] = newBoard[i * m_cols + j];
		}
	}
}

//void Board::setDead(int row, int col) {
//	board[row * cols + col] = 0;
//}
//
//void Board::setAlive(int row, int col) {
//	board[row * cols + col] = 1;
//}

void Board::toString() {
	printf("[");
	for (int i = 0; i < m_rows; i++) {
		if (i > 0)
			printf(",");
		printf("[");
		for (int j = 0; j < m_cols; j++) {
			if (j > 0)
				printf(", ");
			printf("%d", m_board[i * m_cols + j]);
		}
		printf("]");
	}
	printf("]\n");
}

void Board::prettyPrint() {
// can be refactored [1]
	for (int j = 0; j < m_cols + 2; j++) {
		printf("-");
	}
	printf("\n");

	for (int i = 0; i < m_rows; i++) {
		printf("|");
		for (int j = 0; j < m_cols; j++) {
			if (m_board[i * m_cols + j] > 0) {
				printf("#");
			} else
				printf(" ");
		}
		printf("|\n");
	}

// can be refactored [1]
	for (int j = 0; j < m_cols + 2; j++) {
		printf("-");
	}
	printf("\n");
}

Board::~Board() {
	delete[] m_board;
	delete[] m_copy;
	printf("Deconstructor called successfully");
}

} /* namespace samsPackage */
