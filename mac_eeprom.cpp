#include "mac_eeprom.h"

/*
 * Read MAC Address from EEPROM
 *  Check if first 3 bytes in EEPROM match OUI.  If they don't then generate a new MAC address.
 */
void getMACFromEEPROM(byte* mac) {
    // Check if MAC has been defined and generate if not
    if ((EEPROM.read(EEPROM_MAC_OFFSET) != OUI_1)
     || (EEPROM.read(EEPROM_MAC_OFFSET+1) != OUI_2)
     || (EEPROM.read(EEPROM_MAC_OFFSET+2) != OUI_3)) {
        generateMAC(mac);
        setMACToEEPROM(mac);
    }

    // Now read MAC
    for (int i = 0; i < 6; i++) {
        mac[i] = EEPROM.read(EEPROM_MAC_OFFSET + i);
    }
}

/*
 * Write MAC address to EEPROM at offset as defined in EEPROM_MAC_OFFSET
 */
void setMACToEEPROM(byte *mac) {
    // Write actual MAC to EEPROM
    for (int i = 0; i < 6; i++) {
        EEPROM.write(EEPROM_MAC_OFFSET + i, mac[i]);
    }
}

/*
 * Generate unique mac addressed based on defined OUI and random bytes 4,5,6
 */
void generateMAC(byte *mac) {
    randomSeed(analogRead(0));
    // Set OUI
    mac[0] = OUI_1;
    mac[1] = OUI_2;
    mac[2] = OUI_3;
    // Autogenerate last 3 bytes
    for (int i = 3; i < 6; i++) {
        mac[i] = random(0,255);
    }
}

/*
 * Format byte array mac address into char array with format "00:00:00:00:00:00" for display
 */
void formatMACForPrint(byte *mac, char *macstr) {
    snprintf(macstr,18,"%02x:%02x:%02x:%02x:%02x:%02x", mac[0],mac[1],mac[2],mac[3],mac[4],mac[5]);
}
