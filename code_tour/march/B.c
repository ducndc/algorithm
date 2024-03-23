#include <stdio.h>

int main()
{
    int t;
    int i = 0;
    int j = 0;

    scanf("%d", &t);
    int n[t];
    int k[t];
    int mul[t];
    int result;
    int bi;

    for (i = 0; i < t; ++i)
    {
        scanf("%d %d", &n[i], &k[i]);
        mul[i] = 1;
        for (j = 0; j < n[i]; ++j)
        {
            scanf("%d", &bi);
            mul[i] *= bi;
        }
    }

    for (i = 0; i < t; ++i)
    {
        if ((2023 % mul[i]) != 0) 
        {
            printf("NO\n");
        }
        else 
        {
            printf("YES\n");
            result = 2023 / mul[i];
            if (1 == k[i]) 
            {
                printf("%d\n", result);
            }
            else 
            {
                for (j = 0; j < k[i]; ++j)
                {
                    if ((result % 2023) == 0) 
                    {
                        printf("2023 ");
                        result /= 2023;
                    }
                    else if ((result % 289) == 0)
                    {
                        printf("289 ");
                        result /= 289;
                    }
                    else if ((result % 119) == 0)
                    {
                        printf("119 ");
                        result /= 119;
                    }
                    else if ((result % 17) == 0)
                    {
                        printf("17 ");
                        result /= 17;
                    }
                    else if ((result % 7) == 0)
                    {
                        printf("7 ");
                        result /= 7;
                    }
                    else if ((result / 7) == 0)
                    {
                        printf("1 ");
                    }
                }
                printf("\n");
            }
        }
    }

    return 0;
}
