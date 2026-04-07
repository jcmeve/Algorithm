#include <iostream>
using namespace std;int m[26],n,f,c;string s; int main(){cin>>n;while(n--)cin>>s,m[s[0]-'a']++;for(;c<26;++c)if(m[c]>=5)f=1,cout<<(char)(c+'a');if(!f)cout<<"PREDAJA";}