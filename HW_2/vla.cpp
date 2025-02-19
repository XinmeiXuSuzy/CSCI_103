// // vla-search.cpp
// #include <iostream>
// #include <cstdio>
// #include <cassert>
// #include <unistd.h>
// #include <cstring>
// #include "strcmp.h"
// using namespace std;


// // Prototypes. we'll define these below.
// char* getNewInputString();
// char printPromptAndGetCommand(const char* str, int start, int end);
// void shiftUp(char* str, int size, int from, int to);
// // Add prototypes for any functions you'd like to create.
// char* copyToClipboard(char* str, int start, int end);

// /**
//  * @brief reads characters one at a time and adds it to a character array
//  *        (C-string) allocating larger arrays as the input grows and
//  *        returning the pointer to the final null-terminated character 
//  *        array (C-String) 
//  * 
//  * @return char* pointer to the final null-terminated character 
//  *                array (C-String)
//  */
// char* getNewInputString()
// {
//     char *str = nullptr;

//     // Add initial declarations and code here
//     int capacity = 10;
//     int length = 0;
//     str = new char[capacity];
//     str[0] = '\0';

//     // Get the first char
//     char c;
//     c = cin.get();
//     while(c != '.') {
//         // Process c (including growing the array if necessary)

//         //----------- Add code here ------------
//         if (length + 1 > capacity) {
//             capacity = capacity * 2;
//             char* newStr = new char[capacity];
//             strcpy(newStr, str);
//             delete str;
//             str = newStr;
//         }

//         // -------------------------------------
//         // Get next input
//         str[length] = c; 
//         str[length + 1] = '\0';
//         length++; 
//         c = cin.get();
//     }

//     // ---------- Any final wrapup code here ------------


//     // Uncomment and use for a debugging print statement
//     // cout << "getNewInputString() returning: " << str << endl;
//     return str;
// }

// /**
//  * @brief Prints the input string (with selected text in a red background)
//  *        and returns the command character entered by the user.
//  * 
//  * @param str Source string
//  * @param start (Inclusive) start index of the selected text 
//  * @param end (Exclusive) end index of the selected text
//  * @return char next command typed in by the user
//  */
// char printPromptAndGetCommand(const char* str, int start, int end)
// {
//     char c;
//     int i;
//     const char* redBgrnd = "\033[1;41m";
//     const char* resetText = "\033[0;0m";

//     cout << "Current string:" << endl;
//     int len = strlen(str);
//     if(isatty(1)) { // use ANSI color codes?
//       for(i=0; i < len; i++) {
//           if(i == start) { cout << redBgrnd; }
//           if(start != -1 && i == end) { cout << resetText; }
//           cout << str[i];
//       }
//       if(start != -1 && end == len) { cout << resetText; }
//     }
//     else { // output to a file during testing, use '*' to bracket selection
//       for(i=0; i < len; i++) {
//           if(i == start) { cout << '*'; }
//           if(start != -1 && i == end) { cout << '*'; }
//           cout << str[i];
//       }
//       if(start != -1 && end == len) { cout << '*'; }
//     }
//     cout << endl;
//     cout << "Cmd: " << endl;
//     cin >> c;
//     return c;
// }

// // Optional challenge task to add clipboard copy/paste operations
// // Uncomment if you'd like to implement this optional challenge
// // /**
// //  * @brief copies substring from str to a new string and returns it
// //  * 
// //  * @param str Source string
// //  * @param start (Inclusive) index of start of substring to be copied
// //  * @param end (Exclusive) index of the end of the substring to be copied
// //  * @return char* pointer to a new string with the contents of str 
// //  *               between [start, end)
// //  */
// // char* copyToClipboard(char* str, int start, int end)
// // {
// //     // Your code here. No use of library functions


// // }

// /**
//  * @brief shift a substring of the characters in str up (forward) 
//  *        to a given location (overwriting the characters in between)
//  * 
//  * Example:  shiftUp("abcde", 5, 3, 1) should change str to "ade"
//  *
//  * @pre (precondition) from >= to and from < size
//  * @param str Source string
//  * @param size Size of the source string
//  * @param from Starting index of the substring to shift up 
//  * @param to Starting index of where the substring should move to
//  *
//  * 
//  */
// void shiftUp(char* str, int size, int from, int to)
// {
//     // Leave this lines - feel free to search: "C assert function" 
//     // to find out more about what these functions do
//     assert(to <= from);
//     assert(from < size);

//     // Your code here
//     int shiftAmount = from - to;

//     // Shift characters left
//     for (int i = to; i < size - shiftAmount; i++) {
//         str[i] = str[i + shiftAmount];
//     }

//     // Null-terminate the remaining part of the string
//     for (int i = size - shiftAmount; i < size; i++) {
//         str[i] = '\0';
//     }  
// }


// int main(int argc, char* argv[])
// {
//     const int FIND_SIZE = 41;
//     char term[FIND_SIZE];
//     //------------- Do not modify the code in main() above this --------------

//     // First get the body of text to process or search
//     char* str = getNewInputString();
//     int inputSize = strlen(str);
//     int currSize = inputSize;
    
//     char cmd;
//     int start = -1, end = -1, at = -1;

//     // Declare any additional variables that are needed


//     // Start the interactive part of the program
//     cmd = printPromptAndGetCommand(str, start, end);
//     while(cmd != 'q') {
//         if(cmd == 's'){
//             cin >> start >> end;
//             // Your code for select error checking
//             if (start < 0 or end >= currSize) {
//                 cout << "Invalid selection" << endl;
//                 start = -1;
//             }
//         }
//         else if(cmd == 'x') {
//             if(start == -1) {
//                 cout << "No selection." << endl;
//             }
//             else {
//                 // Your code here -- use shiftUp() to implement 
//                 // this operation
//                 shiftUp(str, currSize, end, start);
//                 start = -1;
//             }
//         }
//         else if(cmd == 'f') {
//             cin >> term;
//             int cnt = 0;
//             // Your code here -- use functions we've asked 
//             //   you to write where applicable
            
//             int target_len = strlen(term);
//             int match_count;
//             for (int i = 0; i <= strlen(str) - target_len; i++) {
//                 match_count = 0;
//                 for (int j = 0; j < target_len; j++) {
//                     if (str[i+j] == term[j]) {
//                         match_count++;
//                     }
//                 }
//                 if (match_count == target_len) {
//                     cnt++;
//                 }
//             }

//             // Do not alter
//             cout << cnt << " times" << endl;
//         }
//         else if(cmd == 'c') {
//             if(start == -1) {
//                 cout << "No selection." << endl;
//             }
//             else {
//                 // Your code here -- use functions we've asked 
//                 //   you to write where applicable


//             }
//         }
//         else if(cmd == 'v') {
//             cin >> at;
//             if(at >= currSize) {
//                 cout << "Invalid paste location" << endl;
//             }
//             else {
//                 // you are welcome to replace the old str array with a new one that
//                 // is large enough for the updated contents (with the pasted material)
//                 // You may use strcpy() or strcat() as desired (but no other cstring
//                 // library functions).


//             }
//         }
//         cmd = printPromptAndGetCommand(str, start, end);
//     }
//     // Add any final code that is necessary


//     return 0;
// }



// vla-search.cpp
#include <iostream>
#include <cstdio>
#include <cassert>
#include <unistd.h>
#include <cstring>
using namespace std;

// Prototypes
char* getNewInputString();
char printPromptAndGetCommand(const char* str, int start, int end);
void shiftUp(char* str, int size, int from, int to);
char* copyToClipboard(const char* str, int start, int end);


char* getNewInputString() {
    int capacity = 10;
    int length = 0;
    char* str = new char[capacity];
    str[0] = '\0';

    char c;
    c = cin.get();
    while (c != '.') {
        if (length + 1 >= capacity) { 
            capacity *= 2;
            char* newStr = new char[capacity];
            strcpy(newStr, str);
            delete[] str;
            str = newStr;
        }

        str[length++] = c;
        str[length] = '\0';
        c = cin.get();
    }
    return str;
}


char printPromptAndGetCommand(const char* str, int start, int end) {
    char c;
    const char* redBgrnd = "\033[1;41m";
    const char* resetText = "\033[0;0m";

    cout << "Current string:" << endl;
    int len = strlen(str);

    if (isatty(1)) { 
        for (int i = 0; i < len; i++) {
            if (i == start) cout << redBgrnd;
            if (start != -1 && i == end) cout << resetText;
            cout << str[i];
        }
        if (start != -1 && end == len) cout << resetText;
    } else { 
        for (int i = 0; i < len; i++) {
            if (i == start) cout << '*';
            if (start != -1 && i == end) cout << '*';
            cout << str[i];
        }
        if (start != -1 && end == len) cout << '*';
    }

    cout << "\nCmd: ";
    cin >> c;
    return c;
}


char* copyToClipboard(const char* str, int start, int end) {
    assert(start >= 0 && end >= start);

    int len = end - start;
    char* clipboard = new char[len + 1];
    for (int i = 0; i < len; i++) {
        clipboard[i] = str[start + i];
    }
    clipboard[len] = '\0';
    return clipboard;
}


char* pasteFromClipboard(char* str, const char* clipboard, int& currSize, int at) {
    int clipLen = strlen(clipboard);
    int strLen = strlen(str);

    if (strLen + clipLen >= currSize) { 
        currSize = (strLen + clipLen) * 2;
        char* newStr = new char[currSize];
        strcpy(newStr, str);
        delete[] str;
        str = newStr;
    }

    for (int i = strLen; i >= at; i--) {
        str[i + clipLen] = str[i];
    }

    for (int i = 0; i < clipLen; i++) {
        str[at + i] = clipboard[i];
    }

    return str;
}

void shiftUp(char* str, int size, int from, int to) {
    assert(to <= from);
    assert(from < size);

    int shiftAmount = from - to;
    for (int i = to; i < size - shiftAmount; i++) {
        str[i] = str[i + shiftAmount];
    }
    for (int i = size - shiftAmount; i < size; i++) {
        str[i] = '\0';
    }
}

int main() {
    const int FIND_SIZE = 41;
    char term[FIND_SIZE];

    char* str = getNewInputString();
    int currSize = strlen(str);
    char* clipboard = nullptr;
    
    char cmd;
    int start = -1, end = -1, at = -1;

    cmd = printPromptAndGetCommand(str, start, end);
    while (cmd != 'q') {
        if (cmd == 's') {
            cin >> start >> end;
            if (start < 0 || end >= currSize || start >= end) {
                cout << "Invalid selection" << endl;
                start = -1;
                end = -1;
            }
        } else if (cmd == 'x') {
            if (start == -1) {
                cout << "No selection." << endl;
            } else {
                shiftUp(str, currSize, end, start);
                start = -1;
            }
        } else if (cmd == 'f') {
            cin >> term;
            int cnt = 0;
            int targetLen = strlen(term);
            for (int i = 0; i <= currSize - targetLen; i++) {
                if (strncmp(&str[i], term, targetLen) == 0) cnt++;
            }
            cout << cnt << " times" << endl;
        } else if (cmd == 'c') {
            if (start == -1) {
                cout << "No selection." << endl;
            } else {
                delete[] clipboard; 
                clipboard = copyToClipboard(str, start, end);
            }
        } else if (cmd == 'v') {
            cin >> at;
            if (clipboard == nullptr) {
                cout << "Clipboard is empty." << endl;
            } else if (at < 0 || at > currSize) {
                cout << "Invalid paste location" << endl;
            } else {
                str = pasteFromClipboard(str, clipboard, currSize, at);
            }
        }
        cmd = printPromptAndGetCommand(str, start, end);
    }

    // Cleanup
    delete[] str;
    delete[] clipboard;
    
    return 0;
}
