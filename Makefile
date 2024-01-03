GCC = g++ -std=c++17
#GCC = x86_64-w64-mingw32-g++ -std=c++17
obj = src/engine.o \
      src/EasyRender.o \
      src/main.o


%.o: %.cpp
	$(GCC) -c $< -o $@

no8life: $(obj)
	$(GCC) $^ -o $@ -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lsfml-network

clean: $(obj)
	rm -rf no8life src/*.o