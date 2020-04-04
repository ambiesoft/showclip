# showclip

# prepare msys2
```
pacman -S mingw-w64-i686-toolchain
```
Choose 'gcc', 'make'. 'binutil' might be also needed.

# make
```
mkdir build
cd build/
cmake -G "MinGW Makefiles" ..
cmake --build .
```
# Commandline option
```
-utf8
 Output is utf8 encoded
```
