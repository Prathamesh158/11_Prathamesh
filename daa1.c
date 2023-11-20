#include <stdio.h>
int fibonacciNonRecursive(int n) 
{
    int a = 0, b = 1, next, i;
    if (n <= 1)
    {
        return n;
    }
    for (i = 2; i <= n; i++) 
    {
        next = a + b;
        a = b;
        b = next;
    }
    return b;
}
int fibonacciRecursive(int n) 
{
    if (n <= 1)
    {
        return n;
    }
    return fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2);
}
int main() 
{
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);
    printf("Fibonacci(%d) (Non-Recursive) = %d\n", n, fibonacciNonRecursive(n));
    printf("Fibonacci(%d) (Recursive) = %d\n", n, fibonacciRecursive(n));
    return 0;
}