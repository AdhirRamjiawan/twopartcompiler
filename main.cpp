#include <iostream>
#include <string>
#include <list>

#include "CodeGenerator.h"

using namespace std;

list<string> ParseSource(string source);

int main()
{
    string source = "value 108\nassign_to a\nprint a\nprint 32";
    list<string> lines = ParseSource(source);
    CodeGenerator *codeGen = new CodeGenerator(&lines);

    // output lines to console, TODO: make this debug method
    #ifdef DEBUG
    for (auto line: lines)
    {
        cout << line << endl;
    }
    #endif

    // TODO: create symbol table to validate variables and method names.

    codeGen->GenerateCode();
    codeGen->CompileCode();

    return 0;
}

list<string> ParseSource(string source)
{
    list<string> lines;
    int lastKnownPosition = 0;

    // split source into separate lines
    for (int i = 0; i < (int)source.length(); i++)
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

    return lines;
}

