#include "nagl.h"
int main ()
{ 
	system("cls");
	naglowek();	
	wsk=0;
	odczyt();
	wyswietlanie(w1, k1, m1);
	wyswietlanie(w2, k2, m2); 

    while(1)
	{
		cout <<"\n Wybierz odpowiedni\245 opcj\251:\n";
		cout <<" 1. Dodawanie macierzy.\n";
		cout <<" 2. Odejmowanie macierzy.\n";
		cout <<" 3. Mno\276enie macierzy.\n";
		cout <<" 4. Obliczenie wyznacznika i odwracanie macierzy M1.\n";
		cout <<" 5. Ortogonalno\230\206 macierzy M1.\n";
		cout <<" 6. Transponowanie macierzy M1.\n";
		cout <<" 0. Wyj\230cie.\n";

		switch(getch())
		{
	
			// DODAWANIE
			case '1':
			{
				system("cls");
				naglowek();
				odczyt();
				wyswietlanie(w1, k1, m1);
				wyswietlanie(w2, k2, m2);			
				 // sprawdzamy czy mozna dodac do siebie macierze
				if ((w1==w2)&&(k1==k2))
				{
					// wywolanie funkcji dodajacej macierze
					doda(w1,k1,m1,m2);
					// wyswietlanie wyniku dodawania tych macierzy
					for (h=0;h<w1;h++)
					{
						printf("\n");
						for (g=0;g<k1;g++)
						{
							printf(" %3.2f ",y[h][g]);
						}
					}
				}
				else cout <<"\n\n Nie da sie dodac macierzy ze wzgledu na rozmiary\n";		
	
				cout <<"\n\n";
				t="Wynik dodawania macierzy m1 i m2:";
				zapis(t, h, g, y);
				break;
			}


		 	// ODEJMOWANIE
			case '2':			  	
			{
				system("cls");
				naglowek();
				odczyt();
				wyswietlanie(w1, k1, m1);
				wyswietlanie(w2, k2, m2);       	
				// sprawdzamy czy mozna dodac do siebie macierze
				if ((w1==w2)&&(k1==k2))
				{
				 // wywolanie funkcji dodajacej macierze
					odej(w1,k1,m1,m2);
					for (h=0;h<w1;h++)
					{
						cout <<"\n";
						for (g=0;g<k1;g++)
						{
							printf(" %3.2f ",y[h][g]);
						}
					}
				}
				else cout <<"\n\n Nie da sie odjac macierzy ze wzgledu na rozmiary\n";	

				cout <<"\n\n";	
				t="Wynik odejmownia macierzy m1 i m2:";
				zapis(t, h, g, y);
				break;
			}


			// MNOZENIE
			case '3':
			{
				system("cls");
				naglowek();
				odczyt();	
				wyswietlanie(w1, k1, m1);
				wyswietlanie(w2, k2, m2);     	
				// sprawdzenie czy macierze daja sie pomnozyc
				// liczba kolumn macierzy m1 musi byc rowna liczbie wierszy m2 czyli k1=w2.
				if (k1!=w2)
					cout <<"\nMacierzy m1 i m2 nie da si\251 pomno\276y\206 - rozmiar macierzy musi by\206 r\242wny!\n";
				else
				{
					mnozenie(w1,k1,m1,w2,k2,m2);
					break;
				}
			}	


			// WYZNACZNIK I ODWRACANIE
			case '4':
			{
				system("cls");
				naglowek();
				odczyt();	
				wyswietlanie(w1, k1, m1);
				wyswietlanie(w2, k2, m2);
				wsk=1;
				// sprawdzenie czy da sie okreslic wyznacznik - macierz musi byc kwadratowa
				// Uwaga: przedmiotem dzialania jest tylko pierwsza z dwoch wczytanych macierzy
				// i tylko ona zostanie poddana przetwarzaniu w inna wynikowa
				if (w1!=k1)
				{	
					cout <<"\nNie da sie okreslic wyznacznika tym samym nie mozna odwrocic - macierz niekwadratowa\n";
					break;
				}
			
				else
				{
					wyz=wyzn(k1,m1);
					dop (k1,m1);
					printf("\nWyzn=%3.2f\n\n",wyz);
					trans(k1,k1,y);	

					printf ("\nMacierz odwrotna:\n");
					for (h=0;h<k1;h++)
					{
						printf("\n");
						for (g=0;g<k1;g++)
						{
							y[h][g]=y[h][g]/wyz;
							printf(" %3.2f ",y[h][g]);
						}
					}	

					cout <<"\n\n";
					t="Macierz odwrotna do m1:";
					zapis(t, h, g, y);
					break;
				}
			}

			// SPRAWDZENIE ORTOGONALNOSCI CZYLI czy macierz transponowana do M1 jest rowna macierzy odwrotnej do M1
			case '5':
			{
				system("cls");
				naglowek();
				odczyt();	
				wyswietlanie(w1, k1, m1);
				wyswietlanie(w2, k2, m2);
				if (w1!=k1)
					{
					cout <<"\nMacierz nie jest ortogonalna bo nie jest kwadratowa a to warunek konieczny\n";
					break;
					}
				else
				{
					// okreslam macierz transponowana do M1
					wsk=2;
					trans(w1,w1,m1);	

					// w celu unikniecia konfliktu musze przepisac y[w1,w1] do yy[w1,w1]
					// dopiero wtedy bede mogl sobie sprawdzac rownosc y[w1,w1] z yy[w1,w1] czyli sprawdzac niejako ortogonalnosc
					for (h=0;h<k1;h++)
						for (g=0;g<k1;g++)
							yy[h][g]=y[h][g];
					
					// teraz liczy sie macierz odwrotna do M1 ktora zostanie umieszczona w y[w1,w1]
					wyz=wyzn(k1,m1);
					dop (k1,m1);
					trans(k1,k1,y);
					for (h=0;h<k1;h++)
						for (g=0;g<k1;g++)
							y[h][g]=y[h][g]/wyz;	
		
					// realizujemy sprawdzenie rownosci macierzy y i yy
					if (rown(w1,y,yy)==0)
						cout <<"\nMacierz M1 jest ortogonalna.\n\n";
					else
						cout <<"\nMacierz M1 nie jest ortogonalna.\n\n";
					break;
				}
			}	

			case '6':
			{
				system("cls");
				naglowek();
				odczyt();	
				wyswietlanie(w1, k1, m1);
				wyswietlanie(w2, k2, m2);
				wsk=0;
				trans (w1,k1,m1);
				t="Macierz M1 po trnasponowaniu:";
				zapis(t, h, g, y);
				break;
			}
			
			
			case '0':
			{
				exit(1);
			}

			default:
			{
				system("cls");
				naglowek();
				odczyt();	
				wyswietlanie(w1, k1, m1);
				wyswietlanie(w2, k2, m2);
				cout << "\n\n Nie ma takiej opcji\n\n";	
			}
		}
	}
}
