//
// Created by nandem on 7/18/2018.
//

#ifndef LETCODEPRACTICE_COMMONUTIL_H
#define LETCODEPRACTICE_COMMONUTIL_H

#include <vector>

class CommonUtil
{
public:
    static int max(std::vector<int> & v)
    {
        std::vector<int>::iterator it;
        for (it = v.begin(); it != v.end(); it++)
        {
            if(*it > v[0])
            {
                v[0] = *it;
            }
        }

        return v[0];
    }

    static void max(std::vector<int> & v, int& max, int& index)
    {
        max = INT32_MIN;
        for (int i = 0; i < v.size(); i++)
        {
            if(v[i] > max)
            {
                max = v[i];
                index = i;
            }
        }
    }

    static int min(std::vector<int> & v)
    {
        std::vector<int>::iterator it;
        for (it = v.begin(); it != v.end(); it++)
        {
            if(*it < v[0])
            {
                v[0] = *it;
            }
        }

        return v[0];
    }
    static void min(std::vector<int> & v, int& min, int& index)
    {
        min = INT32_MAX;//此步骤至关重要
        for (int i = 0; i < v.size(); i++)
        {
            if(v[i] < min)
            {
                min = v[i];
                index = i;
            }
        }
    }

    template<class T>
    static int length(T& arr)
    {
        //cout << sizeof(arr[0]) << endl;
        //cout << sizeof(arr) << endl;
        return sizeof(arr) / sizeof(arr[0]);
    }

};

#endif //LETCODEPRACTICE_COMMONUTIL_H
