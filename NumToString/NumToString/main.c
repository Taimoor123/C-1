//
//  main.c
//  NumToString
//
//  Created by Leon Hughes on 16/03/2015.
//  Copyright (c) 2015 Leon Hughes. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

char* unit_given_index(int index);
char* teens_given_index(int index);
char* tens_given_index(int index);
void print_string_number(int value);

int main(void) {

    // setup variables
    int value = 0;
    
    // o/p to user
    printf("type a number: ");
    // get user i/p
    scanf("%d", &value);
    
    // negate user i/p and o/p if minus
    if (value < 0) {
        value *= -1;
        printf("minus ");
    }
    // o/p if zero
    if (value == 0) {
        printf("%s", unit_given_index(value));
    // when i/p < 1000
    } else if (value < 1000) {
        print_string_number(value);
    // when i/p > 1000
    } else{
        // get modulus and division of value
        int thousands = value / 1000;
        int remainder = value % 1000;
        
        // o/p if 1,000,000
        if  (thousands % 1000 == 0){
            printf("%s million", unit_given_index(1));
        } else{
            // o/p thousands
            print_string_number(thousands);
            
            // o/p separators
            printf(" thousand ");
            if (remainder < 100 && remainder > 0){
                printf("and ");
            }
            
            // o/p rest of value
            print_string_number(remainder);
        }
    }
    // print new line
    printf("\n");
    
    return EXIT_SUCCESS;
}

// function to calculate correct index to o/p to user

void print_string_number(int value){
    // while value > 0
    while (value>0) {
        // setup remainder
        
        int remainder=0;
        
        // when value < 10, o/p unit using value
        if (value < 10) {
            printf("%s", unit_given_index(value));
        // when value < 20, find modulus of value, o/p teens using modulus value
        } else if (value < 20){
            int mod = value % 10;
            printf("%s", teens_given_index(mod));
        // when value < 100, calculate remainder for next loop
        // calculate number of tens
        // o/p using tens as index value for array
        } else if (value < 100){
            remainder = value % 10;
            int tens = value / 10;
            printf("%s ", tens_given_index(tens));
        // when value < 1000, calculate number of hundred units
        // calculate remainder for next loop
        // o/p to user
        // check if separator required
        }else if (value < 1000) {
            int hundreds = value / 100;
            remainder = value % 100;
            printf("%s hundred", unit_given_index(hundreds));
            if (remainder != 0){
                printf(" and ");
            }
        }
        // set value to remainder
        value = remainder;
    }
}

// function to return units as string
char* unit_given_index(int index){
    char *str[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    return str[index];
}

// function to return teen units as string
char* teens_given_index(int index){
    
    char *str[10] = {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
    return str[index];
}

// function to return ten units as string
char* tens_given_index(int index){
    // recalculate index for offset incurred
    index -= 2;
    char *str[9] = {"twenty", "thirty", "fourty", "fifty", "sixty", "seventy", "eighty", "ninety"};
    return str[index];
}