find_package(PkgConfig)

PKG_CHECK_MODULES(PC_GR_JFAB_OOT_BLOCKS gnuradio-jfab_oot_blocks)

FIND_PATH(
    GR_JFAB_OOT_BLOCKS_INCLUDE_DIRS
    NAMES gnuradio/jfab_oot_blocks/api.h
    HINTS $ENV{JFAB_OOT_BLOCKS_DIR}/include
        ${PC_JFAB_OOT_BLOCKS_INCLUDEDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/include
          /usr/local/include
          /usr/include
)

FIND_LIBRARY(
    GR_JFAB_OOT_BLOCKS_LIBRARIES
    NAMES gnuradio-jfab_oot_blocks
    HINTS $ENV{JFAB_OOT_BLOCKS_DIR}/lib
        ${PC_JFAB_OOT_BLOCKS_LIBDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/lib
          ${CMAKE_INSTALL_PREFIX}/lib64
          /usr/local/lib
          /usr/local/lib64
          /usr/lib
          /usr/lib64
          )

include("${CMAKE_CURRENT_LIST_DIR}/gnuradio-jfab_oot_blocksTarget.cmake")

INCLUDE(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(GR_JFAB_OOT_BLOCKS DEFAULT_MSG GR_JFAB_OOT_BLOCKS_LIBRARIES GR_JFAB_OOT_BLOCKS_INCLUDE_DIRS)
MARK_AS_ADVANCED(GR_JFAB_OOT_BLOCKS_LIBRARIES GR_JFAB_OOT_BLOCKS_INCLUDE_DIRS)
