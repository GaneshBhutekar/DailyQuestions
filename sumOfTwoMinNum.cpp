#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*
desc:
Given an array arr[] such that each element is in the range [0 - 9], find the minimum possible sum of two numbers formed using the elements of the array. All digits in the given array must be used to form the two numbers. Return a string without leading zeroes.

Examples :

Input: arr[] = [6, 8, 4, 5, 2, 3]
Output: 604
Explanation: The minimum sum is formed by numbers 358 and 246.

*/

void reverseit(string &str,int cnt){
    int start = 0;
    int end = cnt-1;
    while(start < end){
        swap(str[start],str[end]);
        start++;
        end--;
    }
}
void print(vector<int> arr){
    for(int i : arr){
        cout<<i<<" ";
    }
    cout<<endl;
}
string minSum(vector<int> &arr){
    sort(arr.begin(),arr.end(),[](int a,int b){
        return a > b;
    });


    int n = arr.size();
    int i =0;
    string str = "";
    int cnt =0;
    int carry = 0;
    while(i<n && i != n-1 && arr[i] !=0){
        int num1 = arr[i++];
        int num2 = arr[i++];
        int ans = num1+num2+carry;
        int value = ans%10;
        carry = ans/10;
        // put the value into the string converting it
        char inchr = value+'0';
        str.push_back(inchr);
        cnt ++;
    }
    if (i<n && arr[i] != 0){
        int ans = carry+ arr[i];
        carry = ans/10;
        int value = ans%10;
        char inchr = value+'0';
        str.push_back(inchr);
        cnt++;
    }
    if (carry !=0){
        char inchr = carry + '0';
        str.push_back(inchr);
        cnt++;
    }
    reverseit(str,cnt);
    return str;
}
int main(){
    // vector<int> arr = {7, 0, 8, 9, 3, 3, 9, 2, 9, 1, 5, 6, 7, 9, 4, 3, 9, 5, 5, 8, 7, 8, 0, 2,5, 7, 3, 6, 8, 3, 6, 9, 9, 3, 0, 3, 3, 7, 8, 7, 0, 5, 4, 3, 6, 2, 4, 9, 9, 6, 7, 3, 1, 0, 9, 4, 1, 2,5, 8, 3, 6, 3, 6, 3, 9, 5, 0, 5, 3, 8, 2, 6, 6, 1, 2, 6, 9, 2, 7, 3, 9, 3, 9, 0, 8, 8, 1, 6, 9, 0, 0, 6, 7, 1, 1, 1, 0, 6, 5, 4, 3, 8, 6, 1, 3, 3, 2, 7, 4, 1, 4, 5, 5, 8, 0,6, 3, 5, 8, 4, 7, 4, 1, 7, 9, 5, 1, 5, 4, 0, 1, 8, 6, 8, 0, 7, 2, 6, 9, 1, 9, 0, 1, 9, 1, 8, 5, 5, 0, 0, 6, 3, 3, 8, 8, 0, 5, 0, 8, 3, 9, 5, 8, 6, 7, 1, 3, 4, 5, 9, 8, 4, 6, 9, 8, 5, 8, 5, 3, 7, 7, 8, 7, 3, 6, 4, 7, 8,4, 5, 7, 5, 7, 6, 4, 2, 6, 1, 0, 3, 5, 5, 3, 9, 6, 7, 5, 3, 9, 4, 9, 4, 3, 9, 5, 6, 7, 8, 0, 8, 8, 8, 6, 1, 1, 1, 2, 9, 6, 0, 3, 3, 5, 7, 1, 9, 0, 6, 1, 5, 4, 9, 5, 3, 6, 2, 9, 4, 7, 1, 0, 8, 7, 7, 2, 6, 0, 9, 3, 4, 5, 8, 3, 9, 0, 6, 2, 1, 0, 5, 7, 2, 2, 3, 5, 2, 5, 0, 0, 5,9, 0, 0, 9, 0, 9, 4, 9, 5, 9, 2, 1, 3, 6, 0, 0, 9, 0, 2, 1, 2, 5, 6, 8, 1, 0, 7, 4, 4, 6, 4, 4, 6, 2, 6, 0, 0, 4, 0, 3, 9, 9, 5, 6, 1, 7, 5, 8, 2, 5, 1, 3, 4, 6, 4, 4, 4, 3, 3, 7, 6, 8, 1, 4, 7, 3, 5, 2, 6, 1, 6, 9, 3, 0, 8, 0, 9, 5, 3, 5, 4, 2, 9, 5, 0, 5, 7, 2, 1, 1, 8, 8, 1, 7, 8, 3, 4, 9, 9, 9, 1, 3, 8, 9, 4, 7, 8, 7, 6, 5, 4, 4, 9, 4, 9, 3, 1, 8, 5, 8, 7, 0, 0, 8, 7, 7, 3, 2, 6, 8, 4, 8,2, 1, 7, 8, 2, 6, 0, 4, 9, 7, 5, 8, 1, 9, 2, 3, 8, 7, 7, 1, 7, 7, 1, 2, 3, 8, 4, 8, 3, 7, 4, 5, 9, 8, 8, 4, 4, 3, 6, 2, 5, 9, 0, 2, 2, 2, 6, 1, 9, 5, 7, 0, 0, 2, 1, 2, 7, 7, 8, 1, 4, 0, 1, 4, 5, 4, 9, 3, 5, 1, 2, 9, 9, 8, 3, 1, 6, 3};
    vector<int> arr = {5,3,0,7,4};
    string ans = minSum(arr);
    cout<<ans<<endl;

}