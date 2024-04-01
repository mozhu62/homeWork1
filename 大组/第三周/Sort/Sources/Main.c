#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<conio.h>
#include"sort.h"

#define MAX_NUM_OF_DATA 100000
char* HomePage[] = {
    "+------------------------------------------------------+\n",
    "|                   请选择你的排序算法                 |\n",
    "+------------------------------------------------------+\n",
    "|   1.插入排序                   2.归并排序            |\n",
    "|   3.快速排序递归版             4,快速排序非递归版本  |\n",
    "|   5.计数排序                   6.基数排序            |\n",
    "+------------------------------------------------------+\n",
};

void DrawPage(const char* page[], int row)
{
    for (int i = 0; i < row; i++)
    {
        printf("%s", page[i]);
    }
}

int checkMax(int arr[],int size)
{
    long long int max = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}


int main()
{
    char filename[21];
    double use_time;
    clock_t start, end;

    reinput:
    printf("请输入你的数据文件名(包括后缀,长度不超过20):");
    fgets(filename, 20, stdin);
    filename[strcspn(filename, "\n")] = 0;

    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        perror("无法打开文件,请确认你输入的文件名是正确的");
        while (getchar() != '\n');
        goto reinput;
    }
    puts("打开文件成功");

    int* numbers =(int*)malloc(MAX_NUM_OF_DATA*sizeof(int));
    int n = 0;
    while (fscanf(file, "%d", &numbers[n]) == 1) {
        n++;
    }
    fclose(file);

    DrawPage(HomePage, sizeof(HomePage) / sizeof(HomePage[0]));



    while (1)
    {
        realstart:
        if (_kbhit())
        {
            system("cls");
            DrawPage(HomePage, sizeof(HomePage) / sizeof(HomePage[0]));
            int InputChoose = _getch();
            switch (InputChoose)
            {
            case '1':
                start = clock();
                insertSort(numbers,n,1);
                end = clock();
                use_time = ((double)(end - start)) / CLOCKS_PER_SEC;
                for (int i = 0; i < n; i++) {
                    printf("%-8d  ", numbers[i]);
                    if (i % 8 == 7)
                        printf("\n");
                }
                printf("\n排序用时:%lf", use_time);
                while (getchar() == '\n');
                goto realstart;
            case '2':
                start = clock();
                MergeSort(numbers, 0, n-1, NULL);
                end = clock();
                use_time = ((double)(end - start)) / CLOCKS_PER_SEC;
                for (int i = 0; i < n; i++) {
                    printf("%-8d  ", numbers[i]);
                    if (i % 8 == 7)
                        printf("\n");
                }
                printf("\n排序用时:%lf", use_time);
                while (getchar() == '\n');
                goto realstart;
            case '3':
                start = clock();
                QuickSort_Recursion(numbers, 0, n-1);
                end = clock();
                use_time = ((double)(end - start)) / CLOCKS_PER_SEC;
                for (int i = 0; i < n; i++) {
                    printf("%-8d  ", numbers[i]);
                    if (i % 8 == 7)
                        printf("\n");
                }
                printf("\n排序用时:%lf", use_time);
                while (getchar() == '\n');
                goto realstart;
            case '4':
                start = clock();
                QuickSort(numbers, n);
                end = clock();
                use_time = ((double)(end - start)) / CLOCKS_PER_SEC;
                for (int i = 0; i < n; i++) {
                    printf("%-8d  ", numbers[i]);
                    if (i % 8 == 7)
                        printf("\n");
                }
                printf("\n排序用时:%lf", use_time);
                while (getchar() == '\n');
                goto realstart;
            case '5':
                start = clock();
                CountSort(numbers, n, checkMax(numbers,n));
                end = clock();
                use_time = ((double)(end - start)) / CLOCKS_PER_SEC;
                for (int i = 0; i < n; i++) {
                    printf("%-8d  ", numbers[i]);
                    if (i % 8 == 7)
                        printf("\n");
                }
                printf("\n排序用时:%lf", use_time);
                while (getchar() == '\n');
                goto realstart;
            case '6':
                start = clock();
                RadixCountSort(numbers, n);
                end = clock();
                use_time = ((double)(end - start)) / CLOCKS_PER_SEC;
                for (int i = 0; i < n; i++) {
                    printf("%-8d  ", numbers[i]);
                    if (i % 8 == 7)
                        printf("\n");
                }
                printf("\n排序用时:%lf", use_time);
                while (getchar() == '\n');
                goto realstart;
            }
        }
    }
    while (1);
    return 0;

}