#include <bits/stdc++.h>
#define ll long long int
#define ull unsigned long long int
#define forn(i,n)for(ll i=0;i<(n);i++)
#define forn_rev(i,n)for(ll i=(n)-1;i>=0;i--)
#define for1n(i,n) for(ll i=1;i<=(n);i++)
#define ARRAY_SIZE(a) sizeof(a)/sizeof(*a)
#define MOD 1000000007
#define MAXN 100000

using namespace std;

vector<pair<ll,ll>> adj[MAXN];//u,v,w
vector<ll> dist(MAXN,1001);
bool visited[MAXN];

bool relax(ll &N){
    bool ans=false;
    forn(i,N){
        forn(j,adj[i].size()){
            if(dist[i]<MOD){
                if(dist[adj[i][j].first]>dist[i]+adj[i][j].second){
                    ans=true;
                    dist[adj[i][j].first]=dist[i]+adj[i][j].second;
                }
            }

        }

    }
    return ans;
}

void bellman(ll &N){
    dist[0]=0;
    forn(i,N-1){
        bool temp=relax(N);
    }
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

        bellman(N);


        cout<<relax(N)<<endl;



    }





    return 0;
}
