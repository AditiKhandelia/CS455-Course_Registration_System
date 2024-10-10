all:
	@g++ -w -c utilities.cpp -o utilities.o
	@g++ -w -c main.cpp -o main.o
	@g++ -w main.o utilities.o -o application
	@./application

clean:
	@rm -f *.o application