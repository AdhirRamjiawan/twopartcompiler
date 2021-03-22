#ifndef PARAMETER_H
#define PARAMETER_H

#include "Language.h"

using namespace std;

class Parameter
{
    public:
        Parameter();
        Parameter(string name, string value, LanguageDataTypes type, bool IsLiteral);
        virtual ~Parameter();
        string Name;
        string Value;
        LanguageDataTypes Type;
        bool IsLiteral;

    protected:

    private:
};

#endif // PARAMETER_H
