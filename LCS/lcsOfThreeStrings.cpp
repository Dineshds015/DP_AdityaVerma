#include<bits/stdc++.h>
using namespace std;

#define vi2 vector<vector<int>>

int lcs(string a,string b,string c,int n1,int n2,int n3,unordered_map<string,int> &dp){
    if(n1==0 || n2==0 || n3==0)
        return 0;
    if(dp.count(to_string(n1)+" "+to_string(n2)+" "+to_string(n3)))
        return dp[to_string(n1)+" "+to_string(n2)+" "+to_string(n3)];
        
    if(a[n1-1]==b[n2-1] && a[n1-1]==c[n3-1])
        return dp[to_string(n1)+" "+to_string(n2)+" "+to_string(n3)]=1+lcs(a,b,c,n1-1,n2-1,n3-1,dp);
    else
        return dp[to_string(n1)+" "+to_string(n2)+" "+to_string(n3)]=max(lcs(a,b,c,n1,n2,n3-1,dp),max(lcs(a,b,c,n1,n2-1,n3,dp),lcs(a,b,c,n1-1,n2,n3,dp)));
}

int main ()
{
    string a,b,c;
    cin>>a>>b>>c;
    int n1=a.length();
    int n2=b.length();
    int n3=c.length();
    unordered_map<string,int> dp;
    
    return lcs(a,b,c,n1,n2,n3,dp);
}