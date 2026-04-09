/* -*- c++ -*- */
/*
 * Copyright 2026 Justin Fabrizio.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#pragma once

#include <gnuradio/jfab_oot_blocks/noiseBandCuda.h>
#include <curand_kernel.h>
#include "noiseBand.cuh"

namespace gr {
namespace jfab_oot_blocks {

class noiseBandCuda_impl : public noiseBandCuda
{
private:
    float _ampl{1.0};
    int _num_samples{8192};
    int _tpb{256};
    int _blocks{(_num_samples + _tpb - 1) / _tpb};
    curandState* _states;

public:
    noiseBandCuda_impl(float ampl, uint64_t seed);
    ~noiseBandCuda_impl();

    // Where all the action really happens
    int work(int noutput_items,
             gr_vector_const_void_star& input_items,
             gr_vector_void_star& output_items);
};

} // namespace jfab_oot_blocks
} // namespace gr
