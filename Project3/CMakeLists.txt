cmake_minimum_required(VERSION 3.1 FATAL_ERROR)
project(Project3)

# Configure the project
# =====================
set(CMAKE_CXX_STANDARD 11)

# Import installed libraries
# ==========================
find_package(Lib1 CONFIG REQUIRED)
find_package(Lib3 CONFIG REQUIRED)

# Build the executables
# =====================
add_executable(Main3 main3.cpp)
target_link_libraries(Main3 Lib1::Lib1 Lib3::Lib3)
# ${Lib3_LIBRARY} can be used instead of Lib3::Lib3
