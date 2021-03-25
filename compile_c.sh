#!/usr/bin/bash

cd $(dirname $0)
cd src/c_sources/
make clear
make
if mv mincode.py ../mincode.py && mv _mincode.so ../_mincode.so && mv libmincode.so ../libmincode.so ; then
    printf "\033[0;36mC and CXX libraries successfully moved\n"
else
    printf "\033[0;31mC and CXX libraries couldn't be moved: no such file(s)\n"
fi
