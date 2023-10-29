#include<bits/stdc++.h>
using namespace std;

void insertionSort(vector<int> &arr, int n){

    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        
        arr[j + 1] = key;
    }

    for(int x : arr){
        cout<<x<<" ";
    }
    cout<<endl;
}

int main(){
    vector<int> v = {5,4,3,2,1};
    insertionSort(v, 5);

}