#include"comm.h"
vector<int> nums;
vector<int> oneRes;
vector<bool> mark;
bool core(int start, int& level,int k,vector<int>& result){
    if(start == nums.size()){
        level++;
        if(level == k){
            for(auto ele:oneRes){
                result.push_back(ele);
            }
            return true;
        }
        return false;
    }
    for(int i = 0; i< nums.size();i++){
        if(mark[i]){
            continue;
        }
        mark[i] = true;
        oneRes.push_back(nums[i]);

        bool res = core(start+1, level,k,result);
        if(res){
            return true;
        }
        oneRes.pop_back();
        mark[i] = false;
    }
    return false;
}
string getPermutation(int n, int k) {
    if(n < 1 || k < 1){
        return "";
    }
    for(int i = 0; i < n; i++){
        nums.push_back(i+1);
    }    
    mark = vector<bool>(n);
    vector<int> res;
    int level = 0;
    core(0,level,k,res);
    string s;

    for(auto ele : res){
        s.push_back(ele+'0');
    }
    return s;
}

int main(){
    cout<<getPermutation(3,3);
}