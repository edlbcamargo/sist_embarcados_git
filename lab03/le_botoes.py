#!/usr/bin/python3

# Este script configura a GPIO24 como pull-down e a GPIO25 como pull-up,
# e le os valores nas duas portas 20 vezes

import RPi.GPIO as GPIO
from time import sleep

GPIO.setmode(GPIO.BCM)
botao_pulldown=24
botao_pullup=25

GPIO.setup(botao_pulldown,GPIO.IN,pull_up_down=GPIO.PUD_DOWN)
sleep(0.1)
GPIO.setup(botao_pullup,GPIO.IN,pull_up_down=GPIO.PUD_UP)
sleep(0.1)

for x in range(0,20):
    print("GPIO%d = %d; GPIO%d = %d" % (botao_pulldown, GPIO.input(botao_pulldown),botao_pullup, GPIO.input(botao_pullup)))
    sleep(0.4)

GPIO.cleanup()



