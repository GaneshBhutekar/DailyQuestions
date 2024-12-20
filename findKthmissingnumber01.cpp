#include<iostream>
#include<vector>


/*
    DESCRIPTION:
    Given a sorted array of distinct positive integers arr[]
    , we need to find the kth positive number that is missing from arr[].  

*/

int KthMissing(std::vector<int> &arr,int k){
    // got till maximum and increase k always
    int n = arr.size();
    int position = 1;
    int num = 1;
    int i = 0;
    while(i<n){
        if (num != arr[i]){
            if (position == k){
                return num;
            }
            num++;
            position++;

        }
        else{
            num++;
            i++;
        }

    }

    // till jere position is not equal to the K so make it equal
    // position++;
    // while(position != k){
    //     num++;
    //     position++;
    // }
    // return num;
    // OR
    return k+n;

}
int main(){
    std::vector<int> arr = {2,3,4,7,11};
    int ans = KthMissing(arr,100);
    std::cout<<"answer is "<<ans<<std::endl;
}