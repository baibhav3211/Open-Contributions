#Python program to insert a new node at the middle of the Circular Linked List

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
      self.size = 0;    
        
    #This will add the new node to the list.    
    def add(self,value):    
       new_node = Node(value);    
       #Checks if the list is empty.    
       if self.start.value is None:    
         #start and end would point to new node if the list is empty.    
         self.start = new_node;    
         self.end = new_node;    
         new_node.next = self.start;    
       else:    
         #end will point to new node.    
         self.end.next = new_node;    
         #New node will become new end.    
         self.end = new_node;    
         #Since, it is circular linked list end will points to start.    
         self.end.next = self.start;    
       #Size will count the number of element in the list    
       self.size = self.size+1;    
        
    #This function will add the new node at the middle of the list.    
    def addInMid(self,value):    
        new_node = Node(value);    
        #Checks if the list is empty.    
        if(self.start == None):    
            #start and end would point to new node if the list is empty.    
            self.start = new_node;    
            self.end = new_node;    
            new_node.next = self.start;    
        else:    
            #Store the mid-point of the list    
            count = (self.size//2) if (self.size % 2 == 0) else ((self.size+1)//2);    
            #temp will point to start    
            temp = self.start;    
            for i in range(0,count):    
                #Current will point to node before temp.    
                current = temp;    
                #Traverse through the list till the middle of the list is reached    
                temp = temp.next;    
            #current will point to new node    
            current.next = new_node;    
            #new node will point to temp    
            new_node.next = temp;    
        self.size = self.size+1;    
            
    #Displays all the nodes in the list    
    def display(self):    
      current = self.start;    
      if self.start is None:    
        print("List is empty");    
        return;    
      else:    
          #Prints each node by incrementing pointer.    
          print(current.value),    
          while(current.next != self.start):    
              current = current.next;    
              print(current.value),    
        
     
class CircularLinkedList:    
    cl = CreateList();    
    #Adds value to the list    
    cl.add(1);    
    cl.add(2);    
    cl.add(3);    
    cl.add(4);    
    print("Original list: \n");    
    cl.display();    
    #Inserting node '5' in the middle    
    cl.addInMid(5);    
    print("Updated List: \n");    
    cl.display();    
    #Inserting node '6' in the middle    
    cl.addInMid(6);    
    print("Updated List: ");    
    cl.display();    
