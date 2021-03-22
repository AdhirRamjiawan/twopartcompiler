#include "Parameter.h"

Parameter::Parameter()
{
    //ctor
}

Parameter::Parameter(string name, string value, LanguageDataTypes type, bool isLiteral)
{
    this->Name = name;
    this->Value = value;
    this->Type = type;
    this->IsLiteral = isLiteral;
}

Parameter::~Parameter()
{
    //dtor
}
