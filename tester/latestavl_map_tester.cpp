// http : // www.bradapp.net/ftp/src/libs/C++/AvlTrees.html

// https : // www.youtube.com/watch?v=otiDcwZbCo4

#include <iostream>

struct TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    int height;

    TreeNode()
    {
        val = 0;
        left = NULL;
        right = NULL;
        height = 0;
    }

    TreeNode *newNode(int val)
    {
        TreeNode *node = new TreeNode();
        node->val = val;
        node->left = NULL;
        node->right = NULL;
        node->height = 1;
        return (node);
    }
};

class AVLTree
{
public:
    TreeNode *root;

    AVLTree()
    {
        root = NULL;
    }

    int max(int a, int b)
    {
        return (a > b ? a : b);
    }

    int getHeight(TreeNode *root)
    {
        if (root == NULL)
            return (0);
        return (root->height);
    }

    int getBalance(TreeNode *root)
    {
        if (root == NULL)
            return (0);
        return (getHeight(root->left) - getHeight(root->right));
    }

    // rotateRight function
    TreeNode *rotateRight(TreeNode *y)
    {
        TreeNode *x = y->left;
        TreeNode *T3 = x->right;

        x->right = y;
        y->left = T3;

        x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
        y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

        return (x);
    }
    // rotateLeft function
    TreeNode *rotateLeft(TreeNode *x)
    {
        TreeNode *y = x->right;
        TreeNode *T2 = y->left;

        y->left = x;
        x->right = T2;
        
        x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
        y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

        return (y);
    }

    // insert function
    TreeNode *insert(TreeNode *root, int new_val)
    {
        // if root is NULL add new value as a root
        if (root == NULL)
        {
            return (root->newNode(new_val));
        }
        // recursion of insert node in bottom(?)
        if (new_val < root->val)
            root->left = insert(root->left, new_val);
        else if (new_val > root->val)
            root->right = insert(root->right, new_val);
        else
            return (root); // if the value exists in tree, we don't add. AVL alogorithm

        // Update the height after inserting new node:
        root->height = max(getHeight(root->left), getHeight(root->right)) + 1;

        // get balance
        int balance = getBalance(root);

        // Left left case
        if (balance > 1 && new_val < root->left->val)
        {
            return (rotateRight(root));
        }
        // Right right case
        if (balance < -1 && new_val > root->right->val)
        {
            return (rotateLeft(root));
        }
        // Left right case
        if (balance > 1 && new_val > root->left->val)
        {
            root->left = rotateLeft(root->left);
            return (rotateRight(root));
        }
        // Right left case
        if (balance < -1 && new_val < root->left->val)
        {
            root->right = rotateRight(root->right);
            return (rotateLeft(root));
        }
        return (root);
    }
    void printPreOrder(TreeNode *root)
    {
        if (root != NULL)
        {
            std::cout << root->val << " ";
            printPreOrder(root->left);
            printPreOrder(root->right);
        }
    }
};

int main(void)
{
    AVLTree *tree = NULL;
    TreeNode *root = NULL;

    std::cout << "first root : " << '\n';
    root = tree->insert(root, 10);
    tree->printPreOrder(root);
    std::cout << '\n';
    std::cout << "second root : " << '\n';
    root = tree->insert(root, 20);
    tree->printPreOrder(root);
    std::cout << '\n';
    std::cout << "third root : " << '\n';
    root = tree->insert(root, 30);
    tree->printPreOrder(root);
    std::cout << '\n';
    std::cout << "fourth root : " << '\n';
    root = tree->insert(root, 40);
    tree->printPreOrder(root);
    std::cout << '\n';
    std::cout << "fifth root : " << '\n';
    root = tree->insert(root, 50);
    tree->printPreOrder(root);
    std::cout << '\n';
    std::cout << "last root : " << '\n';
    root = tree->insert(root, 25);
    tree->printPreOrder(root);
    std::cout << '\n';

    return (0);
}