from threading import Semaphore, Thread
import time


s = Semaphore(3)

def task(name):
    s.acquire()

    for i in range(5):
        print(name)
        # time.sleep(1)
    
    s.release()

if __name__ == "__main__":
    t1 = Thread(target=task, args=("t1",))
    t2 = Thread(target=task, args=("t2",))
    t3 = Thread(target=task, args=("t3",))
    t4 = Thread(target=task, args=("t4",))
    t5 = Thread(target=task, args=("t5",))

    t1.start()
    t2.start()
    t3.start()
    t4.start()
    t5.start()

    t1.join()
    t2.join()
    t3.join()
    t4.join()
    t5.join()