#include"comm.h"
void core(vector<int>& nums, int begin, vector<vector<int>>& reuslt,vector<int>& mark){
    if(begin == nums.size()){
        reuslt.push_back(nums);
        return;
    }
    for(int i = begin; i < nums.size();i++){
        swap(nums[i],nums[begin]);
        cout <<"start swap|" << "begin:" <<  begin << ' ' <<  "i:"<<i << endl;
        for(auto ele : nums){
            cout << ele << ' ';
        }
        cout << endl;
        core(nums,begin +1, reuslt,mark);

        swap(nums[i],nums[begin]);
        cout <<"done swap| "   << "begin:" <<  begin << ' ' <<  "i:"<<i << endl;
        for(auto ele : nums){
            cout << ele << ' ';
        }
        cout <<endl;
    }
}

vector<vector<int>>permuteUnique(vector<int>& nums) {
    sort(nums.begin(),nums.end());
    vector<vector<int> > res;
    vector<int> mark;
    core(nums,0,res,mark);
    return res;
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