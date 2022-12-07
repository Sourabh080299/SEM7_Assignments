int res =1;
proctype fac(int n){
    if
        :: (n == 1) -> printf("--> Factorial of 6 is %d\n",res)
        :: (n >= 2) -> res = res *n; run fac(n-1)
    fi
} 
init{
    run fac(6);
}