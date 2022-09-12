#include "geesespotter_lib.h"
#include "geesespotter.h"
#include <iostream>

char *createBoard (std::size_t xdim, std::size_t ydim){
  char * gameboard {new char[xdim*ydim]};
  for (std::size_t n{}; n < xdim*ydim; n++) {
      gameboard[n] = 0x00;
  }
  return gameboard;
}

void computeNeighbors(char * board, std::size_t xdim, std::size_t ydim){
  for (int i{}; i < xdim*ydim; i++ ) {
      if (board[i] == 9) {
         
              for (int y{-1}; y <= 1; y++ ){

                    for (int x{-1}; x <= 1; x++ ){
                int new_p = i + xdim * y+x;
                int xloc= i % xdim;
                int yloc= i / xdim;  
                if (xloc+x >= 0 && xloc+x < xdim && yloc+y >= 0 && yloc+y < ydim && (board[new_p] !=9)){
                    board[new_p]++;
                } 
                }         
           }
          } 
  }
}
          
void hideBoard (char *board, std::size_t xdim, std::size_t ydim){
 for (int n {}; n < xdim*ydim; n++){
     board[n] = board[n] | hiddenBit();
 }
}

void cleanBoard(char * board){
 delete[] board;
 board = nullptr;

}

void printBoard(char * board, std::size_t xdim, std::size_t ydim){
    int k {};
    for (std::size_t n{}; n < ydim; n++){
        for (std::size_t i {}; i < xdim; i++){
            
        if ((board[k] & markedBit())) {
            std::cout << "M";
        } else if ((board[k] & hiddenBit())){
            std::cout << "*";
        } else {
            std::cout << char(board[k] +48); 
        }
          k++;
        } 
      
        std::cout << std::endl;
    }

}

int reveal(char * board, std::size_t xdim, std::size_t ydim, std::size_t xloc, std::size_t yloc){
    int element = yloc*xdim + xloc;
    if (board[element] == 0x29){
        board[element] = ~hiddenBit() & board[element];
        //goose
        return 9;
    } else if (!(board[element] & hiddenBit() )) {
        //already revealed
        return 2;
    } else if (board[element] & markedBit()) {
        //field marked
        return 1;
    } else if ( board[element] == 0x20) {
                   for (int y{-1}; y <= 1; y++ ){
                    for (int x{-1}; x <= 1; x++ ){
                int new_p = element + xdim * y+x;
                int xloc= element % xdim;
                int yloc= element / xdim;  
                if (xloc+x >= 0 && xloc+x < xdim && yloc+y >= 0 && yloc+y < ydim ){
                    board[new_p] = ~hiddenBit() & board[new_p];
                } 
                }         
           }
           } else {
             board[element] = ~hiddenBit() & board[element];
        }
        return 0;
    }
       


int mark(char * board, std::size_t xdim, std::size_t ydim, std::size_t xloc, std::size_t yloc){
    std::size_t element = yloc*xdim + xloc;
    if ((!(board[element] & hiddenBit())) && ((!(board[element] & markedBit())))){
        return 2;
    } else if ((board[element] & hiddenBit()) && (board[element] & markedBit()) ){
        board[element] = board[element] &~ markedBit();   
    } else {
        board[element] = board[element] | markedBit();
    }
    return 0;
}



bool isGameWon(char * board, std::size_t xdim, std::size_t ydim){
        for (int i{}; i < xdim*ydim; i++){
            if ((board[i] & hiddenBit()) && (board[i] & valueMask()) != 9){
                return false;
            }
        }
        return true;
    
}

