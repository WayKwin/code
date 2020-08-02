#include"comm.h"
int removeDuplicates(vector<int>& nums) {
    int j = 1;
    int i = 0;
    int size = nums.size();
    for(; j < size; j++){
        if(nums[j] != nums[i]){
            i++;
            nums[i] = nums[j];
        }
    }
    return i + 1;
}
int main(){
    vector<int> a {1,1,2,3};
    int b = removeDuplicates(a);
    for(int i  = 0; i < b ;i++){
        cout << a[i] <<' ';
    }
    cout <<endl;
}