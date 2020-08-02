#include"comm.h"
class Solution {
private:
    vector<vector<bool> > board;
public:
    int totalNQueens(int n) {
        for(int i = 0; i < n; i++){
            vector<bool> a(n,true);
            board.push_back(a);
        }
        int result = 0;
        dfs(0,n,result);
        return result;
    }
    //核心思想：在当前一行中选出来有意义的节点，才进入下一行
    // 因为quee每一行只能有一个，所以每一行都占一个的情况下，就是一种可能
    void dfs(int row,int n,int&result  ){
        if(row == n){
           result += 1;
           return; 
        }
        for(int col = 0; col < n;col++){// 第n行开始的第n列
            if(!isInvalid(row,col)){
                continue;
            }
            board[row][col] = false;
            dfs(row+1, n, result);
            board[row][col] = true;
        }
    }
    bool isInvalid(int row,int col){
        //正对角线 row - col = const
        for(int i = 0; i < board.size();i++){
            for(int j = 0; j <board[i].size(); j++ ){
                if((i ==  row  || j == col ) && board[i][j] == false){
                    return false;
                }
                if ((i + j == row+ col || i -j == row-col) && board[i][j] == false){
                    return false;
                }
            }
        }
        return true;
    }
};
int main(){
    Solution s;
    cout << s.totalNQueens(8) << endl;
}