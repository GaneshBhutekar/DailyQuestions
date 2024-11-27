#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void printit(vector<int> arr){
    for(int i : arr){
        cout<<i<<" ";
    }
    cout<<endl;
}
void replace(vector<int> &arr,int n){
    for(int i = 0;i<n;i++){
        if (arr[i] < 0){
            arr[i]=0;
        }
    }
}


void present(vector<int> &arr,int n){
    // just put the negative on the values -1 index
    for(int i =0;i<n;i++){
        int element = abs(arr[i]);
        // check if it is non zer0
        if (element <=n && element != 0 && arr[element-1] >=0){

            if (arr[element-1] == 0){
                cout<<"problem "<<arr[element-1]<<endl;
                arr[element-1] = -1* (n+1);
            }else{
            arr[element-1]*=-1;
            }
        }
    }
}


int missingNumber(vector<int> &arr){
    // replace thw negatives with the 0 
    int n = arr.size();
    replace(arr,n);
    printit(arr);
    cout<<"we reached here" <<endl;

    // now put negative sign which i -1 is present in the array
    present(arr,n);
    // now just get the first missing positive integer
    printit(arr);
    int i=0;
    while(i<n && arr[i]<0){
        // just find the positive number
        i++;
    }
    return i+1;

}
int main(){
    vector<int> arr = {0,-10,1,3,-20};
    int ans = missingNumber(arr);
    cout<<ans<<endl;

}