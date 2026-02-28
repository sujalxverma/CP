#include "bits/stdc++.h"
using namespace std;
using ll = long long;
vector<ll> employee;
vector<ll> salary;

struct SegTree
{
    ll size;
    vector<ll> tree;

    void init(ll n)
    {
        size = 1;
        while (size < n)
        {
            size *= 2;
        }
        tree.assign(2 * size, 0);
    }
    void addUpdate(ll idx, ll node, ll lx, ll rx)
    {
        if (rx - lx == 1)
        {
            tree[node] += 1;
            return;
        }

        ll mid = (lx + rx) / 2;

        if (idx < mid)
        {
            addUpdate(idx, 2 * node + 1, lx, mid);
        }
        else
        {
            addUpdate(idx, 2 * node + 2, mid, rx);
        }

        tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
    }

    void addUpdate(ll idx)
    {
        addUpdate(idx, 0, 0, size);
    }

    void removeUpdate(ll idx, ll node, ll lx, ll rx)
    {
        if (rx - lx == 1)
        {
            tree[node] -= 1;
            return;
        }

        ll mid = (lx + rx) / 2;

        if (idx < mid)
        {
            removeUpdate(idx, 2 * node + 1, lx, mid);
        }
        else
        {
            removeUpdate(idx, 2 * node + 2, mid, rx);
        }

        tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
    }

    void removeUpdate(ll idx)
    {
        removeUpdate(idx, 0, 0, size);
    }

    ll query(ll l, ll r, ll node, ll lx, ll rx)
    {
        if (lx >= r || rx <= l)
        {
            return 0;
        }
        if (l <= lx && rx <= r)
        {
            return tree[node];
        }

        ll mid = (lx + rx) / 2;

        ll left = query(l, r, 2 * node + 1, lx, mid);
        ll right = query(l, r, 2 * node + 2, mid, rx);

        return (left + right);
    }

    ll query(ll l, ll r)
    {
        return query(l, r, 0, 0, size);
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, q;
    cin >> n >> q;

    for (ll i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        employee.push_back(x);
    }

    vector<tuple<char, ll, ll>> queries;
    for (ll i = 0; i < q; i++)
    {
        char t;
        ll idx;
        ll v;
        cin >> t >> idx >> v;
        queries.push_back({t, idx, v});
        employee.push_back(v);
    }
    salary = employee;
    sort(begin(salary), end(salary));
    // Index compressing.
    salary.erase(unique(begin(salary), end(salary)), end(salary));

    SegTree st;
    st.init((int)salary.size());
    for (int i = 0; i < n; i++)
    {
        st.addUpdate(lower_bound(salary.begin(), salary.end(), employee[i]) - salary.begin());
    }
    for (auto &[t, l, r] : queries)
    {
        if (t == '!')
        {
            // change salary.
            ll idx = l;
            ll value = r;
            ll previdx = lower_bound(begin(salary), end(salary), employee[idx - 1]) - begin(salary);
            ll newidx = lower_bound(begin(salary), end(salary), value) - begin(salary);
            employee[idx - 1] = value;
            st.addUpdate(newidx);
            st.removeUpdate(previdx);
        }
        else
        {
            ll starting = lower_bound(begin(salary), end(salary), l) - begin(salary);
            ll ending = upper_bound(begin(salary), end(salary), r) - begin(salary);
            cout << st.query(starting, ending) << "\n";
        }
    }

    return 0;
}