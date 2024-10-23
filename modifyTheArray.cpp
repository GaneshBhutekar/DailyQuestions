#include<iostream>
#include<vector>
using namespace std;


vector<int> modifyAndRearrangeArray(vector<int> &arr){
    // first create the vector to return it
    int n = arr.size();
    vector<int> ans(n,0);
    // to add in the ans we have to do.
    int point = 0;
    // traverse the array and check for the non integer there
    int i = 0;
    while(i<n){
        // check for the non zero
        if (arr[i] != 0) {
            if(i+1 != n && arr[i+1] == arr[i]){
                // here input the value in double in the ans and move 
                ans[point] = 2* arr[i];
                point++;
                i = i+2;
            }
            else{
                // it means the next array is not equal to the curr element or it is last element 
                // then simply push it and move next
                ans[point] = arr[i];
                point++;
                i++;
            }
        }
        else{
            i++;
        }
    }

    // now we have modified array returned it 
    return ans;
}
int main(){
    vector<int> arr = {3,3};
    vector<int> ans = modifyAndRearrangeArray(arr);
    for(int i : ans){
        cout<<i<<" ";
    }
    cout<<endl;
    
}