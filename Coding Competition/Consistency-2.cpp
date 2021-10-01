//https://www.facebook.com/codingcompetitions/hacker-cup/2021/qualification-round/problems/A2
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF 1e6
vector<ll>v;
void solve(){
    ll graph[30][30],dist[30][30],i,j,k,ans=1e10,n=30,sum;
    char b,c;
    string s;
    for(i=0;i<n;i++){
        for (j=0;j<n;j++)
            if (i!=j)
                graph[i][j]=INF;
            else
                graph[i][j]=0;
    }
    cin>>s>>n;//inputting s and n 
    for(i=0;i<n;i++){
        cin>>b>>c;
        graph[int(b-'A')][int(c-'A')]=1;//putting the character b and c
    }
    for(i=0;i<30;i++)
        for(j=0;j<30;j++)
            dist[i][j]=graph[i][j];
    n=26;
    for(k=0;k<n;k++)
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
    for (i=0;i<26;i++){//putting chararcters of s
        sum=0;
        for(j=0;j<s.size();j++){
            sum+=dist[s[j]-'A'][i];
        }
        ans=min(ans,sum);
    }
    if (ans>=INF)
        v.push_back(-1);
    else
        v.push_back(ans);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,i;
    cin>>t;
    for (i=1;i<=t;i++)
        solve();
    for (int p=0;p<v.size();p++)
        cout<<"Case #"<<i+1<<": "<<v[p]<<endl;
    return 0;
}
