#include "noiseBand.cuh"

#include <cstdint>
#include <vector>

#include <curand_kernel.h>
#include <curand.h>

#include "gpuAssert.h"

namespace noise_band_kernel {

void kernel_setup(curandState** states, const int num_samples, const int blocks, const int tpb, const int seed) {
    size_t states_size = (blocks * tpb) * sizeof(curandState);

    gpuErrchk(cudaMalloc((void**)states, states_size));
    init_curand<<<blocks, tpb>>>(*states, num_samples, seed);
    gpuErrchk(cudaPeekAtLastError());
    gpuErrchk(cudaDeviceSynchronize());
}


void kernel_work(std::vector<void *>& output_items, curandState** states, const int num_samples, float ampl) {
    generate_noise<<<blocks, tpb>>>(&output_items[0], *states, num_samples, ampl);
    gpuErrchk(cudaPeekAtLastError());
    gpuErrchk(cudaDeviceSynchronize());
}

__global__ void init_curand(curandState* states, const int num_samples, uint64_t seed) {
    const int thread_id = blockDim.x * blockIdx.x + threadIdx.x;
    if(thread_id >= num_samples) return;

    curand_init(
        seed,
        thread_id,
        0,
        states + thread_id
    );
}


__global__ void generate_noise(float2* output_items, curandState* states, const int num_samples, float ampl) {
    const int thread_id = blockDim.x * blockIdx.x + threadIdx.x;
    if(thread_id >= num_samples) return;

    // bring state to local register
    curandState state = states[thread_id];

    float2 noise = curand_normal(&state);
    
    noise.x *= ampl;
    noise.y *= ampl;

    output_items[thread_id] = noise;

    // save state back to global device memory
    states[thread_id] = state;
}


__global__ void destruct_curand() {

}

}