#include <bits/stdc++.h>
using namespace std;

void print(vector<int>& v){
    for(int i : v){
        cout<<i<<" ";
    }
    cout<<endl;
}

int findPivot(vector<int>& nums){
    int l = 0, r = nums.size()-1, m;

    while(l < r){
        m = l + (r-l)/2;

        if(nums[m] > nums[r]){
            l = m + 1;
        }
        else if(nums[m] < nums[r]){
            r = m;
        }
        else{
            r --;
        }
    }

    return r;
}

void solve()
{
    int n;
    cin >> n;

    vector<int> nums(n);

    int input = 0;

    for(int i = 0; i < n; i++){
        cin>>nums[i];
    }

    int ans = findPivot(nums);

    // Your solving code goes here
    

    cout <<"Pivot is : "<< ans << endl;
}


int32_t main()
{
    int t = 1;
    cin >> t;

    //sieve(); // Uncomment this if you need to use the sieve

    int test = 1;
    while(t--)
    {
        solve();
        test++;
    }
} 