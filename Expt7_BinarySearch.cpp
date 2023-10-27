#include<bits/stdc++.h>
using namespace std;


int binarySearch(int num, vector<int>& v){


    int l = 0, r = v.size() - 1;
    
    while(l <= r){
        int mid = l + (r - l)/2;
        if(v[mid] == num){
            return mid;
        }
        else if(v[mid] > num){
            r = mid - 1;
        }
        else{
            l = mid + 1;
        }
    } 
    return -1;
}

int main(){
    vector<int> v = {1,2,3,4,31};

    int num;
    cin>>num;

    int b = binarySearch(num, v);

    if(b != -1){
        cout<<"Element found at index : "<<b<<endl;
    }
    else cout<<"Element absent";


    return 0;
}