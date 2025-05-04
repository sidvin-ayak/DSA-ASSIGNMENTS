#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int q;
    cout<<"Enter Number of inputs of N (Q):";
    cin>>q;
    int k;
    cout<<"Number of Elements in array a:";
    cin>>k;
    vector<int> a(k);
    for (int i=0;i<k;i++){
        cout<<"Enter Element "<<i+1<<":";
        cin>>a[i];
    }
    sort(a.begin(), a.end());
    while (q--){
        int n;
        cout<<"Enter Number of Players N:";
        cin>>n;
        cout << min(n, a[0] - 1) << "\n";
    }
}