#include "Tree.h"

Tree::Tree(int n) {
    this->n = n;
    root = nullptr;
}

Tree::~Tree() {
    while (lastLeast() != root)
    {
        removeLast();
    }
    
    delete root;
}

void Tree::change(Tree* t) {
    *this = *t;
}

void Tree::postOrder(node* n, list<pair<string, int>>* l) {
    if(n == nullptr) {
        return;
    } else {
        list <node*> :: iterator it;
        for(it = n->children.begin(); it != n->children.end(); ++it) {
            postOrder(*it, l);
        }    

        l->push_back({n->value, n->repetition});
    }
}

void Tree::preOrder(node* n, list<pair<string, int>>* l) {
    if(n == nullptr) {
        return;
    } else {
        l->push_back({n->value, n->repetition});

        list <node*> :: iterator it;
        for(it = n->children.begin(); it != n->children.end(); ++it) {
            preOrder(*it, l);
        }    
    }
}

void Tree::breadth(node* n, list<pair<string, int>>* l) {
    queue<node*> auxQueue;

    auxQueue.push(n);
    l->push_back({n->value, n->repetition});

    while (!auxQueue.empty())
    {
        list <node*> :: iterator it;
        for(it = auxQueue.front()->children.begin(); it != auxQueue.front()->children.end(); ++it) {
            auxQueue.push(*it);
            l->push_back({(*it)->value, (*it)->repetition});
        } 

        auxQueue.pop();
    }
}

Tree::node* Tree::breadthSearch(string value) {
    if(root != nullptr) {
        queue<node*> auxQueue;

        auxQueue.push(root);

        while (!auxQueue.empty())
        {       
            if(auxQueue.front()->value == value) {
                return auxQueue.front();
            } else {
                list <node*> :: iterator it;
                for(it = auxQueue.front()->children.begin(); it != auxQueue.front()->children.end(); ++it) {
                    auxQueue.push(*it);
                }                    
            }

            auxQueue.pop();
        }
    }

    return nullptr;
}

Tree::node* Tree::lastLeast() {
    return orderStack.top();
}

int Tree::size() {
    return orderStack.size();
}

void Tree::insert(string value, int repetition) {
    int comparisons = 0;

    for_each(value.begin(), value.end(), [](char & c){
        c = tolower(c);
    });

    node* aux = breadthSearch(value);
    
    if(aux != nullptr) {
        aux->repetition += repetition;
    } else {
        aux = new node();

        aux->value = value;
        aux->repetition = repetition;

        if(root == nullptr) {
            aux->father = nullptr;
            root = aux;
            parentList.push_back(root);
            orderStack.push(root);
        } else {           
            while (!parentList.empty())
            {               
                if(parentList.front()->children.size() < n) {
                    aux->father = parentList.front();    
                    aux->father->children.push_back(aux);  

                    orderStack.push(aux);            
                    parentList.push_back(aux);

                    break;
                } else {
                    parentList.pop_front();
                }
            }
        }
    }
}

void Tree::removeLast() {
    node* aux = orderStack.top();
    aux->father->children.remove(aux);
    parentList.pop_back();
    orderStack.pop();
    if(parentList.front() != aux->father) {
        parentList.push_front(aux->father);
    }
    delete aux;
}

void Tree::swap(node* a, node* b) { 
    node aux = *a;
    a->value = b->value;
    a->repetition = b->repetition;
    b->value = aux.value;
    b->repetition = aux.repetition;
}

void Tree::print(node* n, string indent, bool last) {
    cout << indent;
    if(last){
        cout << "\\--";
        indent += "   ";
    } else {
        cout << "|--";
        indent += "|  ";
    }
    cout << n->value << " (" << n->repetition << ")" << endl;

    list <node*> :: iterator it;
    int i = 0;
    for(it = n->children.begin(); it != n->children.end(); ++it) {
        print(*it, indent, i == n->children.size() - 1);
        i++;
    }
}

void Tree::print() {
    if(root != nullptr) {
        print(root, "", true);
    } else {
        cout << "empty" << endl;
    }
}

list<pair<string, int>> Tree::breadth() {
    list<pair<string, int>> auxList;
    breadth(root, &auxList);
    return auxList;
}

list<pair<string, int>> Tree::preOrder() {
    list<pair<string, int>> auxList;
    preOrder(root, &auxList);
    return auxList;
}

list<pair<string, int>> Tree::postOrder() {
    list<pair<string, int>> auxList;
    postOrder(root, &auxList);
    return auxList;
}