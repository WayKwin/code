#include "comm.h"
void dfs(vector<int>& nums, int len, int depth,vector<int>& oneRes,vector<vector<int> >& allRes,vector<bool>& mark);

vector<vector<int>>permuteUnique(vector<int>& nums) {
    sort(nums.begin(),nums.end());
    vector<bool> mark(nums.size());
    vector<vector<int> > allRes;
    vector<int> oneRes;
    dfs(nums,nums.size(),0,oneRes,allRes,mark);
    return allRes;
}
void dfs(vector<int>& nums, int len, int depth,vector<int>& oneRes,vector<vector<int> >& allRes,vector<bool>& mark){
    if(depth == len){
        allRes.push_back(oneRes);
        return;
    }
    for(int i = 0; i < len; i++){
        if(mark[i]){
            continue;
        }
        if(i > 0 && nums[i - 1] == nums[i] && !mark[i - 1]){
            continue;
        }
        mark[i] = true;
        oneRes.push_back(nums[i]);
        // for(auto e : oneRes){
        //     cout << e<< ' ';
        // }
        // cout <<endl;
        cout << "enter" <<i<< endl;
        dfs(nums,len,depth+1,oneRes,allRes,mark);
        oneRes.pop_back();
        cout <<"leave" << i << endl;
        mark[i]= false;
    }
}
int main(){
    //vector<int> vec = {1,2,3};
    vector<int> vec = {1,2,3};
    auto res =permuteUnique(vec);
    for(auto vec : res){
        for(auto ele : vec){
            cout << ele << ' ';
        }
        cout <<endl;
    }
}