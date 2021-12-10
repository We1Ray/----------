#include <stdio.h>
#include <stdlib.h>
int main()
{
	FILE *in, *out;
	unsigned char pic[512][512], p2[512][512];
	in = fopen("darklena.raw", "rb");
	out = fopen("均化.raw", "wb");
	int a[256], p[256] = {0}, min, i, j, x, cd[256], cr[256];

	for (i = 0; i < 256; i++)
	{
		a[i] = i;
	}
	for (i = 0; i < 512; i++)
	{
		for (j = 0; j < 512; j++)
		{
			pic[i][j] = fgetc(in);
		}
	}
	for (i = 0; i < 512; i++)
	{
		for (j = 0; j < 512; j++)
		{
			for (x = 0; x < 256; x++)
			{
				if (pic[i][j] = a[x])
				{
					p[x]++;
				}
			}
		}
	} //計算出現數值
	for (i = 0; i < 256; i++)
	{
		if (p[i] != 0)
		{
			min = i + 1;
			break;
		}
	} //第一個出現的數
	for (i = 0; i < 256; i++)
	{
		if (i > 1)
		{
			cd[i] = cd[i - 1] + p[i];
		}
		else
		{
			cd[i] = p[i];
		}
	} //累加算出cdf值
	for (i = 0; i < 256; i++)
	{
		cr[i] = ((cd[i] - min) * 1.0 * 255) / (512 * 512 - min);
	}
	for (i = 0; i < 512; i++)
	{
		for (j = 0; j < 512; j++)
		{
			for (x = 0; x < 256; x++)
			{
				if (pic[i][j] == a[x])
				{
					putc(cr[x], out);
				}
			}
		}
	}
	fclose(in);
	fclose(out);
	system("PAUSE");
	return 0;
}