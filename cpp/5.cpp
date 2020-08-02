#include<iostream>
#include<string>
#include<vector>
using namespace::std;
int findPalindromeLen(string s,int left, int right);
string longestPalindrome(string s) {
    int maxLen = 0;
    string result;
    for(int i = 0 ; i < s.size(); i ++){
        int oddLen = findPalindromeLen(s,i-1, i+1) + 1;
        int evenLen = findPalindromeLen(s,i,i+1);
        int evenStart = i - (evenLen - 1) / 2;
        int oddStart = i - (oddLen - 1) / 2;
        if (oddLen > maxLen ){
            maxLen = oddLen;
            result = s.substr(oddStart,oddLen);
        }
        if (evenLen > maxLen){
            maxLen = evenLen;
            result = s.substr(evenStart,evenLen);
        }
    }
    return result;
}
int findPalindromeLen(string s,int left, int right){
    int len = 0;
    while(left >= 0 & right < s.size() && s[left] == s[right]){
        len+=2; 
        left--;
        right++;
    }
    return len;
}
int main(){
//cout << longestPalindrome("bb")   <<endl;
 
}