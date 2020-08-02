#include"comm.h"
string s = "012";
vector<bool> visited(s.size());
void printStat(int depth){
    for(int i = 0; i < depth; i++){
        cout <<"  ";
    }
    for(int i = 0 ; i <visited.size();i++){
        cout <<visited[i] << ' ';
    }
    cout << endl;
}
void dfs(int depth){
    if(depth == s.size()){
        return;
    }
    for(int i =0; i < s.size(); i++){
        if(visited[i]){
            continue;
        }
        visited[i] = true;
        printStat(depth);
        dfs(depth+1);
        visited[i] = false;
    }
}
int main(){
    dfs(0);
}