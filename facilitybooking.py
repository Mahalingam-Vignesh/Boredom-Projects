import csv
from datetime import date
from datetime import datetime

#Code performs one to three task for successful completion
#Task 1: Checks for valid input.
##Task 2: Checks for overlapping of booking event.
###Task 3: On successful booking, writes out data for future reference.

###Task 3:
def write(a,b,c,d,g):
    e=[a,b,c,d]
    file=open('data.csv','a')
    writing=csv.writer(file,lineterminator='\n')
    writing.writerow(e)      #Data is written in CSV file for future reference.
    file.close()
    print("Booked, "+"RS.",g)#on successful booking, information and ruppees are displayed.
    return
    

##Task 2:   
def read(a,b,c,d,g):         #file is read for pre-existing booking at the same time.
    f=str(a)
    a44=0
    file=open('data.csv','r')
    reading=csv.reader(file)
    for row in reading:
        a44=a44+1
        a3=0
        if row[0] == f:
            if row[1] == b:
                a1=row[2]
                a2=row[3]
                if  c >= a1 and c<=a2:
                    a3=1
                if d>=a1 and d<=a2:
                    a3=1
                if c==a2:
                    a3=0
                if d==a1:
                    a3=0
                if (c<a1) and (a2<d):
                    a3=1
                if a3==1:                   #checks for overlapping occurence
                    file.close()
                    print("Booking Failed, Already Booked.")
                    return   
    file.close()
    write(a,b,c,d,g)        #write function is called only after, there isn't any overlapping of time.

def cost(a,b,c):
    if c == 1:
        d=100
    elif c == 2:
        d=200
    elif c == 3:
        d=300

    if (10<=a<=16) and (10<=b<=16):
        e = (a-b)*d
    elif (16<a<=22) and (16<b<=22):
        e = (a-b)*(d+300)
    else:
        e = ((16-b)*d)+((a-16)*(d+300))

    return e
    
#Task 1:                    
#Interpretation of code begins here:
file=open('data.csv','a')
file.close()
print("Appartment Facility Booking\n")

print("Slot details:\n10am to 4pm :-\nRs.100 per hour for Club House\nRs.200 per hour for Tennis Court\nRs.300 per hour for Private SPA\n4pm to 10pm :-\nRs.400 per hour for Club House\nRs.500 per hour for Tennis Court\nRs.600 per hour for Private SPA\n")

print("facility Detail:")
try:
    a=int(input("Choose facility\n1 for Club House.\n2 for Tennis Court.\n3 for Private SPA.\n"))
    if a==1 or a==2 or a==3:
        print("Time Details:")
        b=str(input("Give the date in yyyy-mm-dd format.\n"))
        c=str(input("start time in 24 hrs in hh:mm : "))
        if 10<=int(c[0:2])<=22:
            d=str(input("end time in 24 hrs in hh:mm : "))
            if 10<=int(d[0:2])<=22:                                     #to check for 10AM to 10PM 
                c1=c+":00"
                b1=b+" "+c1
                dateTime = datetime.strptime(b1, "%Y-%m-%d %H:%M:%S")
                today = date.today()
                if dateTime.date() > date.today():                      #to check for past time
                    e1=int(d[0:2])
                    e2=int(c[0:2])
                    if e1>e2:
                        e=cost(e1,e2,a)                                     #to calculate Rs. for two section
                        read(a,b,c,d,e)                                     #validation of input get done here. If the provided value are proper
                    else:
                        print("End time is before the start time")
                else:
                    print("Date or time is in past")                    #prompt date/time provided is in past
            else:
                print("Only time of visit is between 10-22 hrs")        #user cannot book after the specified time
        else:
            print("Only time of visit is between 10-22 hrs")
    else:
        print("check the data")                                         #if user gave other input than 1, 2 and 3 for facility option
except:
    print("CHECK THE DATA, PROVIDE AS ASKED")                           #if user didn't provide data in the asked manner                                               
