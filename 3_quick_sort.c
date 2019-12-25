#include <stdio.h>
#include <stdlib.h>

typedef int Datatype;

// ����ȡ�з�
// ����ȡ�з��ǶԿ��ŵ�һ���Ż���Ϊ�˱���ȡ����ֵ���������¿������ܱ��
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


// ǰ��ָ��
// [ , ]
void QuickSort(Datatype* array, int left, int right)
{
	int Pre = 0;
	int Cur = 0;
	Datatype key = 0;
	int mid = 0;
	int div = 0;

	if (!(left < right))
	{
		return;
	}

	Pre = left - 1;
	Cur = left;
	key = array[right];

	mid = GetMidIndex(array, left, right);
	if (mid != right)
	{
		_swap(&array[mid], &array[right]);
	}

	while (Cur < right)
	{
		if (array[Cur] < key && ++Pre != Cur)
		{
			_swap(&array[Pre], &array[Cur]);
		}

		++Cur;
	}

	_swap(&array[++Pre], &array[right]);
	div = Pre;

	QuickSort(array, left, div - 1);
	QuickSort(array, div + 1, right);
}

void Print(Datatype* array, int size);

void TestQSort()
{
	Datatype array[] = { 12, 2, 5, 37, 34, 88, 3, 77, 9, 21, 37 };
	int size = sizeof(array) / sizeof(array[0]);
	Print(array, size);
	QuickSort(array, 0, size - 1);
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


