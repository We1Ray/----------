#include <stdlib.h>
#include <stdio.h>
int main()
{
	FILE *in, *out, *code;
	int i, j, x;
	unsigned char pic[512][512];
	unsigned char codebook[256][16];

	code = fopen("codebook_256", "rb");
	in = fopen("index.txt", "r");
	out = fopen("lenna2.raw", "wb");
	for (i = 0; i < 256; i++)
	{
		for (j = 0; j < 16; j++)
		{
			codebook[i][j] = fgetc(code);
		}
	}
	for (i = 0; i < 509; i += 4)
	{
		for (j = 0; j < 509; j += 4)
		{
			fscanf(in, "%d", &x);
			pic[i][j] = codebook[x][0];
			pic[i][j + 1] = codebook[x][1];
			pic[i][j + 2] = codebook[x][2];
			pic[i][j + 3] = codebook[x][3];
			pic[i + 1][j] = codebook[x][4];
			pic[i + 1][j + 1] = codebook[x][5];
			pic[i + 1][j + 2] = codebook[x][6];
			pic[i + 1][j + 3] = codebook[x][7];
			pic[i + 2][j] = codebook[x][8];
			pic[i + 2][j + 1] = codebook[x][9];
			pic[i + 2][j + 2] = codebook[x][10];
			pic[i + 2][j + 3] = codebook[x][11];
			pic[i + 3][j] = codebook[x][12];
			pic[i + 3][j + 1] = codebook[x][13];
			pic[i + 3][j + 2] = codebook[x][14];
			pic[i + 3][j + 3] = codebook[x][15];
		}
	}
	for (i = 0; i < 512; i++)
	{
		for (j = 0; j < 512; j++)
		{
			fwrite(&pic[i][j], 1, 1, out);
		}
	}
	fclose(in);
	fclose(code);
	fclose(out);
	system("pause");
	return 0;
}