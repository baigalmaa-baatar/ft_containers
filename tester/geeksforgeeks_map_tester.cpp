// C++ program to insert a node in AVL tree
#include <bits/stdc++.h>
// using namespace std;

// An AVL tree node
class Node
{
public:
    int val;
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
new node with the given val and
NULL left and right pointers. */
Node *newNode(int val)
{
    Node *node = new Node();
    node->val = val;
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
    Node *T3 = x->right;

    x->right = y;
    y->left = T3;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;
    return (x);
}

// A utility function to left
// rotate subtree rooted with x
// See the diagram given above.
Node *leftRotate(Node *x)
{
    Node *y = x->right;
    Node *T2 = y->left;

    y->left = x;
    x->right = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;
    return (y);
}

// Get Balance factor of node N

int getBalance(Node *node)
{
    if (node == NULL)
        return (0);
    return (height(node->left) - height(node->right));
}

// Recursive function to insert a val
// in the subtree rooted with node and
// returns the new root of the subtree.
Node *insert(Node *node, int val)
{
    if (node == NULL)
        node = newNode(val);
    if (val < node->val)
        node->left = insert(node->left, val);
    else if (val > node->val)
        node->right = insert(node->right, val);
    else
        return (node);

    /* 2. Update height of this ancestor node */

    node->height = max(height(node->left), height(node->right)) + 1;

    /* 3. Get the balance factor of this ancestor
        node to check whether this node became
        unbalanced */
    int balance = getBalance(node);

    // If this node becomes unbalanced, then
    // there are 4 cases

    // Left Left Case
    // Rotating right
    // y is the left child of z and x is the left child of y
    if (balance > 1 && val < node->left->val)
        return (rightRotate(node));

    // Right Right Case
    // y is the right child of z and x is the right child of y
    if (balance < -1 && val > node->right->val)
        return (leftRotate(node));

    // Left Right Case
    // y is the left child of z and x is the right child of y
    if (balance > 1 && val > node->left->val)
    {
        node->left = leftRotate(node->left);
        return (rightRotate(node));
    }

    // Right Left Case
    // y is the right child of z and x is the left child of y
    if (balance < -1 && val > node->right->val)
    {
        node = rightRotate(node->right);
        return (leftRotate(node));
    }
    //ene hurtel hiisen.
    /* return the (unchanged) node pointer */
    return (node);
}
// A utility function to print preorder
// traversal of the tree.
// The function also prints height
// of every node
// Recursion function

void preOrder(Node *root)
{
    if (root != NULL)
    {
        std::cout << root->val << " ";
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
