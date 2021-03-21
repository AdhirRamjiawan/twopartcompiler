#ifndef CODEGENERATOR_H
#define CODEGENERATOR_H

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

using namespace std;

class CodeGenerator
{
    public:
        const string CODE_PLACEHOLDER = "<<CODE_PLACEHOLDER>>";
        CodeGenerator();
        virtual ~CodeGenerator();
        CodeGenerator *Add(string codeLine);
        CodeGenerator *AddCout(string codeLine);
        void Build();

    protected:

    private:
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
