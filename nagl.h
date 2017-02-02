#ifndef NAGL_H
#define NAGH_H

#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <fstream>


using namespace std;

float m1[15][15], m2[15][15], x, y[15][15], yy[15][15], wyz;
int h, g, r, w1, k1, w2, k2, wsk; 
string t;

 void naglowek()
{
	cout <<" \n\t\t\t*------------------------------------*\n";
    cout <<" \n\t\t\t             13. MATRICES             \n";
    cout <<" \n\t\t\t            BY MICHAL DRAB            \n";
    cout <<" \n\t\t\t*------------------------------------*\n\n\n";
}
int mod (int v)
{
	int w, i;
	w=1;
	for (i=1; i<v+1; i++)
	w=w*(-1);
	return w;
}

//odczyt z pliku
void odczyt ()
{
	int wiersz1=0, kolumna1=0;
	int wiersz2=0, kolumna2=0;
	fstream plik("dane.txt");

	plik >> w1 >> k1;
	cout <<" Wymiar macierzy m1: "<<w1<<"x"<<k1<<endl;
	for ( wiersz1=0; wiersz1 < w1; wiersz1++)
	{
		for ( kolumna1=0; kolumna1 < k1; kolumna1++)
		{
			plik >> m1[wiersz1][kolumna1];
		}
	}

	plik >> w2 >> k2;
	cout <<" Wymiar macierzy m2: "<<w2<<"x"<<k2<<endl;
	for ( wiersz2=0; wiersz2 < w2; wiersz2++)
	{
		for ( kolumna2=0; kolumna2 < k2; kolumna2++)
		{
			plik >> m2[wiersz2][kolumna2];
    	}
	}
	plik.close();
}

//zapis do pliku
void zapis(string text, int &wymiar_wierszy, int &wymiar_kolumn, float m[15][15])
{
	int wiersz = 0, kolumna = 0;
	fstream wynik;
	wynik.open("wynik.txt",ios::out|ios::app);
	wynik <<text<<endl;
	for ( wiersz=0; wiersz < wymiar_wierszy; wiersz++)
	{
		for ( kolumna=0; kolumna < wymiar_kolumn; kolumna++)
		wynik <<m[wiersz][kolumna]<<" ";
		wynik << endl;
	}
	wynik << endl;
	wynik.close();
}

//wyswietlanie macierzy
void wyswietlanie( int wiersz, int kolumna, float m[15][15])
{
	int i,j;
	cout<<endl;
	for(i=0;i<wiersz;i++)
	{
		for(j=0;j<kolumna;j++)
		{
			cout<<m[i][j]<<" ";
			if(j==kolumna-1)
			{
				cout<<endl;
			}
		}
	}
}

// dodawanie
void doda (int i, int j, float mm1[15][15], float mm2[15][15])
{
	int k, l;
	for (k=0;k<=i;k++)
    for (l=0;l<=j;l++)
	y[k][l]=mm1[k][l]+mm2[k][l];
}

// odejmowanie
void odej (int i, int j, float mm1[15][15], float mm2[15][15])
{
	int k, l;
	for (k=0;k<=i;k++)
    for (l=0;l<=j;l++)
    y[k][l]=mm1[k][l]-mm2[k][l];
}

//wyznacznik
float wyzn (int n, float a[15][15])
{
  	float b[15][15];
	int i, k, l;
  	float wyznx;

	wyznx=0;

	if (n==1) wyznx=a[0][0];
	if (n>1)
	{
		for (i=0; i<n; i++)
		{
     	 // teraz bedzie opracowywanie nowej podmacierzy
			for (k=1; k<n; k++)
			{
				for (l=0; l<n; l++)
				{
					if (i>l)
					b[l][k-1]=a[l][k];
					if (i<l)
					b[l-1][k-1]=a[l][k];
				}
			}
      	// koniec procedury wylaniania podmacierzy
			wyznx=wyznx+mod (i)*a[i][0]*wyzn(n-1,b);
		}
	}
	return wyznx;
}

// mno�enie
void mnozenie(int n1, int n2, float mm1[15][15], int n3, int n4, float mm2[15][15])
{
	int i, k, l;

	for (i=0;i<n1;i++)
	{
		for (k=0;k<n4;k++)
		{
			y[i][k]=0;
			for (l=0;l<n2;l++)
			y[i][k]=y[i][k]+mm1[i][l]*mm2[l][k];
		}
	}

  // wypisanie macierzy bedacej wynikiem mnozenia M1 i M2
	cout <<"\nPo pomno\276eniu uzyskalismy macierz wynikowa:\n";
	for (i=0;i<n1;i++)
	{
		cout <<"\n";
		for (k=0;k<n4;k++)
		printf(" %3.2f ",y[i][k]);
	}
	cout <<"\n\n";
	t="Wynik mno�enia macierzy m1 i m2:";
	zapis(t, i, k, y);
}

// transponowanie
void trans(int n1, int n2, float m[15][15])
{
	int i,k;
	float p[15][15];
	for (i=0;i<n1;i++)
		for (k=0;k<n2;k++)
			p[k][i]=m[i][k];
  // wypisanie macierzy transponowanej
	if (wsk==0) printf ("\nMacierz transponowana:\n");
	if (wsk==1) printf ("\nTransponowana macierz dopelnien algebraicznych:\n");
	if (wsk==2) printf ("\nPotrzebne obliczenia do stwierdzenia ortogonalnosci\nwpierw trzeba odwrocic transponowac przepisac i porownac:\n");
	for (i=0;i<n2;i++)
	{ 	printf("\n");
		for (k=0;k<n1;k++)
		{
			y[i][k]=p[i][k];
			printf(" %3.2f ",y[i][k]);
		}
	} cout <<"\n\n";
}

void dop (int n, float a[15][15])
{
	float b[15][15];
	int i,j,k, l;

	for (i=0; i<n; i++)
	{
		for (k=0; k<n; k++)
		{
			for (j=0; j<n; j++)
			{
				for (l=0; l<n; l++)
				{
					if ((i>l)&&(k>j)) b[l][j]=a[l][j];
					if ((i>l)&&(k<j)) b[l][j-1]=a[l][j];
					if ((i<l)&&(k>j)) b[l-1][j]=a[l][j];
					if ((i<l)&&(k<j)) b[l-1][j-1]=a[l][j];
				}
			}

			y[i][k]=mod(i+k)*wyzn(n-1,b);
		}
	}
}

int rown (int n, float m1[15][15], float m2[15][15])
{
	int i,j,k;
	k=0;
	for (i=1; i<n+1; i++)
		for (j=1; j<n+1; j++)
			if (m1[i][j]!=m2[i][j])  k=1;
	return k;
}
#endif

