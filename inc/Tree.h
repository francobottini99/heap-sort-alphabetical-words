#ifndef __TREE_H__
#define __TREE_H__

#include <iostream> 
#include <list>
#include <queue>
#include <iterator>
#include <stack>
#include <string>
#include <algorithm>

using namespace std;

class Tree
{
protected:
    int n;

    struct node {
        string value;
        int repetition;
        struct node* father;
        list<node*> children;
    };

    node* root;

    void postOrder(node* n, list<pair<string, int>>* l);
    void preOrder(node* n, list<pair<string, int>>* l);
    void breadth(node* n, list<pair<string, int>>* l);

    node* breadthSearch(string value);
    node* lastLeast();

    void swap(node* a, node* b);
    void change(Tree* t);
private:
    list<node*> parentList;
    stack<node*> orderStack;

    void print(node* n, string indent, bool last);
public:
    Tree(int n);
    ~Tree();

    void insert(string value, int repetition = 1);

    void removeLast();

    void print();

    list<pair<string, int>> breadth();
    list<pair<string, int>> preOrder();
    list<pair<string, int>> postOrder();

    int size();
};

#endif