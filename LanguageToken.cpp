#include "LanguageToken.h"

LanguageToken::LanguageToken()
{
    //ctor
}

LanguageToken::LanguageToken(LanguageTokenType type, string value)
{
    this->Type = type;
    this->Value = value;
}

LanguageToken::~LanguageToken()
{
    //dtor
}
