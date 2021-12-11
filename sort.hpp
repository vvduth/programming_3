#pragma once
#include<iostream>
using namespace std ;

struct sort_comp_storage
{
    double etime_sort = 0.0;
    long comp_num = 0, swap_num = 0, operations_num = 0;
};


void insertionSort(int a[], int n);

void selectionSort(int a[], int n);

void merge(int arr[], int l, int m, int r);

void mergeSort(int a[], int l, int r) ;

void quickSort(int a[], int l, int r) ;