#include"comm.h"
class Solution {
public:
//贪心法错误 两头选大的错误
    int WrongmaxSubArray(vector<int>& nums) {
        int  curVal= 0;
        int lo = 0;
        int hi = nums.size() - 1;
        for(int i = 0; i < nums.size();i ++){
            curVal += nums[i];
        }
        int maxVal = curVal;
        while(lo < hi){
            if(nums[lo] < nums[hi]){
                curVal -= nums[lo];
                if(curVal > maxVal){
                    maxVal = curVal;
                }
                lo++;
            }else if(nums[hi] < nums[lo]){
                curVal -= nums[hi];
                if(curVal > maxVal ){
                    maxVal = curVal;
                }
                hi--;
            }else{
                int tmpLo = lo;
                int tmpHi = hi;
                while(tmpLo < tmpHi && nums[tmpLo] == nums[tmpHi]){
                    curVal -= nums[tmpLo];
                    if(curVal > maxVal ){
                        maxVal = curVal;
                    }
                    tmpLo++;
                    tmpHi--;
                }
                if(tmpLo > tmpHi){
                    return maxVal;
                }
                if(nums[tmpLo] < nums[tmpHi]){
                    lo = tmpLo;
                }else{
                    hi = tmpHi;
                }
            }
        }
        if(lo + 2 == hi){ 
            curVal -= nums[lo+1];
            if(curVal > maxVal){
                maxVal = curVal;
            }
        }
        return maxVal;
    }
    //开始DP// Dp错误 考虑已有数组的正负，而不是下一个数组的正负
    int Wrong2maxSubArray(vector<int> &nums){
        if(nums.empty()){
            return 0;
        }
        int max =nums[0];
        int cur = nums[0];
        int begin = 0;
        for(int i = 1 ; i < nums.size(); i++){
            if(nums[i] >= 0){
                cur+=nums[i];
            }else if(nums[i] < 0){
                if(nums[i] > nums[begin]){
                    cur-=nums[begin];
                    begin++;
                }else{
                    cur +=nums[i];
                }
            }
            if(cur > max){
                max = cur;
            }
        }
        return max;
    }
    int maxSubArray(vector<int> &nums){
        if(nums.empty()){
            return 0;
        }
        int sum = 0;
        int res = nums[0];
        for(int i : nums){
            if(sum > 0){
                sum +=i;
            }else{
                sum = i; //sum 小于0了 再加上负数 会更小,加上正数 
            }
            res = max(sum,res);
        }
        return res;
    }
};
int main(){
    Solution s;
    vector<int> v = {-2,1,-3,4,-1,2,1,-5,4};

    // vector<int> v = {1,2,-1,-2,2,1,-2,1,4,-5,4};
    // vector<int> a = {-1,1,-1};
    cout << s.maxSubArray(v);
}