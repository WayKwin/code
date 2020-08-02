#include <iostream>
#include<string>
using namespace::std;
string intToRoman(int num) {
    int number[] = {1000, 900,500,400,100,90,50,40,10,9,5,4,1};
    char* roman[] = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
    string s;
    int  number_len = sizeof(number)/ sizeof(number[0]);
    for(int i = 0; i < number_len; i++){
        while(num >= number[i]){
            num -= number[i];
            s += roman[i];
        }
    }
    return s;
}
int main()
{
    cout << intToRoman(1994) << endl;
    return 0;
}

