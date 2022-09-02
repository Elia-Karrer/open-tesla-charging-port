
# Function
Using this code, you can open the charging port of tsla cars ```remotely```


# What do i need?
* 315/433 MHz RF-module
* Arduino or other microcontroller


# Important notes:
* Different frequencies are used in different regions, because some are legal there, but illegal elsewhere ...
* US: ```315 MHz```
* EU: ```433.92 MHz```

# Signal
* ```2500 bit/second```
* ```433.92 / 315 MHz``` depending on your country
* Transmitted 5 times, with a gap of 23ms

# Pattern
```
101010101010101010101010100010101100101100110010110011001100110011001011010011010010110101001010110100110100110010101011010010110001010110010110011001011001100110011001100101101001101001011010100101011010011010011001010101101001011000101011001011001100101100110011001100110010110100110100101101010010101101001101001100101010110100101000
```

```
{0xaa, 0xaa, 0xaa, 0x8a, 0xcb, 0x32, 0xcc, 0xcc, 0xcb, 0x4d, 0x2d, 0x4a, 0xd3, 0x4c, 0xab, 0x4b, 0x15, 0x96, 0x65, 0x99, 0x99, 0x96, 0x9a, 0x5a, 0x95, 0xa6, 0x99, 0x56, 0x96, 0x2b, 0x2c, 0xcb, 0x33, 0x33, 0x2d, 0x34, 0xb5, 0x2b, 0x4d, 0x32, 0xad, 0x28}
```

# Legal
* This code is only published for educational purposes
* I am not responsible for any damage done by this code

# Credits
* github.com/fredilarsen/TeslaChargeDoorOpener
* github.com/rgerganov/tesla-opener
