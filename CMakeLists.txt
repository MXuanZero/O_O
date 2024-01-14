cmake_minimum_required(VERSION 3.26)
project(O_O)

set(CMAKE_CXX_STANDARD 17)

add_definitions(-DU8G2_SDL_COLOR_TYPE=0)

include_directories(
        E:\\Libraries\\C\\SDL2\\2_28_4\\x86_64-w64-mingw32\\include
        include
        3rdparty/u8g2/cppsrc
        3rdparty/u8g2/csrc
)

# O_O source
file(GLOB_RECURSE OO_SRCS
        "src/*.*"
        "prot/*.*"
)

# 3rdparty source
file(GLOB_RECURSE U8G2_SRCS
        "3rdparty/u8g2/cppsrc/*.*"
        "3rdparty/u8g2/csrc/*.*"
        "3rdparty/u8g2/sys/sdl/common/*.*"
#         "3rdparty/u8g2/sys/sdl/text_full_buffer/*.*"
)
set(THIRD_PARTY_SRCS ${U8G2_SRCS})

link_directories(
        E:\\Libraries\\C\\SDL2\\2_28_4\\x86_64-w64-mingw32\\bin
)

set(SOURCES ${OO_SRCS} ${THIRD_PARTY_SRCS})

add_executable(
        ${PROJECT_NAME}
        ${SOURCES}
)

target_link_libraries(
        ${PROJECT_NAME}
        SDL2.dll
)