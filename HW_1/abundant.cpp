/********************************************************
 * Description:
 *   Displays the top 3 most "abundant" (see writeup)
 *   numbers in the input sequence.  The input sequence
 *   is assumed to be valid natural numbers separated
 *   by spaces and ending with 0.
 *
 *   ABSOLUTELY NO ARRAY or `string`/`vector`/etc. usage
 *   is allowed!

 *   You may only declare: bool, int, or unsigned int
 *   No library functions (beyond cin/cout) are allowed.
 *
 *   You may NOT modify any of the given template code.
 *   This ensures our automated checkers can parse your
 *   output.  You MAY add functions, prototypes, etc.
 *   to aide your implementation. Failure to follow this 
 *   direction will lead to a score of 0 on this 
 *   part of the assignment.
 ********************************************************/

#include <iostream>
#include <cmath>
using namespace std;

int cal_abundance(int num) {
    int abundance = 0;
    for(int i = 1; i < num; i++) {
        if (num%i == 0) {
            abundance += i;
        }
    }
    return abundance;
  }

int main() {
    // n1 is the number with the highest abundance, a1
    // n2 is the number with the 2nd-highest abundance, a2
    // n3 is the number with the 3rd-highest abundance, a3
    unsigned int n1 = 0, n2 = 0, n3 = 0;
    int a1 = 0, a2 = 0, a3 = 0;
    // num_abundant counts how many numbers in the input
    // sequence are abundant
    int num_abundant = 0, num;

    cout << "Enter a sequence of natural numbers, separated by spaces, ";
    cout << "and ending with 0."<< endl;
    while (num != 0) {
        cin >> num;
        int abundance = cal_abundance(num);
        if (num < abundance) {
            num_abundant++;
            if (abundance >= a3) {
                a3 = abundance;
                n3 = num;
                if (a3 >= a2) {
                    int temp_a = a2, temp_n = n2;
                    a2 = a3;
                    n2 = n3;
                    a3 = temp_a;
                    n3 = temp_n;
                    if (a2 >= a1) {
                        int temp_a = a1, temp_n = n1;
                        a1 = a2;
                        n1 = n2;
                        a2 = temp_a;
                        n2 = temp_n;
                        if (a3 >= a2) {
                            int temp_a = a2, temp_n = n2;
                            a2 = a3;
                            n2 = n3;
                            a3 = temp_a;
                            n3 = temp_n;
                        }
                    }
                }
            }
        }
    }
    cout << "Abundant number count: " << num_abundant << endl;
    cout << "Top 3 most abundant numbers:" << endl;
    cout << n1 << " : " << a1 << endl;
    cout << n2 << " : " << a2 << endl;
    cout << n3 << " : " << a3 << endl;
}
