#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *in, *in2, *out;
    unsigned char lena[512][512], pan[32][32];
    int t = 0, x, i, j, seed, temp[1024];
    in = fopen("lenna512.raw", "rb");
    in2 = fopen("panda32.raw", "rb");
    out = fopen("watermark.raw", "wb");
    for (i = 0; i < 32; i++)
    {
        for (j = 0; j < 32; j++)
        {
            pan[i][j] = fgetc(in2);
        }
    }

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

        if (pan[i / 32][i % 32] == 0)
        {

            lena[temp[i] / 512][temp[i] % 512] = lena[temp[i] / 512][temp[i] % 512] & 251;
            printf("W\t");
        }

        else if (pan[i / 32][i % 32] == 255)
        {
            printf("b\t");
            lena[temp[i] / 512][temp[i] % 512] = lena[temp[i] / 512][temp[i] % 512] | 4;
        }
    }

    for (i = 0; i < 512; i++)
    {
        for (j = 0; j < 512; j++)
        {
            fputc(lena[i][j], out);
        }
    }
    fclose(in);
    fclose(in2);
    fclose(out);
    system("pause");
    return 0;
}