/*Given a binary search tree, write a function to find the kth smallest element in the tree.

Example :

Input : 
  2
 / \
1   3

and k = 2

Return : 2

As 2 is the second smallest element in the tree.
 NOTE : You may assume 1 <= k <= Total number of nodes in BST */


/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include<stack>

int inorder(TreeNode* A, int B){
    TreeNode* curr = A;
    stack<TreeNode*> s;
    
    while(curr!=NULL || !s.empty()){
        
        while(curr!=NULL){
            s.push(curr);
            curr = curr->left;
        }
        
        curr = s.top();
        B--;
        if(B==0) return curr->val;
        curr = curr->right;
        s.pop();
    }
} 
 
 
int Solution::kthsmallest(TreeNode* A, int B) {
    
    //int count = 0;
    return inorder(A,B);
    
}


/*O(1) space complexity solution*/