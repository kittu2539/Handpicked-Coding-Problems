// link :- https://binarysearch.com/problems/Skip-Tasks-to-Minimize-Work
int solve(vector<int>& nums) {
    if(nums.empty())return 0;
    int dp[nums.size()][2];
    dp[0][0]=nums[0];
    dp[0][1]=0;
    for(int i=1;i<nums.size();i++){
        dp[i][0]=min(dp[i-1][0],dp[i-1][1])+nums[i];
        dp[i][1]=dp[i-1][0];
    }
    return min(dp[nums.size()-1][0],dp[nums.size()-1][1]);
}
