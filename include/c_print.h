int raw_print(int fd, char* text, int count){
    __asm__ volatile(
        "mov $1, %rax;"
        "syscall"
    );
}

int print(char* str){
    int output_fd = 1;
    int count = strlen(str);

    raw_print(output_fd, str, count);

    return;
}