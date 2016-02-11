CC=g++

run_pruebas:hacer_pruebas.cpp prueba.cpp 
	${CC} -L/usr/lib -ldl -lcppunit $? -o $@

clean:
	rm -v run_pruebas
