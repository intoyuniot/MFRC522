/*
 * MFRC522 - Library to use ARDUINO RFID MODULE KIT 13.56 MHZ WITH TAGS SPI W AND R BY COOQROBOT.
 * The library file MFRC522.h has a wealth of useful info. Please read it.
 * The functions are documented in MFRC522.cpp.
 *
 * Based on code Dr.Leong   ( WWW.B2CQSHOP.COM )
 * Created by Miguel Balboa (circuitito.com), Jan, 2012.
 * Rewritten by Søren Thing Andersen (access.thing.dk), fall of 2013 (Translation to English, refactored, comments, anti collision, cascade levels.)
 * Released into the public domain.
 *
 * Read a card using a mfrc522 reader on your SPI interface on your IntoRobot
 * Pin layout should be as follows          SPI
 * MOSI: Pin A7
 * MISO: Pin A6
 * SCK : Pin A5
 * SS  : Pin A4(Configurable)
 * RST : Pin A0(Configurable)
 *
 */
#include <MFRC522.h>

#define SS_PIN  D0
#define RST_PIN A0

MFRC522 mfrc522(SS_PIN, RST_PIN);// Create MFRC522 instance.

void setup()
{
    Serial.begin(115200);// Initialize serial communications with the PC
    SPI.begin();// Init SPI bus
    SPI.setClockDivider(SPI_CLOCK_DIV8);
    mfrc522.PCD_Init();	// Init MFRC522 card
    Serial.println("Scan PICC to see UID and type...");
}

void loop()
{
    // Look for new cards
    if ( ! mfrc522.PICC_IsNewCardPresent()) {
        return;
    }
    // Select one of the cards
    if ( ! mfrc522.PICC_ReadCardSerial()) {
        return;
    }
    // Dump debug info about the card. PICC_HaltA() is automatically called.
    mfrc522.PICC_DumpToSerial(&(mfrc522.uid));
}
