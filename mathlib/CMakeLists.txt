aux_source_directory(. MATH_LIB_FILES)

message("All Source Files:" ${MATH_LIB_FILES})

add_library(ZMathLib STATIC ${MATH_LIB_FILES})

set_target_properties(ZMathLib PROPERTIES VERSION 0.1 SOVERSION 0.1)