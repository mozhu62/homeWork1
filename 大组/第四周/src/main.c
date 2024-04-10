#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<conio.h>
#include"binary_sort_tree.h"

const char* HomePage[] = {
    "+-----------------------------------------------+\n",
    "|                  二叉树学习                   |\n",
    "+-----------------------------------------------+\n",
    "| 1. 查找                 2.插入                |\n",
    "| 3. 删除                 4.先序遍历            |\n",
    "| 5.中序遍历              6.后序遍历            |\n",
    "| 7.层序遍历              8.非递归先序遍历      |\n",
    "| 9.非递归中序遍历       10.非递归后序遍历      |\n",
    "+-----------------------------------------------+\n",
    "| 请选择(1-10):                                 |\n",
    "+-----------------------------------------------+\n"
};

void printNode(NodePtr node) 
{
    printf("%d ", node->value);
}

void flash_stdin()
{
    while (getchar() != '\n');
}

void DrawPage(const char* page[], int row)
{
    for (int i = 0; i < row; i++)
    {
        printf("%s", page[i]);
    }
}
void DrawHomePage() {
    DrawPage(HomePage, sizeof(HomePage) / sizeof(HomePage[0]));
}

int main(void)
{
    BinarySortTreePtr MAINBST = (BinarySortTreePtr)malloc(sizeof(BinarySortTree));
    BST_init(MAINBST);
    DrawHomePage();
    while (true)
    {

        if (_kbhit())
        {
            system("cls");
            DrawHomePage();
            int ch = _getch();
            switch (ch)
            {

            case '1':
                system("cls");
                DrawHomePage();
                printf("请输入查找数据:");
                int search_data = 0;
                while (!scanf("%d", &search_data))
                {
                    printf("输入不规范,请开头输入整数\n");
                    flash_stdin();
                }
                BST_search(MAINBST, search_data);
                flash_stdin();

                break;
            case '2':
                system("cls");
                DrawHomePage();
                printf("请输入插入数据:");
                int insert_value = 0;
                while (!scanf("%d", &insert_value))
                {
                    printf("输入不规范,请开头输入整数\n");
                    flash_stdin();
                }
                flash_stdin();
                if (BST_insert(MAINBST, insert_value))
                    printf("插入成功\n");
                flash_stdin();
                break;
            case '3':
                system("cls");
                DrawHomePage();
                printf("请输入要删除的数据:");
                int delete_value = 0;
                while (!scanf("%d", &delete_value))
                {
                    printf("输入不规范,请开头输入整数\n");
                    flash_stdin();
                }
                flash_stdin();
                if (BST_delete(MAINBST, delete_value))
                    printf("删除成功\n");
                flash_stdin();
                break;
            case '4':
                //BST_preorderR(MAINBST, printNode);
                break;
            case '5':
                break;
            case '6':
                break;
            case '7':
                break;
            case '8':
                BST_preorderI(MAINBST, printNode);
                break;
            case '9':
                break;
            case '10':
                break;
            }
        }
    }
    while (1);

}