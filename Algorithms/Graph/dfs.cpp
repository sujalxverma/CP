
/*
    1. it will accept adjacency vector of graph, and it will be a refrence pass.
    2. can be adjust accordingly as per problem.
*/
void dfs(vector<vector<int>>&graph,vector<bool>&visited,vector<int>&dfsOrder,int node){
    visited[node] = true;
    dfsOrder.push_back(node);
    for(auto neighbor : graph[node]){
        if(!visited[neighbor]){
            dfs(graph,visited,dfsOrder,neighbor);
        }

    }
}

void dfsGraph(vector<vector<int>>&graph){
    vector<bool>visited(graph.size(),false);
    vector<int>dfsOrder;
    for(int i = 0 ; i < graph.size() ; i++){
        if(!visited[i]){
            dfs(graph,visited,dfsOrder,i);
        }
    }
}
