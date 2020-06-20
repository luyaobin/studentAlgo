#!/bin/bash
if [ "$1" == "clean" ];then
    if [ -d "build" ]
    then
        rm -rv build 
    fi
else
    currdir=$(cd `dirname $0`; pwd)
    if [ ! -d "build" ]
    then
        mkdir build
    fi
    cd build
    cmake ..
    make -j4
    echo "run process?[r]"
    read run
    if [ "$run" == "" ];then
        exit
    else
        ./${currdir##*/}
    fi
fi