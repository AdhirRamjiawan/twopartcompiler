#include "CodeGenerator.h"

CodeGenerator::CodeGenerator(list<string> *sourceLines)
{
    this->SourceLines = sourceLines;
}

CodeGenerator::~CodeGenerator()
{
    delete this->SourceLines;
}


CodeGenerator *CodeGenerator::Add(string codeLine)
{
    this->UserCode += codeLine + "\n";
    return this;
}

CodeGenerator *CodeGenerator::AddCout(string codeLine)
{
    this->UserCode += "std::cout << " + codeLine + " << std::endl;\n";
    return this;
}

void CodeGenerator::GenerateCode()
{
    string previousPart1 = "";
    string previousPart2 = "";
    SymbolType previousPart2SymbolType;

    for (auto line: *this->SourceLines)
    {
        string part1 = GetFirstPart(line);
        string part2 = GetSecondPart(line);

        if (part1 == "print")
        {
            // check if it's a literal or variable name
            if (regex_match(part2, regex(REGEX_VARIABLE)))
            {
                Symbol symbol = Symbol::GetSymbolFromTable(this->SymbolTable, part2);

                if (symbol.Type != SymbolType::Null)
                {
                    this->AddCout(symbol.StrValue);
                }
            }
            else
            {
                this->AddCout(part2);
            }
        }
        else if (part1 == "assign_to")
        {
            this->SymbolTable.push_back(Symbol(part2, previousPart2, previousPart2SymbolType));
        }
        else if (part1 == "value")
        {
            previousPart2SymbolType = Symbol::GetSymbolType(part2);
        }

        previousPart1 = part1;
        previousPart2 = part2;
    }
}

void CodeGenerator::CompileCode()
{
    string fileName = "tmpCodeFile.cpp";
    ofstream codeFile;
    codeFile.open(fileName);

    int placeholderIndex = this->CppCodeFile.find(this->CODE_PLACEHOLDER);
    string userCode = this->UserCode;
    string cppCode = this->CppCodeFile;
    auto builtCode = cppCode.replace(placeholderIndex, this->CODE_PLACEHOLDER.length(), userCode);

    codeFile << builtCode << endl;
    codeFile.close();

    string command = "g++ " + fileName;
    system(command.c_str());
    remove(fileName.c_str());
}

// these should actually be moved to a parser file.
string CodeGenerator::GetFirstPart(string line)
{
    return line.substr(0, line.find(' '));
}

string CodeGenerator::GetSecondPart(string line)
{
    return line.substr(line.find(' ') +1, line.length());
}
