/* -*- c++ -*- */
/*
 * Copyright 2026 Justin Fabrizio.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include "noiseBandCuda_impl.h"
#include <gnuradio/io_signature.h>

namespace gr {
namespace jfab_oot_blocks {

#pragma message("set the following appropriately and remove this warning")
using output_type = float;
noiseBandCuda::sptr noiseBandCuda::make(float ampl, uint64_t seed)
{
    return gnuradio::make_block_sptr<noiseBandCuda_impl>(ampl, seed);
}


/*
 * The private constructor
 */
noiseBandCuda_impl::noiseBandCuda_impl(float ampl, uint64_t seed)
    : gr::sync_block("noiseBandCuda",
                     gr::io_signature::make(0, 0, 0),
                     gr::io_signature::make(
                         1 /* min outputs */, 1 /*max outputs */, sizeof(output_type)))
{
}

/*
 * Our virtual destructor.
 */
noiseBandCuda_impl::~noiseBandCuda_impl() {}

int noiseBandCuda_impl::work(int noutput_items,
                             gr_vector_const_void_star& input_items,
                             gr_vector_void_star& output_items)
{
    auto out = static_cast<output_type*>(output_items[0]);

#pragma message("Implement the signal processing in your block and remove this warning")
    // Do <+signal processing+>

    // Tell runtime system how many output items we produced.
    return noutput_items;
}

} /* namespace jfab_oot_blocks */
} /* namespace gr */
