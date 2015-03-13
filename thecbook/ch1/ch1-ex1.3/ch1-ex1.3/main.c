//
//  main.c
//  ch1-ex1.3
//
//  Created by Leon Hughes on 13/03/2015.
//  Copyright (c) 2015 Leon Hughes. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

// prototype for function

int integer_from_getchar();

// main function

int main(void){
    
    // output instructions to user
    printf("type a string: ");
    
    // get total using getchar function
    int total = integer_from_getchar();
    
    // print total found
    printf("integer total from getchar(): %d\n", total);
    
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
        // add character value to
        output += (ch - '0');
        // get next character
        ch = getchar();
    }
    
    return output;
}