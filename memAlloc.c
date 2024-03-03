#include <stdio.h>
#include <stdlib.h>

int main(){

    int* x = (int*)malloc(3 * sizeof(int));
  
    x[0] = 7;
    x[1] = 9;
    x[2] = 11;
    
    int* temp = realloc(x, 5 * sizeof(int));
    
    x = temp;

    /*
    Since I have x now pointing at the new memory allocated with the temp variable, what is 
    happening with the original memory created with the x variable on line 6? How would I go 
    about freeing up that memory so as to not cause a memory leak?
    */
    
    x[3] = 13;
    x[4] = 15;
    
    printf("%d\n", x[4]);
    
    free(x);

    return 0;
}
