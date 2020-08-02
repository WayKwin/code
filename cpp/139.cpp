#include"comm.h"
//dp[i] ==  前i个字符是否可以用字典表示
bool wordBreak(string s, vector<string>& wordDict) {
    vector<bool> dp(s.size()+1,false);
    dp[0] = true;
    for(int i = 1; i <=s.size(); i++){
        for(int j = 0; j < i ; j++){
            cout<<s.substr(j,i-j) << endl;;
            if(dp[j] && find(wordDict.begin(),wordDict.end(),s.substr(j,i-j)) != wordDict.end() ){
                dp[i] = true;
                break;
            }
        }
    }
    return dp[s.size()];
}
int main(){
    auto s = "aaaaaaa";
    vector<string> wordDict = {"aaaa","aaa"};
    cout << wordBreak(s,wordDict) <<endl;
}