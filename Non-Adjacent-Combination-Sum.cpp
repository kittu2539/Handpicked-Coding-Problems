// link :- https://binarysearch.com/problems/Non-Adjacent-Combination-Sum
bool recur(vector<int>&v,int k,int i,vector<vector<int>>&dp){
    if(k==0)return 1;
    if(i>=v.size()+1)return 0;
    if(dp[i][k]!=-1)return dp[i][k];
    if(k<0)return 0;
    int &ans = dp[i][k];
    if(k>=v[i-1])ans=max(recur(v,k,i+1,dp),recur(v,k-v[i-1],i+2,dp));
    else ans=recur(v,k,i+1,dp);
    return ans;
}
bool solve(vector<int>& nums, int k) {
    vector<vector<int>>dp(nums.size()+1,vector<int>(k+1,-1));
    dp[0][0]=0;
    return recur(nums,k,1,dp);
}
