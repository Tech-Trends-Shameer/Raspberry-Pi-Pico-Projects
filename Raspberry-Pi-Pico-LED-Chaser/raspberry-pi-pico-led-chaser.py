//Tech Trends Shameer
//Raspberry Pi Pico LED Chaser

import time
from machine import Pin

led0 = Pin(6,Pin.OUT)
led1 = Pin(7,Pin.OUT)
led2 = Pin(8,Pin.OUT)
led3 = Pin(9,Pin.OUT)
led4 = Pin(10,Pin.OUT)
led5 = Pin(11,Pin.OUT)
led6 = Pin(12,Pin.OUT)
led7 = Pin(13,Pin.OUT)
value = 0

def led_chaser(display_data):
    led0.value(1 if display_data&0x01 else 0)
    led1.value(1 if display_data&0x02 else 0)
    led2.value(1 if display_data&0x04 else 0)
    led3.value(1 if display_data&0x08 else 0)
    led4.value(1 if display_data&0x10 else 0)
    led5.value(1 if display_data&0x20 else 0)
    led6.value(1 if display_data&0x40 else 0)
    led7.value(1 if display_data&0x80 else 0)
    time.sleep(0.1)    
    

while True:
    value = 0
    led_chaser(value)
    
    for x in range (0,8):
        value |= (1 << x);
        led_chaser(value)
        print(hex(value))
