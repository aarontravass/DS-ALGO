#include <bits/stdc++.h>
#define ll long long int
#define ull unsigned long long int
#define forn(i,n)for(ll i=0;i<(n);i++)
#define forn_rev(i,n)for(ll i=(n)-1;i>=0;i--)
#define for1n(i,n) for(ll i=1;i<=(n);i++)
#define ARRAY_SIZE(a) sizeof(a)/sizeof(*a)
#define MOD 1000000007
#define MAXN 100005

using namespace std;


vector<ll> adj[MAXN],color(MAXN,-1);
bool visited[MAXN];

bool bfs(ll s){
    //visited[s]=1;
    queue<ll> q;
    q.push(s);
    color[s]=1;
    while(!q.empty()){
        ll u=q.front();
        q.pop();
        forn(v,adj[u].size()){
            if(color[adj[u][v]]==-1){
                q.push(adj[u][v]);
                color[adj[u][v]]=1-color[u];
            }else if(color[adj[u][v]]==color[u]) return 1;
        }
    }

  return 0;


}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);cout.tie(NULL);
    ll T=1;
    //memset(visited,0,sizeof visited);
    //cin>>T;
    while(T--)
    {
        ll N,M;
        cin>>N>>M;
        forn(i,M){
            ll u,v;
            cin>>u>>v;
            adj[u-1].push_back(v-1);
            adj[v-1].push_back(u-1);
        }
        forn(i,N){
            if(color[i]==-1){
                if(bfs(i)){
                    cout<<0<<endl;
                    return 0;
                }
            }
        }

        cout<<1<<endl;



    }





    return 0;
}
