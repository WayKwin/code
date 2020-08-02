#include"comm.h"
void core(string& a, string& b,int carry,string& result);
string addBinary(string a, string b) {
    string res;
    core(a,b,0, res);
    reverse(res.begin(),res.end());
    return res;
}
void core(string& a, string& b,int carry,string& result){
    if(a.empty() && b.empty()){
        if(carry == 1){
            result.push_back('1');
        }
        return ;
    }
    if(a.empty () && !b.empty()){
        char c = ((b.back() - '0'+ carry) % 2) + '0';
        carry = (b.back() - '0'+ carry) / 2;
        result.push_back(c);
        b.pop_back();
        core(a,b,carry,result);
    } else if(b.empty() && !a.empty()){
        char c = ((a.back() - '0'+ carry) % 2) + '0';
        carry = ((a.back() - '0') + (b.back() - '0')) /2;
        result.push_back(c);
        a.pop_back();
        core(a,b,carry,result); 
    } else {
        char c = (((a.back() - '0') + (b.back() - '0')) %2) + '0';
        carry = ((a.back() - '0') + (b.back() - '0')) /2;
        a.pop_back();
        b.pop_back();
        result.push_back(c);
        core(a,b,carry,result);
    }
}
int main(){
    string a;
    cout << addBinary("11","1");
}