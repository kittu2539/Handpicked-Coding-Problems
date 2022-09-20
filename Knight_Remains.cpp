link :- https://binarysearch.com/problems/Knight-Remains
bool chk(int i,int j,int n,int m){
    if(i<0 || j<0 || i>=n || j>=m)return 0;
    return 1;
}
int solve(int n, int x, int y, int k) {
    double pdp[n][n],cdp[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            pdp[i][j]=0.00,cdp[i][j]=0;
        }
    }
    vector<pair<int,int>> v = {
        {1,2},{1,-2},{-1,2},{-1,-2},{2,1},{2,-1},{-2,1},{-2,-1}
    };
    pdp[x][y]=1.00;
    int prev_n = 8;
    while(k--){
        // cout<<"pdp = ";
        // for(int i=0;i<8;i++){
        //     for(int j=0;j<8;j++){
        //         cout<<pdp[i][j]<<" ";
        //     }cout<<endl;
        // }cout<<endl;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                for(auto to:v){
                    // cout<<to.first<<" "<<to.second<<endl;
                    int X=i+to.first, Y=j+to.second;
                    if(chk(X,Y,n,n)){
                        // if(X==0 && Y==0)cout<<"valid x,y = "<<X<<" "<<Y<<" for i,j = "<<i<<" "<<j<<" ----  ";
                        cdp[i][j] += (double)pdp[X][Y]*((double)(1.00/(double)8));                  
                    }
                }
            }
        }
        // cout<<"cdp = ";
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++){
        //         cout<<cdp[i][j]<<" ";
        //     }cout<<endl;
        // }cout<<endl;
        prev_n=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(cdp[i][j]!=0)prev_n++;
                pdp[i][j]=cdp[i][j];
                cdp[i][j]=0;
            }
        }
        prev_n*=8;
    }
    double ans = 0.0;
    for(int i=0;i<n;i++)for(int j=0;j<n;j++)ans+=pdp[i][j];
    return (int)(ans*100);
}
