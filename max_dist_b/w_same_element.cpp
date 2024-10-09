#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

int maxDistance(vector<int> &arr){
    unordered_map<int,int> mp;
    int max_dist = 0;
    int n = arr.size();
    for(int i =0;i<n;i++){
        if (mp[arr[i]]){
            // calcuate the distance from first appearnce to recent
            int distance = i - mp[arr[i]]+1;
            // cout<<distance<<" for "  <<arr[i]<<endl;
            max_dist = max(distance,max_dist);
        }
        else{
            mp[arr[i]] = i+1;
        }
    }

    return max_dist;

}
int main(){
    vector<int> arr = {3, 2, 1, 2, 1, 4, 5, 8, 6, 7, 4, 2};
    int ans = maxDistance(arr);
    cout<<"ans is "<<ans<<endl;
}