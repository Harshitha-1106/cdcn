#include <iostream>
#include <string>
#include <cctype>
using namespace std;

bool isKeyword(string s)
{
    string keywords[] = {
        "int", "float", "char", "if", "else",
        "while", "for", "return"
    };

    for (string k : keywords)
    {
        if (s == k)
            return true;
    }

    return false;
}

int main()
{
    string input;

    cout << "Enter a line of code: ";
    getline(cin, input);

    for (int i = 0; i < input.length(); i++)
    {
        // Ignore spaces and tabs
        if (input[i] == ' ' || input[i] == '\t')
            continue;

        // Ignore single-line comments
        if (input[i] == '/' && i + 1 < input.length() && input[i + 1] == '/')
            break;

        // Identifier or keyword
        if (isalpha(input[i]) || input[i] == '_')
        {
            string word = "";

            while (i < input.length() &&
                   (isalnum(input[i]) || input[i] == '_'))
            {
                word += input[i];
                i++;
            }

            i--;

            if (isKeyword(word))
                cout << word << " -> KEYWORD\n";
            else
                cout << word << " -> IDENTIFIER\n";
        }

        // Number
        else if (isdigit(input[i]))
        {
            string num = "";

            while (i < input.length() && isdigit(input[i]))
            {
                num += input[i];
                i++;
            }

            i--;

            cout << num << " -> NUMBER\n";
        }

        // Operators
        else if (input[i] == '+' || input[i] == '-' ||
                 input[i] == '*' || input[i] == '=')
        {
            cout << input[i] << " -> OPERATOR\n";
        }

        // Symbols
        else if (input[i] == '(' || input[i] == ')' ||
                 input[i] == '{' || input[i] == '}' ||
                 input[i] == ';' || input[i] == ',')
        {
            cout << input[i] << " -> SYMBOL\n";
        }
    }

    return 0;
}