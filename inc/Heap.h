#ifndef __HEAP_H__
#define __HEAP_H__

#include "Tree.h"

class Tree;

class Heap : public Tree
{
private:
    void descendantHeapfy(node* n, int* comparisons);
    void upwardHeapfy(node* n, int* comparisons);
public:
    Heap(int n);
    ~Heap();

    void insert(string value, int repetition = 1);
    int sort();
};

#endif