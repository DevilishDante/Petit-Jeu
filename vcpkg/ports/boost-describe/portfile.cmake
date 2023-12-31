# Automatically generated by scripts/boost/generate-ports.ps1

vcpkg_from_github(
    OUT_SOURCE_PATH SOURCE_PATH
    REPO boostorg/describe
    REF boost-1.83.0
    SHA512 652972000916ce99a54dc8aa6fe5507c8ea04aba9ff9624cdfdfe89e6f0e9aae19c84b08381066a411bf851239dc9c585205df64a72f57f56e52f2f02e1ce6ad
    HEAD_REF master
)

include(${CURRENT_INSTALLED_DIR}/share/boost-vcpkg-helpers/boost-modular-headers.cmake)
boost_modular_headers(SOURCE_PATH ${SOURCE_PATH})
