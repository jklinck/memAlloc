#include <stdio.h>
#include <stdlib.h>

int main(){

    int* x = (int*)malloc(3 * sizeof(int));
    
    x[0] = 7;
    x[1] = 9;
    x[2] = 11;
    
    int* temp = realloc(x, 5 * sizeof(int));

    if(temp == NULL){
        printf("Reallocation was unsuccessful.");
    }
    else{
    
        x = temp;
        
        if(&temp[0] != &x[0]){
            free(x);
            /*
            if during the reallocation it does not use the 3 original memory 
            addresses then I am freeing up the memory that x had allocated, 
            otherwise we do not want to free it right here because by freeing 
            x I would also be freeing up temp
            */
        }
        else{
            /*
            If temp[0] and x[0] are holding the same memory addresses then proceed
            */

            x[3] = 13;
            x[4] = 15;
            
            printf("%d\n", x[4]); // test to check if everything was successful 
            
            free(x); 
            /*
            this will free up both x and temp since they are pointed to the same 
            memory address
            */

        }
    }

	return 0;
}
