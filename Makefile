run-%: %.cpp
	@g++ --std=c++11 $^ -o $* && ./$* && rm -f $*
