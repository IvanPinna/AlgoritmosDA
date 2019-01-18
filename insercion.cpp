#include <iostream>                                                                                                                                                    
#include <stdlib.h>                                                                                                                                                    
                                                                                                                                                                       
using namespace std;                                                                                                                                                   
                                                                                                                                                                       
void insercion(int vector[], int ini, int fin) //Funciona                                                                                                              
{                                                                                                                                                                      
  int x, j;                                                                                                                                                            
  for(int i = 1; i < fin; ++i)                                                                                                                                     \
                                                                                                                                                                       
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

int main()                                                                                                                                                             
{                                                                                                                                                                      
    int tam = 10;                                                                                                                                                      
    int p[10]  = {9, 8, 4, 7, 3, 6, 5, 0, 1, 2};                                                                                                                               
    insercion(p, 0, tam);
    //insercionDirecta(p, 0, tam);                                                                                                                                          
    for(int i =0; i < 10; ++i)                                                                                                                                         
        cout << p[i] << endl;                                                                                                                                          
                                                                                                                                                                       
} 
