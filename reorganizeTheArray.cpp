#include<iostream>
#include<vector>
using namespace std;

vector<int> rearrange1(const vector<int> &arr){
    // we can make it in no space but it want me to does not make any changes in the orignal array
    int n = arr.size();
    vector<int> ans(n,-1);
    for(int i=0;i<n;i++){
        if (arr[i] != -1 && arr[i] < n){
            ans[arr[i]] = arr[i];
        }
    }
    return ans;

}

vector<int> rearrange(vector<int> &arr){
    int n = arr.size();
    int i =0;
    while(i<n){
        if (arr[i] != -1 && arr[i] < n && arr[i]){
            //swap is simple
            swap(arr[i],arr[arr[i]]);
            if (arr[i] == i){
                i++;
            }
        }
        else if (arr[i] >= n){
            arr[i] = -1;
            i++;
        }
        else{
            i++;
        }
    }

    return arr;
}
int main(){
    vector<int>arr = {-1, 16, 6, 150, 9, 3, 2, -1, 4, -1};
    vector<int> ans = rearrange(arr);
    for(int i : ans){
        cout<<i<<" ";
    }
    cout<<endl;
}