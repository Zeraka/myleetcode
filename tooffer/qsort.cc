
int MyPartition(int data[], int length, int left, int right)
{

}


int MyQsort_01(int data[], int length, int left, int right)
{
	if(left == right)
		return 1;

	int index = 0;

	index = Random_number();
	while(1)
	{
		while(data[left] < data[basic])
		{
			left++;
		}
		while(data[right] > data[basic])
		{
			right--;
		}

		int swap;
		//交换
		swap = data[left];
		data[left] = data[fight];
		data[right] = swap;

		if(left == right)
		{
			//交换

		}

	}


}
//====================================================
/*
small始终小于等于 index, 因为index只有在小于end的时候，才会移动
而index > end的值的时候， small不移动。
index一直移动，直到碰到 index 再次小于 end
然后small++ ,  并且交换small和index的值， 因为small++后所指的值必然是大于end的，
而index所指的值是小于end的，故互换index and small
这样，small所指的就是小于end的，而index所指的是大于end，然后index继续跑
index == end时， 弹出 
 small++ ,此时右边的都是大于end的，故将end和small互换。
 small的位置，就是分界线，被固定住了，
 因此，可以作为 右边的start ,左边的end

 本质是求出了一个数在数列中的具体位置

*/
int Partition(int data[], int length, int start, int end){
	if(data == nullptr || length <= 0 || start < 0 || end >= length)
		throw new std::exception("Invalid Parameters");

	int index = RandomInRange(start, end);

	Swap(&data[index], &data[end]);

	int small = start - 1;
	for(index = start; index < end ; ++ index )
	{
		if(data[index] < data[end])
		{
			++small;
			if(sma ll != index)
				Swap(&data[index], &data[small]);//如果不等于，就交换
		}
	}
	++small;
	Swap(&data[small], &data[end]);

	return small;//为啥返回small
}





//快排的思路，就是 只要相等，就返回。 否则，就执行快排
//
void QuickSort(int data[], int lenght, int left, int right)
{
	if(start == end)	return ;

	int index = Partition(data, length, left, right);//核心在于选出那个index

	if(index > left)//只要左边的小于index，就执行快排
	{
		QuickSort(data, length, left, index - 1);
	}

	if(index < right)
		QuickSort(data, length, index+1, right);
}

