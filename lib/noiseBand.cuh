#pragma once

#include <cstdint>
#include <vector>
#include <curand_kernel.h>

namespace noise_band_kernel {

void setup(curandState** states, const int num_samples, const int blocks, const int tpb, const int seed); 

void work(std::vector<void *>& output_items, curandState** states,  const int blocks, const int tpb, const int num_samples, float ampl);

void cleanup(curandState** states);

__global__ void init_curand(curandState* states, const int num_samples, uint64_t seed);

__global__ void generate_noise(float2* output_items, curandState* states, const int num_samples, float ampl);

}