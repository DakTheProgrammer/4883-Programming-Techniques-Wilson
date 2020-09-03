###############################################################################
##
## Author:           Dakota Wilson
## Email:            dtw3200@live.com
## Label:            11172
## Title:            UVa 11172
## Course:           4883
## Semester:         Fall 2020
##
## Description:
##      This program is written in python and all it does is take a select set 
##    of numbers to do relation operators on them (<,>,=) and prints the symbol 
##    for each of the relationships.
##
#################################################################################

t = int(input())                        #Num inputs

for i in range(t):
    a,b = map(int, input().split())     #map for input spliting

    if(a > b):
        print(">")
    elif(a < b):
        print("<")                      #answers printing
    else:
        print("=")

exit(0)                                 #exit for no runtime error