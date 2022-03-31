import os
#os.system("pwd")
print("pythonththth")
#os.system('conda list')
import cv2
import torch
print(torch.__version__)

img = cv2.imread("acc.jpg")
cv2.imshow("image", img)
cv2.waitKey()
cv2.imwrite("1.jpg", img)

