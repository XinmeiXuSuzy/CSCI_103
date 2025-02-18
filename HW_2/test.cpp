#include <iostream>
using namespace std;



int main() {
    const char src1[1024] = "Hello";
    const char src2[1024] = "Helmlo!";

    for (int i=0; i < 1024; i++) {
        if (src1[i] == src2[i]) {
            continue;
        } else if (src1[i] < src2[i]) {
            cout << -1;  
        } else if (src1[i] > src2[i]) {
            cout << 1;
        }
    }

    return 0;
}
