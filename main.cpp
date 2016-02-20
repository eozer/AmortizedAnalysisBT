#include <iostream>
#include <iomanip>
#include <time.h>
#include "binarysearchtree.h"

#define ANALYSE_CYCLE 50


using namespace std;

// Print data
void PrintResult(int number, int size, int steps, int estimation)
{
    cout << setfill(' ') << setw(1) << "|" << setw(13) << internal << number
         << setw(1) << "|" << setw(11) << internal << size
         << setw(1) << "|"  << setw(7) << internal << steps
         << setw(1) << "|"  << setw(12) << internal << estimation
         << setw(1) << "|" << endl;

    cout << setfill('-') << setw(1) << "+" << setw(13) << "-" << setw(1) << "+"
         << setw(11) << "-" << setw(1) << "+"
         << setw(7)  << "-" << setw(1) << "+"
         << setw(12) << "-" << setw(1) << "+" << endl;
}

// Print headers
void PrintHeader()
{
    cout << setfill('-') << setw(1) << "+" << setw(13) << "-" << setw(1) << "+"
         << setw(11) << "-" << setw(1) << "+"
         << setw(7)  << "-" << setw(1) << "+"
         << setw(12) << "-" << setw(1) << "+" << endl;

    cout << setfill(' ') << setw(1) << "|" << setw(13) << left << " Tree Number "
         << setw(1) << "|" << setw(11) << left << " Tree Size "
         << setw(1) << "|"  << setw(5) << left << " Steps "
         << setw(1) << "|"  << setw(12) << left << " Estimation " << setw(1) << "|" << endl;

    cout << setfill('-') << setw(1) << "+" << setw(13) << "-" << setw(1) << "+"
         << setw(11) << "-" << setw(1) << "+"
         << setw(7)  << "-" << setw(1) << "+"
         << setw(12) << "-" << setw(1) << "+" << endl;
}

int main(int argc, char *argv[])
{
    // Seed the rand function once
    srand(time(nullptr));

    // Print table headers
    PrintHeader();

    // Amortize Analysis
    for(int i = 0; i < ANALYSE_CYCLE; ++i)
    {
        BinarySearchTree *bst = new BinarySearchTree();
        // Fill the tree
        bst->Randomize();   /* Fill the BST with random numbers */

        // Output
        int tree_number = i + 1;
        int tree_size = bst->Size(bst->getRoot());
        int traversal_steps = bst->InOrder();
        int estimation = 2 * (tree_size - 1);

        // Print result
        PrintResult(tree_number, tree_size, traversal_steps, estimation);

        // Free heap
        delete bst;
    }

    getchar();
    return 0;
}


