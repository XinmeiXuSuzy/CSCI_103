// game.cpp
// Hangman game illustrates string library functions, 
// character arrays, arrays of pointers, etc.
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;

// Prototype. we'll define this below.
int processGuess(char* word, const char* targetWord, char guess);
int mystrcmp(const char* src1, const char* src2);

// Define an array of strings (since a string is just a char array)
//  and since string literals (e.g. "hi") evaluate to the starting address
//  of those characters, we really want an array of char *'s
const char* wordBank[] = {"computer", "president", "trojan", "program",
                          "coffee", "library", "football", "popcorn", 
                          "science", "engineer"};

const int numWords = 10;

int main(int argc, char* argv[])
{
  //------------- Do not modify this code --------------
  if(argc < 2){
    srand(time(0)); // use the time to get randomly chosen words each run
  }
  else {
    srand(atoi(argv[1])); // use the command line argument as the seed
  }

  // Pick a random word from the wordBank
  const char* targetWord = wordBank[rand() % numWords];

  int numTurns = 10; // variable to track how many turns remain

  char word[80];  // a blank array to use to build up the answer
                  // It should be initialized with *'s and then
                  //  change them to the actual letters when the 
                  //  user guesses the letter

  // More initialization code as needed
  for (int i = 0; i < strlen(targetWord); i++) {
    word[i] = '*';
  }
  word[strlen(targetWord)] = '\0';

  char guess_record[10] = {};
  char guess = '\0';
  int count = 0;
  bool repeat;

  while (guess != '!' and numTurns > 0) {

    cout << numTurns << " guesses remain: " << word << endl;
    cout << "Enter a letter: " << endl;
    cin >> guess;

    repeat = false;
    for (int i = 0; i < 10; i++) {
        if (guess == guess_record[i]) {
            numTurns--;
            repeat = true;
            break;
        }
    }

    int num_occur = processGuess(word, targetWord, guess);
    if (num_occur == 0 and repeat == false) {
        numTurns--;
    } 

    // check winning status 
    if (mystrcmp(word, targetWord) == 0) {
        cout << "Win! " << numTurns << " to spare.";
        exit(0);
    }

    if (count < 10) { 
        guess_record[count++] = guess; 
    }
  }
 
  // The game should continue until a word
  //  is guessed correctly, a '!' is entered,
  //  or 10 turns have elapsed without the word being guessed

  // Print out end of game status
  if (guess == '!') {
    cout << "Quit!";
    exit(0);
  }
  if (numTurns == 0) {
    cout << "Lose! " << word;
  }
    
  return 0;
}

// Given the current version of the word, target/selected word, and
// the character that the user just guessed, change the word to 
// "turn on" any occurrences the guess character and return a count
// of how many occurrences of 'guess' were found
int processGuess(char* word, const char* targetWord, char guess)
{
    int num_occur = 0;
    for (int i = 0; targetWord[i] != '\0'; i++) {
        if (guess == targetWord[i]) {
            word[i] = guess;
            num_occur++;
            cout << "guess is " << guess << ", index: " << i << ", word is " << word << endl;
        }
    }
    return num_occur;
}

/**
 * @brief Compares the contents of the two input strings use lexicographic
 *        (alphabetical) ordering
 * 
 * @param src1 string1
 * @param src2 string2
 * @return int -1 if src1 < src2, 0 if src1 == src2, +1 if src1 > src2
 */
int mystrcmp(const char* src1, const char* src2) 
{
    // Copy/paste your implementation of mystrcmp from strcmp-test.cpp
    int i = 0;
    while (src1[i] != '\0' and src2[i] != '\0') {
        if (src1[i] < src2[i]) {
            return -1;
        } else if (src1[i] > src2[i]) {
            return 1;
        }
        i++;
    }
    if (src1[i] == '\0' and src2[i] != '\0'){
      return -1;
    } else if (src1[i] != '\0' and src2[i] == '\0'){
      return 1;
    }
    return 0;

}


