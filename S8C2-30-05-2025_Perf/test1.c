//test_gprof.c
#include<stdio.h>

void new_func1(void);
void func1(void);
static void func2(void);
void new_func1(void);

int main(void)
{
    printf("\n Inside main()\n");
    int i = 0;

    for(;i<0xffffff;i++);
    func1();
    func2();

    return 0;
}
void new_func1(void);

void func1(void)
{
    printf("\n Inside func1 \n");
    int i = 0;

    for(;i<0xffffffff;i++);
    new_func1();

    return;
}

static void func2(void)
{
    printf("\n Inside func2 \n");
    int i = 0;

    for(;i<0xffffffaa;i++);
    return;
}   

void new_func1(void)
{
    printf("\n Inside new_func1()\n");
    int i = 0;
    
    for(;i<0xffffffee;i++);
    
    return;
}