#include<stdio.h>

int main(void)
{
    int n, m;
    int i, j;
    int che[1000001] = {0,};
    che[1] = 1;

    scanf("%d %d",&m,&n);

    for(i=2; i<=n; i++)
    {
        for(j=2; i*j<=n; j++)
        {
            che[i*j] = 1;
        }
    }

    for(i=m; i<=n; i++)
    {
        if(che[i] == 0)
        {
            printf("%d\n",i);
        }
    }

    return 0;
}