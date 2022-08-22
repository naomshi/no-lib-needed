#include "c_math.h"

void raw_print(int fd, char* text, int count){
    __asm__ volatile(
        "mov $1, %rax;"
        "syscall"
    );
}

void print(char* str){
    int output_fd = 1;
    int count = strlen(str);

    raw_print(output_fd, str, count);
}

void print_num(int num){
    int working_num = num;
    int num_digits = 0;
    int ASCII_OFFSET = 0x30;

    while(working_num > 0){
        num_digits++;
        working_num = working_num / 10;
    }

    int digits[num_digits];

    for(int i = num_digits; i > 0; i--){
        long long int divisor = pow(10, i);
        long long int mask = divisor * 10;
        int raw_num = num % (mask); // grab the relevant digits
        int digit = raw_num / divisor;

        digits[num_digits - i] = digit;
    }

    int string_length = num_digits + 2;

    char printable_str[string_length];

    for(int i = 0; i < string_length; i++){
        printable_str[i] = (char)(digits[i] + ASCII_OFFSET);
    }

    printable_str[num_digits] = 10;
    printable_str[num_digits + 1] = 0;

    print(printable_str);
}