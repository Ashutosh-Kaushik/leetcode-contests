/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void f(TreeNode* root, int &sum, int &cnt, int &ret) {
        if(root == NULL) return;
        int suml = 0, cntl = 0;
        f(root->left, suml, cntl, ret);
        int sumr = 0, cntr = 0;
        f(root->right, sumr, cntr, ret);
        sum = root->val + suml + sumr;
        cnt = cntr + cntl + 1;
        if((sum / cnt) == root->val) {
            ret++;
        }
    }
    int averageOfSubtree(TreeNode* root) {
        int ret = 0, sum = 0, cnt = 0;
        f(root, sum, cnt, ret);
        return ret;
    }
};