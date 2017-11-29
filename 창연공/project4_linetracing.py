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

        #오른쪽 교차로시 앞으로 전진 후 턴 or T자 교차로 시 우회전
        elif GPIOList == [1,1,0,0,0] or [1,1,1,1,1]:
            stop()
            sleep(1)
            while GPIO.input(rightmostled) == 0:
                go_forward_any(30)
            stop()
            sleep(1)
            while GPIO.input(leftmostled) != 1 and GPIO.input(rightmostled) != 1 and GPIO.input(centerled) != 0: # 직진라인에 딱 안착할때까지 우측으로 포인트 턴
                rightPointTurn(30,0.000000001) #라이트턴
            stop()
            sleep(1)
            continue

        #유턴, 오른쪽 90도 교차로 or 오른쪽 길이 없으면 좌회전
        elif GPIOList == [1,1,1,1,1]:
            stop()
            sleep(1)
            while GPIO.input(leftmostled) != 1 and GPIO.input(rightmostled) != 1 and GPIO.input(centerled) != 0: # 직진라인에 딱 안착할때까지 우측으로 포인트 턴
                rightPointTurn(30,0.000000001) #라이트턴
            stop()
            sleep(1)
            continue

        #좌회전
        elif GPIO.input(leftmostled) == 0 and GPIO.input(rightmostled) == 1:
            stop()
            sleep(1)
            while GPIO.input(leftmostled) == 0:
                go_forward_any(30)
            stop()
            sleep(1)
            #직진을 했을 시 a가 0일시 계속 직진
            if GPIO.input(centerled) == 0:
                continue
            else:
                while GPIO.input(leftmostled) != 1 and GPIO.input(rightmostled) != 1 and GPIO.input(centerled) != 0:  # 직진라인에 딱 안착할때까지 우측으로 포인트 턴
                    leftPointTurn(30, 0.000000001)  #leftturn
                stop()
                sleep(1)
                continue
        #T자 교차로시
        # elif GPIOList [0,0,0,0,0]:
        #     stop()
        #     sleep(1)
        #     while GPIO.input(rightmostled) == 0:
        #         go_forward_any(30)
        #     stop()
        #     sleep(1)
        #     #직진을 했을 시 a가 0일시 계속 직진
        #     if GPIO.input(centerled) == 0:
        #         continue
        #     else:
        #         while GPIO.input(leftmostled) != 1 and GPIO.input(rightmostled) != 1 and GPIO.input(centerled) != 0: # 직진라인에 딱 안착할때까지 우측으로 포인트 턴
        #             rightPointTurn(30,0.000000001) #라이트턴
        #         stop()
        #         sleep(1)
        #         continue








except KeyboardInterrupt:
    pwm_low()

