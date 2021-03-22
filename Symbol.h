#ifndef SYMBOL_H
#define SYMBOL_H

#include <regex>
#include <string>
#include <list>

using namespace std;

enum class SymbolType
{
    Int = 0,
    String = 1,
    Float = 2,
    Bool = 3,
    Variable = 4,
    Method = 5,
    Null = 9999
};

const string REGEX_VARIABLE = "[a-zA-Z]+([a-zA-Z0-9])*";
const string REGEX_BOOLEAN = "false | true";
const string REGEX_INTEGER = "[0-9]+";
const string REGEX_STRING = "\"(.)+\"";
const string REGEX_FLOAT = "[0-9]+\\.[0-9]+";

class Symbol
{
    public:
        string Name;
        string StrValue;
        SymbolType Type;
        Symbol();
        Symbol(string name, string strValue, SymbolType type);
        virtual ~Symbol();
        template <typename T>
        T GetTypedValue();
        static SymbolType GetSymbolType(string part);
        static Symbol GetSymbolFromTable(list<Symbol> symbolTable, string symbolName);

    protected:

    private:
};

#endif // SYMBOL_H
