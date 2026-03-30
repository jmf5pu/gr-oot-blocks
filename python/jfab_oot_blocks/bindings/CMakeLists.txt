# Copyright 2020 Free Software Foundation, Inc.
#
# This file is part of GNU Radio
#
# SPDX-License-Identifier: GPL-3.0-or-later
#

########################################################################
# Check if there is C++ code at all
########################################################################
if(NOT jfab_oot_blocks_sources)
    message(STATUS "No C++ sources... skipping python bindings")
    return()
endif(NOT jfab_oot_blocks_sources)

########################################################################
# Check for pygccxml
########################################################################
gr_python_check_module_raw("pygccxml" "import pygccxml" PYGCCXML_FOUND)

include(GrPybind)

########################################################################
# Python Bindings
########################################################################

list(APPEND jfab_oot_blocks_python_files
    repeatableHead_python.cc python_bindings.cc)

gr_pybind_make_oot(jfab_oot_blocks ../../.. gr::jfab_oot_blocks "${jfab_oot_blocks_python_files}")

# copy bindings extension for use in QA test module
add_custom_command(
    TARGET jfab_oot_blocks_python
    POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:jfab_oot_blocks_python>
            ${PROJECT_BINARY_DIR}/test_modules/gnuradio/jfab_oot_blocks/)

install(
    TARGETS jfab_oot_blocks_python
    DESTINATION ${GR_PYTHON_DIR}/gnuradio/jfab_oot_blocks
    COMPONENT pythonapi)
