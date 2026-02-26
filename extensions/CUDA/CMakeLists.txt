cmake_minimum_required(VERSION 3.22)
project(Sofa.Qt.CUDA LANGUAGES CXX CUDA)

set(SOFAQTCUDA_SOURCE_DIR "src/sofa/qt/cuda")
set(HEADER_FILES
    ${SOFAQTCUDA_SOURCE_DIR}/init.h
    ${SOFAQTCUDA_SOURCE_DIR}/config.h.in
    ${SOFAQTCUDA_SOURCE_DIR}/CudaDataWidget.h
)

set(SOURCE_FILES
    ${SOFAQTCUDA_SOURCE_DIR}/init.cpp
    ${SOFAQTCUDA_SOURCE_DIR}/CudaDataWidget.cpp
)

sofa_find_package(Sofa.Qt REQUIRED)
sofa_find_package(SofaCUDA REQUIRED)

add_library(${PROJECT_NAME} SHARED ${HEADER_FILES} ${SOURCE_FILES})
target_link_libraries(${PROJECT_NAME} Sofa.Qt)
target_link_libraries(${PROJECT_NAME} SofaCUDA)

sofa_create_package_with_targets(
    PACKAGE_NAME ${PROJECT_NAME}
    PACKAGE_VERSION ${Sofa_VERSION}
    TARGETS ${PROJECT_NAME} AUTO_SET_TARGET_PROPERTIES
    INCLUDE_SOURCE_DIR "src"
    INCLUDE_INSTALL_DIR "${PROJECT_NAME}"
    RELOCATABLE "plugins"
)
