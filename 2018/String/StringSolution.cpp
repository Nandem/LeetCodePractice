//
// Created by nandem on 11/12/2018.
//

#include <vector>
#include <cstring>
#include <stdlib.h>
#include <math.h>
#include <sstream>
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

    /**
     * 题目:
     *     颠倒整数
     * 描述:
     *     给定一个 32 位有符号整数，将整数中的数字进行反转。
     * 说明:
     *     假设我们的环境只能存储 32 位有符号整数，
     *     其数值范围是 [−2^31,  2^31 − 1]。根据这个假设，
     *     如果反转后的整数溢出，则返回 0。
     * @param x
     * @return
     */
    int reverse(int x)
    {
        int sign = x < 0 ? -1 : 1;
        int ret = 0;

        string xs = to_string(x);

        for (int i = 0; i < xs.size() / 2; ++i)
        {
            char tem = xs[i];
            xs[i] = xs[xs.size() - i - 1];
            xs[xs.size() - i - 1] = tem;
        }

        istringstream stream(xs);
        stream >> ret;

        if (ret >= pow(2, 31) - 1)
            return 0;

        ret *= sign;

        return ret;
    }
};

int main()
{
    auto *solution = new StringSolution;

//    string testCase = "A man, a plan, a canal: Panama";
    int testCase = -2147483648;

//    cout << solution->reverseString(testCase) << endl;
    cout << solution->reverse(testCase) << endl;

    return 0;
}
