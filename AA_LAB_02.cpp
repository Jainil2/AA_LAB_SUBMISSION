#include <bits/stdc++.h>
#define ull unsigned long long int
using namespace std;

ull gcd(ull a, ull b)
{
    ull q, r;
    while (b > 0)
    {
        q = a / b;
        r = a - q * b;
        a = b;
        b = r;
    }
    return a;
}

ull power(ull a, ull n, ull p)
{
    ull res = 1;
    a = a % p;
    while (n > 0)
    {
        if (n & 1)
            res = (res * a) % p;
        n = n >> 1;
        a = (a * a) % p;
    }
    return res;
}
bool isPrime(ull n)
{
    if (n % 2 == 0 && n != 2)
    {
        return false;
    }
    else if (n > 1 && n < 4)
    {
        return true;
    }
    else if (n < 1)
    {
        return false;
    }
    else
    {
        ull k = 100;
        while (k--)
        {
            ull a = 2 + rand() % (n - 1);
            if (gcd(a, n) != 1)
            {
                return false;
            }
            if (power(a, n - 1, n) != 1)
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    srand(time(0));
    ull nn = rand();
    if (isPrime(nn) == 1)
    {
        cout << nn << " is a prime number" << endl;
    }
    else
    {
        cout << nn << " is not a prime number" << endl;
    }
    return 0;
}
