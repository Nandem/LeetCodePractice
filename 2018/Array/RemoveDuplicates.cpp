#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        for (int i = 0; i < nums.size(); ++i)
        {
            for (int j = nums.size() - 1; j > i; --j)
            {
                if(nums[i] == nums[j])
                {
                    nums.erase(nums.begin() + j);
                }
            }
        }

        vector<int>:: iterator it;
        for(it = nums.begin(); it != nums.end(); it++)
        {
            cout << *it << '\0';
        }

        return nums.size();
    }
};

int main()
{
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(2);
    auto *solution = new Solution();
    solution->removeDuplicates(nums);

    return 0;
}