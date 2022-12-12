void dfs(int node,int parent,vector<int>&vis,vector<int>&tin,vector<int>&low,int &timer,vector<int>adj[],vector<int>&arti){
      vis[node]=1;
      tin[node]=low[node]=timer++;
      int child=0;
      for(auto it:adj[node]){
          if(it==parent) continue;
          if(!vis[it]){
              dfs(it,node,vis,tin,low,timer,adj,arti);
              low[node]=min(low[node],low[it]);
              child++;
              if(low[it]>=tin[node]&&parent!=-1){
                  arti[node]=1;
              }
          }
          else{
                   low[node]=min(low[node],tin[it]);   
           }
      }
    if(parent==-1 &&child>1){
              arti[node]=1;
    }
  }
    vector<int> articulationPoints(int V, vector<int>adj[]) {
        vector<int>ans;
        vector<int>vis(V,0);
        vector<int>tin(V,-1);
        vector<int>low(V,-1);
        vector<int>arti(V,0);
        int timer=0;
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i,-1,vis,tin,low,timer,adj,arti);
            }
        }
        for(int i=0;i<V;i++){
            if(arti[i]==1) ans.push_back(i);
        }
        if(ans.size()==0) return {-1};
        return ans;
    }
