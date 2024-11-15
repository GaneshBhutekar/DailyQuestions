#include<iostream>
#include<vector>
using namespace std;

int getSecondLargest(vector<int> &arr){
    // find the second lkargest sum.
    int largest = INT_MIN;
    int sec_largest = INT_MIN;
    for(int i : arr){
        if(i > largest){
            if (largest != i){
                sec_largest = largest;
            }
            largest= i;
        }

        else if (i > sec_largest && i != largest){
            sec_largest = i;
        }
    }
    return sec_largest;
}
int main(){
    vector<int> arr = {12, 39, 1, 10, 34, 40,40,1};
    int ans = getSecondLargest(arr);
    cout<<ans<<endl;

}