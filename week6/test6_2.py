import sys
from PyQt5.QtWidgets import *

class MyWindow(QMainWindow): #QMainWindow를 상속
    def __init__(self):
        super().__init__()
        self.setWindowTitle("SWP2")
        self.setGeometry(300, 300, 500, 400)

if __name__ == "__main__":
    app = QApplication(sys.argv)
    mywindow = MyWindow()
    mywindow.show()
    app.exec_()