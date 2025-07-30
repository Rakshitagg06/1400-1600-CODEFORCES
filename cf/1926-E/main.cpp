#include <bits/stdc++.h>
#include <strings.h>
#include <iomanip>
#include <stdio.h>
#include <numeric>
#define lld long long int
#define vi vector<lld>
#define vvii vector<vector<lld>>
#define vp vector<pair<lld, lld>>
#define rep_p(i, a, b) for (lld i = a; i < b; i++)
#define mp map<lld, lld>
#define no cout << "No" << endl
#define yes cout << "Yes" << endl
// #define sort(a) sort(a.begin(), a.end())
#define bs(a, val) binary_search(a.begin(), a.end(), val)
#define round_up(a, b) (a + b - 1) / b
using namespace std;
lld gcd(lld a, lld b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}
void print_vec(const vector<lld> &v)
{
    for (lld x : v) // Correct type
        cout << x << " ";
    cout << endl;
}
void seive(lld n, vi &prime)
{
    vi is_prime(n + 1, 1); // Initialize sieve
    for (lld i = 2; i * i <= n; i++)
    {
        if (is_prime[i])
        {
            for (lld j = i * i; j <= n; j += i)
            {
                is_prime[j] = 0;
            }
        }
    }
    prime = is_prime;
}
vi prefix_sum(vi a, int n)
{
    vi pre(n, a[0]);
    rep_p(i, 1, n)
    {
        pre[i] = pre[i - 1] + a[i];
    }
    return pre;
}
lld min(lld a, lld b)
{
    if (a < b)
        return a;
    return b;
}
lld max(lld a, lld b)
{
    if (a > b)
        return a;
    return b;
}
bool is_prime(lld n)
{
    if (n == 2)
        return true;
    else if (!(n & 1))
        return false;
    for (int i = 3; i <= sqrt(n); i += 2)
    {
        if (!(n % i))
        {
            return false;
        }
    }
    return true;
}
lld extended_euclid(int a, int b, lld &x, lld &y)
{
    if (b == 0)
    {
        x = 1;
        return a;
    }
    lld x1, y1;
    int g = extended_euclid(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return g;
}
lld absolute(lld a)
{
    if (a < 0)
        return -a;
    return a;
}
lld binary_exp(lld base, lld power, lld mod_m)
{
    if (power == 0)
        return 1;
    lld temp = (binary_exp(base, power / 2, mod_m)) % mod_m;
    lld result = (temp * temp) % mod_m;
    if (power & 1)
        result = (result * (base % mod_m)) % mod_m;
    return result;
}
bool comp(pair<lld, lld> a, pair<lld, lld> b)
{
    if (a.first < b.first)
    {
        return 1;
    }
    else if (a.first == b.first)
    {
        return a.second > b.second;
    }
    return 0;
}
void seive_algo(int n, vi &prime)
{
    vi check(n + 1, 1);
    check[0] = 0;
    check[1] = 0;
    rep_p(i, 2, sqrt(n) + 1)
    {
        if (is_prime(i))
        {
            for (int j = 2 * i; j <= n; j += i)
            {
                check[j] = 0;
            }
        }
    }
    rep_p(i, 2, check.size())
    {
        if (check[i])
        {
            prime.push_back(i);
        }
    }
    return;
}
bool lexo(vi p, vi q)
{
    int n = p.size();
    rep_p(i, 0, n)
    {
        if (p[i] < q[i])
        {
            return false;
        }
    }
    return true;
}
lld mod=998244353;
vi primes;
void solve(int test)
{
    lld n,k; cin>>n>>k;
    if(k<=((n+1)/2))
    {
        cout<<(k<<1)-1<<endl;
        return;
    }
    k-=(((n+1)/2));
    for(int a=1;a<=33;a++)
    {
        lld val=n/(1LL<<a);
        lld rem=(val+1)/2;
        //rem is the number of values left, val is like 11=(4)*(2), so val is 2 and rem is 1(4*(1))
        // k is the postion, rem is number of odd values, now k is also the index number of the pos
        if(k<=rem)
        {
            cout<<(1LL<<a)*((k<<1LL)-1)<<endl;
            return;
        }
        else
        {
            k-=rem;
        }
    }
    return;
}
int main()
{
    // your code goes here
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test = 1;
    cin >> test;
    rep_p(i,2,1003000)
    {
        if(is_prime(i))
        {
            primes.push_back(i);
        }
    }
    while (test > 0)
    {
        solve(test);
        --test;
    }
    return 0;
}