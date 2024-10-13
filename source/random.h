#ifndef RANDOM_H_
#define RANDOM_H_

#include <stdio.h>
#include <stdint.h>

// Define the Xorshift state
typedef struct {
  uint32_t state;
} Xorshift;

// Initialize the generator with a non-zero seed
inline void xorshift_init(Xorshift *generator, uint32_t seed) {
  if (seed == 0) {
    seed = 1; // Xorshift cannot have a seed of 0
  }
  generator->state = seed;
}

// Generate the next random number
inline uint32_t xorshift_next(Xorshift *generator) {
  uint32_t x = generator->state;
  x ^= x << 13;
  x ^= x >> 17;
  x ^= x << 5;
  generator->state = x;
  return x;
}

// Generate a random number within a specified range [min, max]
inline uint32_t xorshift_range(Xorshift *generator, uint32_t min, uint32_t max) {
  uint32_t rand = xorshift_next(generator);
  return min + (rand % (max - min + 1));
}

#endif // RANDOM_H_
