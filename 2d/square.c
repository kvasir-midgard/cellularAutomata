#include <stdio.h>
#include <stdlib.h>

// Print an array given a pointer and length
void printRay(int *ray, int length){
    for(int i=0; i<length; i++){
        printf("%d", ray[i]);
    }
    printf("\n");
}

// fill array randomly with 1 or 0
void randomize(int *ray, int length){
    for(int i=0; i < length; i++) {
        if((rand() % 2) == 1){
            ray[i] = 1;
        } else {
            ray[i] = 0;
        }
    }
    printf("\n");
}

// apply rule and print symbol accordingly
int map(int a, int b, int c, int *rule){
    int index = a*4 + b*2 + c;
    if(rule[index] == 1){
        printf("▓");
        return 1;
    } else {
        printf("░");
        return 0;
    }
}

int main() {
    // Get size of grid
    int size;
    printf("Enter size:");
    scanf("%d", &size);

    // get number of steps
    int steps;
    printf("Enter steps:");
    scanf("%d", &steps);

    // get random seed
    int ray[size];
    randomize(ray, size);

    // get a random rule
    int rule[8];
    randomize(rule, 8);
    
    while(steps != 0){
        for(int i=0; i < size; i++) {
            /* 
                if first element then take first 3 elements
                if last element then take last 3 elements
                for all other take current, last, and nect elemnt
                used for index of rule array to generate next line
            */
            if(i == 0){
                ray[i] = map(ray[i], ray[i+1], ray[i+2], rule);
            } else if(i == (size - 1)){
                ray[i] = map(ray[i-2], ray[i-1], ray[i], rule);
            } else {
                ray[i] = map(ray[i-1], ray[i], ray[i+1], rule);
            }
        }
        steps--;
        printf("\n");
    }
    printf("\n");
    return 0;
}