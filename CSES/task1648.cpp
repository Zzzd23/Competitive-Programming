/*#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
#define pb push_back
#define debug(x) cout<<#x<<": "<<x<<"\n"
#define all(x) (x).begin(), x.end()
#define rall(x) (x).rbegin(), x.rend()
#define INF -1
#define vi vector<int>
#define vll vector<long long>
#define vvi vector<vector<int>>
#define sz(a) ((int)a.size())

void read(vector<int> &x){
    for(auto &e:x) cin >> e;
}


struct segtree{
    vi t;
    int N;
    segtree(vi &x){
        N = sz(x);
        t.assign(4 * N, 0);
        build(1, 0, N-1, x);
    }
    void build(int no, int l, int r, vi &x){
        if(l == r){
            t[no] = x[l];
            return;
        }
        int mid = l + (r - l) / 2;
        build(2 * no, l, mid, x); //hijo izquierdo
        build(2 * no + 1, mid+1, r, x); //hijo derecho
        t[no] = (t[2*no] + t[2*no+1]); //union de los 2 hijos, puede ser cualquier operacion
        return;
    }
    int query(int no, int l, int r, int a, int b){
        if(a == l && b == r){ //necesito justo lo que tengo ahora
            return t[no];
        }
        int mid = l + (r - l) / 2;
        if(b <= mid){
            return query(2 * no, l, mid, a, b); //solo importa hijo izquierdo
        }else if(a > mid){
            return query(2*no+1, mid+1, r, a, b); //solo derecho
        }else{
            return (query(2*no, l, mid, a, mid) + query(2*no+1, mid+1, r, mid+1, b)); //union de los 2
        }
    }

    int ask(int l, int r){
        return query(1, 0, N-1, l, r);
    }
    void update(int no, int l, int r, int tar, int val){
        if(l == r){
            t[no] = val;
            return;
        }
        int mid = l + (r - l) / 2;
        if(tar <= mid){
            update(2*no, l, mid, tar, val);
        }else{
            update(2 * no + 1, mid+1, r, tar, val);
        }
        t[no] = (t[2*no] + t[2*no+1]);
        return;
    }
    void updt(int tar, int val){
        update(1, 0, N-1, tar, val);
    }

};

void tc(){
    int n; cin >> n;
    int q; cin >> q;
    vi x(n); read(x);
    segtree tree(x);
    while(q--){
        int t; cin >> t;
        int l, r; cin >> l >> r;
        l--;
        if(t == 2){
            r--;
            cout << tree.ask(l, r) << "\n";
        }else{
            tree.updt(l, r);
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t = 1; //cin >> t;
    while(t--){
        tc();
    }
} Con SegmentTree*/


#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define debug(x) cout<<#x<<": "<<x<<"\n"
#define all(x) (x).begin(), x.end()
#define rall(x) (x).rbegin(), x.rend()
#define oo 1e9
#define vi vector<int>
#define vll vector<long long>
#define vb vector<bool>
#define vvi vector<vector<int>>
#define vvll vector<vector<long long>>
#define vpii vector<pair<int, int>>
#define vpll vector<pair<long long, long long>>
#define vvpii vector<vector<pair<int, int>>>
#define vvpll vector<vector<pair<long long, long long>>>
#define pii pair<int, int>
#define pll pair<long long, long long>
#define si set<int>
#define sll set<long long>
#define sti stack<int>
#define stll stack<long long>
#define stc stack<char>
#define mii map<int, int>
#define mll map<long long, long long>
#define qi queue<int>
#define qll queue<long long>
#define qc queue<char>
#define pqi priority_queue<int>
#define pqll priority_queue<long long>
#define pqpii priority_queue<pair<int, int>>
#define pqpll priority_queue<pair<long long, long long>>
#define pqim priority_queue<int, vector<int>, greater<int>>
#define pqllm priority_queue<long long, vector<long long>, greater<long long>>
#define pqpiim priority_queue<pii, vector<pii>, greater<pii>>
#define pqpllm priority_queue<pll, vector<pll>, greater<pll>>
#define sz(a) ((int)a.size())
#define memfull(x, y) memset(x, y, sizeof(x))
 

struct Fenwick {
    int n;
    vector<ll> bit;

    Fenwick(int n) : n(n), bit(n + 1, 0) {}

    // Agrega delta a la posicion i.
    void add(int i, ll delta) {
        while (i <= n) {
            bit[i] += delta;
            i += i & -i;
        }
    }

    // Suma A[1] + ... + A[i].
    ll query(int i) const {
        ll ans = 0;

        while (i > 0) {
            ans += bit[i];
            i -= i & -i;
        }

        return ans;
    }

    // Suma A[l] + ... + A[r].
    ll rangeSum(int l, int r) const {
        if (l > r) return 0;
        return query(r) - query(l - 1);
    }
};


void tc(){
    
    int n = 0, q = 0;
    cin >> n >> q;

    vi a(n, 0);

    for(int i = 0; i < n; i++) cin >> a[i];


    FenwickTree ft(a);

     for (int i = 1; i <= n; i++) { //índex 1, es fundamental para que i & -i funcione
        ll x;
        cin >> x;
        ft.add(i, x);
    }


    while(q--){

        int t = 0, a = 0, b = 0;
        cin >> t >> a >> b;

        if(t == 1){



        }   else {



        }


    }

}
 
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while(t-->0){
        tc();
    }
}
 