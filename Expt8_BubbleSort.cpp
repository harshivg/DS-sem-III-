#include<bits/stdc++.h>
using namespace std;

void bubbleSort(vector<int> &v, int n){

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n-i-1; j++){
            if(v[j+1] < v[j]){
                swap(v[j+1], v[j]);
            }
        }
    }

    for(int x : v){
        cout<<x<<" ";
    }
    cout<<endl;
}


int main(){
    vector<int> v = {5,4,3,2,1};

    bubbleSort(v, 5);

}