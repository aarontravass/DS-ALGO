#include <bits/stdc++.h>
#define ll long long int
#define ull unsigned long long int
#define forn(i,n)for(ll i=0;i<(n);i++)
#define forn_rev(i,n)for(ll i=(n)-1;i>=0;i--)
#define for1n(i,n) for(ll i=1;i<=(n);i++)
#define ARRAY_SIZE(a) sizeof(a)/sizeof(*a)
#define MOD 1000000007
#define MAXN 1000005

using namespace std;

vector<pair<string,ll>> suff;
string patt,bwt="";


void getstr(){
    string temp;
    forn_rev(i,patt.length()){
        temp+=patt[i];
        string rev=temp;
        reverse(rev.begin(),rev.end());
        suff.push_back({rev,i});
    }
    sort(suff.begin(),suff.end());

}

void calbwt(){
    forn(i,suff.size()){
        bwt+=patt[(suff[i].second-1+suff.size())%suff.size()];
        //cout<<suff[i].second<<endl;

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
        cin>>patt;
        getstr();
        calbwt();
        cout<<bwt<<endl;



    }



    return 0;
}
