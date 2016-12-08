ptar : main.o conversion.o listing.o fctFinFichier.o optionx.o date.o permission.o
		gcc -o ptar main.o conversion.o listing.o fctFinFichier.o optionx.o date.o permission.o

optionx.o : optionx.c
		gcc -c optionx.c

main.o : main.c
		gcc -c main.c

listing.o : listing.c
		gcc -c listing.c		

fctFinFichier.o : fctFinFichier.c
		gcc -c fctFinFichier.c

date.o : date.c
		gcc -c date.c

conversion.o : conversion.c
		gcc -c conversion.c

permission.o : permission.c
		gcc -c permission.c
