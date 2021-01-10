
all:
	cc main.c moves.c -o out -lcurl cJSON/cJSON.o  

test:
	./out qwerty_17 info explore move rotate right  

reset:
	./out qwerty_17 reset


memory:
	valgrind ./out qwerty_17 info explore move rotate right 