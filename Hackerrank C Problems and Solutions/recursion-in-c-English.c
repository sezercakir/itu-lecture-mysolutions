#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int find_nth_term(int n, int a, int b, int c) {
    int *array = malloc(n * sizeof(int));
    array[0]=a;array[1]=b;array[2]=c;
    for (int i = 3; i < n; i++)
    {
        array[i] = array[i-1]+array[i-2]+array[i-3];
    }
    int sum = array[n-1]+array[n-2]+array[n-3];
    return sum;
}
int main() {
    int n, a, b, c;
  
    scanf("%d %d %d %d", &n, &a, &b, &c);
    int ans = find_nth_term(n, a, b, c);
    
    printf("%d", ans); 
    return 0;
}
