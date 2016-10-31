#include <stdlib.h>
#include <stdio.h>
//#include <time.h>

void priklad1();
void priklad2();
int **alokuj(int r, int s); //dat. typ = ukazatel na ukazatele (zde pole ukazatelu)
void naplnPole(int **pole, int r, int s);
void vypisPole(int **pole, int r, int s);
void dealokuj(int **pole, int r, int s);
void prohod(int **pole, int r, int s);


int main(int argc, char *argv[]){
	//priklad1();
	priklad2();

	return 0;
}

void priklad1(int n){
	int *pole = (int*)malloc(n * sizeof(int));

}

void priklad2(){
	int r = 3, s = 5;
	int **pole2D; //dvourozmerne pole

	pole2D = alokuj(r, s);
	vypisPole(pole2D, r, s);
	naplnPole(pole2D, r, s);
	vypisPole(pole2D, r, s);
	//printf("nasel? :%d", najdi(pole2D, r, s, 50));
	//dealokuj(pole2D, r, s);
	prohod(pole2D, r, s);
	system("pause");
}

int **alokuj(int r, int s){
	int **pole;
	pole = (int**)calloc(r, sizeof(int*)); //definujeme veliksot prvniho pole (ktere obsahuje ukazatele, proto alokujeme na velikost ukazatele)
										   //calloc vraci void, proto jsme pridali int** ale neni to nutny

	for (size_t i = 0; i < r; i++)
	{
		pole[i] = (int*)calloc(s, sizeof(int)); //zde uz bude konkretni hodnota int
	}

	return pole;
}

void naplnPole(int **pole, int r, int s){
	//srand(time(NULL));
	for (size_t i = 0; i < r; i++)
	{
		for (size_t j = 0; j < s; j++)
		{
			pole[i][j] = rand() % 90 + 10; //scanf("%d", &pole[i][j]) nebo //scanf("%d", (pole+i)+j)
		}
	}
}

void vypisPole(int **pole, int r, int s){
	for (size_t i = 0; i < r; i++)
	{
		for (size_t j = 0; j < s; j++)
		{
			printf("%d ", pole[i][j]);
		}
		printf("\n");
	}
}

void dealokuj(int **pole, int r, int s){ //overeni - crtdump crtmemoryleaks
	
	for (size_t i = 0; i < r; i++)
	{
			free(pole[i]);
	}

	free(pole);
}

int najdi(int **pole, int r, int s, int search){
	for (size_t i = 0; i < r; i++)
	{
		for (size_t j = 0; j < s; j++)
		{
			if (pole[i][j] == search){
				return 1;
			}
		}
	}
	return 0;
}

void prohod(int **pole, int r, int s){
	int *max, *min;

	max = &pole[0][0];
	min = &pole[0][0];

	for (size_t i = 0; i < r; i++)
	{
		for (size_t j = 0; j < s; j++)
		{
			if (pole[i][j] >*max){
				max = &pole[i][j];
			}
			if (pole[i][j] < *min){
				min = &pole[i][j];
			}
		}
	}
	
	printf("\n%d", *max);
	printf("\n%d\n", *min);
	
}