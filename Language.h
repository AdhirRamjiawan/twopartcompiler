#ifndef LANGUAGE_H_INCLUDED
#define LANGUAGE_H_INCLUDED

#include <string>
#include <regex>

using namespace std;

const string REGEX_LANGUAGE_VALUE       = "value";
const string REGEX_LANGUAGE_ASSIGN_TO   = "assign_to";
const string REGEX_LANGUAGE_CALL        = "call";
const string REGEX_LANGUAGE_PARAM       = "param";
const string REGEX_LANGUAGE_COMMENT     = "(\\s)*//(.)*";
const string REGEX_LANGUAGE_ADD         = "add";
const string REGEX_LANGUAGE_SUB         = "sub";
const string REGEX_LANGUAGE_MUL         = "mul";
const string REGEX_LANGUAGE_DIV         = "div";
const string REGEX_LANGUAGE_POW         = "pow";
const string REGEX_LANGUAGE_ROOT        = "root";
const string REGEX_LANGUAGE_INCLUDE     = "include";
const string REGEX_LANGUAGE_IDENTIFIER  = "[a-zA-Z]+([a-zA-Z0-9])*";
const string REGEX_LANGUAGE_BOOLEAN     = "false | true";
const string REGEX_LANGUAGE_INTEGER     = "[0-9]+";
const string REGEX_LANGUAGE_STRING      = "\"(.)+\"";
const string REGEX_LANGUAGE_FLOAT       = "[0-9]+\\.[0-9]+";
const string REGEX_LANGUAGE_PRINT       = "print";

enum class LanguageDataTypes
{
    Int = 0,
    String = 1,
    Float = 2,
    Bool = 3
};

#endif // LANGUAGE_H_INCLUDED
