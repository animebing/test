#include <iostream>
#include <cstdlib>

using namespace std;

struct node {
    int info;
    struct node *left;
    struct node *right;
}*root;

class BST {
    public: 
        void find(int, node **, node **);
        void insert(node *, node *);
        void del(int);
        void case_a(node *, node *);
        void case_b(node *, node *);
        void case_c(node *, node *);
        void preorder(node *);
        void inorder(node *);
        void postorder(node *);
        void display(node *);
        BST() {
            root = NULL;
        }
};

void BST::find(int item, node **par, node **loc) {
    node *ptr, *ptrsave;
    if (root == NULL) {
        *loc = NULL;
        *par = NULL;
        return;
    }
    if (item == root->info) {
        *loc = root;
        *par = NULL;
        return;
    }

    if (item < root->info) ptr = root->left;
    else ptr = root->right;

    ptrsave = root;
    while (ptr != NULL) {
        if (item == ptr->info) {
            *loc = ptr;
            *par = ptrsave;
            return;
        }

        ptrsave = ptr;
        if (item < ptr->info) ptr = ptr->left;
        else ptr = ptr->right;
    }
    *loc = NULL;
    *par = ptrsave;
}


void BST::insert(node *tree, node *newnode) {
    if (root == NULL) {
        root = new node;
        root->info = newnode->info;
        root->left = NULL;
        root->right = NULL;
        cout << "Root Node is Added" << endl;
        return;
    }
    if (tree->info == newnode->info) {
        cout << "Element already in the tree" << endl;   // it doesn't update the node info
        return;
    }

    if (tree->info > newnode->info) {
        if (tree->left != NULL) insert(tree->left, newnode);
        else {
            tree->left = newnode;
            (tree->left)->left = NULL;
            (tree->left)->right = NULL;
            cout << "Node Added To Left" << endl;
            return;
        }
    }else {
        if (tree->right != NULL) insert(tree->right, newnode);
        else {
            tree->right = newnode;
            (tree->right)->left = NULL;
            (tree->right)->right = NULL;
            cout << "Node Added To Right" << endl;
            return;
        }
    }
}


void BST::del(int item) {
    node *parent, *location;
    if (root == NULL) {
        cout << "Tree empty" << endl;
        return;
    }
    find(item, &parent, &location);
    if (location == NULL) {
        cout << "Item not present in tree" << endl;
        return;
    }

    if (location->left==NULL && location->right==NULL) case_a(parent, location);
    if (location->left!=NULL && location->right==NULL) case_b(parent, location);
    if (location->left==NULL && location->right!=NULL) case_b(parent, location);
    if (location->left!=NULL && location->right!=NULL) case_c(parent, location);
    free(location);
}

void BST::case_a(node *par, node *loc) {
    if (par== NULL) root = NULL;
    else {
        if (loc == par->left) par->left = NULL;
        else par->right = NULL;
    }
}

void BST::case_b(node *par, node *loc) {
    node *child;
    if (loc->left != NULL) child = loc->left;
    else child = loc->right;

    if (par == NULL) root = child;
    else {
        if (loc == par->left) par->left = child;
        else par->right = child;
    }
}

// find the smallest node in right subtree or the largest node in the left subtree,
// then substitude loc with that node
void BST::case_c(node *par, node *loc) {
    node *ptr, *ptrsave, *suc, *parsuc;
    ptrsave = loc;
    ptr = loc->right;
    while (ptr->left != NULL) {
        ptrsave = ptr;
        ptr = ptr->left;
    }
    suc = ptr;   // suc and parsuc is redundant here
    parsuc = ptrsave;
    if (suc->left==NULL && suc->right==NULL) case_a(parsuc, suc);   // suc->left must be NULL
    else case_b(parsuc, suc);
    if (par == NULL) root = suc;
    else {
        if (loc == par->left) par->left = suc;
        else par->right = suc;
    }
    suc->left = loc->left;
    suc->right = loc->right;
}

void BST::inorder(node *ptr) {
    if (root == NULL) {
        cout << "Tree is empty" << endl;
        return;
    }
    if (ptr != NULL) {
        inorder(ptr->left);
        cout << ptr->info << " ";
        inorder(ptr->right);
    }
}


int main() {
    int a = 5;
    BST bst;
    node *tmp = new node;
    tmp->info = a;
    bst.insert(root, tmp);
    bst.inorder(root);
    cout << endl;
    return 0;
}



