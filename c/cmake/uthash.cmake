cmake_minimum_required(VERSION 3.20)

project(uthash-download)

include(ExternalProject)
ExternalProject_Add(
        uthash
        GIT_REPOSITORY https://github.com/troydhanson/uthash.git
        SOURCE_DIR "${CMAKE_BINARY_DIR}/uthash-src"
        CONFIGURE_COMMAND ""
        BUILD_COMMAND ""
        INSTALL_COMMAND ""
)