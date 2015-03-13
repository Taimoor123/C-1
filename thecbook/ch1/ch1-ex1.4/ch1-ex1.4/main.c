//
//  main.c
//  ch1-ex1.4
//
//  Created by Leon Hughes on 13/03/2015.
//  Copyright (c) 2015 Leon Hughes. All rights reserved.
//

/*
 
exercise 1.4
Use the function that you just wrote to read a sequence of numbers. Put them into an array declared in main, by repeatedly calling the function. Sort them into ascending numerical order, then print the sorted list.
 
*/

#include <stdio.h>
#include <stdlib.h>

// define array size
#define ARSIZE 5

// use function from exercise 1.3
int integer_from_getchar();

int main(void){
    
    // setup array, indexes
    int ch_arr[ARSIZE];
    int index, index2 = 0;
    
    // ask for number, put in array
    while ( index < ARSIZE ){
        // output instructions to user
        printf("type a string: ");
        
        // get total using getchar function
        ch_arr[index] = integer_from_getchar();
        
        // increment index
        index++;
    }
    
    // reset index
    index = 0;
    
    // bubble sort algorithm
    // iterate through array
    while( index < ARSIZE ){
        // set index2 to one above index
        index2 = index+1;
        // iterate thtough rest of array
        while ( index2 < ARSIZE ) {
            // if value at index > value at index 2
            if (ch_arr[index] > ch_arr[index2]) {
                // setup temporary value
                int temp = ch_arr[index];
                // swap values
                ch_arr[index] = ch_arr[index2];
                ch_arr[index2] = temp;
            }
            // increment index2
            index2++;
        }
        // inccrement index
        index++;
    }
    
    // reset index
    index=0;
    
    // for each value in index, o/p to screen
    while (index < ARSIZE ) {
        printf("ch_arr[%d]: %d\n", index, ch_arr[index]);
        index++;
    }
    
    return EXIT_SUCCESS;
}

// gets integer value from getchar() function

int integer_from_getchar(){
    
    
    // declare character and output
    int ch, output;
    
    // set output = 0
    output = 0;
    
    // get character
    ch = getchar();
    
    // while not end of line
    while (ch != '\n'){
        // multiply o/p by 10
        output *= 10;
        // add character value to output
        output += (ch - '0');
        // get next character
        ch = getchar();
    }
    
    return output;
}