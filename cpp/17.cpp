#include<vector>
#include<unordered_map>
#include<iostream>
using namespace std;
unordered_map<char, string> table{
{'0', " "},
{'1',"*"}, 
{'2', "abc"},
{'3',"def"}, 
{'4',"ghi"},
{'5',"jkl"},
{'6',"mno"}, 
{'7',"pqrs"},
{'8',"tuv"},
{'9',"wxyz"}
};

void _core(string digits, int cur, string& curString, vector<string>& allStrings);
vector<string> letterCombinations(string digits) {
    string s;
    vector<string>ret;
    _core(digits, 0, s, ret);
    return ret;
}
void _core(string digits, int cur, string& curString, vector<string>& allStrings){
    if(cur == digits.size()){
        allStrings.push_back(curString);
        return ;
    }
     string s = table[digits[cur]];// 拿到当前的 strings “ABC”
     for(char c : s){  //“对ABC" 进行 DFS
         curString.push_back(c);
         _core(digits,cur+1,curString,allStrings);
         curString.pop_back();
     }
}
void _core_WRONG(string digits, int cur, string& curString, vector<string>& allStrings){
    if(cur == digits.size()){
        allStrings.push_back(curString);
        return ;
    }
    for(int i = cur; i < digits.size(); i++){ // 错误
        for(int j = 0; j < table[digits[i]].size();  j++){
            char curChar = table[digits[i]][j];
            curString.push_back(curChar);
            _core(digits, cur + 1,curString, allStrings);
            curString.pop_back();
        }
    }
}
int main(){
    string digits = "23";
    auto ret = letterCombinations("23"); 
    for(auto s : ret){
        cout << s<< " ";
    }

}
