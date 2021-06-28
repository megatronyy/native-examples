#include <vector>
#include <algorithm>
#include <iostream>

/**
 * @brief 分配问题--小孩子分饼干
 * 
 * 贪心算法，保证每次操作都是局部最优，从而使最后得到的结果是全局最优
 * 
 * @param children 小孩子的饥饿度
 * @param cookies 饼干的大小
 * @return int 每个孩子最多只能吃一块饼干，返回最多有多少孩子可以吃饱
 */
int findContentChildren(std::vector<int> &children, std::vector<int> &cookies)
{
    std::sort(children.begin(), children.end());
    std::sort(cookies.begin(), cookies.end());

    int child = 0, cookie = 0;
    while (child < children.size() && cookie < cookies.size())
    {
        if (children[child] <= cookies[cookie]) ++child;
        ++cookie;
        
    }
    return child;
}

int main(int argc, char const *argv[])
{
    std::vector<int> childrens = {1, 2};
    std::vector<int> cookies = {1, 2, 3};
    int child = findContentChildren(childrens, cookies);

    std::cout << child << std::endl;
    return 0;
}
