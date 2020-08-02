#include"comm.h" 
bool isValid(string s) {
    if(s.empty()){
        return true;
    }
    unordered_map<char, char> leftBrace = {
        {'(',')'},
        {'{','}'},
        {'[',']'}
    };
    unordered_map<char, char> rightBrace = {
        {')','('},
        {'}','{'},
        {']','['}
    };
    stack<char> validStack;
    for(auto c = s.begin(); c != s.end(); c++){
        if(rightBrace.find(*c) != rightBrace.end()){
            if(validStack.empty() || validStack.top() != rightBrace[*c]){
                return false;
            }
            validStack.pop();
        }else if(leftBrace.find(*c) != rightBrace.end()){
            validStack.push(*c);
        }
    }  
    if (validStack.empty()){
        return true;
    }
}