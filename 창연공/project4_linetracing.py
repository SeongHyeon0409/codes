#file name: project4_linetracing.py
import RPi.GPIO as GPIO
from time import sleep

GPIO.setwarnings(False)
from TurnModule import *

from trackingModule import *

from go_any import *

pwm_setup()

try:
    while True:
        GPIOList = [GPIO.input(leftmostled), GPIO.input(leftlessled), GPIO.input(centerled), GPIO.input(rightlessled),
                    GPIO.input(rightmostled)]
        print(GPIOList)

        #직진의 경우
        if GPIOList == [1,1,0,1,1]:
            go_forward_any(30)
        elif GPIOList == [1,0,0,1,1]:
            CurveTurn(33, 35, 0.00001)
            print('go left')
        elif GPIOList == [1,1,0,0,1]:
            CurveTurn(35, 33, 0.00001)
            print('go right')

        elif GPIOList == [1,1,0,0,0]:
            while GPIO.input(rightmostled) == 1:
                go_forward_any(30)
            stop()
            sleep(1)
            while GPIOList == [1,1,0,1,1]: # 직진라인에 딱 안착할때까지 우측으로 포인트 턴
                rightPointTurn(30,0.000000001) #90도 라이트턴
            stop()
            sleep(1)
            continue
        #UTurn
        elif 




except KeyboardInterrupt:
    pwm_low()

