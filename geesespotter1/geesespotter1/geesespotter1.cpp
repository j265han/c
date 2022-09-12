#include "geesespotter_lib.h"
#include "geesespotter.h"
#include <iostream>

char* createBoard(std::size_t xdim, std::size_t ydim) {

    return 0;
}

void hideBoard(char* board, std::size_t xdim, std::size_t ydim) {

    return;
}

void cleanBoard(char* board) {

    return;
}

void printBoard(char* board, std::size_t xdim, std::size_t ydim) {

    return;
}

int mark(char* board, std::size_t xdim, std::size_t ydim, std::size_t xloc, std::size_t yloc) {
    if (board[xdim * mark_y + mark_x] & markedBit()) {
        return 0;
    }
    else {
        return 2;
    }
    return 0;
}

void computeNeighbors(char* board, std::size_t xdim, std::size_t ydim) {
    return;
}

int reveal(char* board, std::size_t xdim, std::size_t ydim, std::size_t xloc, std::size_t yloc) {
    return 0;
}

bool isGameWon(char* board, std::size_t xdim, std::size_t ydim) {
    return true;
}