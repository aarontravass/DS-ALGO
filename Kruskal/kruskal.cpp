#include <bits/stdc++.h>
#define ll long long int
#define ull unsigned long long int
#define forn(i,n)for(ll i=0;i<(n);i++)
#define forn_rev(i,n)for(ll i=(n)-1;i>=0;i--)
#define for1n(i,n) for(ll i=1;i<=(n);i++)
#define ARRAY_SIZE(a) sizeof(a)/sizeof(*a)
#define MOD 1000000007

using namespace std;
ll nodes,edges;
pair<ll,pair<ll,ll>> adj[50];
vector<ll> parent(50);

void init(){
    forn(i,parent.size()) parent[i]=i;
}


ll find_set(ll v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(ll a, ll b) {
    a = find_set(a);
    b = find_set(b);
    if(a!=b)
        parent[b]=parent[a];
}

ll kruskal(ll vertex,ll edges){
    ll x,y;
    ll cost,mincost=0;
    forn(i,edges){
        x=adj[i].second.first;
        y=adj[i].second.second;
        cost=adj[i].first;
        if(find_set(x)!=find_set(y)){
            mincost+=cost;
            union_sets(x,y);
        }
    }
    return mincost;

}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);cout.tie(NULL);
    init();
    ll x,y,w;
    cin>>nodes>>edges;
    forn(i,edges){
        cin>>x>>y>>w;
        adj[i]=make_pair(w,make_pair(x,y));
    }
    sort(adj,adj+edges);
    cout<<kruskal(nodes,edges)<<endl;




    return 0;
}
