
// Kruskal : Minimum Spanning Tree.
// O(ElogE)
void Kruskal(vector<tuple<int, int, int>> edges, int maxNode)
{
    vector<pair<int, int>> MST;
    DSU dsu(maxNode + 1);
    sort(edges.begin(), edges.end());
    int mstweight = 0;

    for (auto &[weight, u, v] : edges)
    {
        int parentU = dsu.superParent(u);
        int parentV = dsu.superParent(v);

        if (parentU == parentV)
            continue;

        dsu.unionBySize(u, v);
        MST.emplace_back(u, v);
        mstweight += weight;
    }
}