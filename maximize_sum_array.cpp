#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;


long long maxSum(vector<int> arr){
    sort(arr.begin(),arr.end());

    int n = arr.size();
    // every thing comes twice times smaller one and larger ones and in odd case the only left comes one at addition time and one at substraction time
    long long sum = 0;
    for(int i = 0;i<n/2;i++){
        sum -= (2*arr[i]);
        sum += (2* arr[n-i-1]);
    }
    return sum;
}
int main(){
    vector<int> arr = {3,1,2,7,6};
    long long sum = maxSum(arr);
    cout<<sum<<endl;
}