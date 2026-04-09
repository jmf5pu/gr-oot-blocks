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
                     gr::io_signature::make(1, 1, sizeof(output_type))),
      _ampl(ampl),
      _num_samples(8192),
      _tpb(256)
{
    // Re-calculate blocks here to be safe
    _blocks = (_num_samples + _tpb - 1) / _tpb;

    set_min_output_buffer(8192);
    set_max_output_buffer(8192);
    
    noise_band_kernel::setup(&_states, _num_samples, _blocks, _tpb, seed);
}

noiseBandCuda_impl::~noiseBandCuda_impl() {
    noise_band_kernel::cleanup(&_states);
}

int noiseBandCuda_impl::work(int noutput_items,
                             gr_vector_const_void_star& input_items,
                             gr_vector_void_star& output_items)
{
    noise_band_kernel::work(output_items, &_states, _blocks, _tpb, _num_samples, _ampl);

    return noutput_items;
}

} /* namespace jfab_oot_blocks */
} /* namespace gr */
