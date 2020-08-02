#include"comm.h"
int binarySearch(vector<int>& nums,int start, int end, int target);
int search(vector<int>& nums, int target) {
    if(nums.empty()){
        return -1;
    }
    int le = 0;
    int ri = nums.size() - 1;
    if (target < nums[le] && target > nums[ri]){
        return -1;
    }
    while(le <= ri){
        int mid =  (le+ri) / 2;
        if(nums[mid] == target){
            return mid;
        }else if(nums[mid] < nums[ri]){ // mid ,ri有序
            if(nums[mid] < target && target < nums[ri]){ // 在[mid,ri]升序的数组中查找
                le = mid + 1;
            }else{ // 排[mid,ri] 数组, 那么[le,mid - 1] 仍然是一个旋转数组
                ri = mid - 1;
            }
        }else if(nums[mid] > nums[ri]){// le , mid有序
            if(nums[le] <= target && target < nums[mid]){ // 在[le,mid]升序的数组中查找
                ri = mid - 1;
            }else{// 排除[mid,ri] 数组, 那么[le,mid - 1] 仍然是一个旋转数组
                le = mid+1;
            }
        }
    }
    return -1;
}
// int search(vector<int>& nums, int target, int le, int ri){
//     if(le >= ri){
//         return -1;
//     }
//     int mid = (le+ ri)/2;
//     if(nums[mid] == target ){
//         return target;
//     }
//     if(nums[mid] > )
//     if(nums[mid] < target && target < nums[ri]){
//         return search(nums, target, mid + 1, ri);
//     }else if(nums[mid])
// }
int main(){
    vector<int> nums = {1};
    cout <<search(nums, 0) << endl;
}