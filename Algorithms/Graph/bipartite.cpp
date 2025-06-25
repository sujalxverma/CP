
/*
    1. detects if the graph is bipartite or not.
    2. works for single component, can be adjust for more.
    
*/


void bipartite(vector<vector<int>>graph){
    vector<int>color(graph.size(),-1);
    // starting with very first node.
    color[0] = 0;
    queue<int>checker;
    checker.push(0);
    while(!checker.empty()){
        auto node = checker.front();
        checker.pop();
        for(auto neighbor : graph[node]){
            if(color[neighbor] == -1){
                color[neighbor] = !color[node];
                checker.push(neighbor);
            }
            else{
                if(color[neighbor] == color[node]){
                    cout<<"This is not bipartite graph";
                    return;
                }
            }
        }
    }
    cout<<"This is bipartite graph"<<endl;

}