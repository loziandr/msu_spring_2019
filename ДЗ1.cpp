#include<cstdio>
#include<vector>
#include<algorithm>
#include<iostream>
#include <cstdlib>
#include "numbers.dat"

std:: vector<bool> generate_prime_numbers(int n)
{
    std::vector<bool> is_prime(n + 1, true);
    is_prime[1] = false;
    is_prime[0] = false;
    for (int i = 2; i * i <= n; ++i)
        if (is_prime[i])
            for (int j = i * i; j <= n; j += i)
                is_prime[j] = false;
    return is_prime;
}
void Search(int left, int right, std:: vector<bool>  is_prime)
{
    int ans = 0;
    int index_left = std::lower_bound(Data, Data + Size, left) - Data;
    int index_right = std::upper_bound(Data, Data + Size, right) - Data;
    if(Data[index_left] != left || Data[index_right - 1] != right) std:: cout << 0 << std:: endl;
    else
    {
        for(int i = index_left; i < index_right; ++i)
        if(is_prime[Data[i]]) ++ans;
        std:: cout << ans << std:: endl;
    }
}
int main(int argc, char* argv[])
{
    if(!(argc % 2) || argc == 1) return -1;
    const int n = 100000;
    std::vector<bool> is_prime = generate_prime_numbers(n);
    for(int i = 1; i < argc; i += 2)
        Search(atoi(argv[i]), atoi(argv[i + 1]), is_prime);
    return 0;
}
