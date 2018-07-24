#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
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
        if (nums.empty()) return 0;
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
        if (prices.empty()) return 0;

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
        if (nums.empty()) return;

        CommonUtil::print(nums);

        if (nums.empty() || (k %= nums.size()) == 0) return;
        int n = nums.size();
        reverse(nums.begin(), nums.begin() + n - k);
        reverse(nums.begin() + n - k, nums.end());
        reverse(nums.begin(), nums.end());

        CommonUtil::print(nums);
    }

    /**
     * 题目：存在重复
     * 描述：给定一个整数数组，判断是否存在重复元素。
     * 注意：需要判空，存在传入数组为空的情况
     * @param nums
     * @return
     */
    bool containsDuplicate(vector<int> &nums)
    {
        if (nums.empty()) return false;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size() - 1; i++)
        {
            if (nums[i + 1] == nums[i])
            {
                return true;
            }
        }

        return false;
    }

    /**
     * 题目：只出现一次的数字（给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。）
     * 描述：你的算法应该具有线性时间复杂度。 你可以不使用额外空间来实现吗？
     * 巧妙：
     * int singleNumber(vector<int> &nums)
     * {
     *     int ret=0;//异或计算
     *    for(int i=0;i<nums.size();i++)
     *    {
     *        ret^=nums[i];
     *    }
     *    return ret;
     * }
     *
     * @param nums
     * @return
     */
    int singleNumber(vector<int> &nums)
    {
        if (nums.empty()) return 0;

        sort(nums.begin(), nums.end());

        CommonUtil::print(nums);

        for (int i = 0; i < nums.size(); i++)
        {
            if (i - 1 < 0)
            {
                if (nums[i + 1] != nums[i])
                {
                    return nums[i];
                }
            }
            else if (i + 1 > nums.size())
            {
                if (nums[i - 1] != nums[i])
                {
                    return nums[i];
                }
            }
            else if (nums[i - 1] != nums[i] && nums[i] != nums[i + 1])
            {
                return nums[i];
            }
        }
    }

    /**
     * 题目：两个数组的交集 II
     * 描述：给定两个数组，写一个方法来计算它们的交集。
     * @param nums1
     * @param nums2
     * @return
     */
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> result;

        for (int n2 : nums2)
        {
            for (int i = 0; i < nums1.size(); i++)
            {
                if (nums1[i] == n2)
                {
                    result.push_back(n2);
                    nums1.erase(nums1.begin() + i);
                    break;
                }
            }
        }

        return result;
    }

    /**
     * 题目：加一
     * 描述：给定一个非负整数组成的非空数组，在该数的基础上加一，返回一个新的数组。 最高位数字存放在数组的首位， 数组中每个元素只存储一个数字。
     * 你可以假设除了整数 0 之外，这个整数不会以零开头。
     * 巧妙：搞清楚要不要进位是比较好的方案，操作的步骤也少。如下
     * @param digits
     * @return
     */
    vector<int> plusOne(vector<int> &digits)
    {
        int n = digits.size();
        for (int i = n - 1; i >= 0; --i)
        {
            if (digits[i] == 9) digits[i] = 0;
            else
            {
                digits[i] += 1;
                return digits;
            }
        }
        if (digits.front() == 0) digits.insert(digits.begin(), 1);
        return digits;
    }
};

int
main()
{
    auto *solution = new Solution();

    int arr1[] = {6, 1, 4, 5, 3, 9, 0, 1, 9, 5, 1, 8, 6, 7, 0, 5, 5, 4, 3};
    int arr2[] = {2, 2};
    vector<int> v1 = CommonUtil::getVector(arr1, CommonUtil::length(arr1));
    vector<int> v2 = CommonUtil::getVector(arr2, CommonUtil::length(arr2));;

    solution->plusOne(v1).size();

    return 0;
}