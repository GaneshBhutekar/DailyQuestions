#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool findTriplet(vector<int> &arr){
    // sort the array so that 3rd element always find in left side
    int n = arr.size();
    sort(arr.begin(),arr.end());
    // now find pair for the element every time and decrease it
    int end = n-1;
    while(end >= 2){
        int left = 0;
        int right = end-1;
        int value = arr[end];
        while(left<right){
            // check that current pair is equal or not
            if (arr[left]+arr[right] == value){
                return true;
            }
            if (arr[left]+arr[right] > value){
                // decrease the right
                right--;
            }
            else{
                left++;
            }
        }
        end--;
    }

    return false;
}
int main(){
    vector<int> arr = {5, 3, 4};
    if(findTriplet(arr)){
        cout<<"yes"<<endl;
    }
    else{
        cout<<"no"<<endl;
    }

}