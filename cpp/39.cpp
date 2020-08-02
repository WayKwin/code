#include"comm.h"
class Solution {
public:
vector<vector<int>>  res;
vector<int> onePath;
vector<int> candidates;
public:
    void dfs(int start, int target){
        if(target == 0){
            res.push_back(onePath);
        }
        for(int i = start; i < candidates.size()&&target-candidates[i] >=0; i++){
            onePath.push_back(candidates[i]);
            dfs(i, target - candidates[i]);
            onePath.pop_back();
        }
    }
    void dfs_2(int start,int target){
        if(target < 0){
            return;
        }
        if(target == 0){
            res.push_back(onePath);
            return;
        }
        for(int i =  start; i < candidates.size() ; i++){ //每一层的深入
            if(i > start && candidates[i] == candidates[i-1]){//// i > start是精髓， 我写成了 i > 0, i > start就是同层的重复才会掠过， 不会略过 1 1 6
                continue;
            }
            onePath.push_back(candidates[i]);
            dfs_2(i+1, target-candidates[i]);
            onePath.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        for(auto i : candidates){
            cout << i <<' ';
        }
        cout << endl;
        this->candidates = candidates;
        dfs_2(0,target);
        return res;
    }
};
int main(){
    Solution s ;
    vector<int> a = {10,1,2,7,6,1,5};


    auto vv = s.combinationSum(a,8);
    for(auto v : vv){
        cout<< '[';
        for(auto e : v){
            cout << e <<','  ;
        }
        cout <<']';
    }
}