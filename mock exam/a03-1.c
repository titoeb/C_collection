#include<stdio.h>
#include "a03-testing.h"

/*
int recSort(int *start, int *end, int reverse){
	if (start == NULL || end == NULL)
		return 0;

	if(start >= end || start + 1 >= end)
		return 0;

	if (end - start < 2){
		 return 0;
	} else {
		int switched = 0;
		int *cur;
		if(reverse == 0){	
			cur = start;
		} else {
			cur = end;
		}
		int tmp;
		// Vorwaerts
		while((cur >= start) & (cur <= end)){
			if(reverse == 0){
				if (*cur < *(cur + 1)){
					switched++;
					tmp = *cur;
					*cur = *(cur + 1);
					*(cur + 1) = tmp;		
				}
				cur++;
			} else {
				if (*cur >= *(cur - 1)){
					switched++;
					tmp = *cur;
					*cur = *(cur - 1);
					*(cur - 1) = tmp;		
				}
				cur--;
			}
			
		}
		if(switched > 0){
			if(reverse == 0)
				return recSort(start, end - 1, 1) + switched;
			else
				return recSort(start + 1, end, 0) + switched;
		} else {
			return 0;
		}
	}

} */

int recSort(int *start, int *end, int reverse){
	if (start == NULL || end == NULL)
		return 0;

	if(start >= end || start + 1 >= end)
		return 0;

	int *p;
	if(reverse == 1){
		p = end - 1;	
	} else {
		p = start + 1;
	}

	int h;
	int swaps = 0;
	while(p < end && p > start){
		if(*(p - 1) < *p){
			h = *(p - 1);
			*(p - 1) = *p;
			*p = h;
			swaps++;
		}
		if(reverse == 1){
			p--;
		} else {
			p++;		
		}
	}
	if(swaps > 0){
		if (reverse == 1)
			swaps += recSort(start + 1, end, 0);
		else
			swaps += recSort(start, end - 1, 1);
		
	}
	return swaps;
}

