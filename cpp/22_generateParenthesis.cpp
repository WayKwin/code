#include"comm.h"
using namespace std;
void dfs(vector<string>& result,int left, int right,string& curString){
    if(left == 0 && right == 0){
        result.push_back(curString);
        return;
    }
    if(right < left){
        return;
    }
    if(left > 0){
        curString.push_back('(');
        dfs(result, left - 1,right,curString);
        curString.pop_back();
    }
    if(right > 0){
        curString.push_back(')');
        dfs(result, left, right-1,curString);
        curString.pop_back();
    }
}
vector<string> generateParenthesis(int n) {
    vector<string> result;
    string curString = "";
    dfs(result,n,n,curString);
    return result;
}
int main(){
    auto result = generateParenthesis(3);
    for(auto s : result){
        cout << s << endl;
    }
}