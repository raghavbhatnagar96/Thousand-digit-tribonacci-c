#include <stdio.h>
#include <stdlib.h>

int **matrixmult(int matrix[3][3], int matrix2[3][3])
{
	int **newmatrix;
	int i, sum, j, k;
	newmatrix = (int**)malloc(3*sizeof(int*));
	for(i=0;i<3;i++)
	{
		newmatrix[i] = (int*)malloc(3*sizeof(int));
	}
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			sum=0;
			for(k=0;k<3;k++)
			{
				sum=sum+matrix[i][k]*matrix2[k][j];
			}
			newmatrix[i][j]=sum;
		}
	}
	return newmatrix;
}			

int **matrixpow(int **matrix, int n)
{
	if(n=1)
	{
		return matrix;	
	}
	else
	{
		matrix2 = matrixpow(matrix, floor(n/2));
		if(n%2==0)
		{
			return matrixmult(matrix2, matrix2);
		}
		else
		{
			return matrixmult(matrixmult(matrix2, matrix2), matrix);
		}
	}
}

int main(int argc, char *argv[])
{
	FILE *input;
	int a, b, c, num, i=0;
	int array[18], k;//
	char tempchar;
	input = fopen("sample2.txt", "r");
	fscanf(input, "%d\n", &a);
	fscanf(input, "%d\n", &b);
	fscanf(input, "%d\n", &c);
	while(!feof(input))
	{
		fscanf(input, "%c", &tempchar);
		array[i] = tempchar - '0';
		i++;
	}
	for(i=0;i<18;i++)//
	{
		printf("%d ", array[i]);
	}
	
	return 0;
}

