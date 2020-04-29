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

vector<ll> adj[MAXN],color(MAXN);


bool dfs(ll s){
	//memset(visited,0,sizeof visited);

    color[s]=1;

    for(ll v=0;v<adj[s].size();v++){
        if(color[adj[s][v]]==0){

            if(dfs(adj[s][v])){
                return true;

            }
        }
        if(color[adj[s][v]]==1) return 1;

    }
    color[s]=2;
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
        }
        forn(i,N){
            if(!color[i]){
                bool ans=dfs(i);
                if(ans==1){
                    cout<<ans<<endl;
                    return 0;
                }

            }
        }
        cout<<0<<endl;



    }





    return 0;
}
