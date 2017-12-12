#file name: project5_linetracing.py
import RPi.GPIO as GPIO
from time import sleep

GPIO.setwarnings(False)
from TurnModule import *

from trackingModule import *

from go_any import *

pwm_setup()



def getSensor():
    sensor = [GPIO.input(leftmostled), GPIO.input(leftlessled), GPIO.input(centerled), GPIO.input(rightlessled),
                    GPIO.input(rightmostled)]
    return sensor


try:
    while True:
        GPIOList = getSensor()
        print(GPIOList)

        #직진의 경우
        if GPIOList == [1,1,0,1,1] or GPIOList == [1,0,0,0,1] or GPIOList == [0,1,0,0,1]:
            CurveTurn_any(25,25)
            print('straight')
        elif GPIOList == [0,0,0,0,1]:
            CurveTurn_any(23,26)
        elif GPIOList == [1,0,0,1,1] or GPIOList == [1,0,1,1,1]:
                #or GPIOList == [0,0,0,0,1]:
            CurveTurn_any(20,34)
            print('straignt and left')
        elif GPIOList == [1,1,0,0,1]  or GPIOList == [1,1,1,0,1]:
            CurveTurn_any(34,20)
            print('straight and right')

        elif GPIOList == [1,1,1,1,0]:
             rightPointTurn(40,0.1) # 코드의 정확도를 위해서 추가 ,도는방향바낌

        # 좌회전
        elif GPIOList == [0,0,0,0,1] or GPIOList == [0,0,0,1,1] or GPIOList == [0,0,1,1,1] or GPIOList == [0,1,1,1,1]:
            stop()
            sleep(0.5)
            print('좌회전')

            CurveTurn(25,25,0.4)
            while GPIO.input(leftmostled) == 0:
                CurveTurn(25,25,0.1)
                if GPIO.input(rightmostled) == 0:
                    continue
            stop()
            sleep(0.1)
            # 직진을 했을 시 a가 0일시 계속 직진
            if GPIO.input(centerled) == 0:
                print('left code out')
                continue
            else:
                while GPIO.input(centerled) != 0:  # 직진라인에 딱 안착할때까지 우측으로 포인트 턴
                    leftPointTurn(35, 0.09)
                    stop()
                    sleep(0.05)
                    print('left1')  # leftturn
                stop()
                sleep(0.5)


        elif GPIO.input(rightmostled) == 0:
            stop()
            sleep(0.5)
            print('오른쪽 교차로시 앞으로 전진 후 턴 or T자 교차로 시 우회전')
            CurveTurn(25,25,0.4)
            stop()
            sleep(0.1)
            while GPIO.input(rightmostled) == 0:
                CurveTurn_any(25,25)
            stop()
            sleep(0.1)

            print('약간 전진후 스톱 그리고 라이트턴')
            rightPointTurn(37,0.25)
            print('0.5')
            while GPIO.input(centerled) != 0: # 직진라인에 딱 안착할때까지 우측으로 포인트 턴
                rightPointTurn(57,0.09)
                stop()
                sleep(0.07)
                #라이트턴
                print('right 1')





        #유턴
        elif GPIOList == [1,1,1,1,1]:
            stop()
            sleep(1)
            print('유턴')
            CurveTurn(30,30,0.2)
            while GPIO.input(centerled) != 0:
                PointTurn(55, 0.09)
                stop()
                sleep(0.05)#라이트턴
                print('uturn')

            stop()
            sleep(1)
            continue
        sleep(0.07)




except KeyboardInterrupt:
    pwm_low()







