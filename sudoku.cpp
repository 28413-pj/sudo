#include <iostream>
using namespace std;
#define N 9



//Sprawdza czy mozna umiescic dany numer do danego miejsca
bool dziala(int sudoku[N][N], int rzad,
	int kol, int num)
{
//sprawdzanie czy liczba moze byc w tej kolumnie
	for (int x = 0; x <= 8; x++)
		if (sudoku[x][kol] == num)
		return false;

//sprawdzanie czy liczba moze byc w tym rzedzie
	for (int x = 0; x <= 8; x++)
		if (sudoku[rzad][x] == num)
		return false;

//sprawdzanie czy liczba moze byc w tym kwadracie (3x3)
	int poczrzad = rzad - rzad % 3,
		poczkol = kol - kol % 3;

	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			if (sudoku[i + poczrzad][j +
			poczkol] == num)
			return false;
	return true;
}
// częściowo wypełnia i sprawdza czy może byc
bool wynik(int sudoku[N][N], int rzad, int kol)
{
// sprawdza czy jest 8 rzed i 9 kolumna
	if (rzad == N - 1 && kol == N)
		return true;

//sprawdza czy kolumna doszła do 9 jak tak to sprawdza kolejna
	if (kol == N) {
		rzad++;
		kol = 0;}

// Sprawdza czy już dane miejsce jest większe od zera jak tak idzie dalej
	if (sudoku[rzad][kol] > 0)
		return wynik(sudoku, rzad, kol + 1);

	for (int num = 1; num <= N; num++)
	{

// sprawdza, czy mozna dac liczbe
	if (dziala(sudoku, rzad, kol, num))
		{

//przypisuje cyfre do miejsca
	sudoku[rzad][kol] = num;

//sprawdza nastepna kolumne
	if (wynik(sudoku, rzad, kol + 1))
				return true;
		}

// jesli jest zla liczba idzie dalej
		sudoku[rzad][kol] = 0;
	}
return false;
}
int main()
{

	cout << "Sudoku to lamiglowka logiczna. Celem jest wypelnienie siatki 9×9 cyframi w taki sposob, aby kazda kolumna, kazdy wiersz i kazda z dziewieciu siatek 3x3,ktore tworza wieksza siatke 9x9, zawieraly wszystkie cyfry od 1 do 9 dokladnie raz.Kazda lamiglowka Sudoku zaczyna sie od wypelnionych niektorych komorek. Liczby te sa dobierane tak, ze istnieje unikalne rozwiazanie Sudoku." << endl;
	cout << endl;
	int sudoku[N][N] = {{ 9, 0, 0, 0, 8, 0, 3, 0, 0 },
						{ 0, 0, 0, 2, 5, 0, 7, 0, 0 },
						{ 0, 2, 0, 3, 0, 0, 0, 0, 4 },
						{ 0, 9, 4, 0, 0, 0, 0, 0, 0 },
						{ 0, 0, 0, 7, 3, 0, 5, 6, 0 },
						{ 7, 0, 5, 0, 6, 0, 4, 0, 0 },
						{ 0, 0, 7, 8, 0, 3, 9, 0, 0 },
						{ 0, 0, 1, 0, 0, 0, 0, 0, 3 },
						{ 3, 0, 0, 0, 0, 0, 0, 0, 2 } };

	if (wynik(sudoku, 0, 0))
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
				cout << sudoku[i][j] << " ";
			cout << endl;
		}
	else
		cout << "Nie ma rozwiazania " << endl;
	return 0;
}
