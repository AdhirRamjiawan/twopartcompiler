#ifndef CODEGENERATOR_H
#define CODEGENERATOR_H

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <list>

#include "Symbol.h"

using namespace std;

class CodeGenerator
{
    public:
        const string CODE_PLACEHOLDER = "<<CODE_PLACEHOLDER>>";
        CodeGenerator(list<string> *sourceLines);
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
        list<string> *SourceLines;
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
