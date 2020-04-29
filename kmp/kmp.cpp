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

string patt,text;
vector<ll> ans,lps;

void cal_lps(){
    lps.resize(patt.length(),0);
    ll len=0;
    for(ll i=1;i<patt.length();){
        if(patt[i]==patt[len]){
            lps[i++]=++len;
        }
        else{
            if(len!=0) len=lps[len-1];
            else lps[i++]=0;
        }


    }


}

void kmp(){
    for(ll i=0,j=0;i<text.length();){
        if(patt[j]==text[i]){
            i++;j++;
        }
        if(j==patt.length()){
            ans.push_back(i-j);
            j=lps[j-1];
        }
        else if(i<text.length() && patt[j]!=text[i]){
            if(j!=0) j=lps[j-1];
            else i++;
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
        cin>>patt>>text;
        if(patt.length()<=text.length()){
            cal_lps();
            kmp();
            forn(i,ans.size()) cout<<ans[i]<<" ";
        }




    }



    return 0;
}
