#include <bits/stdc++.h>
#define forn(i,n) for(long long int i=0;i<n;i++)
#define ll long long int

using namespace std;

vector<ll> primes,arr(1000,1);

ll power(ll x, unsigned ll y, ll p)
{
    ll res = 1;
    x=x%p;
    while (y > 0)
    {

        if (y & 1) res = (res*x)%p;
        y = y>>1;
        x = (x*x)%p;
    }
    return res;
}


void prime()
{

    for(ll i=2; i*i<=arr.size(); i++)
    {
        if(arr[i])
        {
            primes.push_back(i);
            ll j=2*i;
            while(j<=arr.size())
            {
                arr[j]=0;
                j+=i;
            }
        }
    }

}



int main()
{

    prime();
    ll p=primes[primes.size()-1],q=primes[primes.size()-2],e;
    ll v, phi=(p-1)*(q-1),n=p*q,d;
    cout<<"Enter number less than "<<n<<endl;
    cin>>v;
    while(1)
    {
        e=primes[rand()%primes.size()];
        if(__gcd(e,phi)==1) break;
    }
    for(int i=1; i<=10000; i++)
    {
        if((e*i)%phi==1)
        {
            d=i;
            break;
        }
    }

    ll publiic=power(v,e,n);
    cout<<"Public key is "<<publiic<<endl;
    ll final_val=power(publiic,d,n);
    cout<<"Final value is "<<final_val<<endl;

    return 0;
}
