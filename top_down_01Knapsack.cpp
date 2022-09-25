// link :- https://binarysearch.com/problems/0-1-Knapsack
int recur(vector<int>&w,vector<int>&v,int i,int cp,vector<vector<int>>&dp){
    if(i==w.size()+1)return 0;
    if(cp<=0)return 0;
    if(dp[i][cp]!=-1)return dp[i][cp];
   
    if(w[i-1]<=cp){
        dp[i][cp]=max(recur(w,v,i+1,cp-w[i-1],dp)+v[i-1],recur(w,v,i+1,cp,dp));
    }else {
        dp[i][cp]=recur(w,v,i+1,cp,dp);
    }
    return dp[i][cp];
}

int solve(vector<int>& weights, vector<int>& values, int capacity) {
    int n = weights.size();
    vector<vector<int>>dp(n+1,vector<int >(capacity+1,-1));
    for(int i=0;i<=n;i++){
        dp[i][0]=0;
    }
    for(int j=0;j<=capacity;j++){
        dp[0][j]=0;
    }
    int res = recur(weights,values,1,capacity,dp);
    return res;
}
