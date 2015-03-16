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
    // insert code here...

    int value = 0;
    
    printf("type a number: ");
    scanf("%d", &value);
    
    if (value < 0) {
        value *= -1;
        printf("minus ");
    }
    if (value == 0) {
        printf("%s", unit_given_index(0));
    } else if (value < 1000) {
        print_string_number(value);
    } else{
        int thousands = value / 1000;
        int remainder = value % 1000;
        
        if  (thousands % 1000 == 0){
            printf("%s million", unit_given_index(1));
        } else{
            print_string_number(thousands);
            printf(" thousand ");
            if (remainder < 100 && remainder > 0){
                printf("and ");
            }
            print_string_number(remainder);
        }
    }
    printf("\n");
    
    return EXIT_SUCCESS;
}

void print_string_number(int value){
    while (value>0) {
        int remainder=0;
        if (value < 10) {
            printf("%s", unit_given_index(value));
        } else if (value < 20){
            int mod = value % 10;
            printf("%s", teens_given_index(mod));
        } else if (value < 100){
            remainder = value % 10;
            int tens = value / 10;
            printf("%s ", tens_given_index(tens));
        }else if (value < 1000) {
            int hundreds = value / 100;
            printf("%s hundred", unit_given_index(hundreds));
            remainder = value % 100;
            if (remainder != 0){
                printf(" and ");
            }
        }
        value = remainder;
    }
}

char* unit_given_index(int index){
    char *str[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    
    return str[index];
}

char* teens_given_index(int index){
    
    char *str[10] = {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
    
    return str[index];
}

char* tens_given_index(int index){
    index -= 2;
    char *str[9] = {"twenty", "thirty", "fourty", "fifty", "sixty", "seventy", "eighty", "ninety"};
    
    return str[index];
}