#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *in, *in2, *out;
    unsigned char lena[512][512], pan[32][32];
    int t = 0, x, i, j, seed, temp[1024];
    in = fopen("watermark.raw", "rb");
    out = fopen("pan.raw", "wb");

    for (i = 0; i < 512; i++)
    {
        for (j = 0; j < 512; j++)
        {
            lena[i][j] = fgetc(in);
        }
    }

    printf("請輸入金鑰:");
    scanf("%d", &seed);

    srand(seed);

    for (i = 0; i < 1024; i++)
    {
        temp[i] = rand() % (512 * 512);
        for (j = 0; j < i; j++)
        {
            if (temp[i] == temp[j])
            {
                i--;
                break;
            }
        }
    }

    for (i = 0; i < 1024; i++)
    {

        x = lena[temp[i] / 512][temp[i] % 512];

        if ((x | 4) == x)
        {

            fputc(255, out);
            printf("w\t");
        }

        else if ((x | 4) == x + 4)
        {

            fputc(0, out);
            printf("b\t", x);
        }
    }

    fclose(in);
    fclose(out);
    system("pause");
    return 0;
}