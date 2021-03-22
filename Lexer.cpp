#include "Lexer.h"
#include "LanguageToken.h"

Lexer::Lexer()
{
    //ctor
}

Lexer::~Lexer()
{
    //dtor
}

vector<LanguageToken> Lexer::ReadSource(string source)
{
    vector<LanguageToken> tokens;
    int lastKnownPosition = 0;

    // split source into separate lines
    for (int i = 0; i < (int)source.length(); i++)
    {
        if (source[i] == '\n')
        {
            string line = source.substr(lastKnownPosition , i - lastKnownPosition);
            lastKnownPosition = i + 1;

            string firstPart = Lexer::GetFirstPart(line);
            string secondPart = Lexer::GetSecondPart(line);

            tokens.push_back(*CreateToken(firstPart));
            tokens.push_back(*CreateToken(secondPart));
        }
    }

    // get the last line
    string lastLine = source.substr(lastKnownPosition , source.length() - lastKnownPosition);
    if (lastLine != " " || lastLine != "\n")
    {
        string firstPart = Lexer::GetFirstPart(lastLine);
        string secondPart = Lexer::GetSecondPart(lastLine);

        tokens.push_back(*CreateToken(firstPart));
        tokens.push_back(*CreateToken(secondPart));
    }

    return tokens;
}

LanguageToken* Lexer::CreateToken(string part)
{
    LanguageTokenType type = Lexer::GetTokenType(part);
    LanguageToken *token = new LanguageToken(type, part);
    return token;
}

LanguageTokenType Lexer::GetTokenType(string strToken)
{
    if (regex_match(strToken, regex(REGEX_LANGUAGE_VALUE)))
    {
        return LanguageTokenType::Value;
    }
    else if (regex_match(strToken, regex(REGEX_LANGUAGE_ASSIGN_TO)))
    {
        return LanguageTokenType::AssignTo;
    }
    else if (regex_match(strToken, regex(REGEX_LANGUAGE_CALL)))
    {
        return LanguageTokenType::Call;
    }
    else if (regex_match(strToken, regex(REGEX_LANGUAGE_PARAM)))
    {
        return LanguageTokenType::Param;
    }
    else if (regex_match(strToken, regex(REGEX_LANGUAGE_COMMENT)))
    {
        return LanguageTokenType::Comment;
    }
    else if (regex_match(strToken, regex(REGEX_LANGUAGE_ADD)))
    {
        return LanguageTokenType::Add;
    }
    else if (regex_match(strToken, regex(REGEX_LANGUAGE_SUB)))
    {
        return LanguageTokenType::Sub;
    }
    else if (regex_match(strToken, regex(REGEX_LANGUAGE_MUL)))
    {
        return LanguageTokenType::Mul;
    }
    else if (regex_match(strToken, regex(REGEX_LANGUAGE_DIV)))
    {
        return LanguageTokenType::Div;
    }
    else if (regex_match(strToken, regex(REGEX_LANGUAGE_POW)))
    {
        return LanguageTokenType::Pow;
    }
    else if (regex_match(strToken, regex(REGEX_LANGUAGE_ROOT)))
    {
        return LanguageTokenType::Root;
    }
    else if (regex_match(strToken, regex(REGEX_LANGUAGE_INCLUDE)))
    {
        return LanguageTokenType::Include;
    }

    return LanguageTokenType::Null;
}

string Lexer::GetFirstPart(string line)
{
    return line.substr(0, line.find(' '));
}

string Lexer::GetSecondPart(string line)
{
    return line.substr(line.find(' ') +1, line.length());
}
