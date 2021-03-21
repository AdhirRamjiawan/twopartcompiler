#include <iostream>
#include <string>
#include <list>

#include "CodeGenerator.h"
#include "Symbol.h"

using namespace std;

string GetFirstPart(string line);
string GetSecondPart(string line);

int main()
{
    string source = "value 108\nassign_to a\nprint a\nprint 32";
    list<string> lines;
    list<Symbol> symbolTable;
    CodeGenerator *codeGen = new CodeGenerator();

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
    string previousPart1 = "";
    string previousPart2 = "";
    SymbolType previousPart2SymbolType;

    for (auto line: lines)
    {
        string part1 = GetFirstPart(line);
        string part2 = GetSecondPart(line);

        if (part1 == "print")
        {
            // check if it's a literal or variable name
            if (regex_match(part2, regex(REGEX_VARIABLE)))
            {
                Symbol symbol = Symbol::GetSymbolFromTable(symbolTable, part2);

                if (symbol.Type != SymbolType::Null)
                {
                    codeGen->AddCout(symbol.StrValue);
                }
            }
            else
            {
                codeGen->AddCout(part2);
            }
        }
        else if (part1 == "assign_to")
        {
            symbolTable.push_back(Symbol(part2, previousPart2, previousPart2SymbolType));
        }
        else if (part1 == "value")
        {
            previousPart2SymbolType = Symbol::GetSymbolType(part2);
        }

        previousPart1 = part1;
        previousPart2 = part2;
    }

    codeGen->Build();

    return 0;
}

string GetFirstPart(string line)
{
    return line.substr(0, line.find(' '));
}

string GetSecondPart(string line)
{
    return line.substr(line.find(' ') +1, line.length());
}


