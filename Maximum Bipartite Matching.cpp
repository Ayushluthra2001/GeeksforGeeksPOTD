vector<int>match;
vector<int>vis;
  bool solve(int p,vector<vector<int>>&g){
      for(int j=0;j<g[0].size();j++){
          if(g[p][j] && !vis[j]){
              vis[j]=1;
              if(match[j]==-1 || solve(match[j],g)){
                  match[j]=p;
                  return true;
              }
          }
      }
      return false;
  }
	int maximumMatch(vector<vector<int>>&g){
	    // Code here
	    int p=g.size();
	    int j=g[0].size();
	    match=vector<int>(j,-1);
	    int ans=0;
	    for(int i=0;i<p;i++){
	        vis=vector<int>(j,0);
	        if(solve(i,g))ans++;
	    }
	    return ans;
	}
