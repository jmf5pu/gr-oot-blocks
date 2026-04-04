/* -*- c++ -*- */
/*
 * Copyright 2026 Justin Fabrizio.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef INCLUDED_JFAB_OOT_BLOCKS_NOISEBANDCUDA_IMPL_H
#define INCLUDED_JFAB_OOT_BLOCKS_NOISEBANDCUDA_IMPL_H

#include <gnuradio/jfab_oot_blocks/noiseBandCuda.h>

namespace gr {
namespace jfab_oot_blocks {

class noiseBandCuda_impl : public noiseBandCuda
{
private:
    // Nothing to declare in this block.

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

#endif /* INCLUDED_JFAB_OOT_BLOCKS_NOISEBANDCUDA_IMPL_H */
