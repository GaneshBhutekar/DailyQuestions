#include<iostream>
#include<vector>
using namespace std;



vector<int> DuplicateNumber(vector<int> arr){
    // make an array 
    // there will be value between 0 to 101
    int store[100] = {0};
    vector<int> ans;
    for(int i : arr){
        if (store[i] == 0){
            ans.push_back(i);
            store[i] = 1;
        }
    }
    return ans;
}
int main(){
    vector<int> arr = {3,2,7,3,2,5};
    vector<int> ans = DuplicateNumber(arr);
    for(int i : ans){
        cout<<i<<" ";
    }
    cout<<endl;

}
