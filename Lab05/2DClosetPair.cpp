#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <limits>
#include <iomanip>

struct Point
{
    int x, y;
};

float dist(const Point& a, const Point& b)
{
    const float dx = a.x - b.x;
    const float dy = a.y - b.y;
    return std::sqrt(dx*dx + dy*dy);
}

float strips(std::vector<Point>& strip, int size, float d)
{
    float min = d;

    std::sort(strip.begin(), strip.end(), [](const Point& a, const Point& b){
        return a.y < b.y;
    });

    for (int i = 0; i < size; ++i) 
        for (int j = i+1; j < size && (strip[j].y - strip[i].y) < min; ++j) 
            min = std::min(min, dist(strip[i], strip[j])); 
 
    return min;
}

float closet(std::vector<Point>& v, int l, int r)
{
    if(r-l<=3)
    {
        float min = std::numeric_limits<float>::max(); 
        for (int i = l; i <= r; i++)
            for (int j = i+1; j <= r; j++)
                min = std::min(min, dist(v[i], v[j]));

        return min;
    }

    int m = l + (r-l)/2;

    float dl = closet(v, l, m);
    float dr = closet(v, m+1, r);

    float d = std::min(dl, dr);

    std::vector<Point> strip;
    for (int i = l; i <= r; i++) 
    {
        if (std::abs(v[i].x - v[m].x) < d) 
        {
            strip.push_back(v[i]); 
        }
    }
    
    return std::min(d, strips(strip, strip.size(), d));
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    
    std::vector<Point> v(n);
    for(int i=0; i<n; i++)
    {
        std::cin >> v[i].x >> v[i].y;
    }

    std::sort(v.begin(), v.end(), [](const Point& a, const Point& b){
        return a.x < b.x;
    });

    std::cout << std::fixed << std::setprecision(3) << closet(v, 0, n-1);
}