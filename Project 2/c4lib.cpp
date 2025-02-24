#include "c4lib.h"
#include <iostream>
using namespace std;

// Prototype internal helper functions
/**
 * @brief returns the smallest y coordinate that is BLANK in 
 *        column x or -1 if no location is BLANK
 */
int findYValue(BoardValue** board, int ydim, int x);


// ------------------------------------------------------------
// Global variabes - the ONLY we allow in this program

// converts integer player value: 0 or 1 to appropriate enum
enum BoardValue playerToValue[2] = {RED, YELLOW};

// ----------------------------------------------------------------------


// Helper function 
int findYValue(BoardValue** board, int ydim,  int x)
{
  // You complete!



}

BoardValue** allocateBoard(int ydim,  int xdim)
{
  // You complete!



}
void deallocateBoard(BoardValue** board,  int ydim)
{
  // You complete!



}

void printBoard(BoardValue** board,  int ydim, int xdim)
{
  // Complete - Do not alter
  const char* boardToString[] = { "\U000026ab", "\U0001F534", "\U0001F7E1" }; 
                                  //  "⚫",          "🔴",         "🟡"}
  for(int y = ydim-1; y >= 0; y--){
    for(int x = 0; x < xdim; x++) {
      cout << boardToString[(int)board[y][x]] << " ";
    }
    cout << endl;
  }
  cout << endl;
}

bool getNextHumanInput(
  BoardValue** board, 
  int ydim,  int xdim, 
  int *y, int *x,
  int currentPlayer)
{
  // You complete!




}

bool hasWon(
  BoardValue** board,
  int ydim,  int xdim,
  int sy, int sx,
  int currentPlayer)
{
  // Keep, modify, or delete these as you desire
  const int NDIRS=4;
  const int yDirDelta[NDIRS] = {+1,  0, +1, +1};
  const int xDirDelta[NDIRS] = { 0, +1, -1, +1};
  // You complete!


}

bool isDraw(
  BoardValue** board,
  int ydim,  int xdim)
{
  // You complete!


}



bool getUserAIInput(
  BoardValue** board, 
  int ydim,  int xdim, 
  int *y, int *x,
  int currentPlayer)
{
  // You complete!
  // Check if the current player can win


  // Check if we need to block 
  //  We can greedily play the first blocking location since
  //  if they can win in multiple ways it does not matter which
  //  we choose.


  // Add any other logic for how to choose a location to play
  // if neither case above occurs

  
}

// Complete - Do not alter
bool getRandomAIInput(
  BoardValue** board, 
  int ydim, int xdim, 
  int *y, int *x,
  int currentPlayer)
{
  // Allocate variable size array (we don't know xdim when we compile)
  int* possible = new int[xdim];
  int numX = 0;
  bool error = true;
  // find all the possible columns with a blank
  for(int i = 0; i < xdim; i++){
    if(board[ydim-1][i] == BLANK){
      possible[numX++] = i;
    }
  }
  // If at least 1 column has a blank
  if(numX != 0){
    // Choose one column
    *x = possible[rand()%numX];
    *y = findYValue(board, ydim, *x);
    board[*y][*x] = playerToValue[currentPlayer];
    error = false;  
  }
  delete [] possible;
  return error;
}


