/* -*- c++ -*- */
/*
 * Copyright 2026 Justin Fabrizio.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include "noiseBandCuda_impl.h"

#include <gnuradio/io_signature.h>
#include <curand.h>
#include "noiseBand.cuh"

namespace gr {
namespace jfab_oot_blocks {

using output_type = gr_complex;
noiseBandCuda::sptr noiseBandCuda::make(float ampl, uint64_t seed)
{
    return gnuradio::make_block_sptr<noiseBandCuda_impl>(ampl, seed);
}

noiseBandCuda_impl::noiseBandCuda_impl(float ampl, uint64_t seed)
    : gr::sync_block("noiseBandCuda",
                     gr::io_signature::make(0, 0, 0),
                     gr::io_signature::make(
                        _num_samples /* min outputs */,
                        _num_samples /*max outputs */,
                        sizeof(output_type))),
      _ampl(ampl)
{
    // pin output buffer size for consistency with device memory
    set_min_output_buffer(_num_samples);
    set_max_output_buffer(_num_samples);
    
    // allocate device memory
    noise_band_kernel::kernel_setup(_states, _blocks, _tpb, seed);
}

noiseBandCuda_impl::~noiseBandCuda_impl() {}

int noiseBandCuda_impl::work(int noutput_items,
                             gr_vector_const_void_star& input_items,
                             gr_vector_void_star& output_items)
{
    //noise_band_kernel::generate_noise(output_items, _ampl, _seed);

    return noutput_items;
}

} /* namespace jfab_oot_blocks */
} /* namespace gr */
