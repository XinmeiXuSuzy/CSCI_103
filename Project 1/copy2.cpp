// Add other #includes if you need
#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

/* Prototypes */
void shuffle(int cards[]);
void printCard(int id);
int cardValue(int id);
void printHand(int hand[], int numCards);
int getBestScore(int hand[], int numCards, char turn);

const int NUM_CARDS = 52;

/**
 * Global arrays to be used as look-up tables. You 
 */
 // ♥, ♠, ♦, ♣
const char* suit[4] = {"\U00002665","\U00002660","\U00002666","\U00002663"}; // H, S, D, C
const char* type[13] = 
  {"2","3","4","5","6","7",
   "8","9","10","J","Q","K","A"};
const int value[13] = {2,3,4,5,6,7,8,9,10,10,10,10,11};

/**
 * Should permute the deck of cards, effectively shuffling it.
 * You must use the Fisher-Yates / Durstenfeld shuffle algorithm
 *  described in the assignment writeup.
 */
void shuffle(int cards[])
{
  /******** You complete ****************/

  // Initialize deck
  for(int i=0; i < NUM_CARDS; i++) {
    cards[i] = i;
  }
  // Shuffle deck
  for(int i=NUM_CARDS-1; i > 0; i--) {
    int j = rand() % (i+1);
    swap(cards[j], cards[i]);
  }
}

/**
 * Prints the card in a "pretty" format:   "type-suit"
 *  Examples:  K-C  (King of clubs), 2-H (2 of hearts)
 *  Valid Types are: 2,3,4,5,6,7,8,9,10,J,Q,K,A
 *  Valid Suits are: H, D, C, S
 *
 *  Must use the suit and type arrays to lookup
 *   the appropriate characters to print.
 */
void printCard(int id) {
  /******** You complete ****************/
  int base = (id % 13);
  string card_val;
  
  // find type
  card_val = string(type[base]);
  
  // find suit 
  card_val += suit[id / 13];
  cout << card_val;
}

/**
 * Returns the numeric value of the card.
 *  Should return 11 for an ACE and can then
 *  be adjusted externally based on the sum of the score.
 *
 * Must use the values array to lookup the appropriate
 *  card return value.
 */
int cardValue(int id)
{
  /******** You complete ****************/
  int card_value;
  card_value = value[id % 13];
  return card_value;
}

/**
 * Should print out each card in the hand separated by a space and
 * then print a newline at the end.  
 * Should use printCard() to print out each card.
 */
void printHand(int hand[], int numCards)
{
  /******** You complete ****************/
  for (int i=0; i < numCards; i++) {
    printCard(hand[i]); // for each id in hand 
    cout << " ";
  }
  cout << endl;
}

/**
 * Should return the total score of the provided hand.  
 * ACES should be treated as 11s to make the highest possible hand
 *  and only being reduced to 1s as needed to avoid busting.
 */
int getBestScore(int hand[], int numCards, char turn = 'd')
{
  /******** You complete ****************/
  int score = 0;
  int num_A = 0;
  for (int i=0; i < numCards; i++) {
    if (cardValue(hand[i]) == 11) {
      num_A++;
    }
    score += cardValue(hand[i]);
  }
  if (score > 21 and num_A !=0) {
    score -= 10; // count one ACE as 1 
  }
  return score;
}

/**
 * Main program logic for the game of 21
 */
int main(int argc, char* argv[])
{
  //---------------------------------------
  // Do not change this code -- Begin
  //---------------------------------------
  if(argc < 2){
    cout << "Error - Please provide the seed value." << endl;
    return 1;
  }
  int seed = atoi(argv[1]);
  srand(seed);

  int cards[52];
  int dhand[9];
  int phand[9];
  //---------------------------------------
  // Do not change this code -- End
  //---------------------------------------

  /******** You complete ****************/
  int dnum = 0;
  int pnum = 0;
  int card_pos = 1;
  bool round_ends = false;
  char choice; 
  char play_again = 'y'; // default value 

  while (play_again == 'y') {
    
    int dnum = 0;
    int pnum = 0;
    int card_pos = 1;
    bool round_ends = false;

    int cards[52] = {0};
    int dhand[9] = {0};
    int phand[9] = {0};

    // SET-UP 
    shuffle(cards); // shuffle ids

    // assign two cards to player and dealer each 
    while (card_pos < 4) {
      phand[pnum] = cards[card_pos-1];
      pnum++; // keep track of the number of cards of the player
      card_pos++;
      dhand[dnum] = cards[card_pos-1];
      dnum++; // number of the dealer's cards 
      card_pos++;
    }
    
    cout << "Dealer: " << "? ";
    printCard(dhand[1]);
    cout << " " << endl;
    cout << "Player: ";
    printHand(phand, pnum);

    if (getBestScore(phand, pnum, 'p') == 21) {
      // dealer now plays 
      while (getBestScore(dhand, dnum) < 17) {
        dhand[dnum] = cards[card_pos-1];
        dnum++; // number of the dealer's cards 
        card_pos++;
      }
      cout << "Dealer: ";
      printHand(dhand, dnum);
      if (getBestScore(dhand, dnum) > 21) {
        cout << "Dealer busts" << endl;
        cout << "Win " << getBestScore(phand, pnum, 'p') << " " << getBestScore(dhand, dnum) << endl << endl;
        round_ends = true;
      } else if (getBestScore(dhand, dnum) < 21) {
        cout << "Win " << getBestScore(phand, pnum, 'p') << " " << getBestScore(dhand, dnum) << endl << endl;
        round_ends = true;
      } else {
        cout << "Tie: " << getBestScore(phand, pnum, 'p') << " " << getBestScore(dhand, dnum) << endl << endl;
        round_ends = true;
      }

    } else if (getBestScore(phand, pnum, 'p') < 21) {
      cout << "Type 'h' to hit and 's' to stay:" << endl;
      cin >> choice;
      if (choice != 'h' and choice != 's') {
        return 0;
      }
      while (choice == 'h' or choice == 's') {

        if (choice == 'h') {
          // player gets one more card 
          phand[pnum] = cards[card_pos-1];
          pnum++;
          card_pos++;
          cout << "Player: ";
          printHand(phand, pnum);
          if (getBestScore(phand, pnum, 'p') > 21) {
            cout << "Player busts " << endl;
            cout << "Lose " << getBestScore(phand, pnum, 'p') << " " << getBestScore(dhand, dnum) << endl << endl;
            round_ends = true;
            break;
          } else if (getBestScore(phand, pnum, 'p') == 21){
            // dealer now plays 
            while (getBestScore(dhand, dnum) < 17) {
              dhand[dnum] = cards[card_pos-1];
              dnum++; // number of the dealer's cards 
              card_pos++;
            }
            cout << "Dealer: ";
            printHand(dhand, dnum);
            if (getBestScore(dhand, dnum) > 21) {
              cout << "Dealer busts" << endl;
              cout << "Win " << getBestScore(phand, pnum, 'p') << " " << getBestScore(dhand, dnum) << endl << endl;
              round_ends = true;
              break;
            } else if (getBestScore(dhand, dnum) < 21) {
              cout << "Lose " << getBestScore(phand, pnum, 'p') << " " << getBestScore(dhand, dnum) << endl << endl;
              round_ends = true;
              break;
            } else {
              cout << "Tie: " << getBestScore(phand, pnum, 'p') << " " << getBestScore(dhand, dnum) << endl << endl;
              round_ends = true;
              break;
            }
          }

        } else if (choice == 's') {
          while (getBestScore(dhand, dnum) < 17) {
            dhand[dnum] = cards[card_pos-1];
            dnum++; // number of the dealer's cards 
            card_pos++;
          }
          cout << "Dealer: ";
          printHand(dhand, dnum);
          if (getBestScore(dhand, dnum) > 21) {
            cout << "Dealer busts" << endl;
            cout << "Win " << getBestScore(phand, pnum, 'p') << " " << getBestScore(dhand, dnum) << endl << endl;
            round_ends = true;
            break;
          } else if (getBestScore(phand, pnum, 'p') < getBestScore(dhand, dnum)) {
            cout << "Lose " << getBestScore(phand, pnum, 'p') << " " << getBestScore(dhand, dnum) << endl << endl;
            round_ends = true;
            break;
          } else if (getBestScore(phand, pnum, 'p') > getBestScore(dhand, dnum)) {
            cout << "Win " << getBestScore(phand, pnum, 'p') << " " << getBestScore(dhand, dnum) << endl << endl;
            round_ends = true;
            break;
          } else {
            // tie 
            cout << "Tie: " << getBestScore(phand, pnum, 'p') << " " << getBestScore(dhand, dnum) << endl << endl;
            round_ends = true;
            break;
          }
        }
        cout << "Type 'h' to hit and 's' to stay:" << endl;
        cin >> choice;
      }
    }
    if (round_ends) {
      cout << "Play again? [y/n]" << endl;
      cin >> play_again;
    }
  }

  return 0;
}
