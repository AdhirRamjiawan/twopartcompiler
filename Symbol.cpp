#include "Symbol.h"

Symbol::Symbol()
{
    //ctor
}

Symbol::Symbol(string name, string strValue, SymbolType type)
{
    this->Name = name;
    this->StrValue = strValue;
    this->Type = type;
}

Symbol::~Symbol()
{
    //dtor
}

template <typename T>
T Symbol::GetTypedValue()
{
    return (T)*(this->StrValue());
}

Symbol Symbol::GetSymbolFromTable(list<Symbol> symbolTable, string symbolName)
{
    for (auto symbol : symbolTable)
    {
        if (symbol.Name == symbolName)
        {
            return symbol;
        }
    }
    return Symbol(NULL, NULL, SymbolType::Null);
}

SymbolType Symbol::GetSymbolType(string part)
{
    if (regex_match(part, regex(REGEX_VARIABLE)))
    {
        return SymbolType::Variable;
    }
    else if (regex_match(part, regex(REGEX_BOOLEAN)))
    {
        return SymbolType::Bool;
    }
    else if (regex_match(part, regex(REGEX_STRING)))
    {
        return SymbolType::String;
    }
    else if (regex_match(part, regex(REGEX_INTEGER)))
    {
        return SymbolType::Int;
    }
    else if (regex_match(part, regex(REGEX_FLOAT)))
    {
        return SymbolType::Float;
    }

    return SymbolType::Null;
}
