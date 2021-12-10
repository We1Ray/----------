#include <stdlib.h>
#include <stdio.h>

int main()
{
	FILE *input, *output;
	int i, j = 0;
	char temp;
	input = fopen("壓縮.txt", "r");
	output = fopen("解壓縮.txt", "w");

	while (1)
	{
		if (feof(input))
			break;
		temp = fgetc(input);
		if (temp == 'r')
		{
			fscanf(input, "%d", &i);
			temp = fgetc(input);
			for (j = 0; j < i; j++)
			{
				fputc(temp, output);
			}
		}
		else if (temp == 'n')

		{
			fscanf(input, "%d", &i);
			for (j = 0; j < i; j++)
			{
				temp = fgetc(input);
				fputc(temp, output);
			}
		}
	}

	fclose(input);
	fclose(output);
	system("pause");
	return 0;
}