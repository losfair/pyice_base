all:
	g++ -O3 -fPIC -shared -std=c++11 -I ./pybind11/include `python3-config --cflags --ldflags` pyice_base.cc -o pyice_base.so -lice_core -luv
