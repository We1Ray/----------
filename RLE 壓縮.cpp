#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *inptr, *outptr;
    int i, j, flag = 1, sum = 0, sum2 = 1, sum3 = 0;
    char ch, in[99];

    inptr = fopen("test.txt", "r");
    outptr = fopen("壓縮.txt", "w");
    i = 0;
    while ((in[i] = fgetc(inptr)) != EOF)
    {

        i++;
        sum++;
    }
    for (i = 1; i < sum; i++)
    {
        if ((i == (sum - 1)) && (in[i] == in[i - 1]))
        {
            sum2++;
            if (sum3 > 0)
            {

                fprintf(outptr, "n%d", sum3);
                for (j = i - sum3 - 1; j < i - 1; j++)
                {
                    fprintf(outptr, "%c", in[j]);
                }

                fprintf(outptr, "r%d%c", sum2, in[i - 1]);
            }
            else if (sum3 == 0)
            {
                fprintf(outptr, "r%d%c", sum2, in[i - 1]);
            }
        }
        else if ((i == (sum - 1)) && (in[i] != in[i - 1]))
        {

            if (sum2 > 1)
            {
                fprintf(outptr, "r%d%c", sum2, in[i - 1]);
                fprintf(outptr, "n%d", sum3 + 1);
                for (j = i - sum3; j <= i; j++)
                {
                    fprintf(outptr, "%c", in[j]);
                }
            }
            else if (sum2 == 1)
            {
                fprintf(outptr, "n%d", sum3 + 2);
                for (j = i - sum3 - 1; j <= i; j++)
                    fprintf(outptr, "%c", in[j]);
            }
        }
        else if (in[i] == in[i - 1])
        {
            if (sum3 > 0)
            {
                fprintf(outptr, "n%d", sum3);
                for (j = i - sum3 - 1; j < i - 1; j++)
                {
                    fprintf(outptr, "%c", in[j]);
                }
                sum3 = 0;
            }
            if (sum3 == 0)
            {
                sum2++;
            }
        }
        else if (in[i] != in[i - 1])
        {
            if (sum2 > 1)
            {
                fprintf(outptr, "r%d%c", sum2, in[i - 1]);
                sum2 = 1;
            }
            else if (sum2 == 1)
            {
                sum3++;
            }
        }
    }

    fclose(inptr);
    fclose(outptr);
    system("pause");
    return 0;
}