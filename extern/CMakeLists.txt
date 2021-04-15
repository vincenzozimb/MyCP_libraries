add_library(gnuplot_i-lib STATIC
                        gnuplot_i/src/gnuplot_i.c
)

target_include_directories(gnuplot_i-lib PUBLIC
    $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>)
target_compile_options(gnuplot_i-lib PRIVATE -Wall -O3 -march=native -ffast-math -std=c11)
target_link_libraries(gnuplot_i-lib m)

target_link_libraries(gnuplot_i-lib gnuplot_i)

# Collect header files in include dir for installation
#file(GLOB_RECURSE INCLUDE_FILES "${PROJECT_SOURCE_DIR}/include/*.h")
#set_target_properties(gnuplot_i-lib PROPERTIES PUBLIC_HEADER "${INCLUDE_FILES}")

#include(GNUInstallDirs)
set(CMAKE_INSTALL_LIBDIR $ENV{HOME}/.local)
install( 
    TARGETS gnuplot_i-lib
    EXPORT GnuPlotLibTargets
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}/lib
    PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_LIBDIR}/include
)

install(
    DIRECTORY ${PROJECT_SOURCE_DIR}/include
    DESTINATION ${CMAKE_INSTALL_LIBDIR}
    FILES_MATCHING PATTERN "*.h"
)

install(
    EXPORT GnuPlotLibTargets
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/GnuPlotLib
)

include(CMakePackageConfigHelpers)
configure_package_config_file( 
    "Config.cmake.in" 
    "GnuPlotLibConfig.cmake"
    INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/GnuPlotLib
    PATH_VARS
    CMAKE_INSTALL_LIBDIR
)

write_basic_package_version_file(
    ${CMAKE_CURRENT_BINARY_DIR}/GnuPlotLibConfigVersion.cmake
    VERSION 1.0.0
    COMPATIBILITY SameMajorVersion
)

### Install Config and ConfigVersion files
install(
    FILES "${CMAKE_CURRENT_BINARY_DIR}/GnuPlotLibConfig.cmake"
        "${CMAKE_CURRENT_BINARY_DIR}/GnuPlotLibConfigVersion.cmake"
    DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/GnuPlotLib"
)