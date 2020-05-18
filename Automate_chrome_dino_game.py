import pyautogui as pg
from PIL import Image,ImageGrab
import time
from numpy import asarray

# def takeScreenshot():
#     # image=ImageGrab.grab().convert('L')
#     # image.show()
#     return image


def hit(key):
    pg.press(key)

def isCollide(data):
    # for detecting cactus
    for i in range(380, 480):
        for j in range(658, 730):
            if data[i, j]<120:
                hit('up')
                return True
    # for detecting bird
    for i in range(380, 480):
        for j in range(500, 665):
            if data[i, j] <120:
                hit('down')
                return True

    return False

# main class

if __name__ == '__main__':
    print("Ur dino game is about to start in 5 Minutes")
    time.sleep(5)
    hit('up')
    # image= takeScreenshot();
    while True:
        # Line which is used to grab the screen
        image = ImageGrab.grab().convert('L')
        data= image.load()
        isCollide(data)

# to look at image
# image.show()

