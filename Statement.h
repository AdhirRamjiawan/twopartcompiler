#ifndef STATEMENT_H
#define STATEMENT_H

#include <vector>

#include "LanguageToken.h"

enum class StatementType
{
    FunctionCall = 0
};

class Statement
{
    public:
        virtual ~Statement();
        virtual vector<LanguageToken> GetLanguageTokens();
        StatementType Type;
    protected:

    private:
};

#endif // STATEMENT_H
