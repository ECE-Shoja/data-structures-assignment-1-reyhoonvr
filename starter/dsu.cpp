#include <bits/stdc++.h>
using namespace std;

vector<int> parent, sz;

int findSet(int v) {
    if(parent[v]==v){
        return v;}
    int leader=findSet(parent[v]);
    parent[v]=leader;
    return leader;}

}

void unionSet(int a, int b) {
    int A=findSet(a);
    int B=findSet(b);
    if(A==B) return;
    if(sz[A]<sz[B]){
        parent[A]=B;
        sz[B]+=sz[A];}
    else{
        parent[B]=A;
        sz[A]+=sz[B];}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    parent.resize(n + 1);
    sz.resize(n + 1, 1);

    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }

    while (q--) {
        char type;
        int a, b;
        cin >> type >> a >> b;

        if (type == '+') {
            unionSet(a, b);
        } else if (type == '?') {
            if (findSet(a) == findSet(b)) cout << "YES\n";
            else cout << "NO\n";
        }
    }

    return 0;
}
