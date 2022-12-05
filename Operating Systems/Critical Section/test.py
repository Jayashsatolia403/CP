from threading import *
import time
import os 


count = 0

# lock = Lock()

def task():
    global count
    for i in range(1000000):
        count += 1

def task2():
    global count
    for i in range(1000000):
        count += 1

        

# def task1():
#     for i in range(1000):
#         print("Task 1 :", i)

# def task2():
#     for i in range(1000):
#         print("Task 2 :", 10000+i)

# if __name__ == '__main__':
#     t2 = Thread(target=task1)
#     t3 = Thread(target=task2)
#     t2.start()
#     t3.start()
#     t2.join()
#     t3.join()

if __name__ == '__main__':
    t1 = Thread(target=task)
    t2 = Thread(target=task2)
    # t3 = Thread(target=task)
    # t4 = Thread(target=task)
    # t5 = Thread(target=task)
    # t6 = Thread(target=task)
    # t7 = Thread(target=task)
    # t8 = Thread(target=task)
    # t9 = Thread(target=task)
    # t10 = Thread(target=task)
    # t11 = Thread(target=task)

    t1.start()
    t2.start()
    # t3.start()
    # t4.start()
    # t5.start()
    # t6.start()
    # t7.start()
    # t8.start()
    # t9.start()
    # t10.start()
    # t11.start()

    t1.join()
    t2.join()
    # t3.join()
    # t4.join()
    # t5.join()
    # t6.join()
    # t7.join()
    # t8.join()
    # t9.join()
    # t10.join()
    # t11.join()

    print(count)