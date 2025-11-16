#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool twoSum(vector<int>& arr, int target) {
        int l = 0;
        int r = arr.size()-1;
        sort(arr.begin(),arr.end());
        cout<<"Sorted array "; 
        for(auto i : arr){
            cout<<i<<" ";
        }cout<<endl;

        while (l<r){
            int sum = arr[l]+arr[r];
            cout<<"Sum = "<<sum<<endl;
            if(sum == target){
                cout<<"in return block"<<endl;
                return true;
            }
            else if (sum > target){
                cout<<"in r-- block"<<endl;
                r--;
            }
            else if( sum < target){
                cout<<"in l++ block"<<endl;
                l++;
            }
        }
        return false;
    }
};

int main(){

    int t = -2;
    vector<int> arr = {0,-1,2,-3,1};

    Solution s;
    cout<<"Ans " << s.twoSum(arr,t)<<endl;

    return 0;
}