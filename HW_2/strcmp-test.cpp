// strcmp-test.cpp
// Test an implementation of mystrcmp()
#include <iostream>
#include "strcmp.h"

using namespace std;

int main()
{
  //------------- Do not modify this code --------------
  char s1[1024], s2[1024];
  cin >> s1 >> s2;
  cout << mystrcmp(s1, s2);
  return 0;
}