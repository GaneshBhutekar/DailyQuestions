#include<iostream>
#include<vector>
#include<queue>


bool searchRowMatrix(std::vector<std::vector<int>> &mat,int x){
    int row = mat.size(); // rows
    int col = mat[0].size(); // col
    // go to everry row
    for(int i =0;i<row;i++){
        int start = 0;
        int end = col-1;
        int mid = start+(end-start)/2;
        while(start<=end){
            if (mat[i][mid] == x){
                return true;
            }
            else if (mat[i][mid] < x){
                start = mid+1;

            }
            else{
                end = mid-1;
            }
            mid = start + (end-start)/2;
        }

    }
    return false;
}
int main(){
    std::vector<std::vector<int>> mat = {
        {3,4,9},
        {2,5,6},
        {9,25,27},
        {7,8,16}
    };
    std::cout<<"enter the number you want to add "<<std::endl;
    int x;
    std::cin>>x;
    if(searchRowMatrix(mat,x)){
        std::cout<<"yes the element is present"<<std::endl;
    }else{
        std::cout<<"it is not present"<<std::endl;
    }

}