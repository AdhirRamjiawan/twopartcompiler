#include <iostream>
#include <string>
#include <list>
#include <regex>

#include "CodeGenerator.h"

using namespace std;

int main()
{
    string source = "value 1\nassign_to a\nprint a\nprint 32";
    list<string> lines;
    CodeGenerator *codeGen = new CodeGenerator();

    int lastKnownPosition = 0;

    // split source into separate lines
    for (int i = 0; i < source.length(); i++)
    {
        if (source[i] == '\n')
        {
            lines.push_back(source.substr(lastKnownPosition , i - lastKnownPosition));
            lastKnownPosition = i + 1;
        }
    }

    // get the last line
    string lastLine = source.substr(lastKnownPosition , source.length() - lastKnownPosition);
    if (lastLine != " " || lastLine != "\n")
    {
        lines.push_back(lastLine);
    }

    // output lines to console, TODO: make this debug method
    #ifdef DEBUG
    for (auto line: lines)
    {
        cout << line << endl;
    }
    #endif

    // TODO: create symbol table to validate variables and method names.

    // iterate through lines and execute code top to bottom.
    // this needs to change to code generation.
    for (auto line: lines)
    {
        string part1 = line.substr(0, line.find(' '));
        string part2 = line.substr(line.find(' ') +1, line.length());

        if (part1 == "print")
        {
            // check if it's a literal or variable name
            if (regex_match(part2, regex("[a-zA-Z]+([a-zA-Z0-9])?")))
            {
                cout << "printing out a variable" << endl;
            }
            else
            {
                //cout << part2;
                codeGen->Add("cout << " + part2);
            }
        }
    }

    cout << codeGen->Build() << endl;

    return 0;
}
