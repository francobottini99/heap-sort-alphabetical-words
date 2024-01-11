#include "Heap.h"

Heap::Heap(int n):Tree(n) {}

Heap::~Heap() {}

void Heap::insert(string value, int repetition) {
    int comparisons = 0;
    Tree::insert(value, repetition);
    upwardHeapfy(Tree::lastLeast(), &comparisons); 
}

int Heap::sort() {   
    int comparisons = 0;
    
    Tree* sortTree = new Tree(n);
    stack<pair<string, int>> sortStack;

    while (Tree::lastLeast() != root)
    {
        sortStack.push({root->value, root->repetition});
        
        Tree::swap(Tree::lastLeast(), root);   
        Tree::removeLast();

        descendantHeapfy(root, &comparisons);
    }

    sortStack.push({root->value, root->repetition});

    while (!sortStack.empty())
    {
        sortTree->insert(sortStack.top().first, sortStack.top().second);
        sortStack.pop();
    }

    change(sortTree);

    return comparisons;
}

void Heap::descendantHeapfy(node* n, int* comparisons) {
    node* n_to_swap = nullptr;

    list <node*> :: iterator it;
    for(it = n->children.begin(); it != n->children.end(); ++it) {
        (*comparisons)++;

        if(n_to_swap == nullptr) {
            if((*it)->value > n->value) {
                n_to_swap = *it;
            }
        } else {    
            if((*it)->value > n_to_swap->value) {
                n_to_swap = *it;
            }
        }
    }

    if(n_to_swap != nullptr) {          
        Tree::swap(n_to_swap, n);
        descendantHeapfy(n_to_swap, comparisons);
    }
}

void Heap::upwardHeapfy(node* n, int* comparisons) {
    if(n != root) {
        (*comparisons)++;

        if(n->value > n->father->value) {
            Tree::swap(n, n->father);
            upwardHeapfy(n->father, comparisons);
        }
    }
}