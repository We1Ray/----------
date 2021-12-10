#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
	int gx, gy, gxy, gyx, ee, x, y, i, j;
	float sob;
	FILE *inptr, *outptr;
	unsigned char pic[512][512], n[512][512];
	inptr = fopen("gray.raw", "rb");
	outptr = fopen("sob.raw", "wb");
	for (x = 0; x <= 511; x++)
	{
		for (y = 0; y <= 511; y++)
		{
			pic[x][y] = fgetc(inptr);
		}
	}
	for (x = 1; x <= 510; x++)
	{
		for (y = 1; y <= 510; y++)
		{
			gx = pic[x - 1][y - 1] * -1 + pic[x - 1][y] * 0 + pic[x - 1][y + 1] * 1 + pic[x][y - 1] * -2 + pic[x][y] * 0 + pic[x][y + 1] * 2 + pic[x + 1][y - 1] * -1 + pic[x + 1][y] * 0 + pic[x + 1][y + 1] * 1;
			gy = pic[x - 1][y - 1] * -1 + pic[x - 1][y] * -2 + pic[x - 1][y + 1] * -1 + pic[x][y - 1] * 0 + pic[x][y] * 0 + pic[x][y + 1] * 0 + pic[x + 1][y - 1] * 1 + pic[x + 1][y] * 2 + pic[x + 1][y + 1] * 1;
			gxy = pic[x - 1][y - 1] * -2 + pic[x - 1][y] * -1 + pic[x - 1][y + 1] * 0 + pic[x][y - 1] * -1 + pic[x][y] * 0 + pic[x][y + 1] * 1 + pic[x + 1][y - 1] * 0 + pic[x + 1][y] * 1 + pic[x + 1][y + 1] * 2;
			gyx = pic[x - 1][y - 1] * 0 + pic[x - 1][y] * 1 + pic[x - 1][y + 1] * 2 + pic[x][y - 1] * -1 + pic[x][y] * 0 + pic[x][y + 1] * 1 + pic[x + 1][y - 1] * -2 + pic[x + 1][y] * -1 + pic[x + 1][y + 1] * 0;
			ee = (abs(gx) + abs(gy) + abs(gxy) + abs(gyx)) / 4;
			if (ee <= 27)
			{
				n[x][y] = 0;
			}
			else
			{
				n[x][y] = 255;
			}
		}
	}
	for (x = 0; x <= 511; x++)
	{
		n[0][x] = 255;
		n[x][0] = 255;
	}
	for (y = 0; y <= 511; y++)
	{
		n[511][y] = 255;
		n[y][511] = 255;
	}
	for (x = 0; x <= 511; x++)
	{
		for (y = 0; y <= 511; y++)
		{
			fputc(n[x][y], outptr);
		}
	}
	fclose(inptr);
	fclose(outptr);
	system("pause");
	return 0;
}