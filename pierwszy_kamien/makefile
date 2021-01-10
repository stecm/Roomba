DEPS=main.o moves.o communication.o map.o


pierwszy_kamien: $(DEPS)
	cc $(DEPS) -o $@ -Wall --pedantic -lcurl ~cJSON/cJSON.o

%.o:%.c
	cc -c $^ -o $@


clean:
	rm -f main
	rm -f *.o

test: main
	./main rotate left move explore


