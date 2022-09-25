#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
int dp[N][7];
int arr[N];
int n;
int tmod[N+5];
int cal(int i,int j){
	//j*10^i+j*10^(n-1-i)
	if(n%2 && i==n-1-i)return (tmod[i]*j)%7;
	int res = (tmod[i]*j+(tmod[n-1-i]*j))%7;
	return res;
}
int recur(int i,int rem){
	if(i==n/2+n%2)return !(!(!rem));
	if(i>=n/2+n%2)return 0;
	if(dp[i][rem]!=-1)return dp[i][rem];
	// cout<<i<<" "<<rem<<"\n";
	int &ans = dp[i][rem];
	dp[i][rem]=0;ans=0;
	int st=1;
	if(i)st--;
	for(int j=st;j<=7;j++){
		if(recur(i+1,(cal(i,j)+rem)%7)){
			ans=1;
			arr[i]=j;
			break;
		}
	}
	dp[i][rem]=ans;
	return ans;
}
int main(){
	tmod[0]=1;tmod[1]=3;
	for(int i=2;i<N;i++){
		tmod[i]=(tmod[i-1]*10)%7;
	}
	cin>>n;
	memset(dp,-1,sizeof(dp));
	recur(0,0);
	

	// cout<<"power mods = ";for(int i=0;i<10;i++)cout<<tmod[i]<<" ";cout<<endl;
	// cout<<"dp = ";
	// for(int i=0;i<=n;i++){
	// 	for(int j=0;j<7;j++){
	// 		cout<<dp[i][j]<<" ";
	// 	}cout<<endl;
	// }cout<<endl;

	for(int i=0;i<n/2;i++){
		arr[n-1-i]=arr[i];
	}
	for(int i=0;i<n;i++)cout<<arr[i];
	return 0;
}
