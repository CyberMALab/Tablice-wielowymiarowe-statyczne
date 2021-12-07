#include <stdio.h>
#include <stdlib.h>

int main()
{
	int i,j;
	int tablica [3][3];
	
	for(i=0; i<3; i++)
	{
		for(j=0; j<3; j++)
		{
			printf("Podaj tablica[%d][%d]: ",i,j);
			scanf(" %d", &tablica[i][j]);
		}
	}
	
	for(i=0; i<3; i++)
	{
		for(j=0; j<3; j++)
		{
			printf("\ntablica[%d][%d]= %3d",i,j,tablica[i][j]);
		}
	}
	
	return 0;
}

