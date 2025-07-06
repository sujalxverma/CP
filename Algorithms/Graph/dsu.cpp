
class DSU
{
public:
    vector<int> parent, rank, size;

    DSU(int n)
    { // heres 'n' gives number of nodes, 0 based indexing.
        parent.resize(n + 1);
        rank.resize(n + 1);
        size.resize(n + 1);

        for (int i = 0; i <= n; i++)
        {
            parent[i] = i; // initially, every node will be parent of itself.
            size[i] = 1;
        }
    }

    int superParent(int node)
    {
        if (node == parent[node])
        {
            return node;
        }
        return parent[node] = superParent(parent[node]);
    }

    void unionByRank(int nodeA, int nodeB)
    {
        // it takes 2 nodes as argument.
        int parentOfNodeA = superParent(nodeA);
        int parentOfNodeB = superParent(nodeB);

        if (parentOfNodeA == parentOfNodeB)
        {
            return; // it simply means they are of part of same component.
        }

        if (rank[parentOfNodeA] > rank[parentOfNodeB])
        {
            parent[parentOfNodeB] = parentOfNodeA;
        }
        else if (rank[parentOfNodeA] < rank[parentOfNodeB])
        {
            parent[parentOfNodeA] = parentOfNodeB;
        }
        else
        {
            parent[parentOfNodeB] = parentOfNodeA; // rank only increase if they both have same rank, rank can be considered as level.
            rank[parentOfNodeA]++;                 // if level is same, then only rank increase.
        }
    }
    void unionBySize(int nodeA, int nodeB)   // O(4@) -> O(constant)
    { // it takes 2 nodes as argument.
        int parentOfNodeA = superParent(nodeA);
        int parentOfNodeB = superParent(nodeB);

        if (parentOfNodeA == parentOfNodeB)
        {
            return; // it simply means they are of part of same component.
        }

        if (size[parentOfNodeA] >= size[parentOfNodeB])
        {
            size[parentOfNodeA] += size[parentOfNodeB]; // nodeB is added to nodeA, hence nodeA component size increase.
            parent[parentOfNodeB] = parentOfNodeA;
        }
        else
        {
            size[parentOfNodeB] += size[parentOfNodeA]; // nodeA is added to nodeB , hence nodeB component size increase.
            parent[parentOfNodeA] = parentOfNodeB;
        }
    }
};

/*
    * In every union operation, the superParent() (also known as find() in many texts) function must be called for both nodes.
*/