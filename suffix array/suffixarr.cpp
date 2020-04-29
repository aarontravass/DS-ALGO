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

string text;
ll len;

ll get(char a){
    return a=='$'?0:a-'A'+1;
}

vector<ll> sortchars(){
    vector<ll> order(len),count(5);
    forn(i,len) count[get(text[i])]++;
    for(ll i=1;i<5;i++) count[i]+=count[i-1];
    forn_rev(i,len) order[--count[get(text[i])]]=i;
    //cout<<"1d"<<endl;
    return order;
}

vector<ll> charclass(vector<ll> order){
    vector<ll> clas(len);
    clas[order[0]]=0;
    for(ll i=1;i<len;i++){
        if(text[order[i]]!=text[order[i-1]]){
            clas[order[i]]=clas[order[i-1]]+1;
        }
        else{

            clas[order[i]]=clas[order[i-1]];
        }
    }
    //cout<<"2d"<<endl;
    return clas;

}

vector<ll> sortdouble(vector<ll> order,vector<ll> clas,ll l){
    vector<ll> count(len),neworder(len);
    forn(i,len) count[clas[i]]++;
    for(ll i=1;i<len;i++) count[i]+=count[i-1];
    forn_rev(i,len) {
        ll start=(order[i]-l+len)%len;
        neworder[--count[clas[start]]]=start;
    }
    //cout<<"3d"<<endl;
    return neworder;
}

vector<ll> updateclass(vector<ll> neworder,ll l,vector<ll> clas){
    vector<ll> newclass(neworder.size(),0);
    for(ll i=1;i<neworder.size();i++){
        ll cur=neworder[i],prev=neworder[i-1];
        ll mid=(cur+l),midprev=(prev+l)%neworder.size();
        if(clas[cur]!=clas[prev] || clas[mid]!=clas[midprev]){
            newclass[cur]=newclass[prev]+1;
        }
        else{
            newclass[cur]=newclass[prev];
        }
    }
    //cout<<"4d"<<endl;
    return newclass;


}

vector<ll> buildsuffixarr(){
    vector<ll> order=sortchars();
    vector<ll> clas=charclass(order);
    for(ll i=1;i<len;i*=2){
        order=sortdouble(order,clas,i);
        clas=updateclass(order,i,clas);

    }
    return order;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);cout.tie(NULL);
    ll T=1;
    //cin>>T;
    while(T--)
    {
        cin>>text;
        len=text.length();
        forn(i,len){
            if(text[i]=='C') text[i]='B';
            else if(text[i]=='G') text[i]='C';
            else if(text[i]=='T') text[i]='D';
        }
        vector<ll> ans=buildsuffixarr();
        forn(i,ans.size()) cout<<ans[i]<<" ";




    }
//AACGATAGCGGTAGA$


    return 0;
}





