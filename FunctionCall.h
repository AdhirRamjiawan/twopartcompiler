#ifndef FUNCTIONCALL_H
#define FUNCTIONCALL_H

#include <vector>

class FunctionCall : public Statement
{
    public:
        FunctionCall();
        virtual ~FunctionCall();
        vector<Parameter> Parameters;
        string FunctionName;

    protected:

    private:
};

#endif // FUNCTIONCALL_H
