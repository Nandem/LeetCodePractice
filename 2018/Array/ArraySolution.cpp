#include <iostream>
#include <vector>
#include <algorithm>
#include "../../Utils/CommonUtil.h"

using namespace std;

class Solution
{
public:
    /**
     * 题目：删除已排序数组重复元素
     * @param nums 原始数组
     * @return 去重后的数组元素个数
     */
    int removeDuplicates(vector<int> &nums)
    {
        for (int i = 0; i < nums.size(); ++i)
        {
            for (int j = nums.size() - 1; j > i; --j)
            {
                if (nums[i] == nums[j])
                {
                    nums.erase(nums.begin() + j);
                }
            }
        }

        vector<int>::iterator it;
        for (it = nums.begin(); it != nums.end(); it++)
        {
            cout << *it << '\0';
        }

        return nums.size();
    }

    /**
     * 题目：买卖股票的最佳时机 II
     * 思路：贪心
     * @param prices 原始数组
     * @return 所能获取的最大利润
     */
    int maxProfit(vector<int> &prices)
    {
        int sum = 0;
        for (int i = 1; i < prices.size(); i++)
        {
            if (prices[i] > prices[i - 1])
            {
                sum += prices[i] - prices[i - 1];
            }
        }
        return sum;
    }

    /**
     * 题目：旋转数组
     * 描述：给定一个数组，将数组中的元素向右移动 k 个位置，其中 k 是非负数
     * @param nums
     * @param k
     */
    void rotate(vector<int> &nums, int k)
    {
        for (int i : nums)
        {
            cout << i << '\0';
        }
        cout << endl;
        if (nums.empty() || (k %= nums.size()) == 0) return;
        int n = nums.size();
        reverse(nums.begin(), nums.begin() + n - k);
        reverse(nums.begin() + n - k, nums.end());
        reverse(nums.begin(), nums.end());
        for (int i : nums)
        {
            cout << i << '\0';
        }
    }
};

int
main()
{
    auto *solution = new Solution();

    /*/
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(2);
    solution->removeDuplicates(nums);
    //*/

    /*/
    int pricesArr[] = {7, 1, 5, 3, 6, 4};
    vector<int> prices(&pricesArr[0], &pricesArr[CommonUtil::length(pricesArr)]);
    cout << solution->maxProfit(prices);
    //*/

    int k = 6;
    int arrToBeRotated[] = {1,2,3,4,5,6,7,8};
    vector<int> av;
    av.reserve(CommonUtil::length(arrToBeRotated));
    av.insert(av.begin(), &arrToBeRotated[0], &arrToBeRotated[CommonUtil::length(arrToBeRotated)]);
    solution->rotate(av, k);
    return 0;
}