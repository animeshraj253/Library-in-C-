#include<iostream>
#include<vector>
#include<numeric>

using namespace std;

int main(){

    vector<vector<int>> mat = {{1,2,3,3},
                               {4,5,6},
                               {7,8,9}
                              };

    // for ( int i = 0; i<mat.size())
    // cout<<mat[0][1];
    // for(int i = 0;i<mat.size();i++){
    //     cout<<mat[0][i]<<endl;
    // }
    
    // for (auto i : mat){
    //     for(auto j : i){
    //         cout<<j<<" ";
    //     }
    //     cout<<endl;
    // }
    
    vector <int> ans;
    int rows = mat.size();
    ans.reserve(rows);
    // for(int i = 0; i<mat.size();i++){
    //     for(int j=0;j<mat[i].size();j++){
    //         cout<<mat[i][j]<<" ";
    //     }cout<<endl;
    // }
    for(auto &i : mat){
        ans.push_back(accumulate(i.begin(),i.end(),0));
    }

    for (auto i : ans){
        cout<< i << endl;
    }

    cout << endl;
    return 0;
}