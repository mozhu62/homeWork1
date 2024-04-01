#include<stdlib.h>
#include<string.h>

void exchange(int* a, int* b)//��ֵ����
{
    int c = *b;
	*b = *a;
	*a = c;
}

void insertSort(int* a, int n,int isltoh)//����
{
	int i,ptr = 0;//�����±�������ָ��
	if (isltoh)
	{
		for (i = 0; i < n-1; i++)
		{
			ptr = i + 1;
			while (ptr>0&&a[ptr - 1] > a[ptr])
			{
				exchange(&a[ptr - 1], &a[ptr]);
				ptr--;
			}
		}
	}
	else
	{
		for (i = 0; i < n - 1; i++)
		{
			ptr = i + 1;
			while (ptr > 0 && a[ptr - 1] < a[ptr])
			{
				exchange(&a[ptr - 1], &a[ptr]);
				ptr--;
			}
		}
	}
}


void MergeArray(int* a, int begin, int mid, int end, int* temp)
{

    int leftIndex, rightIndex, mergedIndex;
    int n1 = mid - begin + 1;
    int n2 = end - mid;

    // ������ʱ����
    int *LeftTemp = (int *)malloc(n1*sizeof(int)), *RightTemp = (int*)malloc(n2*sizeof(int));

    // �������ݵ���ʱ����
    for (leftIndex = 0; leftIndex < n1; leftIndex++)
        LeftTemp[leftIndex] = a[begin + leftIndex];
    for (rightIndex = 0; rightIndex < n2; rightIndex++)
        RightTemp[rightIndex] = a[mid + 1 + rightIndex];

    // �ϲ���ʱ����
    leftIndex = 0; 
    rightIndex = 0; 
    mergedIndex = begin; 
    while (leftIndex < n1 && rightIndex < n2) 
    {
        if (LeftTemp[leftIndex] < RightTemp[rightIndex]|| LeftTemp[leftIndex] == RightTemp[rightIndex])
        {
            a[mergedIndex] = LeftTemp[leftIndex];
            leftIndex++;
        }
        else 
        {
            a[mergedIndex] = RightTemp[rightIndex];
            rightIndex++;
        }
        mergedIndex++;
    }
    //����ʣ�µ�Ԫ��
    while (leftIndex < n1) 
    {
        a[mergedIndex] = LeftTemp[leftIndex];
        leftIndex++;
        mergedIndex++;
    }
    while (rightIndex < n2) 
    {
        a[mergedIndex] = RightTemp[rightIndex];
        rightIndex++;
        mergedIndex++;
    }
    //�ͷ���ʱ������Դ
    free(LeftTemp);
    free(RightTemp);
}


void MergeSort(int* a, int begin, int end, int* temp)
{
    if (begin < end)
    {
        int mid = begin + (end - begin) / 2;
        MergeSort(a, begin,mid,NULL);
        MergeSort(a, mid + 1, end, NULL);
        MergeArray(a, begin, mid, end, NULL);
    }
}


void QuickSort_Recursion(int* a, int begin, int end)
{
    if (begin < end)
    {
        //���м��ֵ��Ϊ��׼
        int pivotIndex = begin + (end - begin) / 2;
        int pivotValue = a[pivotIndex];
        exchange(&a[pivotIndex], &a[end]);//����׼ֵ�Ƶ�����ĩβ
        int i = begin - 1;

        for (int j = begin; j < end; j++)
        {
            if (a[j] < pivotValue||a[j] == pivotValue)
            {
                i++;
                exchange(&a[i], &a[j]);
            }
        }
        exchange(&a[i + 1], &a[end]);//��׼�ص���ȷ��λ��
        int pi = i + 1;

        QuickSort_Recursion(a, begin, pi - 1);
        QuickSort_Recursion(a, pi + 1, end);
    }

}


void QuickSort(int* a, int size)
{
    int *stack = (int*)malloc(size*sizeof(int));
    int top = -1;

    stack[++top] = 0;
    stack[++top] = size - 1;

    while (top >= 0) {
        int high = stack[top--];
        int low = stack[top--];

        int p = Partition(a, low, high);

        if (p - 1 > low) {
            stack[++top] = low;
            stack[++top] = p - 1;
        }

        if (p + 1 < high) {
            stack[++top] = p + 1;
            stack[++top] = high;
        }
    }
    free(stack);
}

int Partition(int* a, int begin, int end) 
{
    int pivot = a[end];
    int i = (begin - 1);

    for (int j = begin; j < end; j++) {
        if (a[j] < pivot) {
            i++;
            exchange(&a[i], &a[j]);
        }
    }
    exchange(&a[i + 1], &a[end]);
    return (i + 1);
	return 0;
}

void CountSort(int* a, int size, int max)
{
    int i;
    int range = max + 1; // ��Ϊmax����֪�ģ�ֱ������ȷ����Χ
    int* count = (int*)malloc(range * sizeof(int));
    int* output = (int*)malloc(size * sizeof(int));
    //�� = {0}һ������,��ʼ������
    memset(count, 0, range * sizeof(int));

    // ����ÿ��Ԫ�صĳ��ִ���
    for (i = 0; i < size; i++) {
        count[a[i]]++;
    }

    //���λ��
    for (i = 1; i < range; i++) {
        count[i] += count[i - 1];
    }

    // �����������
    for (i = size - 1; i >= 0; i--) {
        output[count[a[i]] - 1] = a[i];
        count[a[i]]--;
    }

    // ���ƻ�ԭ����
    for (i = 0; i < size; i++) {
        a[i] = output[i];
    }
    free(count);
    free(output);

}

void countSort(int* a, int size, int exp) //�����������õ�
{
    int* output = (int*)malloc(size*sizeof(int));
    int i, count[10] = { 0 };

    for (i = 0; i < size; i++)
        count[(a[i] / exp) % 10]++;

    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (i = size - 1; i > -1; i--) {
        output[count[(a[i] / exp) % 10] - 1] = a[i];
        count[(a[i] / exp) % 10]--;
    }
    for (i = 0; i < size; i++)
        a[i] = output[i];
    free(output);
}


void RadixCountSort(int* a, int size)
{
    int max = a[0];
    for (int i = 1; i < size; i++)
        if (a[i] > max)
            max = a[i];

    for (int exp = 1; max / exp > 0; exp *= 10)
        countSort(a, size, exp);
}

void ColorSort(int* a, int size)
{
    int p1 = 0, p2 = 0, p3 = size-1;
    while (p2 < p3||p2==p3)
    {
        if(a[p2] == 0){ 
            exchange(&a[p1], &a[p2]);
            p1++;
            p2++;
        }
        else if (a[p2] == 2){
            exchange(&a[p2], &a[p3]);
            p3--;
        }
        else{
            p2++;
        }
    }
}