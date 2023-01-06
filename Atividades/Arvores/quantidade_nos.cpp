// C++ program for the above approach
#include <bits/stdc++.h>
using namespace std;
 
// Structure of a Tree Node
class Node {
public:
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int data);
 
// Function to get the left height of
// the binary tree
int left_height(Node* Node)
{
    int ht = 0;
    while (Node) {
        ht++;
        Node = Node->left;
    }
 
    // Return the left height obtained
    return ht;
}
 
// Function to get the right height
// of the binary tree
int right_height(Node* Node)
{
    int ht = 0;
    while (Node) {
        ht++;
        Node = Node->right;
    }
 
    // Return the right height obtained
    return ht;
}
 
// Function to get the coount of Nodes
// in complete binary tree
int TotalNodes(Node* root)
{
 
    // Base Case
    if (root == NULL)
        return 0;
 
    // Find the left height and the
    // right heights
    int lh = left_height(root);
    int rh = right_height(root);
 
    // If left and right heights are
    // equal return 2^height(1<<height) -1
    if (lh == rh)
        return (1 << lh) - 1;
 
    // Otherwise, recursive call
    return 1 + TotalNodes(root->left) + TotalNodes(root->right);
}
 
// Helper function to allocate a new Node
// with the given data
Node* newNode(int data)
{
    Node* Node = new Node();
    Node->data = data;
    Node->left = NULL;
    Node->right = NULL;
    return (Node);
}
 
// Driver Code
int main()
{
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(9);
    root->right->right = newNode(8);
    root->left->left->left = newNode(6);
    root->left->left->right = newNode(7);
 
    cout << TotalNodes(root);
 
    return 0;
}