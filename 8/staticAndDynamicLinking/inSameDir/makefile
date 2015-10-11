checksum.o: checksum.c checksum.h
	gcc -c checksum.c

encrypt.o: encrypt.c encrypt.h
	gcc -c encrypt.c

bank: bank.c checksum.o encrypt.o
	gcc bank.c checksum.o encrypt.o -o bank
