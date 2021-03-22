#include "CodeGenerator.h"
#include "Language.h"
#include "LanguageToken.h"

CodeGenerator::CodeGenerator(list<LanguageToken> *tokens)
{
    this->Tokens = tokens;
}

CodeGenerator::~CodeGenerator()
{
    delete this->Tokens;
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
    LanguageToken previousToken;
    SymbolType previousPart2SymbolType;

    for (auto token: *this->Tokens)
    {
        if (token.Type == LanguageTokenType::Call)
        {
            if (token.Value == "print")
            {

            }
            /*// check if it's a literal or variable name
            if (regex_match(token.Value, regex(REGEX_VARIABLE)))
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
            }*/
        }
        else if (token.Type == LanguageTokenType::AssignTo)
        {
            this->SymbolTable.push_back(Symbol(token.Value, previousToken.Value, previousPart2SymbolType));
        }
        else if (token.Type == LanguageTokenType::Value)
        {
            previousPart2SymbolType = Symbol::GetSymbolType(token.Value);
        }

        previousToken = token;
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
