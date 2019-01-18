#include <iostream>
#include <stdlib.h>

using namespace std;

void insercion(int vector[], int tam) //Funciona
{
    int x, j;                                                                                                                                                                    
                                                                                                                                                                                 
    for(int i = 1; i < tam; ++i)                                                                                                                                                 
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

void fusionar(int u[], int v[], int vector[], int tam1, int tam2) 
{
    int i = 0, j = 0;
    u[tam1] = 2147483647;
    v[tam2] = 2147483647;
    
    for(int k = 0; k < tam1+tam2; ++k)
    {
        if(u[i] < v[j])
        {
            vector[k] = u[i];
            ++i;
        }else
        {
            vector[k] = v[j];
            ++j;
        }
    }
}

void ordenarporfusion(int vector[], int tam)
{
    if(tam <= 3)
        insercion(vector, tam);
    else
    {
        int mitad = tam/2, mitad2;
        
        if(tam%2 == 0)
            mitad2 = mitad;
        else
            mitad2 = mitad+1;
        
        int *vector1 = new int[mitad], *vector2= new int[mitad2];
        
        cout << "Dividiendo vector1" << endl;
        cout << "Mitad " << mitad << endl; 
        for(int i = 0; i < mitad; ++i)
        {
            vector1[i] = vector[i];
        }
        
        cout << "Dividiendo vector2" << endl;
        cout << "Mitad2 " << mitad2 << endl; 
        for(int i = 0; i < mitad2; ++i)
        {
            vector2[i] = vector[mitad + i];
        }

        ordenarporfusion(vector1, mitad);
        cout << "vector1 " << endl;
        for(int i = 0; i < 5; ++i)
            cout << vector1[i] << endl;
        
        ordenarporfusion(vector2, mitad2);
        cout << "vector2 " << endl;
        for(int i = 0; i < 5; ++i)
            cout << vector2[i] << endl;
        cout << "fin" << endl;
        
        
        fusionar(vector1, vector2, vector, mitad, mitad2);
    }
}


int main()                                                                                                                                                            
{                                                                                                                                                                     
    int tam = 13;                                                                                                                                                     
    int p[13];
    // = {9, 8, 4, 7, 3, 6, 5, 0, 1, 2}; 
    for(int i = 0; i < tam; ++i)
        p[i] = rand() % 100;
        
    ordenarporfusion(p, tam); 
    for(int i =0; i < 10; ++i)
        cout << p[i] << endl;
    
}           
