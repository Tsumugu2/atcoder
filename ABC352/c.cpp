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
    int N;cin>>N;
    ll ans = 0,A,B,sa = 0;
    rep(i,N){
        cin>>A>>B;
        ans += A;
        sa = max(sa, B-A);
    }
    cout << ans + sa << endl;
    return 0;
}

