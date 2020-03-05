#include <bits/stdc++.h>
#define forn(i,n) for(int i=0;i<n;i++)
#define N 10
using namespace std;
 
set<int> s[N], ans;
vector<int> as;
bool visited[N];
vector<double> cost(N);
vector<int> origcost(N);
set<int> U;
int c=0;
 
 
int getcost(int n){
    pair<int,int> a(-1,INT_MAX);
 
    forn(i,n){
    	if(!visited[i]){
        vector<int> temp;
        set_difference(s[i].begin(),s[i].end(),ans.begin(),ans.end(),back_inserter(temp));
        cost[i]=cost[i]/temp.size();}
    }
    forn(i,n){
        if(cost[i]<a.second && !visited[i]) a=make_pair(i,cost[i]);
    }
    return a.first;
}
 
int setcover(int n){
    forn(i,n){
        int id=getcost(n);
        if(id!=-1){
                visited[id]=1;
                as.push_back(id);
                c+=origcost[id];
                //cout<<id<<endl;
                for(auto itr=s[id].begin();itr!=s[id].end();itr++){
                    ans.insert(*itr);
                }
                //cout<<c<<endl;
 
        }
        vector<int> temp;
        set_intersection(U.begin(),U.end(),ans.begin(),ans.end(),back_inserter(temp));
        if(temp.size()==U.size()){
            break;
        }
 
 
    }
    return c;
}
 
int main()
{
    int n;
    cin>>n;
    memset(visited,0,sizeof(visited));
    int no;
    cin>>no;
    forn(i,no) {int temp;
    cin>>temp;
    U.insert(temp);}
    c=0;
    forn(i,n){
        int m;
        cin>>m;
        forn(j,m){
            int temp;
            cin>>temp;
            s[i].insert(temp);
        }
    }
    forn(i,n) {cin>>cost[i];origcost[i]=cost[i];}
 
    cout<<setcover(n)<<endl;
    for(auto itr=as.begin();itr!=as.end();itr++){
        cout<<*itr+1<<" ";
    }
 
    return 0;
}
