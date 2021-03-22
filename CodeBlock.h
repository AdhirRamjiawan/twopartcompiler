#ifndef CODEBLOCK_H
#define CODEBLOCK_H

#include <vector>
#include "Statement.h"

class CodeBlock
{
    public:
        CodeBlock();
        virtual ~CodeBlock();
        vector<Statement> Statements;

    protected:

    private:
};

#endif // CODEBLOCK_H
