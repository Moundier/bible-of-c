#include <stdio.h>

// Define a structure to represent complex numbers
typedef struct {
  double real;
  double imag;
} Complex;

// Function to calculate i0 = (1 + i0) * i1
Complex calculate_i0(Complex i0, Complex i1) {
  Complex result;

  result.real = (1 + i0.real) * i1.real - i0.imag * i1.imag;
  result.imag = (1 + i0.real) * i1.imag + i0.imag * i1.real;

  return result;
}

int main() {

  // Example usage
  Complex i0 = {1.0, 2.0};  // Replace with actual values
  Complex i1 = {3.0, 4.0};  // Replace with actual values

  i0 = calculate_i0(i0, i1);

  printf("Result: %.2f + %.2fi\n", i0.real, i0.imag);

  return 0;
}
