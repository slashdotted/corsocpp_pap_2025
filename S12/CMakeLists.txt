set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(S12static staticcast.cpp)
add_executable(S12dynamic dynamiccast.cpp)
add_executable(S12const constcast.cpp)
