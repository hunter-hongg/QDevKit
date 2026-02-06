all: 
	cd build && make
clean: 
	rm -rf build/*
	cd build && cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=ON ..