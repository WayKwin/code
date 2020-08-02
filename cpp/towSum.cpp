#include <iostream>
#include<vector>
#include<unordered_map>
using namespace std;
vector<vector<int> > twoSum(vector<int> nums,int target){
    vector<vector<int> > res;
    unordered_map<int,int> m;
    for(int i = 0; i < nums.size(); i ++){
        if(m.find(target - nums[i]) == m.end()){
            m[target - nums[i]]  = nums[i];
        }else{
            res.push_back(vector<int>{m[target - nums[i]] , nums[i]});
        }
    }
    return res;
}
#if 1
vector<vector<int> > threeSum(vector<int> nums, int target){
    if (nums.empty()){
          vector<vector<int >> ret;
          ret.push_back({});
          return ret;
    } 
    vector<vector<int >> ret;
    sort(nums.begin(),nums.end());
    for(int i = 0; i < nums.size() - 2; i++ ){
        if (i > 0 && nums[i] == nums[i - 1]) continue;
        int le = i + 1;
        int ri = nums.size() - 1;
        while(le < ri){
            int sum = nums[i] + nums[le] + nums[ri];
            if(sum == target){
                ret.push_back({nums[i],nums[le],nums[ri]});
                while(le < ri && (nums[le] == nums[le + 1])){
                    le++;
                }
                le++;
                while( le < ri  &&   nums[ri] == nums[ri - 1]){
                    ri--;
                }
                ri--;
                
            }else if( sum < target){
                // while(le < ri && (nums[le] == nums[le + 1])){
                //     le++;
                // }
                le++;
            }else if (sum > target){
                // while( le < ri  &&   nums[ri] == nums[ri - 1]){
                //     ri--;
                // }
                ri--;
            }
        }
    }
    return ret;
}
#endif
  int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int absClosest = -1;
        int almostSum;
        for(int i = 0; i < nums.size() - 2 ; i ++){
                int lo = i + 1;
                int hi = nums.size() - 1;
                int sum = nums[i] + nums[lo] + nums[hi];
                 if(absClosest == -1){
                     absClosest = abs(sum - target);
                     almostSum = sum;
                 }
                cout << nums[i] << ' ' << nums[lo] << ' ' << nums[hi] << endl;
                while(lo < hi){
                    int sum = nums[i] + nums[lo] + nums[hi];
                    int almostMin = sum - target;
                    int absClosestInLoop = abs(almostMin);
                    cout << "  " << nums[i] << ' ' << nums[lo] << ' ' << nums[hi] << endl;
                    if(absClosestInLoop < absClosest){//本次循环的最接近值可能是整体最小的
                        absClosest  = absClosestInLoop;
                        almostSum = sum;
                    }
                    if (almostMin == 0){
                        return target;
                    }else if(almostMin < 0 ){
                        lo++;
                    }else if(almostMin > 0){
                        hi--;
                    }
                }
        }
        return almostSum;
   }

int main()
{
    // vector<int> a = {-1,2,1,-4};
    //vector<int> a = {-4,-1,1,2};
    vector<int> a = {-2,-2,-4,0,1,-2};
    vector<int> b = {-1,-1,-1,0,1,1,1,2,2};
   // cout <<threeSumClosest(a, -1);
    vector<vector<int> > ret = threeSum(b,0);
    for(auto vec : ret){
        for(auto val : vec){
            cout << val << ' ';
        }
        cout <<endl;
    }
    return 0;
}

