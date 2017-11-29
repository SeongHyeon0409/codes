######################################################################
### Date: 2017/10/5
### file name: project3_student.py
### Purpose: this code has been generated for the three-wheeled moving
###         object to perform the project3 with ultra sensor
###         swing turn, and point turn
### this code is used for the student only
######################################################################

# =======================================================================
# import GPIO library and time module
# =======================================================================
import RPi.GPIO as GPIO
from time import sleep

# =======================================================================
#  set GPIO warnings as false
# =======================================================================
GPIO.setwarnings(False)

# =======================================================================
# import getDistance() method in the ultraModule
# =======================================================================
from ultraModule import getDistance

# =======================================================================
# import TurnModule() method
# =======================================================================
from TurnModule import *

from trackingModule import *

GPIO.setmode(GPIO.BOARD)

# =======================================================================
# rightPointTurn() and leftPointTurn() in TurnModule module
# =======================================================================
# student assignment (1)
# student assignment (2)



# =======================================================================
# import go_forward_any(), go_backward_any(), stop(), LeftPwm(),
# RightPwm(), pwm_setup(), and pwm_low() methods in the module of go_any
# =======================================================================
from go_any import *

# implement rightmotor(x)  # student assignment (3)
# implement go_forward_any(speed): # student assignment (4)
# implement go_backward_any(speed): # student assignment (5)
# implement go_forward(speed, running_time)  # student assignment (6)
# implement go_backward(speed, running_time)  # student assignment (7)

# =======================================================================
# setup and init =ilaize the left motor and right motor
# =======================================================================
pwm_setup()

# =======================================================================
#  define your variables and find out each value of variables
#  to perform the project3 with ultra sensor
#  and swing turn
# =======================================================================
dis = 25  # ??
obstacle = 1
SwingPr = 40
SwingTr = 2
SwingPl = 40
SwingTl = 2

# when obstacle=1, the power and
# running time of the first turn

GPIOList = [GPIO.input(leftmostled),
              GPIO.input(leftlessled),
              GPIO.input(centerled),
              GPIO.input(rightlessled),
              GPIO.input(rightmostled)]

try:
    while True:
        # ultra sensor replies the distance back
        distance = getDistance()
        print('distance= ', distance)
        print(GPIO.input(leftmostled),
              GPIO.input(leftlessled),
              GPIO.input(centerled),
              GPIO.input(rightlessled),
              GPIO.input(rightmostled))
        sleep(1)

        # when the distance is above the dis, moving object forwards
        if (distance > dis):
            if GPIO.input(leftmostled) == 1 and GPIO.input(rightmostled) == 1:
                go_forward_any(30)
                print('go')
                print('obstacle=', obstacle)


            # left
            elif GPIO.input(rightmostled) == 1 and GPIO.input(rightlessled) == 1:
                CurveTurn(16, 35)
                print('more leftturn')


            # right
            elif GPIO.input(leftmostled) == 1 and GPIO.input(leftlessled) == 1:
                CurveTurn(35, 16)
                print('more rightturn')


            # moreleft
            elif GPIO.input(leftmostled) == 0 and GPIO.input(centerled) == 1 and GPIO.input(rightmostled) == 1:
                CurveTurn(16, 40)
                print('more more leftturn')


            elif GPIO.input(leftlessled) == 0 and GPIO.input(centerled) == 0:
                CurveTurn(16, 25)
                print('leftturn')




            elif GPIO.input(centerled) == 0 and GPIO.input(rightlessled) == 0:
                CurveTurn(25, 16)
                print('rightturn')









                # when the distance is below the dis, moving object stops
        else:
            # stop and wait 1 second
            stop()
            sleep(1)
            if obstacle == 1:
                stop()
                rightSwingTurn(40, 1.4)
                sleep(0.5)
                go_forward(30, 1.0)
                sleep(0.5)
                leftSwingTurn(40, 1.2)
                go_forward(30, 1.8)
                leftSwingTurn(SwingPl, 1.4)

                go_forward_any(30)
                continue
            if obstacle == 2:
                rightSwingTurn(40, 1.4)
                sleep(0.5)
                go_forward(30, 1)
                sleep(0.5)
                leftSwingTurn(40, 1.2)
                go_forward(30, 1.8)
                leftSwingTurn(SwingPl, 1.4)
                go_forward_any(30)
                obstacle += 1
                continue


                ########################################################
                ### please continue the code or change the above code
                ### # student assignment (10)
                ########################################################


# when the Ctrl+C key has been pressed,
# the moving object will be stopped

except KeyboardInterrupt:
    pwm_low()
