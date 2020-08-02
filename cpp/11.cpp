#include <iostream>
#include<vector>
using namespace::std;
class balalal{
public:
    int maxArea(vector<int>& height) {
        int max = 0;
        for(int i = 0; i < height.size(); i++){
            int area = 0;
            for (int j = i+1; j < height.size(); j++){
                area = Area(i,j,min(height[i],height[j]));
                if (area > max){
                    max = area;
                }
            }
        }
        return max;
    }
    int Area(int i, int j,int hi){
        return (j - i ) * hi;
    }
};
int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

int maxArea(vector<int>& height){
    int lo = 0;
    int hi = height.size() - 1;
    int maxArea = 0;
    int curArea = 0;
    while(lo + 1 <= hi){
        curArea = min(height[hi] , height[lo]) * (hi - lo);
        if (curArea > maxArea){
            maxArea = curArea;
        }
        if(height[hi] < height[lo]){
            hi--;
        }else{
            lo++;
        }
    }
    return maxArea;
}
