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

vector<ll> adj[MAXN],ans;
bool visited[MAXN],used[MAXN];

void dfs(ll u){
    visited[u]=1;
    //cout<<adj[u].size()<<endl;
    for(ll v=0;v<adj[u].size();v++){
        if(!visited[adj[u][v]]){
            if(!used[adj[u][v]]){
                //cout<<adj[u][v]<<endl;
                dfs(adj[u][v]);
            }

        }


    }

    ans.push_back(u);
    used[u]=1;



}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);cout.tie(NULL);
    ll T=1;
    memset(visited,0,sizeof visited);
    memset(used,0,sizeof used);
    //cin>>T;
    while(T--)
    {
        ll N,M;
        cin>>N>>M;

        forn(i,M){
            ll u,v;
            cin>>u>>v;
            adj[u-1].push_back(v-1);
        }
        forn(i,N){
            if(!visited[i] && adj[i].size()>0){
                dfs(i);
            }
        }
        forn(i,N){
            if(adj[i].size()==0 && !visited[i]){
                ans.push_back(i);
                visited[i]=1;
            }
        }
        forn_rev(i,ans.size()) cout<<ans[i]+1<<" ";



    }





    return 0;
}
