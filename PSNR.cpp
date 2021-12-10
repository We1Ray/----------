#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
	float mse, psnr, sum = 0;
	int i, j;
	FILE *inptr, *inptr2;
	unsigned char pic[512][512], pic2[512][512];
	inptr = fopen("gray.raw", "rb");
	inptr2 = fopen("Lena.raw", "rb");
	for (i = 0; i <= 511; i++)
	{
		for (j = 0; j <= 511; j++)
		{
			pic[i][j] = fgetc(inptr);
			pic2[i][j] = fgetc(inptr2);
		}
	}
	for (i = 0; i <= 511; i++)
	{
		for (j = 0; j <= 511; j++)
		{
			sum += (pic[i][j] - pic2[i][j]) * (pic[i][j] - pic2[i][j]);
		}
	}
	mse = sum / (512.0 * 512.0);
	printf("%f\n", mse);
	psnr = 10 * log10(255 * 255 / mse);
	printf("%f", psnr);
	fclose(inptr);
	fclose(inptr2);

	system("pause");
	return 0;
}