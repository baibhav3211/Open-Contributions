"""

class dog:
    dogs = [] #list of dogs this is not specific to any object this is a class variable
    xc = 5  # class variable


    def __init__(self , name):
        self.name = name
        self.dogs.append(self)

    @classmethod      # these are known as decorators
    def num_dogs(cls):      # cls is the name of the class
        return len(cls.dogs)
    # class is added here to use class variable

    @staticmethod
    def bark():
        # barks n times
        for i in range(n):
            print("bark")

    # static methods cant use class variables and class methods
    # these are just normal function defined inside the class for importing purposes


tim = dog("tim")
jim = dog("jim")
# print(dog.dogs) # can be called with the name of the class can also be called to a particular object
# print(len(dog.dogs))
# print(dog.num_dogs())
# print(tim.num_dogs())
# above used and stated class methos

"""


from oops_python import NotPrivate

test = NotPrivate('tim')
test.display()