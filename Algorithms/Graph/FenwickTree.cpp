
/*
 * Fenwick Tree
 * range query and updation : O(logN)
 * each bit[i] stores answer from [i&(i+1)-1,i].
 */
struct Fenwick
{
    vector<int> bit;
    int size;
    Fenwick(int n)
    {
        size = n;
        bit.assign(size, 0);
    }
    Fenwick(const vector<int> &a) : Fenwick(a.size())
    {
        for (int i = 0; i < size; i++)
            update(i, a[i]);
    }
    void update(int i, int delta)
    {
        while (i < size)
        {
            bit[i] += delta;
            i = i | (i + 1);
        }
    }
    int query(int k)
    {
        int res = 0;
        while (k >= 0)
        {
            res += bit[k];
            k = (k & (k + 1)) - 1;
        }
        return res;
    }
    int query(int l, int r)
    {
        return query(r) - query(l - 1);
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    return 0;
}