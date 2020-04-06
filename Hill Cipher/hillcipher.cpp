#include <bits/stdc++.h>
#define forn(i,n) for(int i=0;i<(n);i++)

using namespace std;


int gcdExtended(int a, int b, int &x, int &y)
{
    if (a == 0)
    {
        x = 0, y = 1;
        return b;
    }
    int x1, y1, gcd = gcdExtended(b%a, a, x1, y1);
    x = y1 - (b/a) * x1;
    y = x1;
    return gcd;
}

int modInverse(int a, int m)
{
    int x, y, g = gcdExtended(a, m, x, y);
    if (g != 1) return -1;
    else return (x%m + m) % m;
}



int matrixmultiply(int a,int b,int c,int d){
    return a*c + b*d;
}



vector<vector<int>> crypt(vector<vector<int>> &key,vector<vector<int>> &text){
    vector<vector<int>> cipher(2,vector<int>(text[0].size()));
    for(int i=0;i<text[0].size();i++){
        for(int j=0;j<2;j++){
            cipher[j][i]=matrixmultiply(key[j][0],key[j][1],text[0][i],text[1][i])%26;
        }
    }
    return cipher;
}

vector<vector<int>> getinverse(vector<vector<int>> &key){
    int det=key[0][0]*key[1][1]-key[0][1]*key[1][0];
    int mod=modInverse(det,26);

    vector<vector<int>> inverted={
                {(key[1][1])%26,(26-key[0][1])%26},
                {(26-key[1][0])%26,(key[0][0])%26}
    };
    for(int i=0;i<2;i++) for(int j=0;j<2;j++) inverted[i][j]=(inverted[i][j]*mod)%26;
    return inverted;
}

int main() {

	string s,cip="",dcip="";
	cout<<"Enter string (Uppercase only): "<<endl;
	cin>>s;
	vector<vector<int>> text(2,vector<int>(ceil((double)s.length()/2.0)));
	int c=0;
	for(int i=0;i<text[0].size();i++){
	    for(int j=0;j<2;j++){
	        text[j][i]=s[c]-'A';
	        c++;
	    }
	}
	if(s.length()%2==1){
        text[1][text[1].size()-1]=0;
	}
	//cout<<text[0].size()<<endl;
	vector<vector<int>> key={
        {3,3},
        {2,5}
	};
	vector<vector<int>> cipher=crypt(key,text);

	for(int i=0;i<cipher[0].size();i++){
	    for(int j=0;j<2;j++){
	        cip+=char(cipher[j][i]+int('A'));
	    }
	}
	if(s.length()%2==1) cip[cip.length()-1]='\0';


	cout<<"Encrypted string is : "<<cip<<endl;
	vector<vector<int>> inv=getinverse(key);
	vector<vector<int>> decrypttext=crypt(inv,cipher);

	for(int i=0;i<decrypttext[0].size();i++) for(int j=0;j<2;j++) dcip+=char(decrypttext[j][i]+int('A'));

    	if(s.length()%2==1) dcip[dcip.length()-1]='\0';
	
	cout<<"Decrypted string is : "<<dcip<<endl;




	return 0;
}
