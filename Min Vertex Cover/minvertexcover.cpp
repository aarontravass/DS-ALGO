#include <bits/stdc++.h>
#define ll long long int
#define ull unsigned long long int
#define forn(i,n)for(ll i=0;i<(n);i++)
#define forn_rev(i,n)for(ll i=(n)-1;i>=0;i--)
#define for1n(i,n) for(ll i=1;i<=(n);i++)
#define ARRAY_SIZE(a) sizeof(a)/sizeof(*a)
#define MOD 1000000007
#define N 100

using namespace std;

ll adj[N][N+1];
bool visited[N];
vector<ll> vertex;

ll get_max(ll n){
    pair<ll,ll> ans(-1,-1);
    forn(i,n) if(adj[i][N]>0 && ans.second<=adj[i][N]) ans=make_pair(i,adj[i][N]);
    return ans.first;
}
ll getedge(ll n,ll index){
    pair<ll,ll> ans(-1,-1);
    forn(i,n){
        if(adj[index][i]==1 && ans.second<=adj[i][N] && adj[i][N]>0 && i!=index){
                ans=make_pair(i,adj[i][N]);

        }
    }
    return ans.first;
}

void vertex_cover(ll n){
    forn(u,n){
        ll index=get_max(n);
        if(index!=-1){
            ll id=getedge(n,index);
            if(id!=-1){
            visited[index]=1;
            visited[id]=1;
            vertex.push_back(index);
            vertex.push_back(id);
                forn(v,n){
                    if(adj[index][v]!=0){
                        adj[index][v]=0;
                        adj[v][index]=0;
                        visited[v]=1;
                        adj[index][N]--;
                        adj[v][N]--;
                    }
                    if(adj[id][v]!=0){
                        adj[id][v]=0;
                        adj[v][id]=0;
                        visited[v]=1;
                        adj[id][N]--;
                        adj[v][N]--;
                    }

                }
            }


        }

    }
    forn(i,vertex.size()) cout<<vertex[i]<<"\t";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);cout.tie(NULL);
    memset(visited,0,sizeof(visited));
    ll n,m;
    cin>>n>>m;
    forn(i,m){
        ll u,v;
        cin>>u>>v;
        adj[u][v]=1;
        adj[v][u]=1;
        adj[u][N]++;
        adj[v][N]++;
    }
    vertex_cover(n);


    return 0;
}

