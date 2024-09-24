#include <bits/stdc++.h>

void merge(std::vector<int>& array, int l, int m, int r)
{
    std::vector<int> result(r-l);
    int i = l;
    int j = m;
    int p = 0;
    while(i < m && j < r)
    {
        if(array[i] < array[j])
        {
            result[p++] = array[i];
            i++;
        }
        else
        {
            result[p++] = array[j];
            j++;
        }
    }

    while(i < m)
    {
        result[p++] = array[i++];
    }
    while(j < r)
    {
        result[p++] = array[j++];
    }
    memcpy(&array[l], &result[0], sizeof(int) * result.size());
}

void BottomUpMergeSort(std::vector<int>& array, int n)
{
    if(n < 2)
        return;
    
    int i = 1;
    while(i < n)
    {
        int j = 0;
        while(j < n - i)
        {
            if(n < j + (2 * i))
                merge(array, j, j+i, n);
            else
                merge(array, j, j+i, j+(2*i));
            
            j += 2*i;
        }

        i *= 2;
    }
}

int main()
{
    int n;
    std::cin >> n;

    std::vector<int> v(n);
    for(int& x : v)
    {
        std::cin >> x;
    }

    BottomUpMergeSort(v, n);
    for(int& x : v)
    {
        std::cout << x << ' ';
    }
}