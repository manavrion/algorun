cd "$(dirname "$0")"
if [ -z "$1" ]; then
  cd .build
  ctest --extra-verbose
else
  mkdir .build
  cd .build
  cmake ..
  cmake --build . --parallel 8 --target $1
  ctest --extra-verbose -R $1
fi
