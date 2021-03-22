#ifndef PARSER_H
#define PARSER_H

#include <vector>
#include <string>

#include "CodeTree.h"

using namespace std;

class Parser
{
    public:
        Parser(vector<LanguageToken> *tokens);
        virtual ~Parser();
        CodeTree* BuildCodeTree();

    protected:

    private:
        vector<LanguageTokens> *Tokens;
};

#endif // PARSER_H
