#include"comm.h"
int removeDuplicates(vector<int>& nums) {
    int i = 1;
    int j = 0;
    int count = 0;
    for(;  i< nums.size(); i++){
        if(nums[i-1] == nums[i]){
            count++;
            if(count < 2){
                    j++;
                    nums[j]= nums[i]; //最后一个i要挪到j上
            }
        }else if(nums[i-1] != nums[i]){
            count = 0;
            j++;
            nums[j] = nums[i];
        }
    }
    return j + 1;
} // 1 1 1 1
int main(){
    vector<int> a = {0,0,1,1,1,1,2,2,3};
    auto j = removeDuplicates(a);
    for(int i = 0; i < j;i++){
        cout << a[i] << ' ';
    }
    cout << endl;
}