#include "noiseBand.cuh"
#include <curand_kernel.h>
#include <curand.h>

namespace noise_band_kernel {


void kernel_setup(curandState* states, const int blocks, const int tpb, const int seed) {
    size_t states_size = (blocks * tpb) * sizeof(curandState);

    cudaError_t err = cudaMalloc((void**)&states, states_size);

    if(err != cudaSuccess) {
        printf("Failed to allocate device memory: %s\n", cudaGetErrorString(err));
        return -1;
    }
    noise_band_kernel::init_curand(seed);
}

__global__ void init_curand(uint64_t seed) {

}

__global__ void generate_noise(std::vector<void *>& output_items, float ampl) {

}

__global__ void destruct_curand() {

}

}