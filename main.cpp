#include <iostream>
#include <string>
#include <list>

#include "CodeGenerator.h"
#include "Parser.h"
#include "Lexer.h"
#include "LanguageToken.h"

using namespace std;

list<string> ParseSource(string source);

int main()
{
    string source = "value 108\nassign_to a\ncall print\nparam a\ncall print\nparam 32";

    // TODO: create compiler pipeline to manage and run compiler phases
    Lexer *lexer = new Lexer();
    Parser *parser = new Parser();
    list<LanguageToken> tokens = lexer->ReadSource(source);
    CodeGenerator *codeGen = new CodeGenerator(&tokens);


    for (auto token : tokens)
    {
        cout << (int)token.Type << ", " << token.Value << endl;
    }

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
