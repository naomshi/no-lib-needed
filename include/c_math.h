long long int pow(int base, int pow){
    long long int result = 1;

    for(int i = 1; i < pow; i++){
        result = result * base;
    }

    return result;
}