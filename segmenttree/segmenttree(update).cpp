#include <bits/stdc++.h>
#define ll long long int
#define ull unsigned long long int
#define forn(i,n)for(ll i=0;i<(n);i++)
#define forn_rev(i,n)for(ll i=(n)-1;i>=0;i--)
#define for1n(i,n) for(ll i=1;i<=(n);i++)
#define ARRAY_SIZE(a) sizeof(a)/sizeof(*a)
#define MOD 1000000007
#define MAXN 1000000

using namespace std;

struct data{
    ll sum,left,right;
};
// ( = 1
// ) = -1
vector<ll> arr(30000);
vector<data> tmax(4*MAXN);

auto make_data(ll val){
    data res;
    res.sum=res.left=res.right=val;
    if(val==-1) {
        res.left=1;
        res.right=0;
    }else if(val==1){
        res.left=0;
        res.right=1;
    }
    return res;
}

auto combine(data &a,data &b){
    //ultra based combine function for easier coding
    data res;
    res.left=a.left;
    res.right=b.right;
    if(a.right>b.left){
        res.right+=(a.right-b.left);
    }
    else{
        res.left+=(b.left-a.right);
    }
    res.sum=res.left+res.right;


    return res;
}



void build(ll v,ll tl,ll tr)
{
    if(tl==tr)
    {

        tmax[v]=make_data(arr[tl]);
        //leaf nodes
    }
    else
    {
        //store in array. Thus childs are 2*v and 2*v+1
        ll tm=(tl+tr)/2;//mid point
        build(2*v,tl,tm);//recurse to left sub tree
        build(2*v+1,tm+1,tr);//recurse to right tree
        tmax[v]=combine(tmax[2*v],tmax[2*v+1]);
    }
}

auto getmax(ll v,ll tl,ll tr,ll l,ll r)
{
    if(r<tl || l>tr)
        return make_data(0);//check if outside range
    if(l<=tl && tr<=r)
        return tmax[v];//in range then return that value

    ll tm=(tl+tr)/2;
    //recurse to left and right subtree
    data left=getmax(2*v,tl,tm,l,r),right=getmax(2*v+1,tm+1,tr,l,r);
    return combine(left,right);
}

void update(ll v,ll tl,ll tr,ll pos){
    if(tl==tr){
        tmax[v]=make_data((-1)*tmax[v].sum);//update tree leaves here
    }
    else{
        ll tm=(tl+tr)/2;
        if(pos<=tm){
            update(2*v,tl,tm,pos);//recurse to left subtree
        }
        else{
            update(2*v+1,tm+1,tr,pos);//recurse to right subtree
        }
        tmax[v]=combine(tmax[2*v],tmax[2*v+1]);//combine
    }
}




int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);cout.tie(NULL);
    ll T=10;

    for1n(counter,T){
        ll N,Q;
        cin>>N;
        string temp;
        cin>>temp;
        for1n(i,N){
            if(temp[i-1]=='(') arr[i]=1;
            else arr[i]=-1;
        }
        build(1,1,N);
        cin>>Q;
        cout<<"Test "<<counter<<":"<<endl;
        while(Q--){
            ll ch;
            cin>>ch;
            if(ch==0){
                ll c=getmax(1,1,N,1,N).sum;
                if(c==0) cout<<"YES"<<endl;
                else cout<<"NO"<<endl;
            }
            else{
                update(1,1,N,ch);
            }
        }
        arr.clear();
        tmax.clear();


    }




    return 0;
}
