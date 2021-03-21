#include "CodeGenerator.h"

CodeGenerator::CodeGenerator()
{
    //ctor
}

CodeGenerator::~CodeGenerator()
{
    //dtor
}


CodeGenerator *CodeGenerator::Add(string codeLine)
{
    this->UserCode += codeLine + "\n";
    return this;
}

CodeGenerator *CodeGenerator::AddCout(string codeLine)
{
    this->UserCode += "cout << " + codeLine + ";\n";
    return this;
}

string CodeGenerator::Build()
{
    int placeholderIndex = this->CppCodeFile.find(this->CODE_PLACEHOLDER);
    string userCode = this->UserCode;
    string cppCode = this->CppCodeFile;
    auto builtCode = cppCode.replace(placeholderIndex, this->CODE_PLACEHOLDER.length(), userCode);

    return builtCode;
}
