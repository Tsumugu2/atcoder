#if __has_include(<atcoder/all>)
    #include <atcoder/all>
#endif
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

vector<pair<int,int>> qa0 = {{0,1},{0,2},{1,1},{0,3},{1,2},{2,1},{3,1},{2,2},{1,3},{4,1},{3,2},{2,3},{4,2},{3,3},{4,3}};
vector<pair<int,int>> qa1 = {{1,1},{0,1},{1,2},{2,1},{0,2},{1,3},{2,2},{3,1},{0,3},{2,3},{3,2},{4,1},{3,3},{4,2},{4,3}};
vector<pair<int,int>> qa2 = {{2,1},{1,1},{2,2},{3,1},{0,1},{1,2},{2,3},{3,2},{4,1},{0,2},{1,3},{3,3},{4,2},{0,3},{4,3}};
vector<pair<int,int>> qa3 = {{3,1},{2,1},{3,2},{4,1},{1,1},{2,2},{3,3},{4,2},{0,1},{1,2},{2,3},{4,3},{0,2},{1,3},{0,3}};
vector<pair<int,int>> qa4 = {{4,1},{3,1},{4,2},{2,1},{3,2},{4,3},{1,1},{2,2},{3,3},{0,1},{1,2},{2,3},{0,2},{1,3},{0,3}};

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    ll N;cin>>N;
    // 初期コンテナの２次元配列
    vector<vector<ll>> A(N,vector<ll>(N));
    // 答えの文字列を入れる配列
    vector<vector<string>> ans(N);
    // それぞれの数字が初期コンテナのどこにいるか
    unordered_map<int,pair<int,int>> mp;
    // 盤面に出ている数字の位置
    unordered_map<int,pair<int,int>> MP;
    rep(i,N){
        rep(j,N){
            cin >> A[i][j];
            mp[A[i][j]] = make_pair(i,j);
        }
    }
    // 現在の盤面状況→コンテナを新たに置けるかどうかの判断に使う
    vector<vector<int>> ima(N,vector<int>(N,-1));
    // 各列の次に出るコンテナはどれか
    vector<int> a(N,1);
    set<int> deteru;set<int> nerai;
    for (int i = 0; i < N; ++i){
        nerai.insert(i*5);
    }
    for (int i = 0; i < N; ++i){
        ima[i][0] = A[i][0];
        deteru.insert(ima[i][0]);
        MP[ima[i][0]] = make_pair(i,0);
    }
    pair<int,int> kuren = {0,0};int cut = 0;int motu = -1;
    while (cut != 25){
        motu = -1;int deru = 0;
        while (deru == 0){
            for (auto v : deteru){
                if (nerai.find(v) != nerai.end()){
                    motu = v;
                    deru++;
                    break;
                }
            }
            if (motu == -1){
                int d = 0;
                // 場に出ていないコンテナを検索
                while(motu == -1){
                    for (int i = 0; i < N; ++i){
                        if (a[i] + d > 4) continue;
                        else{
                            if (nerai.find(A[i][a[i]+d]) != nerai.end()){
                                int modoup = 0,modo_l = 0;
                                if (kuren.first != i){
                                    if (kuren.first > i){
                                        for (int j = 0; j < (kuren.first - i); ++j){
                                            ans[0].push_back("U");
                                            modoup--;
                                        }
                                    }
                                    else{
                                        for (int j = 0; j < (i - kuren.first); ++j){
                                            ans[0].push_back("D");
                                            modoup++;
                                        }
                                    }
                                }
                                kuren.first += modoup;
                                if (kuren.second != 0){
                                    for (int j = 0; j < kuren.second; ++j){
                                        ans[0].push_back("L");
                                        modo_l--;
                                    }
                                }
                                kuren.second += modo_l;
                                // 邪魔なコンテナをどかす処理
                                int ai = 0;
                                for (int j = 0; j < (1+d); ++j){
                                    ai = 0;
                                    ans[0].push_back("P");
                                    a[i]++;
                                    for (int k = 0; k < 15; ++k){
                                        if (i == 0){
                                            if (ima[qa0[k].first][qa0[k].second] == -1){
                                                for (int h = 0; h < qa0[k].first; ++h){
                                                    ans[0].push_back("D");
                                                }
                                                for (int h = 0; h < qa0[k].second; ++h){
                                                    ans[0].push_back("R");
                                                }
                                                ans[0].push_back("Q");
                                                for (int h = 0; h < qa0[k].first; ++h){
                                                    ans[0].push_back("U");
                                                }
                                                for (int h = 0; h < qa0[k].second; ++h){
                                                    ans[0].push_back("L");
                                                }
                                                ima[qa0[k].first][qa0[k].second] = ima[i][0];
                                                for (int h = 0; h < qa0[k].first; ++h){
                                                    MP[ima[i][0]].first++;
                                                }
                                                for (int h = 0; h < qa0[k].second; ++h){
                                                    MP[ima[i][0]].second++;
                                                }
                                                deteru.insert(A[i][a[i]-1]);
                                                ima[i][0] = A[i][a[i]-1];
                                                if (j+1 < (1+d)) MP[ima[i][0]] = make_pair(i,0);
                                                break;
                                            }
                                        }
                                        else if (i == 1){
                                            if (ima[qa1[k].first][qa1[k].second] == -1){
                                                if (qa1[k].first > i){
                                                    for (int h = 0; h < (qa1[k].first - i); ++h){
                                                        ans[0].push_back("D");
                                                    }
                                                }
                                                else{
                                                    for (int h = 0; h < (i - qa1[k].first); ++h){
                                                        ans[0].push_back("U");
                                                    }
                                                }
                                                for (int h = 0; h < qa1[k].second; ++h){
                                                    ans[0].push_back("R");
                                                }
                                                ans[0].push_back("Q");
                                                if (qa1[k].first > i){
                                                    for (int h = 0; h < (qa1[k].first - i); ++h){
                                                        ans[0].push_back("U");
                                                    }
                                                }
                                                else{
                                                    for (int h = 0; h < (i - qa1[k].first); ++h){
                                                        ans[0].push_back("D");
                                                    }
                                                }
                                                for (int h = 0; h < qa1[k].second; ++h){
                                                    ans[0].push_back("L");
                                                }
                                                ima[qa1[k].first][qa1[k].second] = ima[i][0];
                                                if (qa1[k].first > i){
                                                    for (int h = 0; h < (qa1[k].first - i); ++h){
                                                        MP[ima[i][0]].first++;
                                                    }
                                                }
                                                else{
                                                    for (int h = 0; h < (i - qa1[k].first); ++h){
                                                        MP[ima[i][0]].first--;
                                                    }
                                                }
                                                for (int h = 0; h < qa1[k].second; ++h){
                                                    MP[ima[i][0]].second++;
                                                }
                                                deteru.insert(A[i][a[i]-1]);
                                                ima[i][0] = A[i][a[i]-1];
                                                if (j+1 < (1+d)) MP[ima[i][0]] = make_pair(i,0);
                                                break;
                                            }
                                        }
                                        else if (i == 2){
                                            if (ima[qa2[k].first][qa2[k].second] == -1){
                                                if (qa2[k].first > i){
                                                    for (int h = 0; h < (qa2[k].first - i); ++h){
                                                        ans[0].push_back("D");
                                                    }
                                                }
                                                else{
                                                    for (int h = 0; h < (i - qa2[k].first); ++h){
                                                        ans[0].push_back("U");
                                                    }
                                                }
                                                for (int h = 0; h < qa2[k].second; ++h){
                                                    ans[0].push_back("R");
                                                }
                                                ans[0].push_back("Q");
                                                if (qa2[k].first > i){
                                                    for (int h = 0; h < (qa2[k].first - i); ++h){
                                                        ans[0].push_back("U");
                                                    }
                                                }
                                                else{
                                                    for (int h = 0; h < (i - qa2[k].first); ++h){
                                                        ans[0].push_back("D");
                                                    }
                                                }
                                                for (int h = 0; h < qa2[k].second; ++h){
                                                    ans[0].push_back("L");
                                                }
                                                ima[qa2[k].first][qa2[k].second] = ima[i][0];
                                                if (qa2[k].first > i){
                                                    for (int h = 0; h < (qa2[k].first - i); ++h){
                                                        MP[ima[i][0]].first++;
                                                    }
                                                }
                                                else{
                                                    for (int h = 0; h < (i - qa2[k].first); ++h){
                                                        MP[ima[i][0]].first--;
                                                    }
                                                }
                                                for (int h = 0; h < qa2[k].second; ++h){
                                                    MP[ima[i][0]].second++;
                                                }
                                                deteru.insert(A[i][a[i]-1]);
                                                ima[i][0] = A[i][a[i]-1];
                                                if (j+1 < (1+d)) MP[ima[i][0]] = make_pair(i,0);
                                                break;
                                            }
                                        }
                                        else if (i == 3){
                                            if (ima[qa3[k].first][qa3[k].second] == -1){
                                                if (qa3[k].first > i){
                                                    for (int h = 0; h < (qa3[k].first - i); ++h){
                                                        ans[0].push_back("D");
                                                    }
                                                }
                                                else{
                                                    for (int h = 0; h < (i - qa3[k].first); ++h){
                                                        ans[0].push_back("U");
                                                    }
                                                }
                                                for (int h = 0; h < qa3[k].second; ++h){
                                                    ans[0].push_back("R");
                                                }
                                                ans[0].push_back("Q");
                                                if (qa3[k].first > i){
                                                    for (int h = 0; h < (qa3[k].first - i); ++h){
                                                        ans[0].push_back("U");
                                                    }
                                                }
                                                else{
                                                    for (int h = 0; h < (i - qa3[k].first); ++h){
                                                        ans[0].push_back("D");
                                                    }
                                                }
                                                for (int h = 0; h < qa3[k].second; ++h){
                                                    ans[0].push_back("L");
                                                }
                                                ima[qa3[k].first][qa3[k].second] = ima[i][0];
                                                if (qa3[k].first > i){
                                                    for (int h = 0; h < (qa3[k].first - i); ++h){
                                                        MP[ima[i][0]].first++;
                                                    }
                                                }
                                                else{
                                                    for (int h = 0; h < (i - qa3[k].first); ++h){
                                                        MP[ima[i][0]].first--;
                                                    }
                                                }
                                                for (int h = 0; h < qa3[k].second; ++h){
                                                    MP[ima[i][0]].second++;
                                                }
                                                deteru.insert(A[i][a[i]-1]);
                                                ima[i][0] = A[i][a[i]-1];
                                                if (j+1 < (1+d)) MP[ima[i][0]] = make_pair(i,0);
                                                break;
                                            }
                                        }
                                        else if (i == 4){
                                            if (ima[qa4[k].first][qa4[k].second] == -1){
                                                for (int h = 0; h < (i - qa4[k].first); ++h){
                                                    ans[0].push_back("U");
                                                }
                                                for (int h = 0; h < qa4[k].second; ++h){
                                                    ans[0].push_back("R");
                                                }
                                                ans[0].push_back("Q");
                                                for (int h = 0; h < (i - qa4[k].first); ++h){
                                                    ans[0].push_back("D");
                                                }
                                                for (int h = 0; h < qa4[k].second; ++h){
                                                    ans[0].push_back("L");
                                                }
                                                ima[qa4[k].first][qa4[k].second] = ima[i][0];
                                                for (int h = 0; h < (i - qa4[k].first); ++h){
                                                    MP[ima[i][0]].first--;
                                                }
                                                for (int h = 0; h < qa4[k].second; ++h){
                                                    MP[ima[i][0]].second++;
                                                }
                                                deteru.insert(A[i][a[i]-1]);
                                                ima[i][0] = A[i][a[i]-1];
                                                if (j+1 < (1+d)) MP[ima[i][0]] = make_pair(i,0);
                                                break;
                                            }
                                        }
                                    }
                                }
                                // 目的のコンテナを搬入口に運ぶ
                                motu = ima[i][0];
                                deteru.erase(ima[i][0]);
                                // 空いた場所に次のコンテナを出す処理
                                deteru.insert(A[mp[motu].first][a[mp[motu].first]]);
                                MP[motu] = make_pair(mp[motu].first,0);
                                deru++;
                                break;
                            }
                        }
                    }
                    ++d;
                }
            }
            deru++;
        }
        // 次のコンテナにクレーンを向かわせる
        if (MP[motu].first > kuren.first){
            for (int i = 0; i < (MP[motu].first - kuren.first); ++i) ans[0].push_back("D");
            kuren.first = MP[motu].first;
        }
        else{
            for (int i = 0; i < (kuren.first - MP[motu].first); ++i) ans[0].push_back("U");
            kuren.first = MP[motu].first;
        }
        if (MP[motu].second > kuren.second){
            for (int i = 0; i < (MP[motu].second - kuren.second); ++i) ans[0].push_back("R");
            kuren.second = MP[motu].second;
        }
        else{
            for (int i = 0; i < (kuren.second - MP[motu].second); ++i) ans[0].push_back("L");
            kuren.second = MP[motu].second;
        }
        ans[0].push_back("P");
        // 排出口に向かわせる
        for (int i = 0; i < (4-kuren.second); ++i) ans[0].push_back("R");
        if ((motu/5) > kuren.first) for(int i = 0; i < ((motu/5) - kuren.first); ++i) ans[0].push_back("D");
        else for(int i = 0; i < (kuren.first - (motu/5)); ++i) ans[0].push_back("U");
        ans[0].push_back("Q");
        kuren.second = 4;kuren.first = motu/5;
        // 次に狙うコンテナの更新
        nerai.erase(motu);
        if (motu%5 != 4) nerai.insert(motu+1);
        // 次のコンテナを出す
        deteru.erase(motu);
        if (MP[motu].second == 0){
            if (a[mp[motu].first] < 5){
                deteru.insert(A[mp[motu].first][a[mp[motu].first]]);
                ima[mp[motu].first][0] = A[mp[motu].first][a[mp[motu].first]];
                MP[ima[mp[motu].first][0]] = make_pair(mp[ima[mp[motu].first][0]].first,0);
                a[mp[motu].first]++;
            }
            else ima[mp[motu].first][0] = -1;
        }
        else{
            ima[MP[motu].first][MP[motu].second] = -1;
        }
        ++cut;
    }
    for (int i = 1; i < N; ++i){
        ans[i].push_back("B");
    }
    string during = accumulate(ans[0].begin(), ans[0].end(), std::string());
    for (int i = 0; i < N; ++i){
        if (i == 0) cout << during << endl;
        else cout << ans[i][0] << endl;
    }
    return 0;
}
