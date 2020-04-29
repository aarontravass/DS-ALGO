#include <bits/stdc++.h>
#define ll long long int
#define ull unsigned long long int
#define ld long double
#define forn(i,n)for(ll i=0;i<(n);i++)
#define forn_rev(i,n)for(ll i=(n)-1;i>=0;i--)
#define for1n(i,n) for(ll i=1;i<=(n);i++)
#define ARRAY_SIZE(a) sizeof(a)/sizeof(*a)
#define MOD 1000000007
#define MAXN 10005

using namespace std;

struct data{
    char ch;
    ll node;
};

vector<string> arr;
vector<data> adj[MAXN];

ll exist(ll curn,char curs){
    forn(k,adj[curn].size()){
        if(adj[curn][k].ch==curs) return adj[curn][k].node;
    }
    return 0;


}

void contructtrie(){
    ll curn,node=0;
    char curs;
    forn(i,arr.size()){
        string pat=arr[i];
        curn=0;
        forn(j,pat.length()){
            curs=pat[j];
            ll index=exist(curn,curs);
            if(adj[curn].size()>0 && index){
                    curn=index;

            }
            else{
                data temp;
                temp.ch=curs;
                temp.node=++node;
                adj[curn].push_back(temp);
                curn=node;
            }


        }

    }


}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);cout.tie(NULL);
    ll T=1;
    //cin>>T;
    while(T--)
    {
        ll N;
        cin>>N;
        forn(i,N){
            string s;
            cin>>s;
            arr.push_back(s);
        }
        contructtrie();
        forn(i,MAXN){
            if(adj[i].size()>0){
                forn(j,adj[i].size()){
                    cout<<i<<"->"<<adj[i][j].node<<":"<<adj[i][j].ch<<endl;
                }
            }

        }
    }



    return 0;
}
