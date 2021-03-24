#ifndef FUNCTIONCALL_H
#define FUNCTIONCALL_H

#include <vector>

#include "Parameter.h"
#include "Statement.h"

class FunctionCall : public Statement
{
    public:
        FunctionCall();
        virtual ~FunctionCall();
        vector<Parameter> Parameters;
        string FunctionName;
        vector<LanguageToken> GetLanguageTokens();

    protected:

    private:
};

#endif // FUNCTIONCALL_H
