#include"comm.h"
bool cmp(vector<int> &x,vector<int> &y){ 
    return x[0] <y[0];
}
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.empty()){
            return vector<vector<int>>();
        }
        //sort
        sort(intervals.begin(), intervals.end(),cmp);
        vector<vector<int> > res;
        res.push_back(intervals[0]);
        int preVec = 0;
        for(int i = 1; i < intervals.size(); i++){
            vector<int>& preVec = res.back();
            vector<int>& curVec = intervals[i]; 
            if(preVec[1] >=curVec[1]){
                continue;
            }
            if(preVec[1] >= curVec[0]){
                preVec[1] = intervals[i][1];
            }else{
                res.push_back(intervals[i]);
            }
        }
        return res;
    }
};
int main(){
    Solution s;
    //vector<vector<int>> intervals = {{1,3},{2,6},{8,10},{15,18}};
    vector<vector<int>> intervals = {{1,4},{2,3}};
    auto res = s.merge(intervals);
    for(auto vec : res ){
        cout <<'{'<<vec[0] << ',' << vec[1] << '}';
    }
    cout <<endl;
    return 0;
}