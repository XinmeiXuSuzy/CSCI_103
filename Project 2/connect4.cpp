#include <iostream>
#include <iomanip>
#include <cstring>
#include "c4lib.h"
using namespace std;

// Add any prototypes and/or functions you like here



int main(int argc, char* argv[])
{
  if(argc < 4){
    cout << "Please provide the board dimensions, either 0P|1P|2P, and an optional seed" << endl;
    return 1;
  }
  int ydim, xdim, seed;
  BoardValue** board = NULL;

  // Add code here to convert the  command line arguments to  
  //  set the value ydim and xdim 
  
  
  // Since the seed is optional we need to check if there
	// is another argument
  if(argc >= 5){
		// set the seed with the integer value from the command line

  }
	else {
		// if no seed was provided we'll use the current time
    // Do not alter
		seed = time(0);
	}
  srand(seed);


  // Do not alter - determine the player modes
  int numP = 2;
  if(strcmp(argv[3],"1P") == 0 || strcmp(argv[3], "1p") == 0){
    numP = 1;
  }
  else if(strcmp(argv[3],"0P") == 0 || strcmp(argv[3], "0p") == 0){ 
    numP = 0;
  }
  else if(strcmp(argv[3],"test") == 0){ 
    numP = -1;
  }
  cout << "Num players: " << numP << endl;

  // Any initialization code

  // Do not alter these declarations 
  int turn = 0;        // Number of turns for the game 
  int player = 0;      // MUST alternate between 0 (red) and 1 (yellow) 
                       // to represent the two players
  bool error = false;  // input error?
  while( /* condition check to continue the game */ ){
    // ------------------------------------------------------------
    // Do not alter
    
    // Increment the turn and print the board
    turn++;
    printBoard(board, ydim, xdim);
    // Get the input, check for errors, a winner or a draw
    int x, y;
    if(numP == -1) {
      // Random vs. Random
      error = getRandomAIInput(board, ydim, xdim, &y, &x, player);
    }
    else if(numP == 0 && player == 0){
      // Random vs. User AI
      error = getRandomAIInput(board, ydim, xdim, &y, &x, player);
    }
    else if( (numP == 0 || numP == 1) && player == 1 ){
      // Random vs. User AI ..or.. Human vs. User AI
      error = getUserAIInput(board, ydim, xdim, &y, &x, player);
    }
    else {
      // Human vs. user AI ..or.. Human vs. Human
      error = getNextHumanInput(board, ydim, xdim, &y, &x, player);
    }
    // ------------------------------------------------------------

    // Add necessary code to deal with errors and determine if 
    // there is a winner or a draw. Then change to the next player
    // and repeat!




    // Be sure to switch the player


  }
  // Only fill in the conditions of the code below.  
	//  This code will output the expected messages but you
	//  have to complete the conditions based on your 
	//  implementation above.
  printBoard(board, ydim, xdim);
  if( /* condition for the game ending in a yellow win */) {
    cout << "Yellow wins" <<  endl;
  }
  else if(/* condition for the game ending in a red win */) {
    cout <<  "Red wins" <<  endl;
  }
  else if(/* condition for the game ending in a draw */) {
    cout <<  "Draw" <<  endl;
  }
  else if(/* condition for early exit or invalid input */) {
    cout <<  "Early exit" <<  endl;
  }
  cout <<  "Last turn " << turn <<  endl;

  // Add any final cleanup or code that you deem necessary
	// but no additional printing/output should be performed



  return 0;
}