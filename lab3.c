#include <stdio.h>
#include <omp.h>
int fib(int n) {
int x, y;
if (n < 2)
return n;
x = fib(n - 1);
y = fib(n - 2);

return x + y;
}
int main() {
int n;
printf("Enter n: ");
scanf("%d", &n);
int result;

{

result = fib(n);
}
printf("Fibonacci(%d) = %d\n", n, result);
return 0;
}