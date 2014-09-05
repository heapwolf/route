all: build test

gyp: 
	git clone --depth 1 https://chromium.googlesource.com/external/gyp.git ./deps/gyp

build:
	deps/gyp/gyp --depth=. -Goutput_dir=./out -Icommon.gypi --generator-output=./build -Dlibrary=static_library -f make

test: test.cc
	make -C ./build/ test
	cp ./build/out/Release/test ./test

.PHONY: test
