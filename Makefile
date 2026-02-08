all: 
	cd build && make
	build/QDevKit
clean: 
	rm -rf build/*
	cd build && cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=ON ..
	ln -f build/compile_commands.json compile_commands.json
	cd build && make
	build/QDevKit