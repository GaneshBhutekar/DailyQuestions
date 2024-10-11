#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;
int pairWithMaxSum(vector<int> & arr){
    int n = arr.size();
    if (n ==1){
        return -1;
    }

    int first = 0;
    int last = 1;
    int count = arr[first] + arr[last];
    int max_count = count;
    while(last < n-1){
        first++;
        last++;
        count = arr[first]+arr[last];
        max_count = max(max_count,count);
    }
    return max_count;
}
int main(){
    vector<int>  arr = {25,3,1,5,16,10,12};
    cout<<"largest outcome of two small element of subarray is "<<pairWithMaxSum(arr)<<endl;

}