#include<iostream>
#include<vector>
using namespace std;
string roundToNearest(string str){
    int n = str.size();
    if (str[n-1] < '6'){
        str[n-1] = '0';
        return str;
    }   
    else{
        int i = n-1;
        str[i] = '0';
        i--;
        while(i>=0 && str[i] == '9'){
            str[i] = '0';
            i--;
        }

        if (i == -1){
            return '1'+str;
        }
        str[i]++;
        return str;
    }
}
int main(){
    string str = "9";
    string ans = roundToNearest(str);
    cout<<ans<<endl;
}