#include"comm.h"
//双指针
int removeElement(vector<int>& nums, int val) {
    int i = 0;
    for(int j = 0; j < nums.size(); j++){
        if(nums[j] != val){
            nums[i] = nums[j];
            i++;
        }
    }
    return i;
}
// 将符合的元素和末尾的元素交换
int removeElement2(vector<int> & nums, int val){
    int i = 0;
    int size = nums.size();

    while(nums[size - 1] == val){
        size--;
    }
    for(int i = 0; i < size ;i++ ){
        if(nums[i] == val){
            nums[i] = nums[size - 1];
            size--;
        }
    }
    return size;

}
//即使
int removeElements3(vector<int>&nums, int val){
    int n =  nums.size();
    int i = 0;

    while(i < n){ 
        if(nums[i] == val){ //即使把末尾的val交换回首部，下次循环还会检查这个val，使size--
            nums[i] = nums[n - 1];
            n--;
        }else{
            i++;
        }
    }
    return n;
}
int main(){
    vector<int> s = {3,2,2,3};
    int len = removeElements3(s,3);
    for(int i = 0; i < len; i++){
        cout << s[i];
    }
}
