# Python program to check validation of password


#Primary conditions for password validation :

#Minimum 8 characters.
#the alphabets must be between [a-z]
#At least one alphabet should be of Upper Case [A-Z]
#At least 1 number or digit between [0-9].
#At least 1 character from [ _ or @ or $ ].



#code
import re
password = "YxoG233$"
temp = 0
while True:  
    if (len(password)<8):
        temp = -1
        break
    elif not re.search("[a-z]", password):
        temp = -1
        break
    elif not re.search("[A-Z]", password):
        temp = -1
        break
    elif not re.search("[0-9]", password):
        temp = -1
        break
    elif not re.search("[_@$]", password):
        temp = -1
        break
    elif re.search("\s", password):
        temp = -1
        break
    else:
        temp = 0
        print("Valid Password")
        break
  
if temp ==-1:
    print("inalid Password")
    

#output
#Valid Password
