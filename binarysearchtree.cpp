#include "binarysearchtree.h"

// Initialize the root
BinarySearchTree::BinarySearchTree()
{
    root_ = nullptr;
}

// Free the resources
BinarySearchTree::~BinarySearchTree()
{
    root_ = nullptr;
    delete root_;
}


/* Insert data to BST, root_value > left_value */
void BinarySearchTree::Insert(int data)
{
    // If root is empty, assign new node
    if(root_ == nullptr)
    {
        root_ = new Node(data, nullptr, nullptr, nullptr);
    }
    else
    {
        // Insert new data as child
        InsertHelper(root_, data);
    }
}

// Insert helper to make recursion calls using root member
void BinarySearchTree::InsertHelper(Node *parent, int data)
{
    // Node decision, insert left if less than parent
    if( parent->data > data)
    {
        // Insert to left subtree
        if( parent->left == nullptr)
        {
            parent->left = new Node(data, nullptr, nullptr, parent);
        }
        else
        {
            // Go left subtree
            InsertHelper(parent->left, data);
        }
    }
    else
    {
        // Insert to right subtree
        if( parent->right == nullptr)
        {
            parent->right = new Node(data, nullptr, nullptr, parent);
        }
        else
        {
            // Go right subtree
            InsertHelper(parent->right, data);
        }
    }
}



/* Returns the number of nodes in BST */
int BinarySearchTree::Size(Node *parent)
{
    if( parent == nullptr)
        return 0;
    else
        return 1 + Size(parent->left) + Size(parent->right);
}


/* Returns number of steps to traverse BST */
int BinarySearchTree::InOrder()
{
    int steps = 0;

    Node *traverse_node = inorder_first(root_, steps);
    Node *next_node;

    // Make N-1 call to inorder_next
    int call_times = Size(getRoot());
    for(int i = 0; i < call_times - 1; ++i)
    {
        next_node = inorder_next(traverse_node, steps);
        traverse_node = next_node;
    }

    return steps;
}

/* Helper to fill the tree, randomization done in O(n) time using fisher-yates shuffle */
void BinarySearchTree::Randomize()
{    
    // Tree size between 50-100
    int tree_size = (rand() % 51) + 50;

    // Fill the array 1 to 1000
    int samples[K_SAMPLE_SIZE];

    for(int i = 0; i < K_SAMPLE_SIZE; ++i)
    {
        samples[i] = i + 1;
    }

    // Shuffle the array
    for (int i = K_SAMPLE_SIZE - 1; i >= 0; --i)
    {
        // Get random index
        int j = rand() % (i + 1);

        // Swap number with the element at random index
        SWAP(samples[i], samples[j]);
    }

    // Insert to BST
    for(int i = 0; i < tree_size; ++i)
    {
        Insert(samples[i]);
    }
}


/* Returns first node in BST */
Node* BinarySearchTree::inorder_first(Node *root_node, int &steps)
{
    // Handle crashes
    if(root_node == nullptr) return root_node;

    // Check the left node, if null return itself
    if(root_node->left != nullptr)
    {
        steps++;
        return inorder_first(root_node->left, steps);
    }
    else
    {
        return root_node;
    }
}



/* Returns the next node in the BST
 * Is there any node in right?
 *
 *   ..?..
 *    ...
 *     A
 *    / \
 *  |B|   C
 *    \
 *     ?
 *
 * If it has find the first node of it
 * else go to parent
 */
Node *BinarySearchTree::inorder_next(Node *root_node, int &steps)
{
    // Find parent
    if(root_node->right == nullptr)
    {
        Node *next_parent = root_node->parent;
        steps++;    /* Took already one step*/
        // Go to parent until, root
        while(next_parent != nullptr)
        {
            if(next_parent->left == root_node) break;
            root_node = next_parent;
            next_parent = next_parent->parent;
            steps++;
        }
        return next_parent;
    }
    else
    {
        // Go to right subtree
        // find the first node
        steps++;
        return inorder_first(root_node->right, steps);

    }
}
