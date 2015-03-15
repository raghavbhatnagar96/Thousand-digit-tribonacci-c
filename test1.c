#include <stdio.h>

int threefib(int a, int b, int c, int num)
{
	int i;
	int q=a, w=b, e=c, t;
	if(num==0)
	{
		return a;
	}
	else if(num == 1)
	{
		return b;
	}
	else if(num == 2)
	{
		return c;
	}
	else
	{
		for(i=3;i<num;i++)
		{
			 t = (q+w+e)%1000;
			 q = w;
			 w = e;
			 e = t;
		}
	}
	return 0;
}

int main(int argc, char *argv[])
{
	FILE *input;
	int a, b, c, num, i=0;
	int number[18], k;//
	char tempchar;
	input = fopen("sample2.txt", "r");
	fscanf(input, "%d\n", &a);
	fscanf(input, "%d\n", &b);
	fscanf(input, "%d\n", &c);
	while(!feof(input))
	{
		fscanf(input, "%c", &tempchar);
		number[i] = tempchar - '0';
		i++;
	}
	for(i=0;i<18;i++)//
	{
		printf("%d ", array[i]);
	}	
	return 0;
}

