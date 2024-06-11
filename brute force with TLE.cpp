#include <bits/stdc++.h>
using namespace std;
#define FAST_DOT_COM  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define int long long
const int N = 3e4+5 ,MOD=1e9+7, INF=0X3F3F3F3F , MAX= 1e9+7;
bool comp(pair<int, int> &a,pair<int,int> &b) {
    if (a.first != b.first) return a.first > b.first;
    return a.second < b.second;
}
int ans=0 , vis[1000005] , L=0 ,R=0 , a[N];
bool first=1;
void add(int idx){
    if(!vis[a[idx]]){
        ans++;
    }
    vis[a[idx]]++;
}
void remove(int idx){
    vis[a[idx]]--;
    if(!vis[a[idx]]){
        ans--;
    }
}
int go(int l , int r){
    if(first){
        for (int i = l; i <= r ; ++i) {
            add(i);
        }
        L=l ;
        R=r;
        first=0;
    }
    else {
        while (l<L)L--,add(L);
        while (L<l)remove(L),L++;
        while (r>R)R++,add(R);
        while (r<R)remove(R),R--;
    }
    return ans;
}
void solve() {
    int n ;
    cin >> n ;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int q ;
    cin >> q ;
    while (q--){
        int l , r ;
        cin >> l >> r ;
        l--, r--;
        cout<<go(l,r)<<"\n";
    }
}
int32_t main(){
    FAST_DOT_COM
//#ifndef ONLINE_JUDGE
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
//#endif
    int t=1 ;
//    cin>>t ;
    while (t--) solve();
    return 0;
}
