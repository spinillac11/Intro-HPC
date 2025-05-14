CXXFLAGS = -fsanitize=address,leak,undefined -fprofile-arcs -ftest-coverage

all: main_factorial.x

%.x: %.o factorial.o
	g++ $(CXXFLAGS) $^ -o $@

%.o: %.cpp
	g++ -c $<

test_factorial.x: test_factorial.o factorial.o
	g++ $(CXXFLAGS) $^ -o $@ -l Catch2Main -l Catch2

test: test_factorial.x
	./$<

clean:
	rm -f *.o *.x