cmake_minimum_required(VERSION 3.1 FATAL_ERROR)
project(Project2)

# TODO: switch to COMPONENTS

# Configure the project
# =====================
set(CMAKE_CXX_STANDARD 11)
include(GNUInstallDirs)
include(CMakePackageConfigHelpers)
option(BUILD_SHARED_LIBS ON)
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

# Build libraries
# ===============
add_subdirectory(Lib2)
add_subdirectory(Lib3)

# Build the executables
# ====================
add_executable(Main2 main2.cpp)
target_link_libraries(Main2 Lib3)
