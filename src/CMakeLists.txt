set(SOURCE_FILES
        generate_matrix.cpp read_HPC_row.cpp compute_residual.cpp mytimer.cpp
        dump_matlab_matrix.cpp HPC_sparsemv.cpp HPCCG.cpp waxpby.cpp ddot.cpp
        make_local_matrix.cpp exchange_externals.cpp YAML_Element.cpp YAML_Doc.cpp
)


add_library (HPCCG ${SOURCE_FILES})
add_executable (test_HPCCG main.cpp)
target_link_libraries (test_HPCCG HPCCG)
