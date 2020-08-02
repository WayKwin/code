#include"comm.h"
int mySqrt(int x) {
    if(x == 0){
        return 0;
    }
    if(x == 1){
        return 1;
    }
    int i = 2;
    for(;i*i <= x; i++){
    }
    return i * i == x? i : i -1;
}
int main(){
    cout << mySqrt(9);
}