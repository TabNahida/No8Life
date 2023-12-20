GCC = -std=c++17
obj = src/main.o \
      src/engine.o

%.o: %.cpp
	g++ $(GCC) -c $< -o $@

no8life: $(obj)
	g++ -o $@ $<