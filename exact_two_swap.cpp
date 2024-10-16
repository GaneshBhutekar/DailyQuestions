#include<iostream>
#include<vector>
using namespace std;

bool checksorted(vector<int> &arr){ 
    // not good approach
    int n = arr.size();
    if (n < 2){
        return false;
    }
    int shifts = 2;
    int i = 1;

    while(i<n){
        if (arr[i-1] > arr[i]){
            // means larger value come before smaller value so find it's worth element
            int j = i+1;

            // get smallest number index.
            int min = i;
            while(j<n){
                if (arr[min] > arr[j]){
                    min = j;
                }
                j++;
            }
            // now we have the i-1 and the min value than next to i-1
            swap(arr[min],arr[i-1]);
            shifts--;
            if (shifts == 0){
                break;
            }
        }

        else {
            i++;
        }
    }

    if (shifts == 2){
        return true;
    }
    if (shifts != 0){
        return false;
    }
    // now we did 2 swap now check again through iterate
    for(int i =1;i<n;i++){
        if (arr[i-1] > arr[i]){
            return false;
        }
    }

    return true;
}




int main(){
    vector<int> arr = {1,2,4,3,5,6};
    // 1,2,8,4,3,6,7,5
    // 4,3,1,2
    if (checksorted(arr)){
        cout<<"yes it required exactly 2 swap"<<endl;
    }
    else{
        cout<<"no it does not need exact 2 swap"<<endl;
    }
}