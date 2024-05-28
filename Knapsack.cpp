#include <bits/stdc++.h>
#include <algorithm>
using namespace std; 

int Knapsack(int *w, int *c, int max, int size){ 
    
    int arr[size][max] = {0}; 
    for(int i = 1 ; i < size ; i ++) { 
        for(int j = 0; j < max; j++ ) { 
            if(w[i] > j) arr[i][j] = arr[i-1][j];
            else {  
                arr[i][j] = (arr[i-1][j] > arr[i-1][j-w[i]] + c[i]) ? arr[i-1][j] : arr[i-1][j-w[i]] + c[i];
            }  
            cout << arr[i][j] << " "; 
        }
        
        cout << endl; 
    } 
    return arr[size-1][max-1]; 
} 
int main()
{
    int w[] = {1,2,3,4,5}; 
    int c[] = {5,6,7,8,8}; 
    int max = 8; 
    int size = *(&w+1) - w; 
    printf("max = %d",Knapsack(w,c,max,size)); 
    return 0;
}