#include"comm.h"
int jumpB(vector<int>& nums) {
    if(nums.size() < 2 ){
        return 0;
    }
    vector<int>dp(nums.size());
    dp[0] =0;
    for(int i = 1; i < dp.size(); i++){
        int curMinStep = -1 ;
        for(int j = 0; j < i ; j++){
            int preToCurStep = i - j;
            int curAblitily = nums[j];
            if(curAblitily >= preToCurStep && curMinStep == -1){
                curMinStep = dp[j];
            }
            if(curAblitily >= preToCurStep &&  curMinStep != -1 && dp[j] < curMinStep){
                curMinStep = dp[j];
            }
        }
        dp[i] = curMinStep+1;
    }
    cout <<endl;
    return dp[nums.size() - 1];
}
int jump(vector<int>& nums) {
    int maxPos = 0, n = nums.size(), end = 0, step = 0;
    for (int i = 0; i < n - 1; ++i) {
        if (maxPos >= i) {
            maxPos = max(maxPos, i + nums[i]);
            if (i == end) {
                end = maxPos;
                ++step;
            }
        }
    }
    return step;
}
int main(){
    vector<int> a = {2,3,1,1,4};
    vector<int> b = {1,2,3};
    vector<int> c = {2,3,1,20000002,4};
    vector<int> d = {1,2,1,1,1};
    cout << jumpB(d);
    cout << jump(d);
}