#include "CodeGenerator.h"
#include "Language.h"
#include "LanguageToken.h"
#include "FunctionCall.h"
#include "Statement.h"

CodeGenerator::CodeGenerator(CodeTree *codeTree)
{
    this->Tree = codeTree;
}

CodeGenerator::~CodeGenerator()
{
    delete this->Tree;
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
    for (auto &codeBlock: this->Tree->CodeBlocks)
    {
        cout << "size of statements " << codeBlock.Statements.size() << endl;
        vector<Statement*>::iterator statementIterator = codeBlock.Statements.begin();

        //for (auto &statement: codeBlock.Statements)
        for (; statementIterator < codeBlock.Statements.end(); )
        {
            Statement *statement = *statementIterator;

            if (statement->Type == StatementType::FunctionCall)
            {
                FunctionCall *functionCall = dynamic_cast<FunctionCall*>(statement);

                cout << "function call => " << (*functionCall).FunctionName << endl;

                if (functionCall->FunctionName == "print")
                {

                }

                cout << "parameter count " << functionCall->Parameters.size() << endl;

                for (auto &parameter : functionCall->Parameters)
                {
                    cout << "parameter: " << parameter->Name << ", type: " << (int)parameter->Type << ", value: " << parameter->Value << ", isLiteral " << parameter->IsLiteral << endl;
                }
            }

            statementIterator++;
        }
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
