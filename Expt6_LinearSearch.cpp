#include<bits/stdc++.h>
using namespace std;

int linearSearch(int num, vector<int>& v){
    int n = v.size();
    for(int i = 0; i < n; i++){
        if(v[i] == num){
            return i;
        }
    }
    return -1;
}


int main(){
    vector<int> v = {4,31,3,1,2};

    int num;
    cin>>num;

    int a = linearSearch(num, v);

    if(a != -1){
        cout<<"Element found at index : "<<a<<endl;
    }
    else cout<<"Element absent";

    return 0;
}