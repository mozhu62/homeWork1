#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<conio.h>
#include"binary_sort_tree.h"

const char* HomePage[] = {
    "+-----------------------------------------------+\n",
    "|                  ������ѧϰ                   |\n",
    "+-----------------------------------------------+\n",
    "| 1. ����                 2.����                |\n",
    "| 3. ɾ��                 4.�������            |\n",
    "| 5.�������              6.�������            |\n",
    "| 7.�������              8.�ǵݹ��������      |\n",
    "| 9.�ǵݹ��������       10.�ǵݹ�������      |\n",
    "+-----------------------------------------------+\n",
    "| ��ѡ��(1-10):                                 |\n",
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
                printf("�������������:");
                int search_data = 0;
                while (!scanf("%d", &search_data))
                {
                    printf("���벻�淶,�뿪ͷ��������\n");
                    flash_stdin();
                }
                BST_search(MAINBST, search_data);
                flash_stdin();

                break;
            case '2':
                system("cls");
                DrawHomePage();
                printf("�������������:");
                int insert_value = 0;
                while (!scanf("%d", &insert_value))
                {
                    printf("���벻�淶,�뿪ͷ��������\n");
                    flash_stdin();
                }
                flash_stdin();
                if (BST_insert(MAINBST, insert_value))
                    printf("����ɹ�\n");
                flash_stdin();
                break;
            case '3':
                system("cls");
                DrawHomePage();
                printf("������Ҫɾ��������:");
                int delete_value = 0;
                while (!scanf("%d", &delete_value))
                {
                    printf("���벻�淶,�뿪ͷ��������\n");
                    flash_stdin();
                }
                flash_stdin();
                if (BST_delete(MAINBST, delete_value))
                    printf("ɾ���ɹ�\n");
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