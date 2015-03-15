#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int **matrixmult(int **matrix, int **matrix2)//multiply 2 matrix
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
			newmatrix[i][j]=sum%1000;
		}
	}
	return newmatrix;
}			

void divideby2(int *number, int remainder, int index, int size)//divide the 1000 digit number by 2
{
	if(index==size)
	{
		return;
	}
	int temp;
	temp=remainder*10+number[index];
	number[index]=temp/2;
	remainder=temp%2;
	divideby2(number, remainder, index+1, size);
}

int zero(int *number, int size)//is the 1000 digit number now 0
{
	int i, sum=0;
	for(i=0;i<size;i++)
	{
		sum=sum+number[i];
	}
	if(sum!=0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int Odd(int * number, int size)
{
	return (number[size-1]%2);
}

int **matrixpow(int **matrix, int *number, int size)//power of a matrix by number
{
	int **matrix2;
	int i;
	matrix2 = (int**)malloc(3*sizeof(int*));//declare new array
	for(i=0;i<3;i++)
	{
		matrix2[i] = calloc(3, sizeof(int));
	}
	//matrix2=matrix;
	matrix2[0][0]=1;
	matrix2[1][1]=1;
	matrix2[2][2]=1;
	while(zero(number, size))
	{
		if(Odd(number, size)==1)
		{
			matrix2 = matrixmult(matrix2, matrix);
		}
		matrix=matrixmult(matrix, matrix);
		
		divideby2(number, 0, 0, size);
	}
	return matrix2;
}
	
int main(int argc, char **argv)
{
	FILE *input;
	int i, k, a, b, c, w=0, size;
	char tempchar;
	int **array;
	array = (int**)malloc(3*sizeof(int*));
	int *number;
	number = (int*)malloc(1000*sizeof(int));
	int **final;//
	input = fopen(argv[1], "r");
	fscanf(input, "%d\n", &a);//start file reading f(0)=a;f(1)=b;f(2)=c
	fscanf(input, "%d\n", &b);
	fscanf(input, "%d\n", &c);
	while(!feof(input))
	{
		fscanf(input, "%c", &tempchar);
		number[w] = tempchar - '0';
		w++;
	}//end of file reading
	size = w-2;
	for(i=0;i<3;i++)//start of array
	{
		array[i] = calloc(sizeof(int), 3);
	}
	array[0][0]=1;
	array[0][1]=1;
	array[0][2]=1;
	array[1][0]=1;
	array[2][1]=1;//end array
	
	final = (int**)malloc(3*sizeof(int*));
	for(i=0;i<3;i++)
	{
		final[i] = (int*)malloc(3*sizeof(int));
	}
	final = matrixpow(array, number, size);
	a = a*final[2][2];
	b = b*final[2][1];
	c = c*final[2][0];
	printf("%d", (a+b+c)%1000);
	return 0;
}


