cd "$(dirname "$0")"
mkdir .build
cd .build
cmake -DCMAKE_TOOLCHAIN_FILE=../toolchain.cmake ..
cmake --build .
