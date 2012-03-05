#ifndef mac_eeprom__h
#define mac_eeprom__h 1

#define EEPROM_MAC_OFFSET 0

uint8_t *getMACFromEEPROM();

void setMACToEEPROM(uint8_t *mac);

#endif