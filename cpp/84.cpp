#include"comm.h"
int largestRectangleArea1(vector<int>& heights) {
    unsigned long size = heights.size();
    if (size == 1) {
        return heights[0];
    }
    int res = 0;
    stack<int> stk;
    for(int i = 0; i < size; ++i){
        while(!stk.empty() && heights[stk.top()] > heights[i]){
            int length = heights[stk.top()];
            stk.pop();
            int weight = i;
            if(!stk.empty()){
                weight = i - stk.top() - 1;
            }
            res = max(res,weight * length);
        }
        stk.push(i);
    }
    while(!stk.empty()){
        int height = heights[stk.top()];
        cout << height << endl;
        stk.pop();
        int width = size;
        if(!stk.empty()){
            width = size - stk.top() - 1;
        }
        res = max(res,  width * height);
    }
    return res;
}
int main(){
    vector<int> a = {2,0,1,0,1,0};
    cout << largestRectangleArea1(a);


}