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
#include <fstream>
#include <sstream>
#include <string>

namespace samsPackage {

Board::Board(int rows, int cols, double chanceOfLife) {
	m_rows = rows;
	m_cols = cols;
	m_board = new int[rows * cols * sizeof(int)];
	m_copy = new int[rows * cols * sizeof(int)];
	setRandBoard(chanceOfLife);
}

Board::Board(int rows, int cols, int *board) {
	m_rows = rows;
	m_cols = cols;
	m_board = new int[rows * cols * sizeof(int)];
	for (int i = 0; i < m_rows; i++) {
		for (int j = 0; j < m_cols; j++) {
			m_board[i * m_cols + j] = board[i * m_cols + j];
		}
	}
	m_copy = new int[rows * cols * sizeof(int)];
}

Board::Board(char *filename) {

	std::ifstream infile(filename);

	m_rows = 0;
	m_cols = 0;
	std::string line;
	std::getline(infile, line);
	std::istringstream iss(line);
	if (!(iss >> m_rows >> m_cols)) {
		return;
	}
	m_board = new int[m_rows * m_cols * sizeof(int)];
	for (int i = 0; i < m_rows; i++) {
		std::getline(infile, line);
		std::istringstream iss(line);
		for (int j = 0; j < m_cols; j++) {
			iss >> m_board[i * m_cols + j];
		}
	}

	m_copy = new int[m_rows * m_cols * sizeof(int)];
}

void Board::setRandBoard(double chanceOfLife) {
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

void printHorLine(int times) {
	for (int j = 0; j < times; j++) {
		printf("-");
	}
	printf("\n");
}

void Board::prettyPrint() {
	printHorLine(m_cols + 2);
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
	printHorLine(m_cols + 2);
}

Board::~Board() {
	delete[] m_board;
	delete[] m_copy;
	printf("Deconstructor called successfully\n");
}

} /* namespace samsPackage */
