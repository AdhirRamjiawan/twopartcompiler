#include "Parser.h"
#include "Symbol.h"
#include <iostream>

Parser::Parser(vector<LanguageToken> *tokens)
{
    this->Tokens = tokens;
}

Parser::~Parser()
{
    //dtor
}

CodeTree* Parser::BuildCodeTree()
{
    CodeTree *codeTree = new CodeTree();

    LanguageToken previousToken;
    SymbolType previousPart2SymbolType;
    vector<LanguageToken>::iterator tokenIterator = this->Tokens->begin();

    // move into the Parser class
    //for (auto token: *this->Tokens)
    while(tokenIterator < this->Tokens->end())
    {
        LanguageToken token = *tokenIterator;
        std::cout << "token: " << (int)token.Type << ", " << token.Value << std::endl;

        /*LanguageToken token = *tokenIterator;
        if (token.Type == LanguageTokenType::Call)
        {
            if (token.Value == "print")
            {

            }
            // check if it's a literal or variable name
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
            }
        }
        else if (token.Type == LanguageTokenType::AssignTo)
        {
            this->SymbolTable.push_back(Symbol(token.Value, previousToken.Value, previousPart2SymbolType));
        }
        else if (token.Type == LanguageTokenType::Value)
        {
            previousPart2SymbolType = Symbol::GetSymbolType(token.Value);
        }

        previousToken = token;*/
        tokenIterator++;
    }

    return codeTree;
}

