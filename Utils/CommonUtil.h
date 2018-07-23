//
// Created by nandem on 7/18/2018.
//

#ifndef LETCODEPRACTICE_COMMONUTIL_H
#define LETCODEPRACTICE_COMMONUTIL_H

#include <vector>
#include <cstdint>
#include <iostream>

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

    static void print(std::vector<int> & v)
    {
        for(int vn : v)
        {
            std::cout << vn << ' ';
        }

        std::cout << std::endl;
    }

    static void sort(std::vector<int> & v)
    {
        for(int i = 0; i < v.size(); i++)
        {
            for(int j = i; j < v.size(); j++)
            {
                if(v[j] < v[i])
                {
                    int tem = v[i];
                    v[i] = v[j];
                    v[j] = tem;
                }
            }
        }
    }

    template<class T>
    static unsigned int length(T& arr)
    {
        //cout << sizeof(arr[0]) << endl;
        //cout << sizeof(arr) << endl;
        return sizeof(arr) / sizeof(arr[0]);
    }

};

#endif //LETCODEPRACTICE_COMMONUTIL_H
