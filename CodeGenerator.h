#ifndef CODEGENERATOR_H
#define CODEGENERATOR_H

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <list>

#include "Symbol.h"
#include "LanguageToken.h"

using namespace std;

class CodeGenerator
{
    public:
        const string CODE_PLACEHOLDER = "<<CODE_PLACEHOLDER>>";
        CodeGenerator(list<LanguageToken> *tokens);
        virtual ~CodeGenerator();
        CodeGenerator *Add(string codeLine);
        CodeGenerator *AddCout(string codeLine);
        void GenerateCode();
        void CompileCode();

    protected:

    private:
        list<Symbol> SymbolTable;
        string GetFirstPart(string line);
        string GetSecondPart(string line);
        list<LanguageToken> *Tokens;
        string UserCode = "";
        const string CppCodeFile = R"(
            #include <iostream>
            int main()
            {
                <<CODE_PLACEHOLDER>>
                return 0;
            }
        )";
};

#endif // CODEGENERATOR_H
