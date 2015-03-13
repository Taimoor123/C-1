//
//  main.c
//  ch1-ex1
//
//  Created by Leon Hughes on 09/03/2015.
//  Copyright (c) 2015 Leon Hughes. All rights reserved.
//

/*
 
 exercise 1.1
 Type in and test Example 1.1 on your system.
 
 */


// preprocessor statement
// line replaced with contents of stdio.h

#include <stdio.h>

/*
 * Tell the compiler that we intend
 * to use a function called show_message.
 * It has no arguments and returns no value
 * This is the "declaration".
 *
 */

void show_message(void);
/*
 * Another function, but this includes the body of
 * the function. This is a "definition".
 */
int main(void){
    int count;
    
    count = 0;
    while(count < 10){
        show_message();
        count = count + 1;
    }
    
    return 0;
}

/*
 * The body of the simple function.
 * This is now a "definition".
 */
void show_message(void){
    printf("hello\n");
}
