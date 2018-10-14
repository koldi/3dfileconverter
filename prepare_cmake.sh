#!/bin/sh

pushd `dirname $0` > /dev/null

SCRIPT_DIR=`pwd`
SRC_DIR=${SCRIPT_DIR}/src
BUILD_DIR=${SCRIPT_DIR}/build

/bin/rm -rf ${BUILD_DIR}
mkdir -p ${BUILD_DIR}

cd ${BUILD_DIR}
cmake -DCMAKE_CXX_COMPILER=clang++ ${SRC_DIR}
popd > /dev/null
