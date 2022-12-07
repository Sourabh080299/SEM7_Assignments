proctype gcd(int a; int b){
    if
        :: (b == 0) -> printf("--> GCD of 4 & 16 is %d\n", a)
        :: (b != 0) -> run gcd(b, a%b)
    fi
} 
init{
    run gcd(4,16);
}