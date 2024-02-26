#include <iostream>
#include <vector>
#include <set>
using namespace std;

// Problem link -> https://www.geeksforgeeks.org/problems/prime-factors5052/1


// Approach ->> Just fill the sieve table for the prime number calculation, and if the number is prime, then mark its factors as not prime.
//              and also if the factor is initially prime, then their smallest prime factor is the number itself.
vector<int> AllPrimeFactors(int N)
{

    vector<int> prime(N + 1, 1);
    vector<int> spf(N + 1, 0); // smallest prime factor (spf)

// initially smallest prime factors of every number is the number itself.
    for (int i = 1; i <= N; i++)
        spf[i] = i;

    prime[0] = prime[1] = 0;

    // making the sieve.
    for (int i = 2; i * i <= N; i++)
    {
        if (prime[i])
        {
            for (int j = i * i; j <= N; j += i)
            {
                if (prime[j])   // if the number is initially marked as prime, then no one has previously visited it. Then mark its spf(smallest prime factor as i)
                    spf[j] = i;
                prime[j] = 0;
            }
        }
    }

    int num = N;
    set<int> factors;
    while (num != 1)
    {
        factors.insert(spf[num]);
        num = (num / spf[num]);
    }

    return {factors.begin(), factors.end()};
}

int main()
{

    return 0;
}