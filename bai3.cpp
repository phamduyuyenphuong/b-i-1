#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;
//Khai bao dl de quan ly cac nut thuoc AVL
struct AVL
		{
		int key;
		int bal; // thuoc tinh cho biet gia tri can bang
	// 0: can bang, 1: lech trai, 2: lech phai
		AVL* Left;
		AVL* Right;
		};typedef AVL *Tree;  //cay
// khoi tao
void khoiTao(AVL *&root) ;
AVL*root;
//Xac dinh yeu to can bang cua mot nut
//can chinh lai cay AVL
void XoayTrai(AVL* &p);
void XoayPhai(AVL* &p);
void CanBangTrai(AVL* &p); 
void CanBangPhai(AVL* &p);
void CanBang(AVL* t);
int InsertNode(AVL* &root, int x) ;
// Nhap va tao mot cay AVL
void MocNut(AVL *&root, int x);
void TaoCay(AVL *&root);
void DuyetLNR(AVL *root);
//Xoa mot nut thuoc cay AVL
int Xoa(AVL *&t, int x);
//kiem tra cay co phai la cay AVL
int KTcayAVL(AVL *root) ;

int main(){
		int x;
	TaoCay(root);
	DuyetLNR(root);
	cout<<endl;
	cout<<"--------------------------------"<<endl;
	CanBang(root);
	cout<<InsertNode(root,x)<<endl;
	cout<<"------------------********************-------------------------"<<endl;
	cout<<" nhap key can xoa :";
 	cin>>x;
	cout<<Xoa(root,x)<<endl;
	cout<<"-----------------------------------------------"<<endl;
	cout<<"co phai la cay AVL "<<endl;
	CanBang(root);
		if(KTcayAVL(root) == 1)
		cout << "La cay AVL" << endl;
	else
		cout << "Khong phai cay AVL" << endl;
		
	cout << endl;
	
	//////
		
}
 void khoiTao(AVL *&root)
  { 
   root = NULL; 
   }
//nhap va tao cay avl
 void MocNut(AVL *&root, int x) // moc nut vao cay
 { 
 	 if(root == NULL) // neu root null tao cay moi
  	{   root = new AVL;  
   		root->key = x;  
    	root->Left = NULL;  
 		root->Right = NULL;
		  }
	  else  
	  {   if(root->key >= x) // x be hon key
	    MocNut(root->Left,x);// moc x vao ben trai
		    else  
	  	MocNut(root->Right,x); // moc x vao ben phai
	}
 } 
 
void TaoCay(AVL *&root)// tao cay tu nhieu x
 {  int tmp;
   do 
    {   cout<<"Nhap so nguyen, 0 de dung: "; 
	  cin>>tmp;  
	   if(tmp != 0) 
	      MocNut(root,tmp); 
		   }
		while(tmp != 0); } 
void DuyetLNR(AVL *root)// in ra cay  vua tao
 {  
 if(root != NULL) 
  {  
    DuyetLNR(root->Left); 
    cout<<root->key<<"  "; 
	DuyetLNR(root->Right); 
 } 
} 
//can chinh lai cay AVL
void XoayTrai(AVL* &p) 
{  
	AVL *q;
    q = p->Right;
    p->Right = q->Left; 
	q->Left = p; 
 	p = q; 
}
void XoayPhai(AVL* &p) 
{  
	AVL *q;
    q = p->Left;
    p->Left = q->Right; 
	q->Right = p; 
 	p = q; 
}
void CanBangTrai(AVL* &p)
 {  
 	switch(p->Left->bal)
 	{   
	 	case 1: //
	   		XoayPhai(p); 
	     	p->bal = 0;  
		  	p->Right->bal = 0;  
		   	break; 
		case 2: //
		   	XoayTrai(p->Left);  
			XoayPhai(p); 
	switch(p->bal)
	{   
		case 0: //can bang 
			p->Left->bal= 0;
			p->Right->bal= 0; 
			break; 
	 	case 1: // lech phai 
			p->Left->bal= 0;  
			p->Right->bal= 2;   
			break; 
		case 2: //lech trai
			p->Left->bal= 1;
			p->Right->bal= 0;  
			break;   
	}  
	 	p->bal = 0; 
		break;  } } 
 
void CanBangPhai(AVL* &p)
 { 
  	switch(p->Right->bal)
	 {  
	case 1:  
	   	XoayPhai(p->Right); 
	   	XoayTrai(p); 
    switch(p->bal)
	 { 
	case 0:// can bang
		p->Left->bal= 0;  
		p->Right->bal= 0;
	  	break; 
  	case 1:// lech trai
		p->Left->bal= 1;  
	  	p->Right->bal= 0; 
	    break; 
    case 2: // lech phai
	    p->Left->bal= 0; 
	    p->Right->bal= 2; 
	    break; 
	  } 
    p->bal = 0;  
    break; 
    case 2: 
	    XoayTrai(p);
	    p->bal = 0;  
		p->Left->bal = 0; 
		break;  
	 } 
} 
//
AVL* CreateNode(int Data)
 {  
 AVL* pNode; 
  pNode = new AVL;
   //
     if (pNode == NULL)
	 {   return NULL; 
	  }  pNode->key = Data;
	    pNode->Left = NULL; 
		 pNode->Right = NULL; 
		  pNode->bal = 0; 
		  // 
		   return pNode; }
int InsertNode(AVL* &root, int x) 
{ 
 int res; 
  if(root == NULL)
  { //neu cay  null thi tao moi  
  	 root = CreateNode(x);
      if(root == NULL)
	  {    return -1;
	   //them khong thanh cong vi thieu bo nho
	     }  
	    return 2;
		//them thanh cong va lam tang chieu cao
		  } 
	 else
	  {  
	 if(root->key==x)
	{    return 0;
 //khoa nay da ton tai trong cay  
  }   else
   if(root->key > x)
   {   
    res = InsertNode(root->Left,x);
	    if(res < 2) 
		{     return res;    }    
		switch(root->bal)
		{ // 
		case 0:   
		root->bal = 1; // cay lech trai
		return 2;  
		case 1:    
		XoayTrai(root);
		return 1;        
		case 2:     
		root->bal = 0; // cay can bang
		 return 1;    }   } 
		 else
		{   
		 res = InsertNode(root->Right,x);
		 if(res < 2)
		{     return res;    } 
		switch(root->bal)
		{    case 0:   
		root->bal = 2;  // cay lech phai
		return 2;   
		 case 1:  
		root->bal = 0; 
		 return 1;  
		 case 2:  
		XoayPhai(root); 
		 return 1; 
  }   }  } } 
//
void CanBang(AVL* t)
{
	if(t!=NULL)
	{
		CanBang(t->Left);
		cout << "Key: "<< t->key << " can bang: " << t->bal << endl;
		CanBang(t->Right);
	}
}

//kiem tra cay co phai la cay AVL
int KTcayAVL(AVL *root) 
{ 
	if (root == NULL) //cay null thi no la cay avl
  		return 1;  // la cay AVL
  	if(root->Left == NULL && root->Right == NULL)  //dau = null, cuoi =null la cay avl
  		return 1; 
	else 
		if(root->Left == NULL)//ben trai null thi ktra ben phai
	 	KTcayAVL(root->Right);
	 	else  
		if(root->Right == NULL)// ben phai null thi ktra ben trai
		KTcayAVL(root->Left); 
 	 else  
	 if(root->Left->key > root->key || root->Right->key < root->key) // neu key ben trai lon hon key hoac key ben phai be hon key
  	return 0; // khong la cay AVL
}
 //xoa mot nut thuoc cay
int Xoa(AVL *&t, int x)     // xoa nut co key x   
 {    
 		
 	if (t == NULL) 
        return 0; 
    else 
		if (t->key > x)  // so sanh key voi key x can xoa >
		    return Xoa(t->Left, x); //xoa trai
		else 
		if (t->key < x) //so sanh key voi key x can xoa <
			return Xoa(t->Right, x); //xoa phai
	    else // T->key == x  
		   {        
		    AVL *p = t;    
			if (t->Left == NULL) 
			     t = t->Right;
			    // Node chi co cay con phai  
	        else
			   if (t->Right == NULL)  
	           t = t->Left;   
			   // Node chi co cay con trai  
			    else // Node co ca 2 con    
				 { 
				 AVL *s = t, *q = s->Left;    
// s la cha cua q, q la Node phai nhat cua cay con trai cua p    
         while (q->Right != NULL) 
		 { 
		    s = q;
		    q = q->Right;           
		  } 
		   p->key = q->key;   
		   s->Right = q->Left; 
	    delete q;        
		 }
	    }   
  return 1;// thanh cong
  }
