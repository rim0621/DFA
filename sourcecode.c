#define	_CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<string.h>
#include<stdlib.h>


void main()
{
	FILE *fp;
	fp = fopen("input.txt", "r");
	int row = 1, colum = 1, len, n = 0;
	char str[254];
	char tmp[254];
	while (!feof(fp))
	{
		fgets(str, sizeof(str), fp);
		len = strlen(str);
		for (int j = 0; j < len; j++)
		{
			if (str[j] == 10)
			{
				row++;
			}
			if (str[j] == ' ')
			{
				colum++;
			}
			tmp[n] = str[j];
			n++;
		}
	}
	colum = colum / row + 1;

	n = 0;
	printf("int ST_TAB[ROW][COLUM]={\n");
	int **arr;
	arr = (int **)malloc(sizeof(int*)*row);
	for (int i = 0; i < row; i++)
	{
		printf("  {");
		arr[i] = (int*)malloc(sizeof(int)*colum);
		for (int j = 0; j < colum; j++) {
			if (tmp[n] == 'S')
			{
				arr[i][j] = tmp[n] - 'A' - 18;
			}
			else if (tmp[n] == 'A')
			{
				arr[i][j] = tmp[n] - 'A' + 1;
			}
			else if (tmp[n] == '_')
			{
				arr[i][j] = tmp[n] - 'A' - 31;
			}
			else
				arr[i][j] = tmp[n] - 'A';
			printf("%d ", arr[i][j]);
			n += 2;

		}
		printf("}\n");

	}
	printf("};\n");

	int ch;
	int cur_state = 0;
	ch = getchar();
	int a = 0;
	while (ch != '\n')
	{

		if (cur_state == arr[a][0])
		{
			cur_state = a;
			cur_state = arr[cur_state][ch - 'a' + 1];
			if (cur_state < 0) { printf("FAIL"); return 0; }
			ch = getchar();
			a = 0;
		}
		a++;
	}



	if (cur_state == 2 || cur_state == 3 || cur_state == 5 || cur_state == 6 || cur_state == 7) { printf("OK"); }
	else { printf("FAIL"); }

	for (int i = 0; i < colum; i++)
	{
		free(arr[i]);
	}
	free(arr);


}