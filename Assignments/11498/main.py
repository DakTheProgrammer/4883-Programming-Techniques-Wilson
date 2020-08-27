###############################################################################
##
## Author:           Dakota Wilson
## Email:            dtw3200@live.com
## Label:            11498
## Title:            UVa 11498
## Course:           4883
## Semester:         Fall 2020
##
## Description:
##      This program is writen in python and it takes in sets of cases that are
##     graphs and point and with this information it places each pair of points
##     it recives on the graph and finds its relative quadrant or if its on the
##     x or y lines
##
#################################################################################
k = int(input())                                        ## original num sets

while(k != 0):
    for i in range(k):
        if(i == 0):
            DivX, DivY = map(int, input().split())      ## division points

        x, y = map(int, input().split())                ## search points
        
        if((x == DivX) or (y == DivY)):
            print("divisa")                             ## on the lines
        elif((x > DivX) and (y > DivY)):
            print("NE")                                 
        elif((x < DivX) and (y > DivY)):
            print("NO")                                 ## north west
        elif((x < DivX) and (y < DivY)):
            print("SO")                                 ## south west
        else:
            print("SE")
    
    k = int(input())

exit(0)