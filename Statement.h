#ifndef STATEMENT_H
#define STATEMENT_H

#include "LanguageToken.h"

class Statement
{
    public:
        virtual vector<LanguageToken> GetLanguageTokens();
    protected:

    private:
};

#endif // STATEMENT_H
