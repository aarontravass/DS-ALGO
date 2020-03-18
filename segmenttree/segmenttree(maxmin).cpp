/*
  segment tree that works for me. No lazy prop or update. Just max and min
*/


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

vector<double> arr;
vector<double> tmax(4*MAXN,0.0),tmin(4*MAXN,0.0);
//2 arrays for max and min
void build(ll v,ll tl,ll tr)
{
    if(tl==tr)
    {
        tmin[v]=arr[tl];
        tmax[v]=arr[tl];
        //leaf nodes
    }
    else
    {
        //store in array. Thus childs are 2*v and 2*v+1
        ll tm=(tl+tr)/2;//mid point
        build(2*v,tl,tm);//recurse to left sub tree
        build(2*v+1,tm+1,tr);//recurse to right tree
        tmax[v]=max(tmax[2*v],tmax[2*v+1]);//get max
        tmin[v]=min(tmin[2*v],tmin[2*v+1]);//get min
    }
}

double getmax(ll v,ll tl,ll tr,ll l,ll r)
{
    if(r<tl || l>tr)
        return -INT_MAX;//check if outside range
    if(l<=tl && r>=tr)
        return tmax[v];//in range then return that value

    ll tm=(tl+tr)/2;
    //recurse to left and right subtree
    return max(getmax(2*v,tl,tm,l,r),
               getmax(2*v+1,tm+1,tr,l,r));
}

double getmin(ll v,ll tl,ll tr,ll l,ll r)
{
    if(r<tl || l>tr)
        return INT_MAX;//check if outside range
    if(l<=tl && r>=tr)
        return tmin[v];//in range then return that value
    ll tm=(tl+tr)/2;
    //recurse to left and right subtree
    return min(getmin(2*v,tl,tm,l,r),
               getmin(2*v+1,tm+1,tr,l,r));
}

double answer(ll first,ll last,ll mid,ll midmax)
{
    //get answer
    return max((double)max(last+mid,first+mid),((double)midmax+(double)mid)/2);
}

double simpleanswer(ll x,ll y)
{
    //bruteforce code to compare
    double first=-1,last=-1,mid=arr[x],midmax=arr[x];
    for(ll i=1; i<x; i++)
        first=max(first,arr[i]);
    for(ll i=y+1; i<=arr.size(); i++)
        last=max(last,arr[i]);
    for(ll i=x; i<=y; i++)
    {
        mid=min(arr[i],mid);
        midmax=max(midmax,arr[i]);
    }
    return answer(first,last,mid,midmax);

}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);cout.tie(NULL);
    ll N;
    cin>>N;
    arr.resize(N+1);
    for1n(i,N) cin>>arr[i];
    build(1,1,N);
    flush(cout);
    ll Q;
    cin>>Q;
    while(Q--)
    {
        ll x,y;
        cin>>x>>y;
        x++;
        y++;
        //cout<<"Simple"<<endl;
        //cout<<fixed<<setprecision(1)<<simpleanswer(x,y)<<endl;
        ll first=getmax(1,1,N,1,x-1);
        //cout<<"new"<<endl;
        ll last=getmax(1,1,N,y+1,N),mid=getmin(1,1,N,x,y),midmax=getmax(1,1,N,x,y);
        //cout<<first<<endl;cout<<last<<endl;cout<<mid<<endl;cout<<midmax<<endl;

        //cout<<"Segment tree"<<endl;
        cout<<fixed<<setprecision(1)<<answer(first,last,mid,midmax)<<endl;

    }




    return 0;
}
