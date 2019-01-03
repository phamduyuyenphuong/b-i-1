#include<iostream>
#include<string.h>
using namespace std;
struct Nut{
	char nd[80];
	Nut *sau,*truoc;};
	
	Nut *dau;
	Nut *dau1;
	void KhoiTao(Nut *&dau)
	{ dau=NULL;}
// thu tuc nhap van ban
void NhapVb( Nut *&dau)
{
	Nut *p,*q;
	char tam[80];
	do{
		cout<<"Nhap vao dong van ban nhan Enter de dung:";
		fflush(stdin);
		gets(tam);
		if(strcmp(tam,"\0")!=0)
		{// tao nut moi
			p= new Nut;
			strcpy(p->nd,tam);// gan nd tam  moi go vocho p->nd
			p->sau =NULL;
			p->truoc= NULL;
			// moc nut vao van ban(moc sau nut cuoi cung)
			if(dau== NULL)
				dau=p;
			else
			{
				q->sau=p;
				p->truoc=q;
			}
			q=p;
		}
		
	}while (strcmp(tam,"\0")!=0); 
}
void DuyetVb(Nut *dau) // duyet de in ra van ban vua nhap
{  if(dau!=NULL) 
	 {
	    cout<<dau->nd<<endl; // in ra noi dung 
	  	DuyetVb(dau->sau);  
	  } 
}
// in cac dong van bang tu dong i -> j
void Indongij(Nut *dau, int i, int j) 
{  int dem;  
	Nut *p,*q; 
	 if(j >= i)
  { // tim i
    dem = 1;
	p = dau; 
	while(p != NULL && dem != i) 
	{    p = p->sau;
	    dem = dem+1;   } 
	  if(p != NULL)
	 { // tim j 
		q = p; 
		 while(q != NULL && dem != j)  
		{    q = q->sau;
			dem = dem + 1;    } 
// in ra dong i den dong j.  
  if(q != NULL) 
    while(p != q->sau) 
	   {  
	      cout<<p->nd; 
	       p = p->sau;    
		}
    }
  }
 } 
 
 //chen 1 dong vao cuoi vb voi nd moi nhap
 void Chencuoi(Nut *&dau)
 {
 	Nut *p,*q;
	char tam1[80];	
  	p = new Nut;
  	cout<<" nhap dong muon chen :";
  	cin.getline(tam1,80);
  	strcpy(p->nd, tam1);
  	p->truoc =NULL;
    p->sau = NULL;
    q=dau;
	while(q->sau!= NULL)
	{
		q=q->sau;
		}	
		q->sau=p;
		p->truoc=q;
 }
 // xoa dong i
 void Xoa(Nut *&dau, int i){
 	Nut *p,*t,*s;
 	int k=1;
 	p = dau;
 	while((p != NULL)&&(k != i)){
 		p = p->sau;
 		k += 1;
	 }
	 if( p != NULL){
	 	// truong hop p == dau
	 	if( p == dau)
	 	{
	 		dau= dau->sau;
	 		dau->truoc =NULL;
		 }
		 else
		 // truong hop p nut cuoi
		 if(p->sau == NULL)
		 {
		 	t= p->truoc;
		 	t->sau =NULL;
		 }
		 else
		 // truong hop p khong dau khong cuoi
		 if(( p != dau ) && (p->sau != NULL))
			{
					
		 	t = p->truoc;
		 	s= p->sau;
	 		t->sau=s;
	 		s->truoc=t;
	 		
			 } delete p;
	 
	 }
 }
// xoa tu dong i -> j ( tuc la xoa n lan vong i vi sau khi xoa vong i thi dong j la dong i)
void XoaDongij(Nut *&dau, int i, int j)
{
	int k;
	for(k=i; k<=j;k++)
	Xoa(dau,i);
}
// chep nd dong i -> j vao sau dong k

void Chepij(Nut *dau, int i, int j, int k) 
{    int dem; 
	 Nut *p,*q,*t,*l; 
	if(j >= i) 
		  { // tim i
		    dem = 1;  
			p = k;   
			while(p != NULL && dem != i)  
			{    
			p = p->sau;   
			dem = dem + 1; 
			 } 
	if(p != NULL)   
	{ // tim j   
	q = p; 
	 while(q != NULL && dem != j) 
 {    
 	 q = q->sau; 
	dem = dem+1;    
	} 
   // in ra dong i den dong j. 
	 if(q != NULL) 
	 while(p != q->sau)  
	 { 
	   //
	  cout<<p->nd ;
	  t = new Nut;    
	strcpy(t->nd,p->nd); 
	t->sau = NULL;
	t->truoc = NULL;    
	if (k == NULL)      
		k = t;       
	   else        
	     {         
		l->sau = t;         
		t->truoc = l;    
		}       
		l = t;   
		p = p->sau;  
	  }   
	 }    
 } 
 
 
int main(){
	int k;
	NhapVb(dau);
	DuyetVb(dau);
	Indongij(dau,2,3);
	cout<<endl;
	Chencuoi(dau);
	DuyetVb(dau);
	cout<<endl;
	 cout<<"\n xoa tu dong 3 den 4 \n";
	 XoaDongij(dau,3,4);
	DuyetVb(dau);
	cout<<endl;
	Chepij(dau,3,4,7);
	
}

