#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* buildTreeHelper(vector<int>::iterator prl, vector<int>::iterator prr,
                          vector<int>::iterator inl, vector<int>::iterator inr) {
    // stopping criteria
    if (prl >= prr) {
        return NULL;
    }

    int rootValue = *prl;
    TreeNode* root = new TreeNode(rootValue);

    // the find function return an pointer for the element inside the inorder traversal vector that represents the root
    vector<int>::iterator rootIndex = find(inl, inr, rootValue);

    // the size_type means: declare x as a variable of a type suitable for holding the size of a vector
    vector<int>::size_type leftSize = rootIndex - inl;

    // set all parameters for the recursive calls, which will fill the nodes for the children
    root->left = buildTreeHelper(prl + 1, prl + 1 + leftSize, inl, rootIndex);
    root->right = buildTreeHelper(prl + 1 + leftSize, prr, rootIndex + 1, inr);

    return root;
}

TreeNode* buildTree(vector<int> &preorder, vector<int> &inorder) {
    if (preorder.size() == 0) return NULL;
    return buildTreeHelper(preorder.begin(), preorder.end(), inorder.begin(), inorder.end());
}
