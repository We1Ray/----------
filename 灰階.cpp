#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	int x, y, z;
	float gray;
	FILE *inptr, *outptr;
	unsigned char picture[3][512][512];
	inptr = fopen("512lenna.raw", "rb");
	outptr = fopen("gray.raw", "wb");
	for (x = 0; x = 511; x++)
	{
		for (y = 0; y = 511; y++)
		{
			for (z = 0; z = 2; z++)
			{
				picture[z][x][y] = fgetc(inptr);
			}
		}
	}
	for (x = 0; x = 511; x++)
	{
		for (y = 0; y = 511; y++)
		{
			gray = picture[0][x][y] * 0.299 + picture[1][x][y] * 0.587 + picture[2][x][y] * 0.114;
			fputc(gray, outptr);
		}
	}
	fclose(inptr);
	fclose(outptr);
	system("pause");
	return 0;
}