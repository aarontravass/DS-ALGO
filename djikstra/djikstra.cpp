#include <bits/stdc++.h>
#define ll long long int
#define ull unsigned long long int
#define forn(i,n)for(ll i=0;i<(n);i++)
#define forn_rev(i,n)for(ll i=(n)-1;i>=0;i--)
#define for1n(i,n) for(ll i=1;i<=(n);i++)
#define ARRAY_SIZE(a) sizeof(a)/sizeof(*a)
#define MOD 1000000007
#define MAXN 10000

using namespace std;

vector<pair<ll,ll>> adj[MAXN];//u,v,w
vector<ll> dist(MAXN,INT_MAX);
bool visited[MAXN];

ll shpath(ll s,ll f,ll N){
    dist[s]=0;
    bool exist=false;
    forn(i,N){
        ll v=-1;
        forn(j,N){
            if(!visited[j] && (v==-1 || dist[j]<dist[v])) v=j;
        }
        if(dist[v]==MOD) break;
        visited[v]=1;
        forn(e,adj[v].size()){
            if(f==adj[v][e].first) exist=true;

            if(dist[v]+adj[v][e].second<dist[adj[v][e].first]){
                dist[adj[v][e].first]=dist[v]+adj[v][e].second;
            }
        }



    }

    return (exist?dist[f]:-1);



}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);cout.tie(NULL);
    ll T=1;
    memset(visited,0,sizeof visited);
    //cin>>T;
    while(T--)
    {
        ll N,M;
        cin>>N>>M;

        forn(i,M){
            ll u,v,w;
            cin>>u>>v>>w;
            adj[u-1].push_back({v-1,w});

        }
        ll x,y;
        cin>>x>>y;
        bool truth=false;
        visited[x-1]=1;
        stack<ll> st;
        st.push(x-1);
        while(!st.empty()){
            ll u=st.top();
            st.pop();
            forn(v,adj[u].size()){
                if(!visited[adj[u][v].first]){
                    visited[adj[u][v].first]=1;
                    st.push(adj[u][v].first);
                    if(adj[u][v].first==y-1){
                        truth=true;
                        break;
                    }
                }

            }
            if(truth) break;
        }

        if(truth) {memset(visited,0,sizeof visited);cout<<shpath(x-1,y-1,N)<<endl;}
        else cout<<-1<<endl;



    }





    return 0;
}
