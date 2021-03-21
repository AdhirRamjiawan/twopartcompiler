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
