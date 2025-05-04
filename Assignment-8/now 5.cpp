//Program to find maximum number of blocks in tower 1
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solve() {
    //Inatialisation
    int n;
    cout<<"Enter the number of towers: ";
    cin>>n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cout<<"Enter the number of blocks in Tower "<<i+1<<": ";
        cin>>a[i];
    }
    //Sorting
    sort(a.begin() + 1, a.end());

    //Shifting Blocks
    int k = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] > k) {
            k += (a[i] - k + 1) / 2;
        }
    }
    cout<<"Number of Blocks: "<<k<<endl;
    return 0;
}

int main(){
    int t;
    cout<<"Enter Number of Test Cases:";
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}