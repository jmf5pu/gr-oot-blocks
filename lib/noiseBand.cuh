#include <curand_kernel.h>

namespace noise_band_kernel {

void kernel_setup(curandState* states, const int blocks, const int tpb, const int seed); 

__global__ void init_curand(uint64_t seed);

__global__ void generate_noise(std::vector<void *>& output_items, float ampl);

__global__ void destruct_curand();

}