# Automatically generated by scripts/boost/generate-ports.ps1

vcpkg_from_github(
    OUT_SOURCE_PATH SOURCE_PATH
    REPO boostorg/compat
    REF boost-1.83.0
    SHA512 4eb3d73e278da881967d9408822cb6d8a54b98ab7bfe278eed94189a3ff6b1b3987b5317f9765ce2b16b4c0cb75af5755bdb0850a053fa0ccec3e942e67a9347
    HEAD_REF master
)

include(${CURRENT_INSTALLED_DIR}/share/boost-vcpkg-helpers/boost-modular-headers.cmake)
boost_modular_headers(SOURCE_PATH ${SOURCE_PATH})
