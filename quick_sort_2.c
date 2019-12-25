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


// ʱ�临�Ӷ�O(nlgn)
// �ռ临�Ӷ�O(1)
// ����
// [ , ) ����ҿ�����
// �ڿ�
void QuickSort(Datatype* array, int left, int right)
{
	int mid = 0;
	int low = left;
	int high = right - 1;
	Datatype temp = 0;

	if (!(left < right))  // ����һ������ left ���п��ܴ��� right ��  �߽�ϸ�� 
	{                     // �ٸ����� �����ʱ������ 1 2 3                   
		return;           // ��3Ϊ��׼ ��߻���û������ �ص㿴һ���ұ� 
	}					  // �ݹ����ұ��ߵ�ʱ�� leftָ��3�����Ԫ�أ��±�Ϊ3��Ԫ�أ�right ָ��3���±�Ϊ2��
	// ��ô��ʱ���Ҳ����ݹ����(�ͻ�Stack overflow)  
	// ��������ݹ���ڵ��ж����������� ">="  ����д�� !(left < right)

	mid = GetMidIndex(array, left, right - 1);
	if (mid != right - 1)
	{
		_swap(&array[mid], &array[right - 1]);
	}
	temp = array[high]; // �����ڵĵ�һ��"��" ��ԭ��"��"���ֵ��temp����һ�� ԭ�������ݲ��ᶪʧ ������Ҳûɶ��
	while (low < high)
	{
		while (temp >= array[low] && low < high) // �������������� һ�� ">="   ���� low < high
		{
			low++;
		}
		if (low < high)
		{
			array[high] = array[low]; // ��"��"  ����low���λ������һ���µĿ�
		}

		while (temp <= array[high] && low < high)
		{
			high--;
		}
		if (low < high)
		{
			array[low] = array[high]; // ����"��"
		}

	}
	array[low] = temp; // �������һ��"��"����

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


