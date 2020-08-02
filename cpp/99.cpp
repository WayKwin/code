#include"comm.h"
void inorder(TreeNode* root, vector<int>&res){
    if(root == NULL){
        return;
    }
    inorder(root->left,res);
    res.push_back(root->val);
    inorder(root->right,res);
}
void core(TreeNode*root, vector<int>& res,int& index){
    if(root == NULL){
        return;
    }
    inorder(root->left,res);
    cout << root->val << '|'  << res[index] << endl;
    root->val = res[index++];
    inorder(root->right,res);
}
void recoverTree(TreeNode* root) {
    vector<int> save;
    cout <<endl;
    inorder(root,save);
    sort(save.begin(),save.end());
    for(auto i :save){
        cout << i << ' ';
    }
   int index = 0;
   core(root,save,index);
}