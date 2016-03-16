CC=g++

run_pruebas:hacer_pruebas.cpp prueba.cpp Calendario.cpp
	${CC} -std=c++11 -L/usr/lib -ldl -lcppunit $^ -o $@

clean:
	rm -v run_pruebas
