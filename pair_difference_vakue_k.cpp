#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;



void checkHowMany(vector<int> arr,int n, int k,int &total,int left,int right){
    // check for the total how mnay pair come from right.
    while(right < n && arr[right] - arr[left] == k){
        total++;
        right++;
    }
}
int countPairsWithDiffK(vector<int> &arr,int k){
    sort(arr.begin(),arr.end());
    int n = arr.size();
    // now it's two pointer approach
    int left = 0;
    int right = 1;
    int total =0;
    // now check that two number is same or not, if not if it is bigger than move forword , if snaller move backword
    while(left < n){
        int diff = arr[right] - arr[left];
        if (diff == k){
            // at this stage see how  are there who difference is same
            checkHowMany(arr,n,k,total,left,right);
            left++;
        }
        else if (diff < k){
            right++;
        }
        else{
            left++;
        }
        if (right == left){
            right++;
        }
    }

    return total; 
}
int main(){
    vector<int> arr = {1,5,3,4,2};
    int k = 3;
    int ans = countPairsWithDiffK(arr,k);
    cout<<"answer is "<<ans<<endl;

}