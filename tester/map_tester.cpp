// C++ program to insert a node in AVL tree
#include <bits/stdc++.h>
// using namespace std;

// An AVL tree node
class Node
{
public:
    int key;
    Node *left;
    Node *right;
    int height;
};

// A utility function to get the
// height of the tree

int height(Node *node)
{
    if (node == NULL)
        return (0);
    return (node->height);
}

// A utility function to get maximum
// of two integers
int max(int a, int b)
{
    return (a > b ? a : b);
}

/* Helper function that allocates a
new node with the given key and
NULL left and right pointers. */
Node *newNode(int key)
{
    Node *node = new Node();
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return (node);
}

// A utility function to right
// rotate subtree rooted with y
// See the diagram given above.
Node *rightRotate(Node *y)
{
    Node *x = y->left;
    Node *T4 = y->right;

    y->left = x->right;
    y->right = T4;
    x->right = y;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;
    return (x);
}

// A utility function to left
// rotate subtree rooted with x
// See the diagram given above.
Node *lefttRotate(Node *x)
{
    Node *y = x->right;
    Node *T1 = x->left;

    x->left = T1;
    x->right = y->left;
    y->left = x;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;
    return (y);
}

// Get Balance factor of node N

int getBalance (Node *node)
{
    if (node == NULL)
        return (0);
    return (height(node->left) - height(node->right));
}

// Recursive function to insert a key
// in the subtree rooted with node and
// returns the new root of the subtree.
// Node *insert(Node *root, int key)
// {
//     if (root == NULL)
//         root = newNode(key);
//     Node *node = new Node();
//     if (key < root->left->key)
//         root->left


// } //ene hurtel hiisen.
// A utility function to print preorder
// traversal of the tree.
// The function also prints height
// of every node
//Recursion function

void preOrder (Node *root)
{
    if (root != NULL)
    {
        std::cout << " " << std::endl;
        preOrder(root->left);
        preOrder(root->right);
    }
}

// Driver Code
int main()
{
    Node *root = NULL;

    /* Constructing tree given in
    the above figure */
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);

    /* The constructed AVL Tree would be
                30
            / \
            20 40
            / \ \
        10 25 50
    */
    std::cout << "Preorder traversal of the "
            "constructed AVL tree is \n";
    preOrder(root);

    return 0;
}
