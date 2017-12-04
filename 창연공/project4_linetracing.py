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
            CurveTurn_any(20,20)
            print('straight')
        elif GPIOList == [0,0,0,0,1]:
            CurveTurn_any(20,22)
        elif GPIOList == [1,0,0,1,1] or GPIOList == [1,0,1,1,1]:
                #or GPIOList == [0,0,0,0,1]:
            CurveTurn_any(20,25)
            print('straignt and left')

        #elif GPIOList == [0,1,1,1,1]:
            #CurveTurn_any(20,28)

        # elif GPIOList == [0,0,1,1,1]:
        #     CurveTurn_any(20, 25)

        elif GPIOList == [1,1,0,0,1]  or GPIOList == [1,1,1,0,1]:
            CurveTurn_any(25,20)
            print('straight and right')

        elif GPIOList == [1,1,1,1,0]:
            rightPointTurn(15,0.1) # 도는방향바낌
        elif GPIOList == [0,1,1,1,1]:
            leftPointTurn(15,0.1)

        # 좌회전
        elif GPIOList == [0, 0, 0, 0, 1] or GPIOList == [0, 0, 0, 1, 1] or GPIOList == [0, 0, 1, 1, 1]:
            stop()
            sleep(0.1)
            print('좌회전')
            # while GPIO.input(leftmostled) == 0:
            #     CurveTurn_any(20,20)
            CurveTurn(20, 20, 0.4)
            stop()
            sleep(0.5)
            # 직진을 했을 시 a가 0일시 계속 직진
            if GPIO.input(centerled) == 0:
                print('left code out')
                continue
            else:
                while GPIO.input(centerled) != 0:  # 직진라인에 딱 안착할때까지 우측으로 포인트 턴
                    leftPointTurn(15, 0.1)
                    print('left1')  # leftturn
                stop()
                sleep(0.5)
                list1 = getSensor()
                print(list1)
                while GPIO.input(leftmostled) != 0:
                    leftPointTurn(20, 0.1)
                    print('라인 잘 탈때까지 좌회전')
                continue

        #오른쪽 교차로시 앞으로 전진 후 턴 or T자 교차로 시 우회전
        #elif GPIOList == [1,1,1,1,0] or GPIOList == [1,1,1,0,0] or GPIOList == [1,1,0,0,0] \
                #or GPIOList == [1,0,0,0,0] or GPIOList == [0,0,0,0,0] or GPIOList == [0,1,0,0,0]:
        elif GPIO.input(rightmostled) == 0:
            stop()
            sleep(0.1)
            print('오른쪽 교차로시 앞으로 전진 후 턴 or T자 교차로 시 우회전')
            # while GPIO.input(rightmostled) == 0:
            #     CurveTurn_any(20,20)
            #     sleep(0.5)
            while GPIO.input(rightmostled) != 0:
                CurveTurn(20,20,0.1)
            stop()
            sleep(0.1)
            if GPIO.input(centerled) == 0:
                print('right code out')
                continue
            else:
                print('약간 전진후 스톱 그리고 라이트턴')
                rightPointTurn(20,0.4)
                print('0.5')
                while GPIO.input(centerled) != 0: # 직진라인에 딱 안착할때까지 우측으로 포인트 턴
                    rightPointTurn(20,0.1) #라이트턴
                    print('right 1')
                continue




        #유턴, 오른쪽 90도 교차로 or 오른쪽 길이 없으면 좌회전
        elif GPIOList == [1,1,1,1,1]:
            stop()
            sleep(1)
            print('유턴, 오른쪽 90도 교차로 or 오른쪽 길이 없으면 좌회전')
            while GPIO.input(centerled) != 0:
                rightPointTurn(35, 0.1)#라이트턴
                print('uturn')
            stop()
            sleep(1)
            continue


        sleep(0.05)
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







