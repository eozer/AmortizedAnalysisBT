#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include <iostream>

// Generic SWAP Macro
#define SWAP(x,y) do \
   { unsigned char swap_temp[sizeof(x) == sizeof(y) ? (signed)sizeof(x) : -1]; \
     memcpy(swap_temp,&y,sizeof(x)); \
     memcpy(&y,&x,       sizeof(x)); \
     memcpy(&x,swap_temp,sizeof(x)); \
    } while(0)

// Sample size used in randomization
#define K_SAMPLE_SIZE 1000

/* Basic Node POD
 * with parent
 */
struct Node
{
    int data;
    Node *left;
    Node *right;
    Node *parent;

    Node(int data, Node *left, Node *right, Node *parent)
    {
        this->data = data;
        this->left = left;
        this->right = right;
        this->parent = parent;
    }
};


/* Standard BST(Binary Search Tree)
 * implementation used for the amortized
 * analysis. InOrder traversal is analyzed
 * in this class.
 */
class BinarySearchTree
{
public:  
    BinarySearchTree();
    ~BinarySearchTree();

    void Insert(int data);      /* Insert data to BST, root_value > left_value */
    int Size(Node *parent);     /* Returns the number of nodes in BST */
    int InOrder();              /* Returns number of steps to traverse BST */
    void Randomize();           /* Helper to fill the tree using shuffle */
    inline Node *getRoot()               { return root_; }
private:
    // Variables
    Node *root_;

    // These two operations change the state of BST
    Node* inorder_next(Node *root_node, int &steps);     /* Returns next node in BST */
    Node* inorder_first(Node *root_node, int &steps);    /* Returns first node in BST */
    // Utility Functions
    void InsertHelper(Node *parent, int data);

};


#endif // BINARYSEARCHTREE_H
