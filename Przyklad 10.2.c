#include <stdio.h>
#include <stdlib.h>

/* Należy zauważyć że deklaracja tablicy zawiera od razu rozmiar o jako zmienna parametru size_y */
void print_arr_2Dim(unsigned size_x, unsigned size_y, int array[][size_y]);
void scanf_arr_2Dim(unsigned size_x, unsigned size_y, int array[][size_y]);
int main()
{
	int tablica [3][3];
	scanf_arr_2Dim(3,3,tablica);
	print_arr_2Dim(3,3,tablica);	
	return 0;
}

void print_arr_2Dim(unsigned size_x, unsigned size_y, int array[][size_y])
{
	unsigned i,j;
		for(i=0; i<size_x; i++)
		{
			for(j=0; j<size_y; j++)
			{
			printf("\ntablica[%d][%d]= %3d",i,j,array[i][j]);
			}
		}	
}
void scanf_arr_2Dim(unsigned size_x, unsigned size_y, int array[][size_y])
{
	unsigned i,j;
	for(i=0; i<size_x; i++)
	{
		for(j=0; j<size_y; j++)
		{
			printf("Podaj tablica[%d][%d]: ",i,j);
			scanf(" %d", &array[i][j]);
		}
	}
}


