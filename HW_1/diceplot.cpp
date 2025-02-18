// ============================================================================
// diceplot.cpp
//
//
// ============================================================================

#include <iostream>
#include <cstdlib>
using namespace std;

// Prototype/define functions anywhere below
int roll() {
    int randNum;
    randNum = rand() % 6 + 1;
    return randNum;
}

void printHistogram(int counts[]) {
    for(int i = 0; i < 21; i++) {
        cout << i + 4 << ":";
        for(int j = 0; j < counts[i]; j++) {
            cout << 'X';
        }
        cout << endl;
    }
}

int main()
{
    int seed, n;
    cin >> seed >> n;

    // Seed the pseudo-random number generator for repeatable results
    srand(seed);

    // Your code here
    int counts[21] = {0};
    int sum = 0;
    for(int i = 0; i < n; i++) {
        sum = roll() + roll() + roll() + roll();
        counts[sum-4]++;
    }
    printHistogram(counts);
    return 0;
    }