run-%: %.cpp
	@g++ --std=c++11 lib/*.cpp $^ -o $* && ./$* && rm -f $*
