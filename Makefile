a.out:Test.cpp List.cpp Vector.cpp
	g++ -o $@ $^ -g -std=gnu++0x
.PHONY:clean
clean:
	rm a.out
