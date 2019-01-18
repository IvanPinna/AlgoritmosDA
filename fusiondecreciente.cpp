#include <iostream>
#include <stdlib.h>

using namespace std;

struct Celda{
  int valor_, x_, y_;

  Celda(int valor = 0, int x = 0, int y = 0):valor_(valor), x_(x), y_(y)
  {}
  
  Celda& operator=(const Celda& a)
  {
    if(this != &a)
      {
	this->valor_ = a.valor_;
	this->x_ = a.x_;
	this->y_ = a.y_;
      }
    
    return *this;
  }
  
};

bool operator >(const Celda& a, const Celda& b)
{
  return a.valor_ > b.valor_;
}

/*
void insercion(Celda vector[], int tam) //Funciona
{
  Celda x;
  int j;
  for(int i = 1; i < tam; ++i)                                                                                                                                    
    {      
      x = vector[i];
      j = i - 1;
      while( j >= 0 && x > vector[j])
	{
	  vector[j+1] = vector[j];
	  --j;
	}
	vector[j+1] = x;
    }            
}
*/

void insercion(Celda vector[], int ini, int fin) //Funciona
{
  Celda x;
  int j;
  for(int i = 1; i < fin; ++i){
    x = vector[i];
    j = i - 1;
    while( j >= 0 && x > vector[j]){
      vector[j+1] = vector[j];
      --j;
    }
    vector[j+1] = x;
  }
}


void fusionar(Celda u[], Celda v[], Celda vector[], int tam1, int tam2) 
{
    int i = 0, j = 0;
    u[tam1].valor_ = -2147483647;
    v[tam2].valor_ = -2147483647;
    
    for(int k = 0; k < tam1+tam2; ++k)
    {
      cout << " k-> " << k << endl;
      if(u[i] > v[j])
      {
	vector[k] = u[i];
	cout << "insertando " << u[i].valor_ << endl; 
	++i;
      }else
      {
	vector[k] = v[j];
	cout << "insertando " << v[j].valor_ << endl;
	++j;
      }
    }
}

void ordenarporfusion(Celda vector[], int tam)
{
  if(tam <= 5)
  {
    insercion(vector, 0, tam);
  }
  else
  {
    int mitad2;
    if(tam%2 == 0)
      mitad2 = tam/2;
    else
      mitad2 = tam/2 + 1;

    Celda p[tam/2];
    Celda q[mitad2];
    for(int i = 0; i < tam/2; ++i)
      p[i] = vector[i];
    for(int i = 0; i < mitad2; ++i)
      q[i] = vector[tam/2 + i];
    ordenarporfusion(p, tam/2);
    ordenarporfusion(q, mitad2);
    fusionar(p,q,vector,tam/2, mitad2);
  }
}


int main(){ 
    int tam = 10;
    Celda p[10] = {9, 8, 4, 7, 3, 6, 5, 0, 1, 2}; 
    Celda q[5] = {11, 12 , 13, 14, 15};
    Celda r[15];
    //ordenarporfusion(p, tam); 
    
    insercion(p, 0, tam);
    cout << "Vector p" << endl;
    for(int i = 0; i < tam; ++i)
      cout << p[i].valor_ << endl;

    insercion(q,0, 5);
    cout << "Vector q" << endl;
    for(int i = 0; i < 5; ++i)
      cout << q[i].valor_ << endl;

    fusionar(p,q,r,10,5);
    for(int i =0; i < 15; ++i)
      cout << r[i].valor_ << endl;
    
}           
