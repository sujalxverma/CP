#include "bits/stdc++.h"
using namespace std;
using ll = long long;

ll f(ll &n, ll &d)
{

    ll ans = 0;
    ll count = 0;
    ll number = n;

    while (number > 0)
    {
        ll digit = (number % 10);
        count++;
        number = number / 10;

        if (digit == d)
        {
            if (d == 0)
            {
                number = ((number * pow(10, count))) + stoi(string(count, '1'));
                ans = number - n;
            }
            else
            {
                number = ((number * pow(10, count))) + (d + 1) * pow(10, count - 1);
                ans = number - n;
            }
            count = 0;
        }
    }

    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        ll n, d;
        cin >> n >> d;
        cout << f(n, d) << "\n";
    }
    return 0;
}

/*

1. This code fails for n = 88888889 , d = 9.
2. As per this code number = 88888890 , and diff = 1.
3. Which is wrong, it simply ignores that adding 1 to leftmost d can also, make d in its left
   position.
4. DAMN.

bool check_digit(ll n, ll d)
{

    while (n > 0)
    {
        ll digit = n % 10;
        if (digit == d)
        {
            return true;
        }
        n = n / 10;
    }
    return false;
}

vector<ll> digits(ll n)
{
    vector<ll> nums_digits;
    while (n > 0)
    {
        nums_digits.push_back(n % 10);

        n = n / 10;
    }
    reverse(nums_digits.begin(), nums_digits.end());

    return nums_digits;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        ll n, d;
        cin >> n >> d;
        // First check if d is even present in n.
        bool flag = check_digit(n, d);
        if (!flag)
        {
            cout << "0\n";
            continue;
        }
        else if (d == 0)
        {
            vector<ll> nums_digits = digits(n);
            int size = (int)nums_digits.size();
            // for(int i = 0; i< size ; i++){
            //     cout<<nums_digits[i]<<" ";
            // }
            // cout<<"\n";

            ll number = 0;
            bool ft = false;
            for (int i = 0; i < size; i++)
            {
                if (ft)
                {
                    number = number * 10 + 1;
                    continue;
                }
                else if (nums_digits[i] == d)
                {
                    number = number * 10 + (d + 1);
                    ft = true;
                    //  cout<<number<<"\n";
                }
                else
                {
                    number = number * 10 + nums_digits[i];
                }
            }
            // cout<<number<<"\n";
            cout << number - n << "\n";
            continue;
        }
        else
        {
            // only make digit d -> d+1, to the place having highest place value of d.
            // can simply store it in vector.
            vector<ll> nums_digits = digits(n);
            int size = (int)nums_digits.size();
            ll number = 0;
            int idx = 0;
            //  for(int i = 0; i< size ; i++){
            //     cout<<nums_digits[i]<<" ";
            // }
            // cout<<"\n";
            for (int i = 0; i < size; i++)
            {
                if (nums_digits[i] == d)
                {
                    number = number * 10 + (d + 1);
                    //  cout<<number<<"\n";
                    idx = i + 1;
                    break;
                }
                else
                {
                    number = number * 10 + nums_digits[i];
                    // cout<<number<<"\n";
                }
            }

            for (int i = idx; i < size; i++)
            {
                number *= 10;
                //  cout<<number<<"\n";
            }
            cout<<number<<"\n";
            cout << number - n << "\n";
            continue;
        }
    }
    return 0;
}

*/