#include"comm.h"
 void core(int n, string curStr ,string& result);
 string countAndSay(int n) {            
     string curStr = "1";
     string res; 
     core(n,curStr,res);
     return res;
 }
 void core(int n, string curStr ,string& result){
     if(n == 1){
        result = curStr; 
        return;
     }
     string nextStr = "";
     int i = 0;
     while(i < curStr.size()){
         char base = curStr[i];
         int j = i+1;
         int nCount = 1;
         while(j < curStr.size()){
             if(base == curStr[j]){
                 j++;
                 nCount++;
             }else{
                 break;
             }
         }
         i+=(nCount);
         nextStr+= (to_string(nCount) + base);
     }
     core(n-1,nextStr,result);
 }
 int main(){
     for(int i = 1; i <= 6; i++){
     cout << countAndSay(i)<<endl;
     }
 }