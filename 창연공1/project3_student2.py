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
# setup and initilaize the left motor and right motor
# =======================================================================
pwm_setup()

# =======================================================================
#  define your variables and find out each value of variables
#  to perform the project3 with ultra sensor
#  and swing turn
# =======================================================================
dis = 25  # ??
obstacle = 0

# when obstacle=1, the power and
# running time of the first turn
SwingPr = 40  # student assignment (8)
SwingTr = 0.5  # student assignment (9)

PointPr = 30
PointTr = 0.1

PointP180 = 30
PointT180 = 0.4

PointPl = 27
PointTl = 0.1

SwingPl = 50
SwingTl = 0.45

PointP360 = 30
PointT360 = 0.8

try:
    while True:
        # ultra sensor replies the distance back
        distance = getDistance()
        print('distance= ', distance)

        # when the distance is above the dis, moving object forwards
        
        CurveTurn(20,20,1)

        print('obstacle=', obstacle)



            ########################################################
            ### please continue the code or change the above code
            ### # student assignment (10)
            ########################################################


# when the Ctrl+C key has been pressed,
# the moving object will be stopped

except KeyboardInterrupt:
    pwm_low()
