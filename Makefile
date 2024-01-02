GCC = -std=c++17
obj = src/engine.o \
      src/main.o

%.o: %.cpp
	g++ $(GCC) -c $< -o $@

no8life: $(obj)
	g++ $^ -o $@ -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lsfml-network

clean: $(obj)
	rm -rf no8life src/*.o