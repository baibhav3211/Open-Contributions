#Python program to insert a new node at the beginning of the Circular Linked List

#The node of list.    
class Node:    
  def __initialize__(self,value):    
    self.value = value;    
    self.next = None;    
     
class CreateList:    
  #Declaring start and end pointer as null.    
  def __initialize__(self):    
    self.start = Node(None);    
    self.end = Node(None);    
    self.start.next = self.end;    
    self.end.next = self.start;    
        
  #This will add at the start of the list.    
  def addAtStart(self,value):    
    new_node = Node(value);    
    #Checks for an empty list.    
    if self.start.value is None:    
      #start and end would point to new node if the list is empty.    
      self.start = new_node;    
      self.end = new_node;    
      new_node.next = self.start;    
    else:    
        #Stores value into temporary node    
        temp = self.start;    
        #New node will point to temp as next node    
        new_node.next = temp;    
        #New node will be the start node    
        self.start = new_node;    
        #end will point to start as it is a circular linked list.    
        self.end.next = self.start;    
     
  #Displays all the nodes in the list    
  def display(self):    
    current = self.start;    
    if self.start is None:    
      print("List is empty");    
      return;    
    else:    
        print("Adding nodes to the start of the list: ");    
        #Prints each node by incrementing pointer to 1.    
        print(current.value),    
        while(current.next != self.start):    
            current = current.next;    
            print(current.value),    
        print("\n");    
     
class CircularLinkedList:    
  cl = CreateList();    
      
  #Adding 1 to the list    
  cl.addAtStart(1);    
  cl.display();    
  #Adding 2 to the list    
  cl.addAtStart(2);    
  cl.display();    
  #Adding 3 to the list    
  cl.addAtStart(3);    
  cl.display();    
  #Adding 4 to the list    
  cl.addAtStart(4);    
  cl.display();    
