#ifndef LEXER_H
#define LEXER_H


#include <list>
#include <string>

#include "Language.h"
#include "LanguageToken.h"

using namespace std;


class Lexer
{
    public:
        Lexer();
        virtual ~Lexer();
        list<LanguageToken> ReadSource(string source);

    protected:

    private:
        string GetFirstPart(string line);
        string GetSecondPart(string line);
        LanguageToken* CreateToken(string line);
        LanguageTokenType GetTokenType(string strToken);
};

#endif // LEXER_H