def palin_string(strng):
    strng = strng.lower()
    return strng == strng[::-1]

strng = input("Input a String: ")

if palin_string(strng):
	print("\n", strng, " is palindrome.")
else:
	print(strng, " is not a palindrome")
