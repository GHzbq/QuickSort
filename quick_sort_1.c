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



// 分治思想
// [left, right] 左闭右闭区间
void QuickSort(Datatype* array, int left, int right)
{
	int mid = 0;
	int div = 0;
	Datatype key = 0;
	int begin = 0;
	int end = 0;

	// 解释一下这里 left 是有可能大于 right 的    边界细节 
	// 举个例子 如果此时序列是 1 2 3                   
	// 以3为基准 左边划分没有问题 重点看一下右边 
	// 递归往右边走的时候 left指向3后面的元素（下标为3的元素）right 指向3（下标为2）
	// 那么此时就找不到递归出口(就会Stack overflow)  
	// 所以这里递归出口的判断条件必须是 ">="  或者写成 !(left < right)
	if (left >= right)
	{
		return;
	}

	// 这是我们的一种优化  三数取中法
	// 如果每次取序列最优端的那个元素 极易取到极值
	// 我们在序列中选择了三个数
	// 拿到这三个数的中间值 如果他不是最右边的元素就把他交换到最右边
	// 以此来提高快排的性能
	mid = GetMidIndex(array, left, right);
	if (mid != right)
	{
		_swap(&array[mid], &array[right]);
	}
	key = array[right]; // 这是选的基准
	begin = left;
	end = right;

	// begin从前往后找第一个比基准值大的元素
	// end从后往前找第一个比基准值小的元素
	// 然后交换他们指向的元素 这样小数就在前面 大数就调到后面了 
	while (begin < end)
	{
		// begin 找大
		while (begin < end && array[begin] <= key)
		{
			++begin;
		}
		// end 找小
		while (begin < end && array[end] >= key)
		{
			--end;
		}
		if (begin < end)
		{
			_swap(&array[begin], &array[end]);
		}
	}

	// 当begin与end相遇的时候 begin这个位置记录的元素应该是大于基准值的
	// 将begin位置元素与序列最右边元素交换
	_swap(&array[begin], &array[right]);

	// begin记录分割边界 div之前元素都比 div之后的元素小
	div = begin;

	// 递归排序列的左半部分
	QuickSort(array, left, div - 1);
	// 递归排序列的右半部分
	QuickSort(array, div + 1, right);
}


void Print(Datatype* array, int size);

void TestQSort()
{
	Datatype array[] = { 12, 2, 5, 37, 34, 88, 3, 77, 9, 21, 37 };
	int size = sizeof(array) / sizeof(array[0]);
	Print(array, size);
	QuickSort(array, 0, size-1);
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


