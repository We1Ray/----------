#include <stdlib.h>
#include <stdio.h>
int main()
{
	int i, j, k, l = 0, sum = 0, q, f, ans, s = 0, m, o = 0;
	unsigned char pic[600][600] = {};
	unsigned char op[20] = {};
	unsigned char pic2[300][20] = {};
	FILE *in, *out, *code;
	in = fopen("lenna.raw", "rb");
	code = fopen("codebook_256", "rb");
	out = fopen("index.txt", "wb");
	for (i = 0; i < 256; i++)
	{
		for (j = 0; j < 16; j++)
		{
			pic2[i][j] = fgetc(code);
		}
	}
	for (i = 0; i < 512; i++)
	{
		for (j = 0; j < 512; j++)
		{
			pic[i][j] = fgetc(in);
		}
	}
	for (i = 0; i < 509; i += 4)
	{
		for (j = 0; j < 509; j += 4)
		{
			op[0] = pic[i][j];
			op[1] = pic[i][j + 1];
			op[2] = pic[i][j + 2];
			op[3] = pic[i][j + 3];
			op[4] = pic[i + 1][j];
			op[5] = pic[i + 1][j + 1];
			op[6] = pic[i + 1][j + 2];
			op[7] = pic[i + 1][j + 3];
			op[8] = pic[i + 2][j];
			op[9] = pic[i + 2][j + 1];
			op[10] = pic[i + 2][j + 2];
			op[11] = pic[i + 2][j + 3];
			op[12] = pic[i + 3][j];
			op[13] = pic[i + 3][j + 1];
			op[14] = pic[i + 3][j + 2];
			op[15] = pic[i + 3][j + 3];
			for (q = 0; q < 16; q++)
				f += ((op[q] - pic2[0][q]) * (op[q] - pic2[0][q]));
			for (k = 0; k < 256; k++)
			{
				for (q = 0; q < 16; q++)
				{
					sum += ((op[q] - pic2[k][q]) * (op[q] - pic2[k][q]));
				}

				if (sum < f)
				{
					ans = k;
					f = sum;
				}
				sum = 0;
			}
			printf("%d ", ans);
			fprintf(out, "%d ", ans);
			o++;
		}
	}
	fclose(in);
	fclose(code);
	fclose(out);
	printf("%d", o);
	system("pause");
	return 0;
}