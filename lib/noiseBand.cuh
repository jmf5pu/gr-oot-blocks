#pragma once

#include <cstdint>
#include <vector>
#include <curand_kernel.h>

namespace noise_band_kernel {

void kernel_setup(curandState** states, const int num_samples, const int blocks, const int tpb, const int seed); 

void kernel_work(std::vector<void *>& output_items, curandState** states, const int num_samples, float ampl);

__global__ void init_curand(curandState* states, const int num_samples, uint64_t seed);

__global__ void generate_noise(float2* output_items, curandState* states, const int num_samples, float ampl);

__global__ void destruct_curand();

}