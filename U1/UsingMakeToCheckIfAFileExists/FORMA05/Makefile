#ARCHIVO_OBJETO_PRESENTE := $(shell find . -name archivo.o 2>/dev/null)
ARCHIVO_OBJETO_PRESENTE := $(shell find . -name archivo.o)

all:
ifdef ARCHIVO_OBJETO_PRESENTE
	@echo "Archivo objeto encontrado $(ARCHIVO_OBJETO_PRESENTE)"
else
	@echo "archivo.o NO encontrado!..."
endif
#Para obtener el segundo @echo como salida archivo.o no debe 
#existir en este directorio.
#Para obtener el primer @echo como salida se puede usar 
#touch archivo.o y despues ejecutar make
