#include <stdio.h>
#include <stdlib.h>

/*
Q2) Implemente um programa que, infinitamente, receba, como parâmetro de entrada, um número
n e retorne os n primeiros números primos existentes. Seu programa para quando n for menor ou
igual a zero.
*/

// Verifica se um determinado numero n é primo.
// Ou seja, ao encontrar qualquer divisor que não seja 1 ou n então é primo.
int is_prime(int n) {
  if(n < 2) return 0;
  
  for(int i = 2; i < n; i++) {
    if(n % i == 0) return 0;
  }
  return 1;
}

// Exibe os n primeiros números primos existente.
void show_n_primes(int n) {
  printf("Os %d primeiros primos são: \n", n);

  int count = 0;
  for(int i = 2; count < n; i++) {
    if(is_prime(i)) {
      printf(" %d ", i);
      count++;
    }
  }
  printf("\n");
}

int main () {

  int n;
  do {
    printf("Informe um numero positivo N (negativo para sair): ");
    scanf("%d",&n);
    if(n < 0) break; 
    show_n_primes(n);
  } while (1);

  printf("\n");
  return 0;
}
