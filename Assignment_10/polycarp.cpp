#include <iostream>
#include <vector>
using namespace std;

class polycarp{
    public:
        int solve(vector<int>& arr,int size);
};

int main(){
    int testcase;
    polycarp game;
    while(true){
        cout<<"Enter The number of Testcases :";
        cin>>testcase;
        if(1<=testcase && testcase <=250){
            break;
        }
        else{
            cout<<"Enter a Valid Testcase"<<endl;

        }
    }
    long int n;
    vector<int>result(testcase);
    while(testcase--){
        while(true){
            cout<<"Enter the num of Elements :";
            cin>>n;
            if((1<=n && n<=200000) ){
                break;
            }
            else{
                cout<<"Enter a Valid Input"<<endl;

            }
        }
        vector<int>arr(n);
        

        for(int i=0;i<n;i++){
            cin>>arr[i];
        }

        result[testcase]=game.solve(arr,n);

    }
    for(int i= result.size()-1;i>=0;i--){
        cout<<result[i]<<endl;
    }


    return 0;
}

int polycarp::solve(vector<int>&arr,int size){
    
    int max1=-1;
    for(int i=0;i<size;i++){
        if(arr[i]>max1){
           max1=arr[i];
        }
    }
    vector<bool> seen(max1,false);
    int count = 0;
    for (int i = size - 1; i >= 0; i--) {
        if (seen[arr[i]]) {
            break;
        }
        seen[arr[i]] = true;
        count++;
    }
    return (size - count);


}