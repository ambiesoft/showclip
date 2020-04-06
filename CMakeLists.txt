cmake_minimum_required(VERSION 3.17)

# set the project name
project(showclip VERSION 1.0.1)

# add the executable
add_executable(showclip showclip.cc ../lsMisc/GetClipboardText.cpp ../lsMisc/UTF16toUTF8.cpp ../lsMisc/UrlEncode.cpp)

# include dir
include_directories(.)

# define
add_definitions(-DUNICODE -D_UNICODE)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

#static
set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++")
