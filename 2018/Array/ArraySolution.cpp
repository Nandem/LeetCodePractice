#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include "../../Utils/CommonUtil.h"

using namespace std;

class Solution
{
public:
    ~Solution()
    {
        cout << "Solution销毁" << endl;
    }

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

    /**
     * 题目：移动零
     * 描述：给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。
     * 说明：必须在原数组上操作，不能拷贝额外的数组。 尽量减少操作次数。
     * 下面为双指针压缩法：
     * void moveZeroes(vector<int> &nums)
     * {
     *     int j = 0;
     *     for (int i = 0; i < nums.size(); ++i)
     *     {
     *         if (nums[i] != 0)
     *         {
     *             nums[j] = nums[i];
     *             ++j;
     *         }
     *     }
     *     for (; j < nums.size(); ++j)
     *     {
     *         nums[j] = 0;
     *     }
     * }
     * @param nums
     */
    void moveZeroes(vector<int> &nums)
    {
        int breakIndex = 0;
        for (int n : nums)
        {
            if (n == 0) breakIndex++;
        }

        for (int i = 0; i < nums.size();)
        {
            if (nums[i] == 0)
            {
                for (int j = i; j < nums.size() - 1; ++j)
                {
                    nums[j] = nums[j + 1];
                }
                nums[nums.size() - 1] = 0;
            }

            if (i == (nums.size() - breakIndex)) break;

            if (nums[i] == 0)
            {
                continue;
            }
            i++;
        }

        CommonUtil::print(nums);
    }

    /**
     * 问题：两数之和
     * 描述：给定一个整数数组和一个目标值，找出数组中和为目标值的两个数下标。你可以假设每个输入只对应一种答案，且同样的元素不能被重复利用。
     * 下面使用map辅助，一遍哈希表：
     * vector<int> twoSum(vector<int> &nums, int target)
     * {
     *     unordered_map<int, int> m;
     *     for (int i = 0; i < nums.size(); ++i)
     *     {
     *         if (m.count(target - nums[i]))
     *         {
     *             return {i, m[target - nums[i]]};
     *         }
     *         m[nums[i]] = i;
     *     }
     *     return {};
     * }
     * @param nums
     * @param target
     * @return
     */
    vector<int> twoSum(vector<int> &nums, int target)
    {
        vector<int> result;
        for (int i = 0; i < nums.size(); i++)
        {
            int dv = target - nums[i];

            //if(dv < 0) continue;//测试用例中有负数，此行需要注释掉

            for (int j = i + 1; j < nums.size(); j++)
            {
                if (dv == nums[j])
                {
                    result.push_back(i);
                    result.push_back(j);
                }
            }
        }
        return result;
    }

    /**
     * 问题：有效的数独
     * 描述：判断一个 9x9 的数独是否有效。只需要根据以下规则，验证已经填入的数字是否有效即可。
     *       1.数字 1-9 在每一行只能出现一次。
     *       2.数字 1-9 在每一列只能出现一次。
     *       3.数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。
     * 说明：
     *      一个有效的数独（部分已被填充）不一定是可解的。
     *      只需要根据以上规则，验证已经填入的数字是否有效即可。
     *      给定数独序列只包含数字 1-9 和字符 '.' 。
     *      给定数独永远是 9x9 形式的。
     * @param board
     * @return
     */
    bool isValidSudoku(vector<vector<char>> &board)
    {
        if (board.empty() || board[0].empty()) return false;
        unsigned int m = board.size(), n = board[0].size();
        vector<vector<bool>> rowFlag(m, vector<bool>(n, false));
        vector<vector<bool>> colFlag(m, vector<bool>(n, false));
        vector<vector<bool>> cellFlag(m, vector<bool>(n, false));
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (board[i][j] >= '1' && board[i][j] <= '9')
                {
                    int c = board[i][j] - '1';
                    if (rowFlag[i][c] || colFlag[c][j] || cellFlag[3 * (i / 3) + j / 3][c]) return false;
                    rowFlag[i][c] = true;
                    colFlag[c][j] = true;
                    cellFlag[3 * (i / 3) + j / 3][c] = true;
                }
            }
        }
        return true;
    }

    /**
     * 题目：旋转图像
     * 描述：给定一个 n × n 的二维矩阵表示一个图像。
     *       将图像顺时针旋转 90 度。
     * 说明：你必须在原地旋转图像，这意味着你需要直接修改输入的二维矩阵。请不要使用另一个矩阵来旋转图像。
     * @param matrix
     */
    void rotate(vector<vector<int> > &matrix)
    {
        CommonUtil::print(matrix);
        int n = matrix.size();
        for (int i = 0; i < n / 2; ++i)
        {
            for (int j = i; j < n - 1 - i; ++j)
            {
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[n - 1 - j][i];
                matrix[n - 1 - j][i] = matrix[n - 1 - i][n - 1 - j];
                matrix[n - 1 - i][n - 1 - j] = matrix[j][n - 1 - i];
                matrix[j][n - 1 - i] = tmp;
            }
        }
        CommonUtil::print(matrix);
    }

    /**
     * 题目：寻找数组的中心索引
     * 描述：给定一个整数类型的数组 nums，请编写一个能够返回数组“中心索引”的方法。
     *       我们是这样定义数组中心索引的：数组中心索引的左侧所有元素相加的和等于右侧所有元素相加的和。
     *       如果数组不存在中心索引，那么我们应该返回 -1。如果数组有多个中心索引，那么我们应该返回最靠近左边的那一个。
     * 说明：nums 的长度范围为 [0, 10000]。
     *       任何一个 nums[i] 将会是一个范围在 [-1000, 1000]的整数。
     * @param matrix
     */
    int pivotIndex(vector<int> &nums)
    {
        int sum = 0;
        int sumLeft = 0;
        int sumRight = 0;
        for (auto num : nums)
        {
            sum += num;
        }

        for (int i = 0; i < nums.size(); ++i)
        {
            if(i == 0)
            {
                sumLeft = 0;
            }
            else
            {
                sumLeft += nums[i - 1];
            }

            sumRight = sum - sumLeft - nums[i];

            if(sumLeft == sumRight)
            {
                return i;
            }
        }

        return -1;
    }

    /**
     * 题目：至少是其他数字两倍的最大数
     * 描述：在一个给定的数组nums中，总是存在一个最大元素 。
     *       查找数组中的最大元素是否至少是数组中每个其他数字的两倍。
     *       如果是，则返回最大元素的索引，否则返回-1。
     * 说明：nums 的长度范围在[1, 50].
     *       每个 nums[i] 的整数范围在 [0, 99].
     * @param nums
     * @return
     */
    int dominantIndex(vector<int>& nums) {
        int maxNum = 0;
        int maxNumIndex = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            for (int j = 0; j < nums.size(); ++j)
            {
                if(nums[i] >= nums[j])
                {
                    int tem = nums[i];
                    nums[i] = nums[j];
                    nums[j] = tem;

                }

                if(nums[j] > maxNum)
                {
                    maxNum = nums[j];
                    maxNumIndex = j;

                    std::cout << "maxNumIndex: " << maxNumIndex << std::endl;
                }
            }
        }

        for (auto n : nums)
        {
            std::cout << n ;
        }

        std::cout << std::endl;

        if(nums[0] >= 2 * nums[1])
        {
            return maxNumIndex;
        }

        return -1;
    }
};