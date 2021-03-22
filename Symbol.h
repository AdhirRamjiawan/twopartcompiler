#ifndef SYMBOL_H
#define SYMBOL_H

#include <regex>
#include <string>
#include <vector>

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
        static Symbol GetSymbolFromTable(vector<Symbol> symbolTable, string symbolName);

    protected:

    private:
};

#endif // SYMBOL_H
