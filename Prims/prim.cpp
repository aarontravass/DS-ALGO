#include <bits/stdc++.h>
#define ll long long int
#define ull unsigned long long int
#define forn(i,n)for(ll i=0;i<(n);i++)
#define forn_rev(i,n)for(ll i=(n)-1;i>=0;i--)
#define for1n(i,n) for(ll i=1;i<=(n);i++)
#define ARRAY_SIZE(a) sizeof(a)/sizeof(*a)
#define MOD 1000000007
#define sz 100

using namespace std;

vector<pair<ll,ll>> adj[sz];
bool visited[sz];
priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater< pair<ll,ll> > > pq;

ll prim(ll s){
    memset(visited,0,sizeof(visited));
    pq.push(make_pair(s,0));
    ll minsoct=0;
    while(!pq.empty()){
        pair<ll,ll> a=pq.top();
        ll u=a.first;
        pq.pop();
        if(visited[u]) continue;
        visited[u]=1;
        minsoct+=a.second;
        for(ll i=0;i<adj[u].size();i++){
            ll y=adj[u][i].first;
            if(!visited[y]) pq.push(adj[u][i]);
        }


    }
    return minsoct;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);cout.tie(NULL);

    ll x,y,w,edges;
    cin>>edges;
    forn(i,edges){
        cin>>x>>y>>w;
        adj[x].push_back(make_pair(y,w));
        adj[y].push_back(make_pair(x,w));
    }

    cout<<prim(1)<<endl;




    return 0;
}
