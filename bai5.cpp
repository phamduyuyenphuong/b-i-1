#include <iostream>
#include <fstream>
#include <stdio.h>
using namespace std;
// Khai bao 
 struct PhanSo{
	int tu;
	int mau;
};
void DocFile(int &n, int &p, int &q);	// Ham doc du lieu tu file
void LuuFile(PhanSo pso[100], int n);// luu ket qua sau sap xep vao file
void SapXep(PhanSo pso[100], int n);	// Sap xep day so ket qua theo thu tu tang dan 
void KiemTra(int n, int p, int q);	// Ham kiem tra voi dieu kien bai toan
int main(){
	int n, p, q;
	DocFile(n, p, q);//  dk n > p >q
	KiemTra(n, p, q);
}
// Doc du lieu tu file 
void DocFile(int &n, int &p, int &q) {
	FILE *fi;
	fi = fopen("bai5inp.txt", "rt");
	fscanf(fi,"%d",&n); 
	fscanf(fi,"%d",&p);
	fscanf(fi,"%d",&q);
	fclose(fi);
}
// luu ket qua sau sap xep vao file
void LuuFile(PhanSo pso[], int n){
	FILE *fi;
	fi = fopen("bai5out.txt", "wt");
	for(int i = 0; i < n; i++)
		fprintf(fi, "%d/%d\n", pso[i].tu, pso[i].mau);
}
// Sap xep day so ket qua theo thu tu tang dan
void SapXep(PhanSo pso[], int n) {
	// Sap xep day so
	for(int i = 0; i < n - 1; i++)
	{
		for(int j = i + 1; j < n; j++)
		{
			if((float)pso[i].tu / pso[i].mau > (float)pso[j].tu / pso[j].mau)// neu ps i > ps j
				swap(pso[i], pso[j]); // doi cho ps i, ps j
			
		}
	}
}

//  kiem tra theo dieu kien bai toan 
void KiemTra(int n, int p, int q) {
	PhanSo pso[(n / 2) - 1];
	int vitri = 0;
	for (float i = n / 2; i < n; i++){
		for(float j = 1; j < n / 2; j++){
			if(j / i > (float) 1 / p && j / i < (float)1 / q) {
				pso[vitri].tu = j;
				pso[vitri].mau = i;
				vitri++;
			}
		}
	}
	SapXep(pso, (n / 2) - 1);
	LuuFile(pso,(n / 2) - 1);
	cout << "da ghi vao file "<<endl;
}

