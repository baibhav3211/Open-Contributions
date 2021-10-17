#PYTHON PROGRAM TO ADD A NEW NODE AT THE END OF A CIRCULAR LINKED LIST

#The node of list.    
class Node:    
  def __init__(self,value):    
    self.value = value;    
    self.next = None;    
     
class CreateList:    
  #Declaring start and end pointer as null.    
  def __init__(self):    
    self.start = Node(None);    
    self.end = Node(None);    
    self.start.next = self.end;    
    self.end.next = self.start;    
        
  #This function will append to the end of the list.    
  def addAtEnd(self,value):    
    new_node = Node(value);    
    #Checks for an empty list.    
    if self.start.value is None:    
      #start and end will point to new_node if the class is empty.    
      self.start = new_node;    
      self.end = new_node;    
      new_node.next = self.start;    
    else:    
      #end will point to new node.    
      self.end.next = new_node;    
      #New node will become new end.    
      self.end = new_node;    
      # end will point to start as it is circular linked list     
      self.end.next = self.start;    
     
  #Displays all the nodes in the list    
  def display(self):    
    current = self.start;    
    if self.start is None:    
      print("List is empty");    
      return;    
    else:    
        print("Adding nodes to the end of the list: ");    
        #Prints each node by incrementing pointer.    
        print(current.value),    
        while(current.next != self.start):    
            current = current.next;    
            print(current.value),    
        print("\n");    
     
class CircularLinkedList:    
    cl = CreateList();    
    #Adding 1 to the list    
    cl.addAtEnd(1);    
    cl.display();    
    #Adding 2 to the list    
    cl.addAtEnd(2);    
    cl.display();    
    #Adding 3 to the list    
    cl.addAtEnd(3);    
    cl.display();    
    #Adding 4 to the list    
    cl.addAtEnd(4);    
    cl.display();    
