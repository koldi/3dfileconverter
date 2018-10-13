#!/bin/sh

pushd `dirname $0` > /dev/null

SCRIPT_DIR=`pwd`
SRC_DIR=${SCRIPT_DIR}/src
BUILD_DIR=${SCRIPT_DIR}/build

/bin/rm -rf ${BUILD_DIR}
/bin/rm -f ${SRC_DIR}/compile_commands.json
mkdir -p ${BUILD_DIR}

cd ${BUILD_DIR}
cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=1 ${SRC_DIR}

popd > /dev/null
