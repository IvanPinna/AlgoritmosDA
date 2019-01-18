#include <iostream>
#include <stdlib.h>

using namespace std;

void insercion(int vector[], int ini, int fin) //Funciona
{
  int x, j;    
  for(int i = ini; i <= fin; ++i)                                                                                                                                      
  {                                                                                                                                                                 
    x = vector[i];
    j = i - 1;
    while( j >= 0 && x < vector[j])
    {  
      vector[j+1] = vector[j];
      --j;                    
    }                        
    vector[j+1] = x;                                                                                                                                                
  }            
}

int pivote(int vector[], int i, int j)
{
  int p = vector[i], k = i, l = j-1;  // + 1;
  while(vector[k] <= p && k < j) //Revisar segunda condicion
    ++k;
  
  while(vector[l] > p)
    --l;
  int aux;     
  while( k < l)
  {
    aux = vector[k];
    vector[k] = vector[l];
    vector[l] = aux; 
    while(vector[k] <= p) //REVISAR
      ++k;
    while(vector[l] > p)
      --l;
  }
    
  aux = vector[i];
  vector[i] = vector[l];
  vector[l] = aux; 
    
  return l; 
}

void quicksort(int vector[], int i, int j)
{
  if( j-i <= 5)
    insercion(vector, i, j);
  else{ 
    int l = pivote(vector, i, j);
    cout << "Pivote " << l << endl; 
    quicksort(vector, i, l-1); //REVISAR
    quicksort(vector, l+1, j); //REVISAR   
  }
    
}

int main()
{                                                                                                                                                                     
  int tam = 11;                                                                                                                                                      
  int p[11]; // = {6, 5, 7, 1, 9, 3, 8, 0, 4, 2}; 
  for(int i = 0; i < tam; ++i)
    p[i] = rand() % 100;
    
  cout << "Array sin ordenar" << endl;
  for(int i =0; i < tam; ++i)
    cout << p[i] << endl;
    
  quicksort(p, 0, tam);
  cout << "Array ordenado" << endl; 
  for(int i =0; i < tam; ++i)
    cout << p[i] << endl;    
}                                                                                                                                                                      

       
