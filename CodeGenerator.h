#ifndef CODEGENERATOR_H
#define CODEGENERATOR_H

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <vector>

#include "Symbol.h"
#include "CodeTree.h"

using namespace std;

class CodeGenerator
{
    public:
        const string CODE_PLACEHOLDER = "<<CODE_PLACEHOLDER>>";
        CodeGenerator(CodeTree *codeTree);
        virtual ~CodeGenerator();
        CodeGenerator *Add(string codeLine);
        CodeGenerator *AddCout(string codeLine);
        void GenerateCode();
        void CompileCode();

    protected:

    private:
        vector<Symbol> SymbolTable;
        string GetFirstPart(string line);
        string GetSecondPart(string line);
        CodeTree *Tree;
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
