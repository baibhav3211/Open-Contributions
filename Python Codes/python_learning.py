#-------------------------------------------------------------------------------
# Name:        module1
# Purpose:
#
# Author:      ishan
#
# Created:     27-09-2022
# Copyright:   (c) ishan 2022
# Licence:     <your licence>
#-------------------------------------------------------------------------------

def main():
    pass

if __name__ == '__main__':
    main()
    name="Ishan";
#basic input and output
'''first_name = "Ishan"
second_name = "Agarwal"
age=51
is_genius=True

print(first_name,second_name)
print(age)
print(is_genius)'''

#string functions
'''print(name.upper())
print(name.find('sh'))
print(name.replace('ishan','Nomaan'))
print('I' in name)'''

#type conversions
'''#name=input("who is your superhero Tony :- ")
#print("Tony's superhero is :- "+ name)
#old_age=input("My age is: ")

#new_age=int(old_age)+2 #type conversion to int
#print("New age is: "+str(new_age))
#float() #type_conversions for float string and bool
#str()
#bool()

#arithmatic operators
#print(5 -,*,/,+ 2)
#print(5//1.8) will remove the decimal portion of answer
#print(5%2.2) modulus
#print(5.1 ** 2) something to the power'''

#comparision
'''print(3<2)
print(3==2)
print(3!=2)'''

#logical operators
'''print(3>2 or 5<2)
print(3>2 and 5<2)
print(not 5<2)

age=2
if age>=18:
    print("you are an adult")
    print("you can indulge in sexual activities")
elif age<18 and age>3:
    print("You are in school")
    print("Focus on ur studies")
else:
    print("Come on! You are a baby")
print(age)'''

#range
'''numbers=range(5) #0, 1, 2, 3, 4
print(numbers)'''

#while loops
'''i=1
while i<=5:
    print(i*"*") # that number of times '*' will be printed
    i+=1
for item in range(5):
    print(item+1)'''

#list
'''marks=[95,98,97] //list
print(marks[0])
print(marks[-1]) #count from backwards
print(marks[0:2]) #last index not inclusive
for score in marks:
    print(score)

marks.append(99)
print(marks)
marks.insert(-2,99) # append at a particular position
print(marks)
print(93 in marks)
print(len(marks)) #marks length

#marks.clear()
#print(marks)

for score in marks:
    if score == 97:
        continue
    print(score)'''

#tuple (it is immutable)
'''marks=(95,98,97,97,97) #tuple
marks=95,98,97,97,97 #by this way also we can define tuple
#marks[0]=96 we can't change it
print(marks.count(95))
print(marks.index(95))'''

#set (unordered)
'''marks={95,98,97,97,97}
print(marks) #not possible as set has does not have indexing
for score in marks:
    print(score)'''

#dictionary (key and value)
'''marks={"english":95,"hindi":90}
marks['chemistry']=91
print(marks["chemistry"])
marks['hindi']=89
print(marks['hindi'])'''

#functions -in-built,module,user defined
'''import math #all related functions stored in a single file
print(dir(math)) #print all functions
from math import sqrt #import sqrt from that module
from math import * #import all functions from that module
print(sqrt(4))'''

#user defined
'''def function_name(parameters):
   //do something
def print_sum(first,second=4):
    print(first+second)
print_sum(1)'''

