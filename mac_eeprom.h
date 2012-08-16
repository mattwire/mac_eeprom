#ifndef mac_eeprom__h
#define mac_eeprom__h 1

#include <Arduino.h>
#include <stdio.h>
#include <EEPROM.h>

#define EEPROM_MAC_OFFSET 0
//Microchip OUI is 00-04-A3
#define OUI_1 0
#define OUI_2 4
#define OUI_3 163

void getMACFromEEPROM(byte *mac);

void setMACToEEPROM(byte *mac);

void generateMAC(byte *mac);

void formatMACForPrint(byte *mac, char *macstr);

#endif
