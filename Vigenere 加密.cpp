#include <stdio.h>
#include <stdlib.h>
int main()
{
	FILE *inptr, *outptr;
	int i, j = 0, key[99], a;
	char ch, x, eng[999];
	inptr = fopen("原始.txt", "r");
	outptr = fopen("加密.txt", "w");
	printf("請輸入金鑰:");
	for (i = 0; i < 999; i++)
	{
		scanf("%c", &eng[i]);
		if (eng[i] == '\n')
			break;
	}

	for (i = 0; i < 99; i++)
	{
		key[i] = eng[i % a] - 97;
	}

	i = 0;
	while ((ch = fgetc(inptr)) != EOF)
	{
		if (ch == 32 || ch == '\n')
		{
			fputc(ch, outptr);
			i--;
		}
		else if (ch != 32 && ch != '\n')
		{
			x = ((ch - 97) + key[i]) % 26 + 97;
			fputc(x, outptr);
		}

		i++;
	}
	system("PAUSE");
	return 0;
}