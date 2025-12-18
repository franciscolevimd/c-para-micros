CC        = gcc
BUILD_DIR = Build
APP       = MaquinaEventosApp

LNFLAGS = --inline-suppr          # comments to supress lint warnings
LNFLAGS += --quiet                # spit only useful information
LNFLAGS += --enable=warning,style # enable only warnings
LNFLAGS += --error-exitcode=1     # return error if any warnings
LNFLAGS += std=c11                # check against C11
LNFLAGS += --template=gcc         # display warning gcc style
LNFLAGS += --force                # evaluate all the #if sentences
LNFLAGS += --platform=unix32      # lint againt a unix32 plataform, but we are using arm32
LNFLAGS += --cppcheck-build-dir=Build/lint

# Archivos fuente
SRC = App/MaquinaDeEventos.c App/Semaforo.c App/main.c

# Archivos .i
PRE = $(patsubst App/%.c,$(BUILD_DIR)/%.i,$(SRC))

# Archivos .s
ASM = $(patsubst Build/%.i,$(BUILD_DIR)/%.s,$(PRE))

# Archivos .o
OBJ = $(patsubst Build/%.s,$(BUILD_DIR)/%.o,$(ASM))

# Ejecutables
EXECUTABLES = $(APP)
TARGETS     = $(addprefix $(BUILD_DIR)/,$(EXECUTABLES))

# Target principal
all: $(BUILD_DIR) $(TARGETS)

# Crea dierctorio Build si no existe
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Preprocesador.
$(BUILD_DIR)/%.i: App/%.c
	$(CC) -E $< -o $@

# Ensamblador.
$(BUILD_DIR)/%.s: Build/%.i
	$(CC) -S $< -o $@

# Compila objetos.
$(BUILD_DIR)/%.o: Build/%.s
	$(CC) -c $< -o $@

# Enlaza ejecutables.
$(BUILD_DIR)/$(APP): $(OBJ)
	$(CC) $^ -o $@


.PHONY: test clean cleang cleanb cleant lint

# Target para reglas Misra.
lint:
	mkdir -p Build/lint
	cppcheck --addon=misra.json --suppressions-list=.msupress $(LNFLAGS) App

# Pruebas unitarias
test:
	ceedling clobber
	ceedling test:all gcov:all

# Limpieza
cleang:
	rm -rf App/*~ test/*~ ./*~

cleanb:
	rm -rf Build/*.o Build/*.s Build/*.i

cleant:
	rm -rf Build/ceedling

clean:
	rm -rf $(BUILD_DIR)

.PRECIOUS: $(BUILD_DIR)/%.i $(BUILD_DIR)/%.s
