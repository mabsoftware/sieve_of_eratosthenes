#include <stdio.h>
#include <stdlib.h>

/**
 * Finds prime numbers in range [0, n - 1]
 * @param sieve array filled with zeros
 * @param n length of the sieve
 */
void sieveOfEratosthenes(int* sieve, int n) {
  if (n < 2) return; // no prime numbers below 2
  sieve[2] = 1; // we know 2 is a prime number

  for (int i = 3; i < n; i += 2) {
    sieve[i] = 1;
  } // the sieve is initially blank, but we know that evens above 2 are
    // certainly not prime numbers

  int prime = 3;

  while (1) {
    int mult = 2;
    while (mult * prime < n) {
      sieve[mult * prime] = 0;
      mult++;
    } // cross off all multiples of a prime

    int primesLeft = 0;
    for (int i = prime + 2; i < n; i+=2) {
      if (sieve[i]) {
        prime = i;
        primesLeft = 1;
        break;
      }
    } // find the next prime in the list to later cross of its multiples

    if (!primesLeft) break; // if there aren't any primes left, we are done
  }
}

int main() {
  int sieve[10000] = {0};
  sieveOfEratosthenes(sieve, 10000);
  printf("%d\n", sieve[1571]);
}
