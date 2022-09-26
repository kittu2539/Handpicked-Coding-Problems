// link :- https://binarysearch.com/problems/Longest-Fibonacci-Subsequence
int solve(vector<int>& nums) {
    int n=nums.size();
    int dp[n+1][n+1];
    // memset(dp,1,sizeof(dp));
    for(int i=0;i<=n;i++)for(int j=0;j<=n;j++)dp[i][j]=1;
    for(int i=0;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            dp[i][j]=2;
        }
    }
    map<int,int>m;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(m.find(nums[j]-nums[i])!=m.end()){
                int k = m[nums[j]-nums[i]];
                dp[i][j]=max(dp[i][j],1+dp[k][i]);
            }
        }
        m[nums[i]]=i;
    }
    
    int ans = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            ans=max(ans,dp[i][j]);
        }
    }
    return (ans>2)*ans;
}
