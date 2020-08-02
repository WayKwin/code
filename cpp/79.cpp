#include"comm.h"
bool dfs(int curI,int curJ, int pos,const string& word,vector<vector<bool>>&visited,const vector<vector<char>>board){
    if(curI >= board.size() || curJ >= board[curI].size() || pos >= word.size() ){
        return false;
    }
    if(visited[curI][curJ]){
        return false;
    }
    if(board[curI][curJ] != word[pos]){
        return false;
    }
    if(pos ==  word.size() - 1){
        return true;
    }
    visited[curI][curJ] = true;
    if(dfs(curI,curJ+1,pos+1,word,visited,board)) return true;
    
    if(dfs(curI+1,curJ,pos+1,word,visited,board)) return true;

    if(dfs(curI,curJ-1,pos+1,word,visited,board)) return true;

    if(dfs(curI-1,curJ,pos+1,word,visited,board)) return true;
    visited[curI][curJ] = false;
    return false;
}
bool exist(vector<vector<char>>& board, string word) {
    vector<vector<bool>> visited(board.size());
    for(int i = 0; i < board.size(); i++){
        visited[i] = vector<bool>(board[i].size());
    }    
    for(int i = 0; i< board.size(); i++){
        for(int j = 0; j < board[i].size(); j++){
            if(dfs(i,j,0,word,visited,board)) return true;
        }
    }
    return false;
}
int main(){
    vector<vector<char>> board = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    cout<< exist(board,"ABCB");
}