#include<fstream>
#include <stdio.h>
#include <string>
#include <cstdlib>
using namespace std;
void GhiFile();
void XuatFile(FILE *fi , const char duongdan[]);
void Chiaa(FILE	*fi, FILE *fi1, FILE *fi2, int p);
void Tron(FILE *fi, FILE *fi1, FILE *fi2, int p);
int n=1;	
int p=1;	
int main()
{ 
	FILE *fi, *fi1, *fi2;
	int t;
	int a[50];
	
	// mang a
	GhiFile();
	XuatFile(fi,"bt4.txt");
	 // 
	while (p < n)
	{
		Chiaa(fi,fi1,fi2,p);
		printf("\n Xuat ra file 1 \n"); 	
		XuatFile(fi1,"file1.txt");  
		printf("\n Xuat ra file 2 \n");
		XuatFile(fi2,"file2.txt"); 
		Tron(fi,fi1,fi2,p);
		printf("\n File nguon sau khi tron:");
		XuatFile(fi,"bt4.txt"); 
		p = p*2;//tiep tuc gap doi len	
	}

}
// ghi filevao file bt4.txt
void GhiFile(){
	int	i, s;
	FILE *fi;
	printf("Nhap n...... "); // nhap so phan tu	
	scanf("%d", &n); printf("\n");
	fi = fopen("bt4.txt","wt");// mo file de viet
	for (int i = 0; i < n; i++)
		{
			scanf("%d", &s);       //nhap s tu ban phim
			fprintf(fi, "%3d", s); 	//ghi s vao file 
		}
	printf("da ghi vao file :\n ");
		fclose(fi);
}
// xuat tu file bt4.txt ra
void XuatFile( FILE  *fi, const char duongdan[])
{
	
	int x;
	fi = fopen(duongdan,"rt"); 
	printf("Cac phan tu  :\t");
	while  (!feof(fi)) 
	{
		fscanf(fi, "%d", &x);		//doc tu fle vao bien 
		printf("%3d", x);		//xuat ra man hinh
	}
	fclose(fi);	
}
// chia mang a cho 2 mang b, c
void Chiaa(FILE	*fi, FILE *fi1, FILE *fi2, int p)
{
	int	dem, s;
	fi = fopen("bt4.txt","rt"); 	
	fi1 = fopen("file1.txt","wt"); 	
	fi2 = fopen("file2.txt","wt"); 	

	while (!feof(fi))
	{
		//chia p phan tu cho fi1
		dem	= 0;
		while ((dem < p) and (!feof(fi)))
		{
			fscanf(fi,"%3d", &s);			//doc tu file fi ra s
			fprintf(fi1,"%3d", s);			//ghi s ra file	fi1
			dem++;			
		}
		//chia p phan tu cho fi2
		dem	= 0;
		while ((dem < p)and (!feof(fi)))
		{
			fscanf(fi,"%3d", &s);			//doc tu file fi ra s
			fprintf(fi2,"%3d", s);			//ghi s ra file	fi2
			dem++;			
		}
	
	}	
		fclose(fi);	 
		fclose(fi1);	
		fclose(fi2);	
}
void Tron(FILE *fi, FILE *fi1, FILE *fi2, int p)
{
	int	stop, x, y, a, b;
	
	fi = fopen("bt4.txt","wt"); 	
	fi1 = fopen("file1.txt","rt"); 	
	fi2 = fopen("file2.txt","rt");
	
	while ((!feof(fi1))&& (!feof(fi2)))
	{
		a = 0;	//so phan tu cua fi1 da ghi len fi
		b = 0;	//so phan tu cua fi2 da ghi len fi
		fscanf(fi1, "%3d", &x);		//doc 1 phan tu tu fi1 vao bien x
		fscanf(fi2, "%3d", &y);		//doc 1 phan tu tu fi2 vao bien y
			stop = 0;
		
		while ((a != p) && (b != p) && (!stop))
		{
			if (x < y)					//ghi file fi1 (da doc ra  bien x) vao truoc
			{
				fprintf(fi,"%3d", x);			//ghi x ra file	f1
				a++;
				
				if ((a < p) && (!feof(fi1)))			//chua du p phan tu va chua het file fi1
					fscanf(fi1, "%3d", &x);		//doc tiep 1 phan tu tu fi1 vao bien x, de lan sau lap sau ghi vao fi
				
				else 						//da xong fi1(du p phan tu hoac ket thuc), ==> ghi fi2 vao a
				{
					fprintf(fi,"%3d", y);			//ghi y ra file	fi
					b++;
					if (feof(fi1))			//neu fi1 da ket thuc thi dung viec phan phoi
						stop = 1;
				}
			}
			
			else 		//ghi file fi2 (da doc ra bien y) vao truoc
			{
				
				fprintf(fi,"%3d", y);			//ghi y ra file	fi
				b++;
				
				if ((b < p) && (!feof(fi2)))			//chua du p phan tu va chua het file fi1
					fscanf(fi2, "%3d", &y);		//doc tiep 1 phan tu tu fi1 vao bien x, de lan sau lap sau ghi vao fi
				
				else 						//da xong fi2 (du p phan tu hoac ket thuc), ==> ghi  fi1 vao fi
				{
					fprintf(fi,"%3d", x);			//ghi x ra file	fi
					a++;
					if (feof(fi2))			//neu fi1 da ket thuc thi dung viec phan phoi
						stop =1;
				}							
			}	
		}
		//ghi tiep phan con lai cua p phan tu tren fi1 vao fi
		while ((a<p)&& (!feof(fi1)))	
		{
			fscanf(fi1, "%3d", &x);
			fprintf(fi,"%3d", x);	
			a++;
		}
		
		//ghi tiep phan con lai cua p phan tu tren fi2 vao fi
		while ((b < p) && (!feof(fi2)))	
		{
			fscanf(fi2, "%3d", &y);
			fprintf(fi,"%3d", y);	
			b++;
		}
				
	}
	
	if(!feof(fi1))			// fi1 con phan tu
	{
		//chep phan con lai cua fi1 len fi
			while (!feof(fi1))
			{	
				fscanf(fi1, "%3d", &x);
				fprintf(fi,"%3d", x);	
			}
	}
	
	
	if(!feof(fi2))			// fi2 con phan tu
	{
		//chep phan con lai cua fi2 len fi
			while (!feof(fi2))
			{	
				fscanf(fi2, "%3d", &y);
				fprintf(fi,"%3d", y);	
			}
	}
	
	fclose(fi);	 
	fclose(fi1);		
	fclose(fi2);	
}


