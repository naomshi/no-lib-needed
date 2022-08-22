void exit(int exit_code){
    __asm__ volatile(
        "mov $60, %rax;"
        "syscall;"
    );
}