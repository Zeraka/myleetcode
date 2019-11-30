/*
continuous array's successive subarray's max sum

*/

#include <string>
#include <iostream>
#include <cstring>
//
int FindGreatSumOfSubArray(int list[],int length);

int FindGreatSumOfSubArray(int list[],int length)
{

	
	printf("len=%d\n",length);
	int MaxSum = 0;
	int sum = 0;

	int n = 0;
	
	while(n < length){
		sum += list[n];
		if(sum > MaxSum)
		{
			MaxSum = sum;
		}

		if(sum < 0)
		{
			n++;
			sum=0;
			sum+=list[n];
		}

		n++;

		
	}
		printf("Max=%d\n",MaxSum);
}

int main(){

	//输入的数组
	int list[] = {1,-2,3,10,-4,7,2,-5};

	//
	FindGreatSumOfSubArray(list, 8);


}
