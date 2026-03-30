/* -*- c++ -*- */
/*
 * Copyright 2026 Justin Fabrizio.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include "repeatableHead_impl.h"
#include <gnuradio/io_signature.h>

namespace gr {
namespace jfab_oot_blocks {

repeatableHead::sptr repeatableHead::make(size_t sizeof_stream_item, uint64_t nitems)
{
    return gnuradio::make_block_sptr<repeatableHead_impl>(sizeof_stream_item, nitems);
}


repeatableHead_impl::repeatableHead_impl(size_t sizeof_stream_item, uint64_t nitems)
    : gr::sync_block("repeatableHead",
                     gr::io_signature::make(1, 1, sizeof_stream_item),
                     gr::io_signature::make(0, 1, sizeof_stream_item)),
      d_nitems(nitems),
      d_ncopied_items(0) {}

repeatableHead_impl::~repeatableHead_impl() {}

int repeatableHead_impl::work(int noutput_items,
                              gr_vector_const_void_star& input_items,
                              gr_vector_void_star& output_items)
{
    unsigned n = std::min(d_nitems - d_ncopied_items, (uint64_t)noutput_items);

    // nothing to do - block awaiting increase or more input items
    if (d_ncopied_items >= d_nitems || n == 0) {
        return 0;
    }

    // can have zero or one output port, if zero, don't copy
    if (!output_items.empty()) {
        memcpy(output_items[0],
               input_items[0],
               n * input_signature()->sizeof_stream_item(0));
    }
    d_ncopied_items += n;

    return n;
}

} /* namespace jfab_oot_blocks */
} /* namespace gr */