#ifndef neteeprom__h
#define neteeprom__h 1

#define EEPROM_MAC_OFFSET 0

uint8_t *getMACFromEEPROM();

void setMACToEEPROM(uint8_t *mac);

#endif