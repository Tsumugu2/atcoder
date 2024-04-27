#include <atcoder/all>
#include <bits/stdc++.h>
#include <regex>
#include <cassert>
#include <numeric>
#define rep(i, n) for(ll i=0; i<(n);i++)
#define all(i) begin(i),end(i)
using namespace std;
using namespace atcoder;
using Graph = vector<vector<int>>;
using ll = long long;

int main(){
    int n;cin>>n;
    vector<vector<char>> A(n,vector<char>(n)),B(n,vector<char>(n));
    rep(i,n){
        rep(j,n){
            cin>>A[i][j];
        }
    }
    rep(i,n){
        rep(j,n){
            cin>>B[i][j];
        }
    }
    rep(i,n){
        rep(j,n){
            if (A[i][j] != B[i][j]){
                cout << i+1 << " " << j+1 << endl;
                break;
            }
        }
    }
    return 0;
}