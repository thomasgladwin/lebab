import sys
import serial
import time
import pygame
from pygame.locals import *
import os
import subprocess
import math
import random
import winsound

savefilename = input("Save to .log file with base name: ")
savefilename = savefilename + ".log"
print("Saving data to " + savefilename)
print('\n')

file2write = open(savefilename, 'w')

try:
    arduino = serial.Serial('COM5', 9600)
    time.sleep(2) # Allow Arduino to reset after opening port
except Exception as e:
    print(e)

pygame.init()
screen = pygame.display.set_mode((600, 400))
pygame.display.set_caption('Lebab')
screen.fill((155,155,55))
myFont = pygame.font.SysFont("Times New Roman", 18)

transmitting = 1
while transmitting == 1:
	
	for event in pygame.event.get():
		if (event.type == pygame.QUIT):
			print("Ending measurement...")
			transmitting = 0
		else:
			screen.fill((55,55,55))
			valDisplay = myFont.render("Event: " + str(event), 1, (0, 255, 0))
			screen.blit(valDisplay, (10, 50))
			if (event.type == pygame.KEYDOWN):
				print(event.key)
				for i in range(7):
					if (event.key == ord("1") + i):
						valDisplay = myFont.render("Sending bit-trigger " + str(i + 1), 1, (0, 255, 0))
						screen.blit(valDisplay, (10, 200))
						arduino.write(str.encode(str(i + 1) + "\n"))
	pygame.display.flip()
	
pygame.display.quit()
file2write.close()
