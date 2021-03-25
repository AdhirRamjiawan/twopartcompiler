#include "Parser.h"
#include "Symbol.h"
#include "FunctionCall.h"

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

        if (token.Type == LanguageTokenType::Call)
        {
            CodeBlock codeBlock;

            tokenIterator++;
            if (tokenIterator != this->Tokens->end())
            {
                token = *tokenIterator;
                FunctionCall *functionCall = new FunctionCall();
                functionCall->Type = StatementType::FunctionCall;
                functionCall->FunctionName = token.Value;

                std::cout << "token: " << (int)token.Type << ", " << token.Value << std::endl;

                tokenIterator++;
                while (tokenIterator < this->Tokens->end())
                {
                    token = *tokenIterator;

                    std::cout << "token: " << (int)token.Type << ", " << token.Value << std::endl;

                    if (token.Type != LanguageTokenType::Param)
                    {
                        break;
                    }

                    tokenIterator++;
                    token = *tokenIterator;

                    Parameter *parameter = new Parameter();
                    parameter->Name = token.Value;
                    parameter->Value = token.Value;
                    parameter->IsLiteral = (token.Type == LanguageTokenType::Int ||
                                           token.Type == LanguageTokenType::Bool ||
                                           token.Type == LanguageTokenType::Float ||
                                           token.Type == LanguageTokenType::String);

                    switch (token.Type)
                    {
                    case LanguageTokenType::Int:
                        parameter->Type = LanguageDataTypes::Int;
                        break;
                    case LanguageTokenType::Bool:
                        parameter->Type = LanguageDataTypes::Bool;
                        break;
                    case LanguageTokenType::Float:
                        parameter->Type = LanguageDataTypes::Float;
                        break;
                    case LanguageTokenType::String:
                        parameter->Type = LanguageDataTypes::String;
                        break;
                    }

                   functionCall->Parameters.push_back(parameter);
                   tokenIterator++;
                }
                codeBlock.Statements.push_back(functionCall);
                codeTree->CodeBlocks.push_back(codeBlock);
            }
        }

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

