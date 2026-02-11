# # x=int(input("enter the first statement"))
# # y=int(input("enter the second statement "))
# # if x > y :
# #    print("x greatest ")

# # else:git add .
# # git commit -m "fix vercel api"
# # git push
# #     print(" y gretest")  

# a = int(input("enter the c marks"))
# b = int(input("enter the c marks"))
# c = int(input("enter the c marks"))
# # = int(input("enter the c marks"))
# x=a+b+c
# grad=x/3
# if grad>=90:
#     print("divisin i A")
# elif grad>=75:
#     print("grad is b")
# elif grad>=50:
#     print("grad is c")


# else :
#     print("fail")
# a = int(input("enter the year"))
# leap =a/4 
# if (leap==0):
#     print("this is leap year")
# else:
#     print("this is not leap year")    

# a = int(input("enter the c marks"))
# # b= int(input("enter the c marks"))
# # c = int(input("enter the c marks"))
# if a <10:
#     print("its single didgit number")
# elif a <100:
#     print("this is double digit")    
# else  :
#  print(" whwter is more than two didgit")
# a = int(input("enter the c marks"))
# #b= int(input("enter the c marks"))
# #c = int(input("enter the c marks"))
# if a <20:
#     print(" wether is cold")
# elif a <35:
#     print("weather is warm")    
# else  :
#  print(" weather is hot")

# a = int(input("enter the c marks"))
# #b= int(input("enter the c marks"))
# #c = int(input("enter the c marks"))
# if a >0:
#     print("number is positive")
#     if a%2==0:
#        print(a,"this is even number")
#     else:
#        print(a,"this odd number")    
# else  :
#     print("this is negative number")
# with open(r"C:\Users\Ultra 5\OneDrive\Desktop\filehadndling1.txt", "r") as file1:
#     content= file1.read()
#     print(content)
#     print(file1.readline())
#     lines =file1.readlines()
#     print(lines)
#     count=0
#     for line in file1:
#         print(line)
#         count+=1
#     print("number of student = ",count)    
#     #writ mode

# #     with open (r"C:\Users\Ultra 5\OneDrive\Desktop\filehadndling1.txt","w") as file1:
# #         file1.write("mohd vsaish siddique ,22, fatehpur \n jamil,22,maharajganj \n saif, 22,maharajganj\n")

# #     append mode 
# # with open(r"C:\Users\Ultra 5\OneDrive\Desktop\filehadndling1.txt","a") as file1:
# #     file1.write("mohd osama bin ladain ,23,dhartipur\n")

# #     read & write mode (+r)
# # with open(r"C:\Users\Ultra 5\OneDrive\Desktop\filehadndling1.txt","r+") as file1:
# #     lines  = file1.readlines()
# #     # file1.seek(0)
# #     # file1.write(data.replace("mohd vaishu,22,ftp","ayan,22,faizabad"))
# #     # file1.retucate()
# #     lines[0] = lines[0].replace(" mohd osama","khan")
# #     file1.seek(0)
# #     file1.writelines(lines)
# class and object 
#
 
# car1.start()
# car2.start()

# class Student:
#     def __init__(self, name, roll):
#         self.name = name
#         self.roll = roll
# s1 = Student("alice",100) 
# print(s1.name,s1.roll)


       
# inheritance 
# class Animal:
#     def speak(self):
#         print("Animal make  sounds")

# class Dog(Animal):
#     def bark(self):
#         print("Dog barks")
# d= Dog()
# d.speak()
# d.bark()        

# polymorphisum 
# car1.start()
# car2.start()

# class Student:
#     def __init__(self, name, roll):
#         self.name = name
#         self.roll = roll
# s1 = Student("alice",100) 
# print(s1.name,s1.roll)

# class shape :
#     def area(self,length,breadth):
#         print(length*breadth)  
# class Rectangle:
#     def area(self,length,breadth) :
#         self.length = length
#         self.breadth = breadth 



#         return (length*breadth)  
    
# ract = Rectangle()
# print(ract.area(15,10))

# encapsulation
# class BankAccount:
#     def __init__(self,owner,balance):
#        self.owner=owner
#        self.__balance = balance

#     def deposit(self,amount):
#         self.__balance +=amount
#     def get_balance(self):
#         return self.__balance
# acc = BankAccount("alice", 2000)
# acc.deposit(5000)
# print(acc.get_balance())

class Student:
#     def __init__(self ,marks):
        self.__marks = marks
    def display(self):
        return self.__marks
s1 = Student(95)    
print(s1.display()) 
class Employee:
    def __init__(self, salary):
        self.__salary = salary
    def display(self):
        return self.__salary
s2 = Employee(10000)
print(s2.display()) 
class Mobile:
    def __init__(self, price):
        self.__price = price
    def display(self):
        return self.__price
s4 = Mobile(100000)
print(s4.display())
# # class Person :
# #     def __init__(self, age):
# #         self.__age = age
# #     def display(self):
# #         return self.__age
# # s3 = Person(14)
# # print(s3.display())
# # q5
# # class Student:

# #     def __init__(self, age,name,clas):
# #         self.name = name
# #         self.__age = age
# #         self.clas = clas
# #     def display(self):
# #         print(self.name,self.__age,self.clas)
# #         # return  self.namme,self.age, self.clas
# # s1 = Student(67,"alone",4)
# # s1.display()
# # # print(s1.display())
        




#  class Car:
# #     def _init_(self,brand ,color):
# #      self.brand = brand
# #      self.color = color

# #     def start(self):
# #         print(f"{self.color}{self.brand}is starting...")
# # car1=Car("tesla","red")
# # car2=Car("BMW","BLACK")   