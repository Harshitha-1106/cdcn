
#include<iostream>
#include<string>
using namespace std;

int main() {
    string a;

    cout << "Enter expression (a=b+c*d): ";
    cin >> a;

    int eq = a.find('=');

    string lhs = a.substr(0, eq);
    string exp = a.substr(eq + 1);

    int pos = exp.find('*');

    if(pos != string::npos) {
        string t1 = exp.substr(pos - 1, 1);
        string t2 = exp.substr(pos + 1, 1);

        cout << "t1 = " << t1 << " * " << t2 << endl;

        exp.replace(pos - 1, 3, "t1");

        cout << "t2 = " << exp << endl;
        cout << lhs << " = t2" << endl;
    }

    return 0;
}
