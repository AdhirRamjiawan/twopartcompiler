#include <iostream>
#include <string>
#include <vector>

#include "CodeGenerator.h"
#include "Parser.h"
#include "Lexer.h"
#include "LanguageToken.h"
#include "CodeTree.h"

using namespace std;

vector<string> ParseSource(string source);

int main()
{
    //string source = "value 108\nassign_to a\ncall print\nparam a\ncall print\nparam 32";
    string source = "call print\nparam 32";

    // TODO: create compiler pipeline to manage and run compiler phases
    Lexer *lexer = new Lexer();
    vector<LanguageToken> tokens = lexer->ReadSource(source);
    Parser *parser = new Parser(&tokens);
    CodeTree *codeTree = parser->BuildCodeTree();
    CodeGenerator *codeGen = new CodeGenerator(codeTree);


    /*for (auto token : tokens)
    {
        cout << (int)token.Type << ", " << token.Value << endl;
    }*/

    // output lines to console, TODO: make this debug method
    #ifdef DEBUG
    for (auto line: lines)
    {
        cout << line << endl;
    }
    #endif

    // TODO: create symbol table to validate variables and method names.

    //codeGen->GenerateCode();
    //codeGen->CompileCode();

    return 0;
}
