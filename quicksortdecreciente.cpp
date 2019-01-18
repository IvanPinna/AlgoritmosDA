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

int pivote(Celda vector[], int i, int j)
{
  int p = vector[i].valor_, k = i, l = j-1;  // + 1;
  while(vector[k].valor_ <= p && k < j) //Revisar segunda condicion
    ++k;
  
  while(vector[l] > p)
    --l;
  int aux;     
  while( k < l)
  {
    aux = vector[k].valor_;
    vector[k] = vector[l];
    vector[l] = aux; 
    while(vector[k].valor_ <= p) //REVISAR
      ++k;
    while(vector[l] > p)
      --l;
  }
    
  aux = vector[i].valor_;
  vector[i] = vector[l];
  vector[l] = aux; 
    
  return l; 
}

void quicksort(Celda vector[], int i, int j)
{
  if( j-i <= 2)
    insercion(vector, i, j);
  else{ 
    int l = pivote(vector, i, j);
    //cout << "Pivote " << l << endl; 
    quicksort(vector, i, l-1); //REVISAR
    quicksort(vector, l+1, j); //REVISAR   
  }
    
}

int main()
{                                                                                                                                                                     
  int tam = 10;                                                                                                                                                      
  Celda p[10]; // = {6, 5, 7, 1, 9, 3, 8, 0, 4, 2}; 
  for(int i = 0; i < tam; ++i)
    p[i] = rand() % 100;
    
  cout << "Array sin ordenar" << endl;
  for(int i =0; i < tam; ++i)
    cout << p[i].valor_ << endl;
    
  quicksort(p, 0, tam);
  cout << "Array ordenado" << endl; 
  for(int i =0; i < tam; ++i)
    cout << p[i].valor_ << endl;    
}                                                                                                                                                                      

       
