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
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n;cin>>n;
    vector<int> A(n);
    vector<pair<int,int>> ans;
    rep(i,n)cin>>A[i];
    rep(i,n){
        while (A[i] != i+1){
            if (i+1 < A[i]) ans.push_back(make_pair(i+1,A[i]));
            else ans.push_back(make_pair(A[i],i+1));
            swap(A[A[i]-1],A[i]);
        }
    }
    cout << ans.size() << endl;
    if (ans.size() != 0){
        rep(i,ans.size()){
            cout << ans[i].first << " " << ans[i].second << endl;
        }
    }
    return 0;
}

