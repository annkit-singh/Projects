import numpy as np 
import cv2
cpt=0
cap=cv2.VideoCapture(0)

while(True):
	ret,frame=cap.read()
	cv2.imshow("Test windows ",frame)

	cv2.imwrite("D:/FaceRecog/images/Sher/image%04i.jpg" %cpt,frame)
	cpt+=1

	if cv2.waitKey(20) & 0xFF ==ord('q'):
		break

cap.release()
cv2.destroyAllWindows()		