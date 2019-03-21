#include<cstdio>
#include<vector>
#include<algorithm>
#include <cstdlib>
#include "numbers.dat"


int main(int argc, char* argv[])
{
    const int n = 100000;
    std::vector<bool> is_prime(n + 1, true);
    is_prime[1] = false;
    is_prime[0] = false;
    for (int i = 2; i * i <= n; ++i)
        if (is_prime[i])
            for (int j = i * i; j <= n; j += i)
                is_prime[j] = false;
    if(!(argc % 2) || argc == 1) return -1;
    for(int i = 1; i < argc; i += 2)
    {
        int left = atoi(argv[i]), right = atoi(argv[i + 1]), ans = 0;
        int index_left = std::lower_bound(Data, Data + Size, left) - Data;
        int index_right = std::upper_bound(Data, Data + Size, right) - Data;
        if(Data[index_left] != left || Data[index_right - 1] != right) printf("%d \n", 0);
        else
        {
            for(int i = index_left; i < index_right; ++i)
                if(is_prime[Data[i]]) ++ans;
            printf("%d \n", ans);
        }
    }
}
