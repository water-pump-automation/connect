CC=gcc

CORE_FOLDER=./core
INFRA_FOLDER=./infra
ESP32_FOLDER=$(INFRA_FOLDER)/esp32

CFLAGS=-I $(CORE_FOLDER) -I $(ESP32_FOLDER)

network_plug: $(ESP32_FOLDER)/connect.c
	@$(CC) -o network_plug $(CFLAGS) $(ESP32_FOLDER)/connect.c

clean:
	@rm network_plug_lib network_plug
