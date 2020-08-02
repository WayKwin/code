#include"comm.h"
vector<int> printOneCircle(vector<vector<int>>& matrix, int row,int col,int rowLen,int colLen);
vector<int> spiralOrder(vector<vector<int>>& matrix) {
    //auto res = printOneCircle(matrix,0,0,3,3);
    // auto res = printOneCircle(matrix,1,1,1,1);
    auto res = vector<int>{};
    int i = 0;
    int j = 0;
    int colLen = matrix[i].size();
    int rowLen = matrix.size();
    int row = 0;
    int col = 0;
    while(i <= matrix.size() / 2 && j <= matrix[i].size() / 2 && rowLen > 0 &&colLen > 0){
        auto oneCircleResult =  printOneCircle(matrix,i,j,rowLen,colLen);
        for(auto ele : oneCircleResult){
            res.push_back(ele);
        }
        rowLen -= 2;
        colLen -= 2;
        i++;
        j++;

    }
    return  res;
}
vector<int> printOneCircle(vector<vector<int>>& matrix, int row,int col,int rowLen,int colLen){
    vector<int> res;
    // 上
    for(int i = col; i < col+colLen;i++ ){
        res.push_back(matrix[row][i]);
    }
    if(rowLen > 1){
        //左边
        for(int i =row + 1; i <  row+rowLen; i++){
            res.push_back(matrix[i][col + colLen - 1]);
        }
        if(colLen > 1){
            //下边
            for(int i = col+colLen-2;  i >= col; i-- ){
                res.push_back(matrix[row+rowLen-1][i]);
            }
            //右边
            for(int i = row+rowLen -2; i > row ; i--){
                res.push_back(matrix[i][col]);
            }
        }
    }
    return res;
}
int main(){
    // vector<vector<int>> v = {{1,2,3},{4,5,6},{7,8,9}};
    vector<vector<int>> v = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    // vector<vector<int>> v = {{1,2,3,4},{5}};
    vector<int> res = spiralOrder(v);
    for(auto ele : res){
        cout << ele << ' ';
    }
    cout << endl;

}
