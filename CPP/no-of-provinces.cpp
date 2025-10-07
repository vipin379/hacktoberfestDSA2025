#include <iostream>
using namespace std;
#include<vector>
class Solution {
private:
    void dfs_traversal(int node,vector<vector<int>>& isConnected,vector<int>& vis){
        
        //making visited array for taking care of traversal of all connected components
        vis[node]=1;
        
        for(int i=0;i<isConnected.size();i++){
            if(isConnected[node][i]==1 && !vis[i]){   // if node is not visited as well as edge with the node exists then go more deep to the next node 
                dfs_traversal(i,isConnected,vis);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        int V=isConnected.size();
        vector<int> vis(V,0);    // here it is 0-based thats why the size of visited array is v
        int ans=0;
        
        for(int i=0;i<V;i++){
            if(vis[i]==0){   // chheck for non visited nodes if there is then do dfs tracersal again.
                // this is especially for handling the connected component
                dfs_traversal(i,isConnected,vis);
            ans++;
            }
        }
        return ans;
    }
};