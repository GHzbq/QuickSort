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



// ����˼��
// [left, right] ����ұ�����
void QuickSort(Datatype* array, int left, int right)
{
	int mid = 0;
	int div = 0;
	Datatype key = 0;
	int begin = 0;
	int end = 0;

	// ����һ������ left ���п��ܴ��� right ��    �߽�ϸ�� 
	// �ٸ����� �����ʱ������ 1 2 3                   
	// ��3Ϊ��׼ ��߻���û������ �ص㿴һ���ұ� 
	// �ݹ����ұ��ߵ�ʱ�� leftָ��3�����Ԫ�أ��±�Ϊ3��Ԫ�أ�right ָ��3���±�Ϊ2��
	// ��ô��ʱ���Ҳ����ݹ����(�ͻ�Stack overflow)  
	// ��������ݹ���ڵ��ж����������� ">="  ����д�� !(left < right)
	if (left >= right)
	{
		return;
	}

	// �������ǵ�һ���Ż�  ����ȡ�з�
	// ���ÿ��ȡ�������Ŷ˵��Ǹ�Ԫ�� ����ȡ����ֵ
	// ������������ѡ����������
	// �õ������������м�ֵ ������������ұߵ�Ԫ�ؾͰ������������ұ�
	// �Դ�����߿��ŵ�����
	mid = GetMidIndex(array, left, right);
	if (mid != right)
	{
		_swap(&array[mid], &array[right]);
	}
	key = array[right]; // ����ѡ�Ļ�׼
	begin = left;
	end = right;

	// begin��ǰ�����ҵ�һ���Ȼ�׼ֵ���Ԫ��
	// end�Ӻ���ǰ�ҵ�һ���Ȼ�׼ֵС��Ԫ��
	// Ȼ�󽻻�����ָ���Ԫ�� ����С������ǰ�� �����͵��������� 
	while (begin < end)
	{
		// begin �Ҵ�
		while (begin < end && array[begin] <= key)
		{
			++begin;
		}
		// end ��С
		while (begin < end && array[end] >= key)
		{
			--end;
		}
		if (begin < end)
		{
			_swap(&array[begin], &array[end]);
		}
	}

	// ��begin��end������ʱ�� begin���λ�ü�¼��Ԫ��Ӧ���Ǵ��ڻ�׼ֵ��
	// ��beginλ��Ԫ�����������ұ�Ԫ�ؽ���
	_swap(&array[begin], &array[right]);

	// begin��¼�ָ�߽� div֮ǰԪ�ض��� div֮���Ԫ��С
	div = begin;

	// �ݹ������е���벿��
	QuickSort(array, left, div - 1);
	// �ݹ������е��Ұ벿��
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


