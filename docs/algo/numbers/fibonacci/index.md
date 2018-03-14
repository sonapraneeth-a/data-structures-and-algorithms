# Algorithms related to Fibonacci numbers

**Source:** [Link](https://github.com/sonapraneeth-a/data-structures-and-algorithms/blob/master/Src/Algorithms/Numbers/Fibonacci.cpp)

## Recursive algorithm to get N<sup>th</sup> fibonacci number

### Details

**Time Complexity:** $O(2^N)$ where $N$ is the number which is input to the algorithm

**Space Complexity:** $O(2^N)$ where $N$ is the number which is input to the algorithm

**Explanation:**

### Pseudo code

``` cpp hl_lines="5"
Fib(N)
{
    // Fib(0) = 0
    // Fib(1) = 1
    if (N <= 1) {return N;}
    /* Recursive relation: F(N) = F(N-1) + F(N-2) */
    return Fib(N - 1) + Fib(N - 2);
}
```

!!! danger "Hanging"
    If **N** is a very large number, the recursion stack could go deep leading to hanging of the program.

## Iterative algorithm to get N<sup>th</sup> fibonacci number

### Details

**Time Complexity:** O(N) where N is the number which is input to the algorithm

**Space Complexity:** O(1)

**Explanation:**

### Pseudo code

``` cpp hl_lines="9 10 11"
Fib(N)
{
    fn_2 = 0;   // F(N-2) => Fib(0) = 0
    fn_1 = 1;   // F(N-1) => Fib(1) = 1
    fn = 0;     // F(N)
    /* Recursive relation: F(N) = F(N-1) + F(N-2) */
    ForLoop(i from 2 to N) // O(N)
    {
        fn = fn_1 + fn_2;  // O(1)
        fn_2 = fn_1;       // O(1)
        fn_1 = fn;         // O(1)
    }
    return fn;
}
```

!!! note "Best Algorithm for calculating N<sup>th</sup> fibonacci number"
    From the above discussion, it is evident that iterative version of calculating n<sup>th</sup> fibonacci number is the best.

## Fibonacci Series

### Details

**Time Complexity:** O(N) where N is the length of the series required

**Space Complexity:** O(N) where N is the length of the series required

**Explanation:**

### Pseudo code

``` cpp hl_lines="7 8 15"
FibSeries(N)
{
    series = empty;
    fn_2 = 0;   // F(N-2) => Fib(0) = 0
    fn_1 = 1;   // F(N-1) => Fib(1) = 1
    fn = 0;     // F(N)
    series.push(fn_2);
    series.push(fn_1);
    /* Recursive relation: F(N) = F(N-1) + F(N-2) */
    ForLoop(i from 2 to N) // O(N)
    {
        fn = fn_1 + fn_2;  // O(1)
        fn_2 = fn_1;       // O(1)
        fn_1 = fn;         // O(1)
        series.push(fn);
    }
    return fn;
}
```
