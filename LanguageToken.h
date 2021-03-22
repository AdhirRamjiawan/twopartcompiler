#ifndef LANGUAGETOKEN_H
#define LANGUAGETOKEN_H

#include <string>

using namespace std;

enum class LanguageTokenType
{
    Value = 0,
    AssignTo = 1,
    Call = 2,
    Param = 3,
    Comment = 4,
    Add = 5,
    Sub = 6,
    Mul = 7,
    Div = 8,
    Pow = 9,
    Root = 10,
    Include = 11,
    Print = 12,
    Null = 9999
};

class LanguageToken
{
    public:
        LanguageToken();
        LanguageToken(LanguageTokenType type, string value);
        virtual ~LanguageToken();
        LanguageTokenType Type;
        string Value;

    protected:

    private:
};

#endif // LANGUAGETOKEN_H
