cmake_minimum_required(VERSION 3.1 FATAL_ERROR)
project(Project1)

# Configure the project
# =====================
set(CMAKE_CXX_STANDARD 11)
include(GNUInstallDirs)
include(CMakePackageConfigHelpers)
option(BUILD_SHARED_LIBS ON)
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

# Build libraries
# ===============
add_subdirectory(Lib1)

# Build the executables
# =====================
add_executable(Main1 main1.cpp)
target_link_libraries(Main1 Lib1)
