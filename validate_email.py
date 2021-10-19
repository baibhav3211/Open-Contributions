# Python program to validate an Email
 
# import re module
import re
 
# Regular expression to validate an Email
regex = r'\b[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\.[A-Z|a-z]{2,}\b'
 
# Define a function for validating an Email
 
 
def check(mail):
 
    # pass the regular expression
    # and the string into the fullmatch() method
    if(re.fullmatch(regex, mail)):
        print("Valid mail")
 
    else:
        print("Invalid mail")
 
 
# Driver Code
if __name__ == '__main__':
 
    # Enter the Email-id
    mail = "xyzabc@gmail.com"
 
    # calling run function
    check(mail)
 
    
