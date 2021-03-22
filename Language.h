#ifndef LANGUAGE_H_INCLUDED
#define LANGUAGE_H_INCLUDED

#include <string>
#include <regex>

using namespace std;

const string REGEX_LANGUAGE_VALUE     = "value";
const string REGEX_LANGUAGE_ASSIGN_TO = "assign_to";
const string REGEX_LANGUAGE_CALL      = "call";
const string REGEX_LANGUAGE_PARAM     = "param";
const string REGEX_LANGUAGE_COMMENT   = "(\\s)*//(.)*";
const string REGEX_LANGUAGE_ADD       = "add";
const string REGEX_LANGUAGE_SUB       = "sub";
const string REGEX_LANGUAGE_MUL       = "mul";
const string REGEX_LANGUAGE_DIV       = "div";
const string REGEX_LANGUAGE_POW       = "pow";
const string REGEX_LANGUAGE_ROOT      = "root";
const string REGEX_LANGUAGE_INCLUDE   = "include";

#endif // LANGUAGE_H_INCLUDED
