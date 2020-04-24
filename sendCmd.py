import serial
from time import sleep,time
import sys
import math

with serial.Serial("COM5",115200,timeout=1) as ser:
    start = time()
    while True:
        cur = time()
        speed = math.sin(cur-start)
        #-1~1轉0~255
        speed = int((speed+1)*0.5*255)

        #產生command
        packet = bytearray()
        packet.append(0xFE) #header
        packet.append(0x01) #motor control
        packet.append(0x04) #arg num
        packet.append(speed) #motor1
        packet.append(speed) #motor2
        packet.append(speed) #motor3
        packet.append(speed) #motor4
        #compute checksum
        sum = 0
        for c in packet:
            sum += c
        packet.append(sum%256)
        #print(packet)
        ser.write(packet)
        
        message = ser.readline()
        if len(message) > 0:
            print(message)