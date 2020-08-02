#include"comm.h"
void setZeroes(vector<vector<int>>& matrix) {
    if(matrix.empty()){
        return;
    }
    int colZero = false;
    int rowZero = false;
   for(int i = 0; i < matrix.size(); i++){
       if(!matrix[i][0]){
           colZero = !colZero;
           break;
       }
   } 
   for(int j = 0; j < matrix[0].size(); j++){
       if(!matrix[0][j]){
           rowZero = !rowZero;
       }
   }
   for(int i = 1; i < matrix.size(); i++ ){
       for(int j = 1; j < matrix[i].size();j++){
           if(!matrix[i][j]){
               matrix[0][j] = matrix[i][0] = 0;
           }
       }
   }
   for(int j = 1; j < matrix[0].size(); j++){
       if(!matrix[0][j]){// 这一列
           for(int i = 0; i < matrix.size() ; i++){
               matrix[i][j] = 0;
           } 
       }
   }
   for(int i = 1; i < matrix.size();i++){
       if(!matrix[i][0]){
           for(int j = 0; j < matrix[0].size();j++){
               matrix[i][j] = 0;
           }
       }
   }
   if(colZero){
    for(int i = 0; i < matrix.size();i++    ){
        matrix[i][0] = 0;
    }
   }
   if(rowZero){
       for(int j = 0; j < matrix[0].size(); j++){
           matrix[0][j] = 0;
       }
   }

}
int main(){
 vector<vector<int> > matrix = {{0,1,1},{1,0,1},{1,1,1}};
 setZeroes(matrix);
 for(auto vec : matrix){
     for(auto ele: vec){
         cout << ele << ' ';
     }
     cout << endl;
 }
}