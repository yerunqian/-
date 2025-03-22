#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    char data[10];
    int length;
} node;

// 初始化顺序表
void initlist(node *&L) {
    L = (node*)malloc(sizeof(node));
    L->length = 0;
}

// 判断是否为空表
bool listempty(node *L)
{
    return L->length == 0;
}

// 插入元素
bool listinsert(node *&L, int n, char *a)
{
    if (n < 0 || n > L->length) {
        return false;
    }

    if (L->length + 1 > 10) {
        return false;
    }
    for (int i = L->length; i > n; i--) {
        L->data[i] = L->data[i - 1];
    }

    for (int i = 0; a[i] != '\0' && L->length < 10; i++) {
        L->data[n + i] = a[i];
        L->length++;
    }
    return true;
}
//销毁线性表
void destorylist(node *&L)
{
    free(L);
}
// 查找元素
int listsearch(node *L, char a)
{
    for (int i = 0; i < L->length; i++) {
        if (L->data[i] == a) {
            return(i);
        }
    }
    return -1;
}
//输出顺序表
void listprint(node *L)
{
    for (int i = 0; i < L->length; i++) {
        printf("%c", L->data[i]);
    }
    printf("\n");
}
//删除元素
void listdelete(node *&L, int n)
{
    if (n < 0 || n >= L->length) {
        return;
    }
    for (int i = n; i < L->length - 1; i++) {
        L->data[i] = L->data[i + 1];
    }
    L->length--;
}
//求长度
int listlength(node *L)
{
    return L->length;
}
//输出第i个元素
char listget(node *L, int n)
{
    return L->data[n];
}

//插入数据元素
bool listinsert2(node *&L, int n, char a)
{
   int j;
   if (n < 1 || n > L->length) {
       return false;
   } 
   n--;
   for (j = L->length; j > n; j--) {
       L->data[j] = L->data[j - 1];
   }
   L->data[n] = a;
   L->length++;
   return true;
}
//删除数据元素
bool  adelete(node *&L, int n)
{
    int j;
    if (n < 1 || n > L->length) {
        return false;
   
    }
    n--;
    for (j = n; j < L->length - 1; j++) {
        L->data[j] = L->data[j + 1];
   
    }
    L->length--;
    return true; 
}
int main()
{
    node *l;
    char a[] = "abcde";  
    initlist(l);
    listinsert(l, 0, a); 
    listprint(l);
   listlength(l); 
  listempty(l);
   listget(l, 3);
   listsearch(l, 'a');
    listinsert2(l, 4, 'f');
    listprint(l);
    adelete(l, 3);
    listprint(l);
    destorylist(l);
    return 0;
}
