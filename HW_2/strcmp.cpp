#include "strcmp.h"

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
     // Note: You can ignore the `const` keywords above. 
     // They are necessary for certain kinds of calls to this function
     // and we will learn more about this soon!
     // ---------  Add your code here  ------------
 
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