#include"search.hpp"

int linearSearch(int a[], int n , int x, int *comparison_num ){
    for (int i = 0; i < n; i++){
        if (comparison_num) ++*comparison_num;
		if (a[i] == x){
			return i;
		}
	}
	return -1;   
}

int binarySearch(int a[], int n, int x, int *comparison_num ) {
    int l = 0, r = n-1;
	while (l < r){
        if (comparison_num) ++*comparison_num;
		int mid = (l+r)/2;
		if (a[mid] < x){
			l = mid+1;
		}
		else{
			r = mid;
		}
	}
	if (a[l] == x){
		return l;
	}
	return -1;
}