// Reader Writer Problem using Semaphores
//ID : 20200204006
//Mahmudul Haque Tafhim

import java.util.concurrent.Semaphore;

class Shared {
    static int data = 0;
}

class Reader implements Runnable {
    private Semaphore mutex;
    private Semaphore db;
    private static int readCount = 0;

    public Reader(Semaphore mutex, Semaphore db) {
        this.mutex = mutex;
        this.db = db;
    }

    @Override
    public void run() {
        while (true) {
            try {
                mutex.acquire();
                readCount++;
                if (readCount == 1) {
                    db.acquire();
                }
                mutex.release();

                System.out.println("Reader " + Thread.currentThread().getId() + " reads " + Shared.data);

                mutex.acquire();
                readCount--;
                if (readCount == 0) {
                    db.release();
                }
                mutex.release();
            } catch (InterruptedException e) {
                Thread.currentThread().interrupt();
            }
        }
    }
}


class Writer implements Runnable {
    private Semaphore db;
    private Semaphore writerMutex;
    private Semaphore exclusiveLock;
    private static int writerCount = 0;

    public Writer(Semaphore db, Semaphore writerMutex, Semaphore exclusiveLock) {
        this.db = db;
        this.writerMutex = writerMutex;
        this.exclusiveLock = exclusiveLock;
    }

    @Override
    public void run() {
        while (true) {
            try {
                writerMutex.acquire();
                writerCount++;
                if (writerCount == 1) {
                    db.acquire();
                }
                writerMutex.release();

                exclusiveLock.acquire();
                Shared.data++;
                System.out.println("Writer " + Thread.currentThread().getId() + " writes " + Shared.data);
                exclusiveLock.release();

                writerMutex.acquire();
                writerCount--;
                if (writerCount == 0) {
                    db.release();
                }
                writerMutex.release();
            } catch (InterruptedException e) {
                Thread.currentThread().interrupt();
            }
        }
    }
}

public class Main {
    public static void main(String[] args) {
        Semaphore mutex = new Semaphore(1);
        Semaphore db = new Semaphore(1);
        Semaphore writerMutex = new Semaphore(1);
        Semaphore exclusiveLock = new Semaphore(1);

        Thread readerThread1 = new Thread(new Reader(mutex, db));
        Thread readerThread2 = new Thread(new Reader(mutex, db));
        Thread readerThread3 = new Thread(new Reader(mutex, db));
        Thread readerThread4 = new Thread(new Reader(mutex, db));
        Thread writerThread1 = new Thread(new Writer(db, writerMutex, exclusiveLock));
        Thread writerThread2 = new Thread(new Writer(db, writerMutex, exclusiveLock));

        writerThread1.start();
       
        readerThread1.start();
        writerThread2.start();
        readerThread2.start();
        readerThread3.start();
        readerThread4.start();
        
    }
}
