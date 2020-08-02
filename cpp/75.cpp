#include"comm.h"

void sortColors(vector<int>& nums) {
    if(nums.empty()){
        return;
    }
    int p0 = 0;
    int cur = 0;
    int p2 = nums.size() - 1;
    while(cur <= p2){
        if(nums[cur] == 0){
            swap(nums[p0],nums[cur]);
            p0++;
            cur++;
        }else if(nums[cur] == 2){
            swap(nums[cur],nums[p2]);
            p2--;
        }else{
            cur++;
        }
    }    
}
int main(){
    priority_queue<int, vector<int>, greater<int> > q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.pop();
    cout << q.top();
}