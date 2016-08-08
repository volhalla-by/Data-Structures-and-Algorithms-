/*Partial Sum of Fibonacci Numbers
Now, we would like to find the last digit of a partial sum of Fibonacci numbers: 𝐹𝑚 + 𝐹𝑚+1 + · · · + 𝐹𝑛.
Task.. Given two non-negative integers 𝑚 and 𝑛, where 𝑚 ≤ 𝑛, find the last digit of the sum 𝐹𝑚 + 𝐹𝑚+1 +
· · · + 𝐹𝑛.
Input Format. The input consists of two non-negative integers 𝑚 and 𝑛 separated by a space.
Constraints. 0 ≤ m ≤ 𝑛 ≤ 10^18
Output Format.Output the last digit of 𝐹𝑚 + 𝐹𝑚+1 + · · · + 𝐹𝑛.
Time limit: 1 sec
Memory limit: 512 MB
Results: max time used: 0.00/1.00, max memory used: 8572928/536870912
*/

#include <iostream>
long long fib_mod(long long num, long long m);
long long get_fibonaccihuge(long long n, long long m);
long long get_fibonacci_partial_sum(long long n, long long m);

int main() {
	long long from, to;
	std::cin >> from >> to;
	std::cout << get_fibonacci_partial_sum(from, to) << '\n';
}

long long get_fibonaccihuge(long long n, long long m) {
	long long first = 0 % m, second = 1 % m, temp;
	long long period, rest;
	for (long long k = 1; k <= m*m - 1; k++) {
		temp = first;
		first = second;
		second = (temp + first) % m;
		period = k;
		if (first == 0 && second == 1) break;
	}
	rest = n;
	while (rest >= period) {
		rest %= period;
	}
	long long res = fib_mod(rest, m);
	return res;
}

long long fib_mod(long long num, long long m)
{
	long long a = 1, b = 1, c = 1, d = 0, 
		ta, tb, 
		rc = 0 % m, tc,rd = 1 % m;

	while (num)
	{
		if (num & 1)
		{
			tc = rc;
			rc = (rc*a + rd*c) % m;
			rd = (tc*b + rd*d) % m;
		}

		ta = a; tb = b; tc = c;
		a = (a*a + b*c) % m;
		b = (ta*b + b*d) % m;
		c = (c*ta + d*c) % m;
		d = (tc*tb + d*d) % m;

		num >>= 1;

	}

	return rc;
}

long long get_fibonacci_partial_sum(long long m, long long n) {
	if (n == m) return get_fibonaccihuge(n, 10);
	long long num_n = n + 2, num_m = m + 1;
	int fib_n = get_fibonaccihuge(num_n, 10);
	int fib_m = get_fibonaccihuge(num_m, 10);
	if (fib_n == 0) fib_n = 9;
	else fib_n = fib_n - 1;
	if (fib_m == 0) fib_m = 9;
	else fib_m = fib_m - 1;
	if (fib_m > fib_n) return fib_n + 10 - fib_m;
	else return fib_n - fib_m;
}

