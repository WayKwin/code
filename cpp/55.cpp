#include "comm.h"
class Solution {
public:
    bool wr_canJump(vector<int>& nums) {
        if(nums.empty()){
            return false;
        }
        bool res = false;
        core(nums,nums.size() - 1,res);
        return res;
    }
    bool core(vector<int>& nums, int cur,bool & res){
        if(cur < 0){
            return false;
        }
        if(cur == 0){
            res = true;
            return true;
        }
        cout << cur << endl;
        for(int i = 0; i < cur; i++){
            int distance = cur - i;
            int canJumpOver = nums[i];
            if(canJumpOver >= distance){
                 if(core(nums, i,res)){
                     return true;
                 };
            }
        }
        return false;
    }
    bool TimeoutcanJump(vector<int>& nums){
        if(nums.empty()){
            return 0;
        }
        vector<int> dp(nums.size());
        dp[0] = true;
        for(int i = 1; i < nums.size();i++){
            for(int j = 0; j < i;j ++){
                int distance = i - j;
                int canJumpOver = nums[j];
                if(dp[j] == true &&distance <= canJumpOver){
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[nums.size() - 1];
    }
    //贪心， 从i出发最远可以到达的点
    bool canJump(vector<int>& nums) {
        int rightMost = 0;
        for(int i = 0; i < nums.size(); i++){
            // 例如 a={2,1,0,3,4}, 当i = 3,  但是rightMost = 2, 表明最大只能跳跃到a[2]a[3]根本无法到达 
            // 所以i 必须 i<=rightMost (i处于当前最大活动范围内)
            if(i <= rightMost){
                rightMost = max(rightMost,i + nums[i]);
                if(rightMost >= nums.size() - 1){
                    return true;
                }
            }
        }
        return false;
    }
};
int main(){
    Solution s;
    vector<int> vec = {3,2,1,0,4};
    cout << s.canJump(vec) <<endl;
}