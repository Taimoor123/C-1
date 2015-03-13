//
//  main.c
//  ch1-ex1.2
//
//  Created by Leon Hughes on 12/03/2015.
//  Copyright (c) 2015 Leon Hughes. All rights reserved.
//

/*
 
 exercise 1.2
 Using Example 1.2 as a pattern, write a program that prints prime pairs
 - a pair of prime numbers that differ by 2, for example 11 and 13, 29 and 31.
 
 */

/*
 *
 * Dumb program that generates prime numbers.
 */
#include <stdio.h>
#include <stdlib.h>

int main(void){
    // added previous prime
    int this_number, divisor, not_prime, previous_prime;
    
    this_number = 3;
    
    // set previous prime to 0
    previous_prime = 0;
    
    while(this_number < 10000){
        divisor = this_number / 2;
        not_prime = 0;
        while(divisor > 1){
            if(this_number % divisor == 0){
                not_prime = 1;
                divisor = 0;
            }
            else
                divisor = divisor-1;
        }
        
        
        if(not_prime == 0){
            printf("%d is a prime number\n", this_number);
            // if difference between this_number and previous_prime is 2
            // output text
            if (this_number - previous_prime == 2){
                printf("%d and %d are prime numbers with difference 2\n", previous_prime, this_number);
            }
            // set previous_prime value to this_number
            previous_prime=this_number;
        }
        this_number = this_number + 1;
    }
    exit(EXIT_SUCCESS);
}

