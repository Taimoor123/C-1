//
//  main.c
//  ch1-ex1.5
//
//  Created by Leon Hughes on 13/03/2015.
//  Copyright (c) 2015 Leon Hughes. All rights reserved.
//

/*
 
exercise 1.5
Again using the function from Exercise 1.3, write a program that will read numbers from its input,
 then print them out in binary, decimal and hexadecimal form.
 
*/

#include <stdio.h>
#include <stdlib.h>

// prototypes
int integer_from_getchar();
void hex_from_int(int int_value);
void bin_from_int(int int_value);

int main(void) {
    
    // output instructions to user
    printf("type a string: ");
    
    // get int value from getchar()
    int int_value = integer_from_getchar();
    
    // convert to hex
    hex_from_int(int_value);
    // convert to binary
    bin_from_int(int_value);
    
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

// convert int to binary
void bin_from_int(int int_value){
    // setup output and offset
    int bin_value=0;
    int offset=1;
    // while int value > 0
    while (int_value > 0){
        // get modulus of int value and 2
        int bit = int_value % 2;
        // divide int value by 2
        int_value /= 2;
        // multiply current binary value by offset
        bin_value += bit*offset;
        // multiply offset by 10
        offset *= 10;
    }
    // o/p binary value
    printf("binary: %d", bin_value);
}

// define max digit value
#define MAXDIG 32

// get hex value from int
void hex_from_int(int int_value){
    // setup array and index
    char hex_string[MAXDIG];
    int index = 0;
    
    // o/p to user
    printf("%d in hex: ", int_value);
    
    // while int_value > 0
    while (int_value > 0){
        // get int value modulus 16
        hex_string[index] = int_value % 16;
        // divide int value by 16
        int_value /= 16;
        // increment index
        index++;
    }
    
    // decrement index by 1
    index--;
    
    // while index >= 0
    while (index>=0) {
        // find a - f if hex_string[index] >= 10
        if (hex_string[index] >= 10) {
            hex_string[index] = hex_string[index]-10+'A';
            // o/p to user
            printf("%c", hex_string[index]);
        } else{
            // o/p normal digit
            printf("%d", hex_string[index]);
        }
        // decrement index
        index--;
    }
    // print new line
    printf("\n");
}