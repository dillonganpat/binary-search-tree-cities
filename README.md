# Binary Search Tree — World Cities 🌍

C++ program that stores 1030 world cities in a Binary Search Tree and performs operations including insertion, deletion, search, range queries, statistics, and rebalancing.

## Features
- Builds a BST from a world cities dataset
- Insert, search, and delete cities by name
- Range query — display all cities between two names in order
- BST statistics — height, one-child nodes, min/max keys, level breakdown
- Rebalances the BST using inorder traversal and recursive midpoint insertion
- Level-order traversal using a custom queue implementation
- Command-driven execution from a commands file

## Tech Stack
C++ · Binary Search Trees · Queues · Recursion · File I/O

## 🚀 Run
```bash
g++ Assignment2.cpp BinarySearchTree.cpp BinaryTree.cpp Queue.cpp -o bst
./bst
```

Ensure `worldcities.txt` and `Commands.txt` are in the same directory.
