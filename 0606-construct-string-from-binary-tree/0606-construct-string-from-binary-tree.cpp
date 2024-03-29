class Solution {
public:
    string tree2str(TreeNode* t) {
        if (!t)
            return "";
        if (!t->left && !t->right) 
            return to_string(t->val) + "";
        if (!t->right)
            return to_string(t->val) + "(" + tree2str(t->left) + ")";
        return to_string(t->val) + "(" + tree2str(t->left) + ")(" + tree2str(t->right) + ")";
    }
};