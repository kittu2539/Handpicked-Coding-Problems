// link :- https://binarysearch.com/problems/Longest-Contiguously-Strictly-Increasing-Sublist-After-Deletion
int solve(vector<int>& nums) {
    int n=nums.size();
     if(n==0)return 0;
    if(n==1)return 1;
    int dp[n+1][2];
    dp[0][0]=dp[0][1]=0;
    dp[1][0]=dp[1][1]=1;
    for(int i=2;i<=n;i++){
        dp[i][0]=dp[i][1]=1;
        if(nums[i-1]>nums[i-2]){
            dp[i][0]=dp[i-1][0]+1;
            dp[i][1]=max(dp[i-1][0],dp[i-1][1])+1;
        }
        if(nums[i-1]>nums[i-3]){
            dp[i][1]=max(dp[i][1],dp[i-2][0]+1);
        }
    }
    int ans=0;
    for(int i=0;i<=n;i++){
        ans=max(ans,max(dp[i][0],dp[i][1]));
    }
    return ans;
}
