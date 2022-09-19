// link :- https://binarysearch.com/problems/Longest-Increasing-Subsequence
int solve(vector<int>& nums) {
    if(nums.empty())return 0;
    int n=nums.size();
    map<int,int>m;
    int j=0;
    vector<int >a = nums;
    sort(nums.begin(),nums.end());
    for(int i : nums){
        if(m.find(i)==m.end()){
            m[i]=++j;
        }
    }
    for(int i=0;i<nums.size();i++){
        a[i]=m[a[i]];
    }
    for(int i : a)cout<<i<<" ";
    int dp[n+1][n+1]={};
    int mx[n+1]={};
    for(int i=0;i<=n;i++)for(int j=0;j<=n;j++)dp[i][j]=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            dp[i][j]=dp[i-1][j];
            if(j==a[i-1])dp[i][j]=max(dp[i][j],mx[j-1]+1);
        }
        mx[0]=dp[i][0];
        for(int j=1;j<=n;j++){
            mx[j]=max(mx[j-1],dp[i][j]);
        }
    }
    int ans=0;
    for(int i=0;i<=n;i++)ans=max(ans,dp[n][i]);
    return ans;
}
