#include <EEPROM.h>
#include "neteeprom.h"

uint8_t *getMACFromEEPROM() {
	uint8_t mac[6];
	for (int i = 0; i < 6; i++) {
		mac[i] = EEPROM.read(EEPROM_MAC_OFFSET + i);
	}
	return mac;
}

void setMACToEEPROM(uint8_t *mac) {
	for (int i = 0; i < 6; i++) {
		EEPROM.write(EEPROM_MAC_OFFSET + i, mac[i]);
	}
}