#include <iostream>
#include <unordered_map>
#include <stack>
#include <unordered_set>
using namespace std;
// =================== Configuration ===================
unordered_map<char, char> mp = {
    {')', '('},
    {'}', '{'},
    {']', '['}
};
unordered_set<char> brackets = {'(',')','[',']','{','}'};
// =================== Logic ===================
bool valid_parenthes(const string& input) {
    stack<char> open;
    if (input.empty()) return true; // Empty string is valid
    for(const char &x : input)
    {
        if(brackets.find(x) != brackets.end()){
           if(mp.find(x) == mp.end()){
                // Openning bracket
                open.push(x);
            }
            else{
                if(open.empty() || open.top() != mp[x]) return false;
                open.pop();
            }
        }
    }
    return open.empty();
}

int main() {
    string s;
    while(1)
    {
        getline(cin,s);
        if (s == "exit") break;
        cout << boolalpha << valid_parenthes(s) << endl;
    }

	return 0;
}
