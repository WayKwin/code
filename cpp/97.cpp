#include"comm.h"
vector<TreeNode*> generateTrees(int n) {

   return generate(1,n);
}
vector<TreeNode*> generate(int left, int right){
    vector<TreeNode*> ans;
    if(left <=0 || left > right){
        ans.push_back(NULL);
        return ans;
    }
    for(int i = left; i <= right; i++){
        vector<TreeNode*> left_comb = generate(left, i -1);
        vector<TreeNode*> right_comb = generate(i+1, right); 
        for(auto left_head : left_comb){
            for(auto right_head:right_comb){
                TreeNode* head = new TreeNode(i);
                head->left = left_head;
                head->right = right_head;
                ans.push_back(head);
            }
        }
    }
    return ans;

}