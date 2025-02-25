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
  for (int i = 0; i < ydim; i++) {
    if (board[i][x] == BLANK) {
        return i;
    }
  }
  return -1;
}

BoardValue** allocateBoard(int ydim,  int xdim)
{
  // You complete!
  BoardValue** board = new BoardValue*[ydim];
  for (int i = 0; i < ydim; i++) {
    board[i] = new BoardValue[xdim];
  }

  // Initialize board values to blank
  for (int i = 0; i < ydim; i++) {
    for (int j = 0; j < xdim; j++) {
        board[i][j] = BLANK;
    }
  }

  return board;
}
void deallocateBoard(BoardValue** board,  int ydim)
{
  // You complete!
  for (int i = 0; i < ydim; i++) {
    delete [] board[i];
  }
  delete [] board;
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
  bool error = true;
  // only proceed if user input is in valid range 
  if (valid_position(*y, *x, ydim, xdim)) {
    board[*y][*x] = playerToValue[currentPlayer];
    error = false;
  }
  return error;
}

bool hasWon(
  BoardValue** board,
  int ydim,  int xdim,
  int sy, int sx,
  int currentPlayer)
{
  // Keep, modify, or delete these as you desire
  const int NDIRS=4;
  const int yDirDelta[NDIRS] = {1, 1, 0, -1}; // four directions -> eight directions 
  const int xDirDelta[NDIRS] = {0, 1, 1, 1};
  // You complete!
  for (int i = 0; i < NDIRS; i++) {
    int count = 1;
    
    // positive direction 
    for (int step = 1; step < 4; step++) {
        int ny = sy + step * yDirDelta[i];
        int nx = sx + step * xDirDelta[i];
        if (ny >= 0 && ny < ydim && nx >= 0 && nx < xdim && board[ny][nx] == playerToValue[currentPlayer]) {
            count++;
        } else {
            break;
        }
    }
    
    // negative direction 
    for (int step = 1; step < 4; step++) {
        int ny = sy - step * yDirDelta[i];
        int nx = sx - step * xDirDelta[i];
        if (ny >= 0 && ny < ydim && nx >= 0 && nx < xdim && board[ny][nx] == playerToValue[currentPlayer]) {
            count++;
        } else {
            break;
        }
    }
    
    if (count >= 4) {
        return true;
    }
  }
  return false;
}

bool isDraw(
  BoardValue** board,
  int ydim,  int xdim)
{
  // You complete!
  for (int i = 0; i < ydim; i++) {
    for (int j = 0; j < xdim; j++) {
        if (board[i][j] == BLANK) {
            return false;
        }
    }
  }
  return true;
}



bool getUserAIInput(
    BoardValue** board, 
    int ydim, int xdim, 
    int *y, int *x,
    int currentPlayer)
{
    int opponent = (currentPlayer == 0) ? 1 : 0;

    // First, check if we can win
    for (int j = 0; j < xdim; j++) {
        int i = findYValue(board, ydim, j);
        if (i != -1) {  // Valid move
            board[i][j] = playerToValue[currentPlayer]; 
            if (hasWon(board, ydim, xdim, i, j, currentPlayer)) {
                *y = i; *x = j;
                return false;  // Play winning move
            }
            board[i][j] = BLANK;  // Undo move
        }
    }

    // Second, check if we need to block opponent's win
    for (int j = 0; j < xdim; j++) {
        int i = findYValue(board, ydim, j);
        if (i != -1) {  // Valid move
            board[i][j] = playerToValue[opponent]; 
            if (hasWon(board, ydim, xdim, i, j, opponent)) {
                *y = i; *x = j;
                board[i][j] = playerToValue[currentPlayer];  // Play blocking move
                return false;
            }
            board[i][j] = BLANK;  // Undo move
        }
    }

    // Default: Play the first available move
    for (int j = 0; j < xdim; j++) {
        int i = findYValue(board, ydim, j);
        if (i != -1) {
            *y = i; *x = j;
            board[i][j] = playerToValue[currentPlayer];
            return false;
        }
    }

    return true;  // No move available (should not happen unless board is full)
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

bool valid_position(int y, int x, int ydim, int xdim) {
    if ((0 <= y and y < ydim) and (0 <= x and x < xdim)) {return true;};
    return false;
}


