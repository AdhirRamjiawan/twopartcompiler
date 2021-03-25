
#include "FunctionCall.h"

FunctionCall::FunctionCall()
{
    //ctor
    this->Parameters = vector<Parameter>();
}

FunctionCall::~FunctionCall()
{
    //dtor
}

vector<LanguageToken> FunctionCall::GetLanguageTokens()
{
    vector<LanguageToken> tokens;

    tokens.push_back(LanguageToken(LanguageTokenType::Call, this->FunctionName));

    for (auto param : this->Parameters)
    {
        tokens.push_back(LanguageToken(LanguageTokenType::Param, param.Value));

        if (param.IsLiteral)
        {
            tokens.push_back(LanguageToken(LanguageTokenType::Literal, param.Value));
        }
        else
        {
            tokens.push_back(LanguageToken(LanguageTokenType::Identifier, param.Value));
        }
    }

    return tokens;
}
