// C++ program to insert a node in AVL tree
#include <bits/stdc++.h>
using namespace std;

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
int height(Node *N)
{
    if (N == NULL)
        return 0;
    return N->height;
}

// A utility function to get maximum
// of two integers
int max(int a, int b)
{
    return (a > b) ? a : b;
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
    node->height = 1; // new node is initially
                      // added at leaf
    return (node);
}

// A utility function to right
// rotate subtree rooted with y
// See the diagram given above.
Node *rightRotate(Node *y)
{
    Node *x = y->left;
    Node *T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = max(height(y->left),
                    height(y->right)) +
                1;
    x->height = max(height(x->left),
                    height(x->right)) +
                1;

    // Return new root
    return x;
}

// A utility function to left
// rotate subtree rooted with x
// See the diagram given above.
Node *leftRotate(Node *x)
{
    Node *y = x->right;
    Node *T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    x->height = max(height(x->left),
                    height(x->right)) +
                1;
    y->height = max(height(y->left),
                    height(y->right)) +
                1;

    // Return new root
    return y;
}

// Get Balance factor of node N
int getBalance(Node *N)
{
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}

// Recursive function to insert a key
// in the subtree rooted with node and
// returns the new root of the subtree.
Node *insert(Node *node, int key)
{
    /* 1. Perform the normal BST insertion */
    if (node == NULL)
        return (newNode(key));

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else // Equal keys are not allowed in BST
        return node;

    /* 2. Update height of this ancestor node */
    node->height = 1 + max(height(node->left),
                           height(node->right));

    /* 3. Get the balance factor of this ancestor
        node to check whether this node became
        unbalanced */
    int balance = getBalance(node);

    // If this node becomes unbalanced, then
    // there are 4 cases

    // Left Left Case
    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

    // Right Right Case
    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    // Left Right Case
    if (balance > 1 && key > node->left->key)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Left Case
    if (balance < -1 && key < node->right->key)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    /* return the (unchanged) node pointer */
    return node;
}
// Function to find the AVL_Node with minimum key value
Node *minValueAVL_Node(Node *node)
{
    Node *current = node;
    // Going to the left most side
    while (current->left != NULL)
        current = current->left;
    return current;
}

// Function to delete an AVL_Node with the given key from the subtree
Node *AVL_delete(Node *root, int key)
{
    // Perform normal BST deletion
    if (root == NULL)
        return root;
    // Find the node to be deleted
    // Left Side
    if (key < root->key)
        root->left = AVL_delete(root->left, key);

    // Right Side
    else if (key > root->key)
        root->right = AVL_delete(root->right, key);
    // Root Node
    else
    {
        // AVL_Node with only one child or no child
        if ((root->left == NULL) || (root->right == NULL))
        {
            Node *temp = root->left ? root->left : root->right;
            // No child case
            if (temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else               // One child case
                *root = *temp; // Copy the contents of the non-empty child
            free(temp);
        }
        else
        {
            // AVL_Node with two children: Get the inorder
            // successor (smallest in the right subtree)
            Node *temp = minValueAVL_Node(root->right);

            // Copy the inorder successor's
            // data to this AVL_Node
            root->key = temp->key;
            // Delete the inorder successor
            root->right = AVL_delete(root->right, temp->key);
        }
    }

    // If the tree had only one AVL_Node then return
    if (root == NULL)
        return root;

    // UPDATE HEIGHT OF THE CURRENT AVL_Node
    root->height = 1 + max(height(root->left), height(root->right));

    // GET THE BALANCE FACTOR OF THIS AVL_Node (to check whether this AVL_Node became unbalanced)
    int balance = getBalance(root);

    // If this AVL_Node becomes unbalanced, then there are 4 cases

    // Left Left Case
    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);

    // Left Right Case
    if (balance > 1 && getBalance(root->left) < 0)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Right Right Case
    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);
    // Right Left Case
    if (balance < -1 && getBalance(root->right) > 0)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

void preOrder(Node *root)
{
    if (root != NULL)
    {
        cout << root->key << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

int main(){
	Node *root = NULL;
	//Constructing tree 
	// root = insert(root, 40);
	// root = insert(root, 20);
	// root = insert(root, 10);
	// root = insert(root, 30);
	// root = insert(root, 25);
	// root = insert(root, 60);
	// root = insert(root, 45);
	// root = insert(root, 42);
	// root = insert(root, 52);
	// root = insert(root, 50);
	// root = insert(root, 55);
	// root = insert(root, 75);
	// root = insert(root, 70);
	// root = insert(root, 80);
	// root = insert(root, 85);
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);

	cout << "Preorder traversal of the above AVL tree is:\n"<<endl;
	preOrder(root);
    std::cout << '\n';
	//Deleting the node 25
    root = AVL_delete(root, 20);
	cout <<endl<<"preOrder traversal after"<< " deletion of 25:\n"<<endl;
	preOrder(root);
    std::cout << '\n';
	return 0;
}
