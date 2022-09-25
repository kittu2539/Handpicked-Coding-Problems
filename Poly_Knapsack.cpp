// link :- https://binarysearch.com/problems/Poly-Knapsack
int recur(vector<int>&w,vector<int>&v,int cp,int i,vector<vector<int>>&dp){
    if(cp<=0 || i>=v.size())return 0;
    if(dp[i][cp]!=-1)return dp[i][cp];
    int res = 0;
    for(int j=0;j<=cp/w[i];j++){
        res=max(res,v[i]*j+recur(w,v,cp-j*w[i],i+1,dp));
    }
    dp[i][cp]=res;
    return dp[i][cp];
}
int solve(vector<int>& weights, vector<int>& values, int capacity) {
    if(weights.empty())return 0;
    vector<vector<int>>dp(weights.size()+1,vector<int>(capacity+1,-1));
    dp[0][0]=0;
    return recur(weights,values,capacity,0,dp);
}
