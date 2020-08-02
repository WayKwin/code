#include"comm.h"
int treeSum(int n){
    vector<int> a(n+1);
    a[0] = a[1]= 1;
    for(int i = 2; i <= n; i++){ //G(n)
        for(int j = 1; j <=i;j++){
            a[i] += a[j - 1] * a[i - j]; //F(n) = ∑G(i-1) + G(n-i)
        }
    }
    return a[n];
}
int main(){
    cout << treeSum(3)<<endl;
}