# -*- coding: utf-8 -*-
"""
Created on Tue Jul 25 09:15:23 2023

@author: Sasani
"""

import mediapipe as mp
import cv2
import time
import imutils
import serial
from math import hypot
import numpy as np


arduino = serial.Serial(port = 'COM5', baudrate=9600, timeout=0.1)
time.sleep(2) 
'''

def write_read(x):
    xxx = str(x).encode()
    time.sleep(0.05)
    data = arduino.writelines(xxx)
    return data
'''

cap = cv2.VideoCapture(0)



#initializing hand recognition
mpHands = mp.solutions.hands
#set the hands fucntion which will hold the landmark position
hands = mpHands.Hands()
#set up drawing function
mpDraw = mp.solutions.drawing_utils

intensity_list = ['b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y']

#camera work
while(cap.isOpened()):
    ret, frame = cap.read()
    if(ret == False):
        break
    if (ret):
        fliped_frame = cv2.flip(frame,1) #bgr to get non mirried image
        
        #here goes the every drawings
        #openCV reads the frame as bgr image.
        #mediapipe works with rgb images
        #so we have to rearrange the layers
        rgb_frame = cv2.cvtColor(fliped_frame, cv2.COLOR_BGR2RGB)
        
        results = hands.process(rgb_frame) #because process wantd rgb
        #print(results.multi_hand_landmarks) #these landmarks are the 21 points in hand
        #print(results)
        
        landmarkList = []
        
        if(results.multi_hand_landmarks):
            for i in range(0,len(results.multi_hand_landmarks)):
                handLms = results.multi_hand_landmarks[i]
                for ilm, lm in enumerate(handLms.landmark): #make the points have indexes
                    h,w,c = fliped_frame.shape
                    lm_x,lm_y = int(lm.x*w),int(lm.y*h) #x coor multiplied by width, y coord mult by height
                    landmarkList.append([ilm,lm_x,lm_y]) 
                    #print(landmarkList)
                    
                mpDraw.draw_landmarks(fliped_frame, handLms,mpHands.HAND_CONNECTIONS,
                                      mpDraw.DrawingSpec(color=(140,40,0),thickness=2, circle_radius=3),
                                      mpDraw.DrawingSpec(color=(70,100,20),thickness=2, circle_radius=3))
                
                if landmarkList != []:
                    # store x,y coordinates of (tip of) thumb  
                    x_1,y_1 = landmarkList[4][1],landmarkList[4][2]
                      
                    # store x,y coordinates of (tip of) index finger
                    x_2,y_2 = landmarkList[8][1],landmarkList[8][2]
                      
                    # draw circle on thumb and index finger tip
                    cv2.circle(fliped_frame,(x_1,y_1),7,(0,255,0),cv2.FILLED)
                    cv2.circle(fliped_frame,(x_2,y_2),7,(0,255,0),cv2.FILLED)
                      
                    # draw line from tip of thumb to tip of index finger
                    cv2.line(fliped_frame,(x_1,y_1),(x_2,y_2),(0,255,0),3)
                      
                    # calculate square root of the sum
                    # of squares of the specified arguments.
                    L = hypot(x_2-x_1,y_2-y_1)
                      
                    # 1-D linear interpolant to a function
                    # with given discrete data points 
                    # (Hand range 15 - 220, Brightness range 0 - 100),
                    # evaluated at length.
                    b_level = int(np.interp(L,[30,250],[0,23]))
                
                    print(b_level)
                    intensity = intensity_list[b_level]
                    arduino.write(intensity.encode())
                    
                    
                    
        
    
        cv2.imshow("Frame", fliped_frame)
        if(cv2.waitKey(1) & 0xFF == ord('q')):
            cap.release()
            arduino.close()
            cv2.destroyAllWindows()
            break
    else:
        break

