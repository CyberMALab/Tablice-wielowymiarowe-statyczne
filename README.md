# Tablice wielowymiarowe – statyczne.
Tablica wielowymiarowa, podobnie jak tablica jednowymiarowa jest strukturą danych, przechowującą dane, tego samego typu. Inaczej można ją też nazwać zbiorem indeksowanych zmiennych o więcej niż jednym indeksie. Wymiar tablicy można łatwo porównać z wymiarem znanym z matematyki. Spójrzmy na poniższy schemat (10.0). Konfrontuje on wymiary układu współrzędnych z tablicami, różnych wymiarów. Wymiary tablic nie kończą się na 3. Nie ma określonego maksimum, jednak człowiekowi ciężko jest wyobrazić sobie reprezentację figury więcej niż trójwymiarowej.

*Schemat (10.0) wymiary tablic*

![Schemat 10 0](https://user-images.githubusercontent.com/71324202/144988115-c869f552-c3a1-41e3-8d8d-19ccd5fa6226.png)

## **Deklaracja i obsługa tablicy wielowymiarowej**
Deklaracja tablic wielowymiarowych jest analogiczna do deklaracji jednowymiarowej tablicy, z tą różnicą, że ilość nawiasów kwadratowych musi być tożsama z wymiarem tablicy.

*Przykład (10.0) deklaracja tablic wielowymiarowych*

`int a[5][5]; /* tablica dwuwymiarowa 5x5 */`

`int b[2][4][2]; /* tablica trójwymiarowa 2x4x2 */`


Aby dostać się do poszczególnego elementu tablicy wielowymiarowej, należy podać wartości wszystkich jej współrzędnych. Załóżmy, że mamy tablicę dwuwymiarową 4x5 którą reprezentuje poniższa tabela. Wartości podane w tabeli to pojedyncze elementy tablicy wraz z jej indeksami (pamiętając, że indeksowane są one od 0).

`int a[4][5]; `

||||||
| :-: | :-: | :-: | :-: | :-: |
|`a[0][0];`|`a[0][1];`|`a[0][2];`|`a[0][3];`|`a[0][4];`|
|`a[1][0];`|`a[1][1];`|`a[1][2];`|`a[1][3];`|`a[1][4];`|
|`a[2][0];`|`a[2][1];`|`a[2][2];`|`a[2][3];`|`a[2][4];`|
|`a[3][0];`|`a[3][1];`|`a[3][2];`|`a[3][3];`|`a[3][4];`|

W praktyce w pamięci, tablica taka definiowana jest tak samo jak tablica jednowymiarowa, pamięć bowiem jest właśnie jednowymiarowa. W pamięci zatem tablica taka będzie ułożona w następujący sposób.

|||||||||
| :-: | :-: | :-: | :-: | :-: | :-: | :-: | :-: | 
|`a[0][0];`|`a[0][1];`|`a[0][2];`|`a[0][3];`|`a[0][4];`|...|`a[3][3];`|`a[3][4];`|


Zauważmy więc, że program poprzez zapis `a[0][5];` dostanie się do elementu tablicy o indeksie `a[1][0];`. Jednak odwoływanie się do elementów tablicy w ten sposób jest niezalecane- działa, ale prowadzi do bałaganu w kodzie oraz ciężkich do wykrycia błędów (bo program najpewniej skompiluje się, ale wystąpi błąd dostępu do pamięci znany jako *segfault*), kiedy programista straci nad tym kontrolę. Więc zalecane jest użycie maksymalnie takiego indeksu jaki jest legalnym rozmiarem tablicy.

*Przykład (10.1) wczytywanie i wypisywanie elementów tablicy wielowymiarowej*

```
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

```


*Wynik działania programu:*

>Podaj tablica[0][0]: 1
>
>Podaj tablica[0][1]: 2
>
>Podaj tablica[0][2]: 3
>
>Podaj tablica[1][0]: 4
>
>Podaj tablica[1][1]: 5
>
>Podaj tablica[1][2]: 6
>
>Podaj tablica[2][0]: 7
>
>Podaj tablica[2][1]: 8
>
>Podaj tablica[2][2]: 9
>
>tablica[0][0]=   1
>
>tablica[0][1]=   2
>
>tablica[0][2]=   3
>
>tablica[1][0]=   4
>
>tablica[1][1]=   5
>
>tablica[1][2]=   6
>
>tablica[2][0]=   7
>
>tablica[2][1]=   8
>
>tablica[2][2]=   9

## **Tworzenie własnych funkcji obsługujących tablice wielowymiarowe.**
Podrozdział ten podchodzi do działania tablicami w funkcji tylko względem praktyki. Wyjaśnienie zjawiska jest zawarte w rozdziale 14 dla którego istotnym jest zrozumienie wskaźników (rozdział 12) oraz dynamicznego tworzenia tablic (rozdział 13).  

Tworzenie funkcji, obsługujących tablice wielowymiarowe jest analogiczne do tworzenia funkcji obsługujących tablice jednowymiarowe. Jednak deklaracja parametru jako tablicy jest już różna. Należy bowiem podać wszystkie wymiary tablicy z wyjątkiem pierwszego. Prezentuje to poniższy przykład (10.2).

*Przykład (10.2) własne funkcje a tablice wielowymiarowe*

```
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


```

*Wynik działania programu (taki sam jak 10.1)*

>Podaj tablica[0][0]: 1
>
>Podaj tablica[0][1]: 2
>
>Podaj tablica[0][2]: 3
>
>Podaj tablica[1][0]: 4
>
>Podaj tablica[1][1]: 5
>
>Podaj tablica[1][2]: 6
>
>Podaj tablica[2][0]: 7
>
>Podaj tablica[2][1]: 8
>
>Podaj tablica[2][2]: 9
>
>tablica[0][0]=   1
>
>tablica[0][1]=   2
>
>tablica[0][2]=   3
>
>tablica[1][0]=   4
>
>tablica[1][1]=   5
>
>tablica[1][2]=   6
>
>tablica[2][0]=   7
>
>tablica[2][1]=   8
>
>tablica[2][2]=   9



***
[Poprzednia część](https://github.com/CyberMALab/Tablice-znakow.git) | [Spis treści](https://github.com/CyberMALab/Wprowadzenie-do-programowania-w-j-zyku-ANSI-C.git) | [Następna część](https://github.com/CyberMALab/Comming-Soon.git)
***
&copy; Cyberspace Modelling and Analysis Laboratory
