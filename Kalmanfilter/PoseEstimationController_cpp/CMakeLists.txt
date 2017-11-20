cmake_minimum_required (VERSION 2.6)

# Set the project name to the name of the folder
string (REGEX MATCH "[^/]+$" PROJECT_NAME "${CMAKE_CURRENT_SOURCE_DIR}")
message (STATUS "Set PROJECT_NAME to ${PROJECT_NAME}")
project ("${PROJECT_NAME}")


# Read the pkg-config modules
FIND_PACKAGE(PkgConfig)
pkg_check_modules(PROTOBUF protobuf)
pkg_check_modules(EIGEN eigen3)
if ($ENV{ARCH} MATCHES "arm")
    pkg_check_modules(RSB rsb0.13)
    pkg_check_modules(RSC rsc0.13)
    pkg_check_modules(RST rstsandbox0.13)
    SET (SRC_PROTO_DIR "src_proto_amiro")
else()
    set(RSB_V 0.16)
    set(RST_V 0.16)
    pkg_check_modules(RSB rsb${RSB_V})
    pkg_check_modules(RSC rsc${RSB_V})
    pkg_check_modules(RST rstsandbox${RST_V})
    SET (SRC_PROTO_DIR "src_proto")
endif()

# Get BOOST modules (If this does not work, define it via the cross compiler environment)
SET (BOOST_COMPONENTS regex date_time program_options system thread)
SET (Boost_ADDITIONAL_VERSIONS "1.55" "1.55.0")
FIND_PACKAGE(Boost QUIET COMPONENTS "${BOOST_COMPONENTS}" PATH $ENV{BOOST_ROOT} $ENV{BOOST_INCLUDEDIR} $ENV{BOOST_LIBRARYDIR})
IF (NOT Boost_FOUND)
  SET(Boost_LIBRARIES "")
  MESSAGE(STATUS "Boost module NOT found, using the cross compiler env. in $ENV{SDKTARGETSYSROOT}")
  SET(Boost_FOUND "TRUE")
  FOREACH (BOOST_COMP ${BOOST_COMPONENTS})
   SET(Boost_LIBRARIES "${Boost_LIBRARIES};-lboost_${BOOST_COMP}")
  ENDFOREACH ()
  SET(Boost_INCLUDE_DIR "$ENV{SDKTARGETSYSROOT}/usr/include")
  SET(Boost_INCLUDE_DIRS "$ENV{SDKTARGETSYSROOT}/usr/include")
ENDIF()


# Get the compiler specific includes and store them in GXX_INCLUDES
set (test "${CMAKE_CXX_COMPILER}${CMAKE_CXX_COMPILER_ARG1}")
execute_process(COMMAND printCompilerIncludes OUTPUT_VARIABLE GXX_INCLUDES)
message (STATUS "Set GXX_INCLUDES to ${GXX_INCLUDES}")


# Set the include pathe
include_directories(
    ${RSB_INCLUDE_DIRS}
    ${RSC_INCLUDE_DIRS}
    ${RST_INCLUDE_DIRS}
    ${PROTOBUF_INCLUDE_DIRS}
    ${CMAKE_CURRENT_BINARY_DIR}
    ${GXX_INCLUDES}
    ${Boost_INCLUDE_DIR}
    ${EIGEN_INCLUDE_DIRS}
    "${CMAKE_CURRENT_SOURCE_DIR}/include"
    "${CMAKE_CURRENT_SOURCE_DIR}/src_matlab"
    "${CMAKE_CURRENT_SOURCE_DIR}/${SRC_PROTO_DIR}"
)

# Define the source
SET (SOURCE src/main.cxx
  src/base85.c
  # MATLAB STUFF
  src_matlab/PoseEstimationController.cpp
  src_matlab/const_params.cpp
  src_matlab/dbiemohljmgdohdb_norm.cpp
  src_matlab/iecjgdjeaimokfcj_mrdivide.c
  src_matlab/rt_atan2d_snf.cpp
  src_matlab/rtGetInf.cpp
  src_matlab/rtGetNaN.cpp
  src_matlab/rt_nonfinite.cpp
  # PROTO STUFF
  ${SRC_PROTO_DIR}/enum.pb.cc
  ${SRC_PROTO_DIR}/loc.pb.cc
  ${SRC_PROTO_DIR}/pose.pb.cc
  ${SRC_PROTO_DIR}/rotation.pb.cc
  ${SRC_PROTO_DIR}/shapes.pb.cc
  ${SRC_PROTO_DIR}/vertex.pb.cc
)

LINK_DIRECTORIES (
    ${RSB_LIBRARY_DIRS}
    ${RSC_LIBRARY_DIRS}
)

# add the executable
add_executable ("${PROJECT_NAME}" ${SOURCE})

target_link_libraries (
    "${PROJECT_NAME}"
    ${RSB_LIBRARIES}
    ${RSC_LIBRARIES}
    ${RST_LIBRARIES}
    ${PROTOBUF_LIBRARIES}
    ${Boost_LIBRARIES}
)

# Special flags for RST
ADD_DEFINITIONS(${RST_CFLAGS} ${RSTSANDBOX_CFLAGS} -std=c++11)

# Set compiler flags as you like
SET ( CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall -Wno-deprecated-declarations -O0 -g -Wno-write-strings -std=c++0x" )
SET ( CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -Wall -Wno-deprecated-declarations -O2 -Wno-write-strings -std=c++0x" )
