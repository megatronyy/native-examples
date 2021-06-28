#include <vector>
#include <iostream>
#include <functional>
#include <algorithm>
#include <numeric>

/**
 * @brief 分配问题--小孩子分糖果
 * 
 * 贪心算法，保证每次操作都是局部最优，从而使最后得到的结果是全局最优
 * 
 * 规则：孩子站成一排，每一个孩子有自己的评分。如果孩子的评分比自己身旁的一个孩子高，那么这个孩子要比身旁这个孩子得到更多的糖果;
 * 所有孩子至少要有一颗糖果。
 * 
 * @param ratings 孩子的评分
 * @return 最少需要多少糖果
 */
int candy(std::vector<int> &ratings)
{
    int size = ratings.size();
    if (size < 2)
    {
        return size;
    }

    std::vector<int> num(size, 1);

    //从左往右循环一遍
    for (int i = 1; i < size; i++)
    {
        if (ratings[i] > ratings[i - 1])
        {
            num[i] = num[i] + 1;
        }
        
    }

    //从右往左再循环一遍
    for (int i = size - 1; i > 0; i--)
    {
        if (ratings[i] < ratings[i - 1])
        {
            num[i - 1] = std::max(num[i -1], num[i] + 1);
        }
        
    }
    return std::accumulate(num.begin(), num.end(), 0);
}

int main(int argc, char const *argv[])
{
    std::vector<int> ratings = {1, 0, 2};
    std::cout << candy(ratings) << std::endl;
    return 0;
}
