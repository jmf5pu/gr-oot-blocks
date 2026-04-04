/* -*- c++ -*- */
/*
 * Copyright 2026 Justin Fabrizio.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef INCLUDED_JFAB_OOT_BLOCKS_NOISEBANDCUDA_H
#define INCLUDED_JFAB_OOT_BLOCKS_NOISEBANDCUDA_H

#include <gnuradio/jfab_oot_blocks/api.h>
#include <gnuradio/sync_block.h>

namespace gr {
namespace jfab_oot_blocks {

/*!
 * \brief <+description of block+>
 * \ingroup jfab_oot_blocks
 *
 */
class JFAB_OOT_BLOCKS_API noiseBandCuda : virtual public gr::sync_block
{
public:
    typedef std::shared_ptr<noiseBandCuda> sptr;

    /*!
     * \brief Return a shared_ptr to a new instance of jfab_oot_blocks::noiseBandCuda.
     *
     * To avoid accidental use of raw pointers, jfab_oot_blocks::noiseBandCuda's
     * constructor is in a private implementation
     * class. jfab_oot_blocks::noiseBandCuda::make is the public interface for
     * creating new instances.
     */
    static sptr make(float ampl, uint64_t seed = 0);
};

} // namespace jfab_oot_blocks
} // namespace gr

#endif /* INCLUDED_JFAB_OOT_BLOCKS_NOISEBANDCUDA_H */
