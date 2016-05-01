avrdude -F -v -v -v -c arduino -p attiny85 -P /dev/ttyACM0 -U eeprom:r:Junk.txt:h
