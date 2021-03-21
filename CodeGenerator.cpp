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
    this->UserCode += "std::cout << " + codeLine + " << std::endl;\n";
    return this;
}

void CodeGenerator::Build()
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
