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
vector<pair<char,ll>> pattarr;

string getstr(){
    
    sort(pattarr.begin(),pattarr.end());
    string ans="";
    ll x=pattarr[0].second;
    forn(i,pattarr.size()){
        x=pattarr[x].second;
        ans+=patt[x];
    }
    return ans;


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
        forn(i,patt.length()) pattarr.push_back({patt[i],i});
        cout<<getstr()<<endl;



    }



    return 0;
}
