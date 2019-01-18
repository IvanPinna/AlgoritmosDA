#include <iostream>
#include <stdlib.h>
#include <queue>

using namespace std;

int main()                                                                                                                                                            
{                                                                                                                                                                     
    int tam = 10;                                                                                                                                                     
    int p[10] = {6, 5, 7, 1, 9, 3, 8, 0, 4, 2}; 
    
    std::priority_queue<int> q;
    

    for(int i =0; i < tam; ++i)
        q.push(p[i]);
        
    cout << "Array ordenado" << endl;   
    for(int i = 0; i < tam; ++i)
    {
        cout << q.top() << endl;
        q.pop();
    }
}
