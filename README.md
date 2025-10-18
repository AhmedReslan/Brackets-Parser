=============================
   Bracket Parser (C++)
=============================

A simple and efficient C++ program that checks whether a given string has
balanced and properly nested brackets. Built using Code::Blocks, this project
demonstrates stack usage, map lookups, and clean C++ structure.


=============================
 Features
=============================
- Supports three types of brackets: (), {}, []
- Ignores non-bracket characters like letters or numbers
- Prints true or false for each input line
- Runs continuously for multiple inputs
- Clean and easy-to-read logic


=============================
 Example
=============================
Input:
({[]})
a+(b*c)
([)]
((])
exit

Output:
true
true
false
false

Typing "exit" ends the program.


=============================
 How It Works
=============================
The program uses:
- std::stack         → stores opening brackets
- std::map           → maps closing to opening brackets
- std::unordered_set → identifies valid bracket characters

When a closing bracket is found, it checks if it matches the latest opened one.
If all brackets are properly matched, the result is true.


=============================
 Code Overview
=============================
#include <iostream>
#include <map>
#include <stack>
#include <unordered_set>
using namespace std;

map<char, char> mp;
unordered_set<char> brackets = {'(', ')', '{', '}', '[', ']'};

bool valid_parenthes(const string& input) {
    stack<char> open;
    for (const char &x : input) {
        if (brackets.find(x) != brackets.end()) {
            if (mp.find(x) == mp.end()) {
                open.push(x);
            } else {
                if (open.empty() || open.top() != mp[x])
                    return false;
                open.pop();
            }
        }
    }
    return open.empty();
}

int main() {
    mp[')'] = '(';
    mp['}'] = '{';
    mp[']'] = '[';

    string s;
    while (true) {
        getline(cin, s);
        if (s == "exit") break;
        cout << boolalpha << valid_parenthes(s) << endl;
    }
    return 0;
}


=============================
 How to Build and Run (Code::Blocks)
=============================
1. Open Code::Blocks.
2. Create a new "Console Application" → choose C++.
3. Replace the contents of main.cpp with the code above.
4. Make sure your compiler uses C++17:
   - Go to Project → Build Options → Compiler settings → Other options
   - Add: -std=c++17
5. Click "Build and Run" or press F9.
6. Type your expressions in the console.


=============================
 Recommended Folder Layout
=============================
BracketParser/
├── src/
│   └── main.cpp
├── README.txt
├── bin/
│   └── Debug/
│   └── Release/
└── obj/
    └── Debug/
    └── Release/


=============================
 Possible Improvements
=============================
- Add support for < > angle brackets
- Highlight position of mismatch
- Add colored console output (true → green, false → red)
- Split logic into .h and .cpp files
- Add automated test cases


=============================
 Author
=============================
Ahmed Gamal
Embedded Software Engineer @ SwiftAct
Cairo, Egypt
Passionate about clean embedded C/C++ design and problem solving.
