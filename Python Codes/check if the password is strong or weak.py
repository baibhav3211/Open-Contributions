


def password(v):
   
    # the password should not be a newline or space
    if v == "\n" or v == " ":
        return "Password cannot be a newline or space!"
   
    # the password length should be in between 9 and 20
    if 9 <= len(v) <= 20:
   
        # checks for occurrence of a character three or more times in a row
        if re.search(r'(.)\1\1', v):
            return "Weak Password"
   
        # checks for occurrence of same string pattern( minimum of two character length) repeating
        if re.search(r'(..)(.*?)\1', v):
            return "Weak password"
   
        else:
            return "Strong Password!"
   
    else:
        return "Password length must be 9-20 characters!"
  

def main():
   
    print(password("Yzog233%6"))
    print(password("00000000000"))
   
   
   if __name__ == '__main__':
    main()
    
    
#output
#strong password
#weak password
