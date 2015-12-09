set(target ${MP2_LIBRARY})

file(GLOB hdrs "*.hpp*" "${MP2_INCLUDE}/*.hpp*")
file(GLOB srcs "*.cpp")

add_library(${target} STATIC ${srcs} ${hdrs})
target_link_libraries(${target} ${LIBRARY_DEPS})
