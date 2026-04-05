/* -*- c++ -*- */
/*
 * Copyright 2026 Justin Fabrizio.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#pragma once

#include <gnuradio/jfab_oot_blocks/repeatableHead.h>

namespace gr {
namespace jfab_oot_blocks {

class repeatableHead_impl : public repeatableHead
{
private:
    uint64_t d_nitems;
    uint64_t d_ncopied_items;

public:
    repeatableHead_impl(size_t sizeof_stream_item, uint64_t nitems);
    ~repeatableHead_impl() override;

    /**
    @brief increases the size of the head block, allowing more items to pass
    @param nitems the amount of items to increase the head size by
    */
    void increase(uint64_t nitems) override {
        // set remaining items to current remaining plus the additional requested size
        d_nitems = (d_nitems - d_ncopied_items) + nitems;
        
        // reset copy counter
        d_ncopied_items = 0;
    }

    int work(int noutput_items,
             gr_vector_const_void_star& input_items,
             gr_vector_void_star& output_items) override;
};

} // namespace jfab_oot_blocks
} // namespace gr
