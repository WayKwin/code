#include"comm.h"
vector<int> path;
vector<int> oper; // 0,1,2,3 加减乘除
vector<int> nums;
vector<bool>visited(4,false);
bool dfs(int begin, int end,int target){
    if (target == 0 && begin== end){
        return true;
    }
    for(int i =0;i < nums.size();i++){
        if (visited[i]){
            continue;
        }
        visited[i] = true;
        if(dfs(begin+1,end,target + nums[i])) return true;
        if (dfs(begin+1,end,target - nums[i])) return true;
        if (target % nums[i] == 0 && dfs(begin+1, end, target/nums[i])) return true;//判断错误
        if (dfs(begin +1,end,target * nums[i])) return true;
        visited[i] = false;
    }
    return false;
}
int main(){
    nums = {4,1,1,12};

    cout << dfs(0,nums.size(), 24) << endl;
}