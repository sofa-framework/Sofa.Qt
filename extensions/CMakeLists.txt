cmake_minimum_required(VERSION 3.22)

find_package(Sofa.Config)

sofa_add_subdirectory(plugin CUDA Sofa.Qt.CUDA)

