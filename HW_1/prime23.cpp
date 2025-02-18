#include <iostream>
#include <cmath>
using namespace std;

int main() {
  int num, count2 = 0, count3 = 0;
  bool factor23 = true;
  cout << "Enter a positive integer: ";
  cin >> num;
  for(int i = 2; i <= num; i++) {
    if (i == 2) {
      int myNum = num;
      while (myNum % 2 == 0) {
        count2++; 
        myNum = myNum / 2;
      }
    }
    if (i == 3) {
      int myNum = num;
      while (myNum % 3 == 0) {
        count3++; 
        myNum = myNum / 3;
      }
    }
    if (i%2 != 0 and i%3 != 0 and num % i == 0) {
      factor23 = false;
      break;
    }
  }

  if (factor23 == true) {
    cout << "Yes" << endl;
    cout << "Twos=" << count2 << " Threes=" << count3;
  }
  else {
    cout << "No";
  }

  return 0;
}