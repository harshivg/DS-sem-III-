#include<bits/stdc++.h>
using namespace std;

void selectionSort(vector<int> v, int n){

    for(int i = 0; i < n - 1; i++){
        int mini = i;

        for(int j = i + 1; j < n; j++){
            if(v[j] < v[mini]){
                mini = j;
            }
        }
        swap(v[mini], v[i]);
    }

    for(int x : v){
        cout<<x<<" ";
    }
    cout<<endl;
}

int main(){
    vector<int> v = {5,4,3,2,1};

    //bubbleSort(v, 5);

    selectionSort(v, 5);

    //insertionSort(v, 5);

}