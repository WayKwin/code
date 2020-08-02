#include"comm.h"
string addInParenthesis(string s){
}
string addBesidesParenthesis(string s){
    return "()";
}
void removeInParenthesis(string& s){
    s = s.substr(1,s.end() - s.begin() - 2);
}

void removeBesidesParenthesis(string &s){
    s.pop_back();
    s.pop_back();
}
void _core(string curString, int curLen, int len,vector<string>& result){
    if(curLen == len){
        result.push_back(curString);
    } 
    curString = addInParenthesis(curString);
    _core(curString, curLen+1,len,result);
    curString = addBesidesParenthesis(curString);
    _core(curString, curLen +1 ,len,result);
}
vector<string> generateParenthesis(int n) {
    if( n < 2){
        return vector<string>{"()"};
    }
    vector<string> result;

    return result;
}
int main(){
    auto ret = generateParenthesis(3);
    // for(auto v : ret){
    //     cout <<v <<endl;
    // }
    return 0;
}