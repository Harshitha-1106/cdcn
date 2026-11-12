#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    
    cout << "Enter string: ";
    cin >> s;

    int i = 0;

    // S -> AB
    // A -> a
    if (s[i] == 'a') {
        i++;
    }
    else {
        cout << "String Rejected";
        return 0;
    }

    // B -> bB | b
    if (s[i] == 'b') {
        while (s[i] == 'b') {
            i++;
        }
    }
    else {
        cout << "String Rejected";
        return 0;
    }

    if (i == s.length()) {
        cout << "String Accepted";
    }
    else {
        cout << "String Rejected";
    }

    return 0;
}