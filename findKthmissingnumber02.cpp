#include<iostream>
#include<vector>


/*
    DESCRIPTION:
    Given a sorted array of distinct positive integers arr[]
    , we need to find the kth positive number that is missing from arr[].  

*/

int KthMissing(std::vector<int> &arr,int k){
    // first check it the k missing is outside the array
    int n = arr.size();
    if (arr[n-1]-n < k){
        std::cout<<"1"<<std::endl;
        return n+k;
    }
    // if it is smaller than second element
    if (arr[0]-1 >= k){
        std::cout<<"2"<<std::endl;
        return k;
    }
    
    // if it is between the array then we will find it by binary search
    // find the mid which is greateer then the missing value
    int start = 0;
    int end = n-1;
    int mid = start+(end-start)/2;

    while(start<=end){
        if (arr[mid]-(mid+1) < k){
            start = mid+1;            
        }
        else{
            end= mid-1;
        }
        mid = start +(end-start)/2;
    }

    // whatever mid value is there go one less
    return mid+k;
}
int main(){
    std::vector<int> arr = {3, 5, 9, 10, 11, 12};
    int k= 5;
    int ans = KthMissing(arr,k);
    std::cout<<"answer is "<<ans<<std::endl;


    
}