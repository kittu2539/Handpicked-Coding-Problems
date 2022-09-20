// link :- 
int solve(vector<int>& days) {
    int n = days.size();
    for(int i=1;i<n;i++)days[i]-=days[0]-1;
    days[0]=1;
    int N = days[n-1];
    int dp[N+1];
    dp[0]=0;
    int m[N+1]={};
    for(int i=0;i<n;i++)m[days[i]]=1;
    // cout<<"map = ";
    for(int i=1;i<=N;i++){
        if(m[i]==0){
            dp[i]=dp[i-1];
            continue;
        }
        // cout<<i<<" ";
        dp[i]=2+dp[i-1];
        for(int j=2;j<=7;j++)if(i>=j)dp[i]=min(dp[i],7+dp[i-j]);
        for(int j=8;j<=30;j++)if(i>=j)dp[i]=min(dp[i],25+dp[i-j]);
    }
    // cout<<endl;
    // for(int i=0;i<=N;i++)cout<<dp[i]<<" ";
    return dp[N];
}
