#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>


using namespace std;
bool checkDuplicateWithinK(vector<int> &arr,int k){
    // we will use dictionary here.
    int n = arr.size();
    unordered_map<int,int> mp;
    // now put initial window in it
    for(int i =0;i<= k;i++){
        if (mp[arr[i]]){
            return true;

        }
        // if not then 
        mp[arr[i]] = 1;

    }

    // now we put remaining one
    int i = 1;
    mp[arr[i-1]] = 0;
    int last =k+1;
    while(last < n){
        // remove the 
        if (mp[arr[last]] == 1){
            // cout<<arr[last]<<endl;
            return true;
        }
        mp[arr[last]]= 1;
        mp[arr[i]] = 0; // delete the left one 
        i++; // increase the left one
        last++; // add new element for further check.
    }

    // here we realize that there is not any duplicate in any k window so return false
    return false;

}
int main(){

    vector<int> arr = {6, 8, 4, 1, 8, 5, 7};
    int k = 3;
    if (checkDuplicateWithinK(arr,k)){
        cout<<"yes there is duplicate "<<endl;
    }
    else{
        cout<<"no! there is not any duplicate"<<endl;
    }

}