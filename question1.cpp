#include<bits/stdc++.h>
#define int long long int
using namespace std;
int powerFinder(int a,int b,int p){
    if(b==0) return 0;
    if(b==1) return b%p;
    int ans = powerFinder(a,b/2,p)%p;
    int fiAns = ((ans%p) * (ans%p))%p;
    if(b%2==1) return fiAns;
    else return (fiAns%p) * (a%p))%p;
}
int solve(int n, int p){
    int ans=1;
    for(int i=n+1;i<=p-1;i++){
        ans=(ans%p * powerFinder(i,p+1,p)%p);
    }
    return ans;
}
int32_t main(){
    int t;
    cin>>t;
    while(t--){
        int n,p;
        cin>>n>>p;
        if(2*n>=p){
            cout<<0<<endl;
        } 
       	cout<<solve(n,p)<<endl; 
    }
    return 0;
}
