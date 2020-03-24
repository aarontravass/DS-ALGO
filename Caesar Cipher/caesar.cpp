#include <bits/stdc++.h>
using namespace std;


string encrypt(string s,int shift){
    string temp="";
    for(int i=0;i<s.length();i++){
        if(s[i]!=' '){
            if(isupper(s[i])) temp+=char((int(s[i]-'A')+shift)%26+int('A'));
            else temp+=char((int(s[i]-'a')+shift)%26+int('a'));
        }
        else{
            temp+=' ';
        }
    }
    return temp;
}

string decrypt(string s,int shift){
    string temp="";
    for(int i=0;i<s.length();i++){
        if(s[i]!=' '){
            if(isupper(s[i])) temp+=char((26+int(s[i]-'A')-shift)%26+int('A'));
            else temp+=char((26+int(s[i]-'a')-shift)%26+int('a'));
        }
        else{
            temp+=' ';
        }
            
        }
    return temp;
}

int main() {
	string plain;
	cout<<"Enter text"<<endl;
	cin>>plain;
	int shift;
	cout<<"Enter Shift value"<<endl;
	cin>>shift;
	shift%=26;
	string key=encrypt(plain,shift);
	cout<<"Encrypted string is : "<<key<<endl;
	cout<<"Decrypted string is : "<<decrypt(key,shift)<<endl;
	
	return 0;
}
