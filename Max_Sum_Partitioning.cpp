// link :- https://binarysearch.com/problems/Max-Sum-Partitioning
int solve(vector<int>& nums, int k) {
    int n = nums.size();
    int dp[n+1]={};
    for(int i=1;i<=n;i++){
        int mx=0;
        for(int j=i;j>=max(1,i-k+1);j--){
            mx=max(nums[j-1],mx);
            dp[i]=max(dp[i],dp[j-1]+(i-j+1)*mx);
        }
    }
    return dp[n];
}
