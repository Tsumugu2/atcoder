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
    int n,a;cin>>n;
    vector<int> balls;
    rep(i,n){
        cin>>a;
        balls.push_back(a);
        while (balls.size() > 1){
            int last = balls.back();
            int secondLast = balls[balls.size() - 2];
            if (last != secondLast){
                break;
            }
            else{
                balls.pop_back();
                balls.pop_back();
                balls.push_back(last + 1);
            }
        }
    }
    cout << balls.size() << endl;
    return 0;
}

