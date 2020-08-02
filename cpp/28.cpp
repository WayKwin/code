#include"comm.h"

int strStr(string haystack, string needle) {
    int windowSize = needle.size();
    for(int i = 0; i + windowSize <= haystack.size(); i++){
         if (haystack.substr(i,windowSize) == needle){
            return i;    
         }
    }    
    return -1;
}
int main(){
    string a = "aqwertc";
    string  b = "qwert";
    int  res = strStr(a,b);
    if(res == -1){
        cout << "not find" << endl;
    }
    cout << a.substr(res,b.size()) << endl;
    return 0;
}