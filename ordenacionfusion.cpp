#include <iostream>
#include <string>
#include <vector>

using namespace std;

int* insercion(int* vector, int tam){
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
    
    return vector;
}

int* fusionar(int* u, int* v, int tam1, int tam2)
{
    int j = 0;
    int* res = new int[tam1+tam2];
    
    for(int i = 0; i < tam1; ++i)
    {
        res[j] = u[i];
        ++j;
    }
    
    for(int i = 0; i < tam2; ++i)
    {
        res[j] = v[i];
        ++j;
    }
    
    return res;
}

int* ordenarporfusion(int* vector, int tam){
    
    if(tam < 3)
    {
        insercion(vector, tam); //Ordenamos por insercion.
    }
    else //Dividir el array en dos subvectores.
    {
        int mitad = tam/2;
        int* v, u = ordenarporfusion(vector, mitad);
        
        if(tam%2 != 0)
        {
            v = ordenarporfusion(*(vector+mitad), mitad + 1);
            fusionar(u , v, mitad, mitad+1);    
        }
        else
        {
            v = ordenarporfusion(*(vector+mitad), mitad);
            fusionar(u , v, mitad, mitad);
        }   
        
    }
    
    return vector;
}


int main()
{
    int tam = 13;
    int p[13] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5, 8, 9};
    int* o = ordenarporfusion(p, tam);
    
    for(int i = 0; i < tam; ++i)
        cout << o[i] << endl;
    
    
}