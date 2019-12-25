#include <stdio.h>
#include <stdlib.h>

typedef int Datatype;

// 三数取中法
// 三数取中法是对快排的一个优化，为了避免取到极值，进而导致快排性能变差
int GetMidIndex(int* array, int left, int right)
{
	int mid = left + (right - left) / 2;

	if (array[left] < array[mid])
	{
		if (array[mid] < array[right])
		{
			return mid;
		}
		else if (array[left] > array[right])
		{
			return left;
		}
		else
		{
			return right;
		}
	}
	else // left > mid
	{
		if (array[right] > array[left])
		{
			return left;
		}
		else if (array[mid] > array[right])
		{
			return mid;
		}
		else
		{
			return right;
		}
	}
}

void _swap(Datatype* left, Datatype* right) {
	Datatype tmp = *left;
	*left = *right;
	*right = tmp;
}


// 时间复杂度O(nlgn)
// 空间复杂度O(1)
// 快排
// [ , ) 左闭右开区间
// 挖坑
void QuickSort(Datatype* array, int left, int right)
{
	int mid = 0;
	int low = left;
	int high = right - 1;
	Datatype temp = 0;

	if (!(left < right))  // 解释一下这里 left 是有可能大于 right 的  边界细节 
	{                     // 举个例子 如果此时序列是 1 2 3                   
		return;           // 以3为基准 左边划分没有问题 重点看一下右边 
	}					  // 递归往右边走的时候 left指向3后面的元素（下标为3的元素）right 指向3（下标为2）
	// 那么此时就找不到递归出口(就会Stack overflow)  
	// 所以这里递归出口的判断条件必须是 ">="  或者写成 !(left < right)

	mid = GetMidIndex(array, left, right - 1);
	if (mid != right - 1)
	{
		_swap(&array[mid], &array[right - 1]);
	}
	temp = array[high]; // 这是挖的第一个"坑" 把原来"坑"里的值用temp保存一份 原来的数据不会丢失 覆盖了也没啥事
	while (low < high)
	{
		while (temp >= array[low] && low < high) // 这里有两个陷阱 一是 ">="   二是 low < high
		{
			low++;
		}
		if (low < high)
		{
			array[high] = array[low]; // 填"坑"  并且low这个位置又是一个新的坑
		}

		while (temp <= array[high] && low < high)
		{
			high--;
		}
		if (low < high)
		{
			array[low] = array[high]; // 再填"坑"
		}

	}
	array[low] = temp; // 最后把最后一个"坑"填上

	QuickSort(array, left, low);
	QuickSort(array, low + 1, right);
}

void Print(Datatype* array, int size);

void TestQSort()
{
	Datatype array[] = { 12, 2, 5, 37, 34, 88, 3, 77, 9, 21, 37 };
	int size = sizeof(array) / sizeof(array[0]);
	Print(array, size);
	QuickSort(array, 0, size);
	Print(array, size);

}

int main()
{
	TestQSort();
	system("pause");
	return 0;
}

void Print(Datatype* array, int size)
{
	int i = 0;
	for (i = 0; i < size; i++)
	{
		printf("%d ", array[i]);
	}
	printf("\n");
}


