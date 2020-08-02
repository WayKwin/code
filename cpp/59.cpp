#include"comm.h"
vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> res(n);
    for(int i = 0; i < n; i++){
        res[i] = vector<int>(n);
    }
    int begin = 1;
    int end = n*n;
    int l = 0; int t = 0; int r = n - 1;int b = n-1;
    while(begin <= end){
        for(int i = l ; i <= r; i++){
            res[t][i] = begin++;
        }
        t++;// t++了，所以右边不用自己下移一个格子
        for(int i = t; i <= b;i++){
            res[i][r] = begin++;
        }
        r--;
        for(int i = r; i >=l ; i--){
            res[b][i] = begin++;
        }
        b--;
        for(int i = b; i >=t; i--){
            res[i][l] = begin++;
        }
        l++;

    }
    return res;
}
int main(){
    for(auto vec : generateMatrix(3)){
        for(auto ele : vec){
            cout << ele << ' ';
        }
        cout << endl;
    }
}