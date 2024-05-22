int getSum(int a, int b) {
    unsigned carry = 1;
    while(carry){
        carry = a & b;
        a = a ^ b;
        b = carry << 1;
    }

    return a;
}