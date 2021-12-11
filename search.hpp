#pragma once

#include<vector>



struct time_stat
{
    double etime_bin = 0.0, etime_linear = 0.0;
    int bin_comp_num = 0, linear_comp_num = 0;
};

int linearSearch(int a[], int n, int x, int *comparison_num = nullptr) ;

int binarySearch(int a[], int n , int x, int *comparison_num = nullptr);