#include <iostream>
#include <vector>

int main()
{
    int n;
    std::cin >> n;

    std::vector<int> v(n);
    for(int& x : v)
    {
        std::cin >> x;
    }

    int max = -2147483647;
    int cur = 0;
    for(int i=0;i<n;i++)
    {
        if(cur < 0)
            cur = 0;

        cur += v[i];
        max = std::max(max, cur);
    }

    std::cout << max;
}