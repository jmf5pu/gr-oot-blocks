/* -*- c++ -*- */
/*
 * Copyright 2026 Justin Fabrizio.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef INCLUDED_JFAB_OOT_BLOCKS_REPEATABLEHEAD_H
#define INCLUDED_JFAB_OOT_BLOCKS_REPEATABLEHEAD_H

#include <gnuradio/jfab_oot_blocks/api.h>
#include <gnuradio/sync_block.h>
#include <cstddef>
#include <memory>

namespace gr {
namespace jfab_oot_blocks {

/*!
 * \brief <+description of block+>
 * \ingroup jfab_oot_blocks
 *
 */
class JFAB_OOT_BLOCKS_API repeatableHead : virtual public gr::sync_block
{
public:
    typedef std::shared_ptr<repeatableHead> sptr;

    static sptr make(size_t sizeof_stream_item, uint64_t nitems);

    virtual void increase(uint64_t nitems) = 0;
};

} // namespace jfab_oot_blocks
} // namespace gr

#endif /* INCLUDED_JFAB_OOT_BLOCKS_REPEATABLEHEAD_H */