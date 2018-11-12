//
// Created by nandem on 11/12/2018.
//

#include <vector>
#include <cstring>
#include "../../Utils/CommonUtil.h"

using namespace std;

class StringSolution
{
public:
    /**
     * 题目:
     *     反转字符串
     * 描述:
     *     编写一个函数，其作用是将输入的字符串反转过来。
     * 说明:
     *     无
     * @param s
     * @return
     */
    string reverseString(string s)
    {
        for (int i = 0; i < s.size() / 2; ++i)
        {
            char tem = s[i];
            s[i] = s[s.size() - i - 1];
            s[s.size() - i - 1] = tem;
        }

        return s;
    }
};

int main()
{
    auto *solution = new StringSolution;

    string testCase1 = "A man, a plan, a canal: Panama";
//    string testCase1 = "nandem";

    cout << solution->reverseString(testCase1) << endl;

    return 0;
}
