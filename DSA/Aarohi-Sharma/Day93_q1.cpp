class Solution {
public:
    unordered_map<int,unordered_set<int>> adj;
    vector<int> indegree;
    int n;
void dfs(int node,vector<bool> &vis){
    if(vis[node]){
        return;
    }
    vis[node]=1;
    for(auto i:adj[node]){
        dfs(i,vis);  
    }
}
bool isRooted(){
    int root=-1;
    for(int i=1;i<=n;i++){
        if(indegree[i]==0){
            root=i;
            break;
        }
    }
    if(root==-1)
    return 0;
    vector<bool> vis(n+1,0);
    dfs(root,vis);
    for(int i=1;i<=n;i++){
        if(vis[i]==0){
            return 0;
        }
    }
    return true;
}
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        this->n=edges.size();
        indegree.resize(n+1,0);
        for(auto i:edges){
            adj[i[0]].insert(i[1]);
            indegree[i[1]]++;
        }
        vector<int> ans;
        for(auto i:edges){
            adj[i[0]].erase(i[1]);
            indegree[i[1]]--;
            if(isRooted()){
                ans={i[0],i[1]};
            }
            adj[i[0]].insert(i[1]);
            indegree[i[1]]++;
        }
        return ans;    
    }
};
