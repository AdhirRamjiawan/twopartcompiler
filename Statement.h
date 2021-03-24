#ifndef STATEMENT_H
#define STATEMENT_H

#include <vector>

#include "LanguageToken.h"

class Statement
{
    public:
        Statement();
        ~Statement();
        virtual vector<LanguageToken> GetLanguageTokens();
    protected:

    private:
};

#endif // STATEMENT_H
