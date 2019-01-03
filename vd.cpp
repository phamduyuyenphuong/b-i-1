#include<iostream>
#include<cstdlib>
#include <fstream>
using namespace std;

const int n = 5;
int a[n][n] ;
int tt[n];
int thutu = 2;
int dinhkd(int a[n][n], int n);
void xoacung(int j);
void GhiNhan(int j);
void Ktra(int tt[n],int n);
//
int main(){ 
	int n;
	char k[255];
	 ifstream filein;
	filein.open("input1.txt",ios_base::in);
	filein.getline(k, 255);
	n=atoi(k);
	int dinh;
	int sddc = 0;
	do
		{
			dinh = dinhkd(a,n);
			if((dinh != -1) && (sddc < n))
			{
				if(tt[dinh] != 0)
				{
					xoacung(dinh);
					sddc += 1;
				}
			}
		}
	while((dinh != -1) && (sddc < n));
	Ktra(tt, n);
	return 0;
	}
//ham tra ve khong co cung den, tra ve -1 khong co dinh
int dinhkd(int a[n][n], int n)
{
	int j = 0, i;// i cot j hang
	int kt = 0;
	while(j < n)
	{
		for(i = 0; i < n; i++)
			if(a[i][j] != 0)
				kt = 3;
			if((kt == 0) && (tt[j] == 0))
			{
				GhiNhan(j);	
				thutu + 1;
				return j; // return cot bang 0
			}
			else 
			{
				kt = 0;
				j = j + 1;
			}
	}
	if(j > n)
	return -1;
}
//---------------------------------------------------------------------
// xoa tat ca cac cung den tu dinh j
void xoacung(int j)
{
	int k;
	for(k = 0; k < n; k++)
		a[j][k] = 0;// tuc la gan hang j = 0		
}
//
void GhiNhan(int j)// cot j da chon roi gan trang thai =2
{
	tt[j] = thutu;
}
//
void Ktra(int tt[n],int n)
{
	int k, dem = 0;
	int i;
	for (k = 0;k <= n; k++)
		if(tt[k] != 0)
			dem += 1;
	if(dem != n)
		cout << "Khong sap xep Topo \n";
	else
	{
		for(k = 2; k <= n + 2; k++)
			{
				for(i = 0; i < n; i++)
					if(tt[i] == k)
						cout << i ;
			}
	}
}

