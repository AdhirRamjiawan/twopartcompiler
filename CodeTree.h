#ifndef CODETREE_H
#define CODETREE_H

#include <vector>
#include "CodeBlock.h"

class CodeTree
{
    public:
        CodeTree();
        virtual ~CodeTree();
        vector<CodeBlock> CodeBlocks;

    protected:

    private:
};

#endif // CODETREE_H
