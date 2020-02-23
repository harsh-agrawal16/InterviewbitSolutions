/*
Given an array where elements are sorted in ascending order, convert it to a height balanced BST.

 Balanced tree : a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1. 
Example :


Given A : [1, 2, 3]
A height balanced BST  : 

      2
    /   \
   1     3
*/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* ans(const vector<int> &A, int start,int end){
    
    int n = (start + end)/2;
    TreeNode* node = new TreeNode(A[n]);
    if(n > start) node->left = ans(A,start,n-1);
    if(n < end) node->right = ans(A,n+1,end);
    
    return node;
} 

 
 
TreeNode* Solution::sortedArrayToBST(const vector<int> &A) {
    
    int n = A.size();
    TreeNode* root = new TreeNode(A[n/2]);
    if(n/2> 0) root->left = ans(A,0,n/2 -1);
    if(n/2 < n-1) root->right = ans(A,n/2+1, n-1);
    return root;
}
