set(program_name dark)
if(CMAKE_HOST_WIN32)
    set(tool_subdirectory "wix311-binaries")
    set(paths_to_search "${DOWNLOADS}/tools/dark/${tool_subdirectory}")
    set(download_urls "https://github.com/wixtoolset/wix3/releases/download/wix311rtm/wix311-binaries.zip")
    set(download_filename "wix311-binaries.zip")
    set(download_sha512 74f0fa29b5991ca655e34a9d1000d47d4272e071113fada86727ee943d913177ae96dc3d435eaf494d2158f37560cd4c2c5274176946ebdb17bf2354ced1c516)
endif()
