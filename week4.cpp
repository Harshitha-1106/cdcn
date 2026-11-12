#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    int i = 0;

    cout << "Enter string: ";
    cin >> s;

    s += '$';

    // E -> T E'
    // T -> a
    if (s[i] == 'a') {
        i++;
    }
    else {
        cout << "Rejected";
        return 0;
    }

    // E' -> + T E' | epsilon
    while (s[i] == '+') {
        i++;

        // T -> a
        if (s[i] == 'a') {
            i++;
        }
        else {
            cout << "Rejected";
            return 0;
        }
    }

    if (s[i] == '$') {
        cout << "Accepted";
    }
    else {
        cout << "Rejected";
    }

    return 0;
}