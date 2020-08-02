#include <iostream>
#include<vector>
using namespace std;
vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector<vector<int> > ret;
    if (nums.size() < 4){
        return ret;
    }
    sort(nums.begin(), nums.end());
    for(int i = 0; i < nums.size() - 3; i++){
        if(i > 0  && nums[i] == nums[i-1]) continue;
        int targetInLoop = target - nums[i];
        for(int j = i+1; j < nums.size() - 2 ; j++){
            if(j > i + 1 && nums[j] == nums[j-1]) continue;
                int lo = j + 1;
                int hi = nums.size() - 1;
                while(lo < hi){
                    int sum = nums[j] + nums[lo] + nums[hi];
                    if(sum == targetInLoop){
                        ret.push_back({nums[i],nums[j],nums[lo],nums[hi]});
                        while(lo < hi && nums[lo] == nums[lo + 1]){
                            lo++;
                        }
                        while(lo < hi && nums[hi] == nums[hi - 1]){
                            hi--;
                        }
                        hi--;
                        lo++;
                    }else if(sum > targetInLoop){
                        while(lo < hi && nums[hi] == nums[hi - 1]){
                            hi--;
                        }
                        hi--;
                    }else if(sum < targetInLoop){
                        while(lo < hi && nums[lo] == nums[lo+1]){
                            lo++;
                        }
                        lo++;
                    }
                }
        }

    }
    return ret;
}
vector<vector<int>> fourSum(vector<int>& nums, int target) {
    sort(nums.begin(),nums.end());
    vector<vector<int>> result;
    int size=nums.size();
    for(int a=0;a<size-3;++a)
    {
        if(a>0&&nums[a]==nums[a-1])continue;
        for(int b=a+1;b<size-2;++b)//以下代码与三数之和一样的
        {
            if(b>a+1&&nums[b]==nums[b-1])continue;
            int i=b+1,j=size-1;
            while(i<j)
            {
                int sum=nums[a]+nums[b]+nums[i]+nums[j];
                if(sum<target){
                    while(i<j&&nums[i]==nums[ i + 1]){
                       i++; 
                    }
                    i++;
                }
                else if(sum>target){
                    while(i<j&&nums[j]==nums[j - 1]){
                        j--;
                    }
                    j--;
                }
                else{
                    result.push_back(vector<int>{nums[a],nums[b],nums[i],nums[j]});
                    while(i<j&&nums[i]==nums[i+1]){
                        i++;
                    }
                    while(i<j&&nums[j]==nums[j - 1]){
                        j--;
                    }
                    i++;
                    j--;
                }
            }
        }
    }
    return result;
}
int main(){
    //vector<int> vec = {1, 0, -1, 0, -2, 2};
    vector<int> vec = {0};
    auto ret = fourSum(vec, 0);
    // for(auto vec : ret){
    //     for(auto num : vec){
    //         cout << num << ' ';
    //     }
    //     cout<< endl;
    // }
    return 0;
}


