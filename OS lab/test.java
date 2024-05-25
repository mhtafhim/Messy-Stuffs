package readerWritter;

import java.util.concurrent.Semaphore;



public class ReaderWriterTest {
    public static void main(String[] args) {
//        Semaphore mutex = new Semaphore(1);
//        Semaphore db = new Semaphore(1);
//        Semaphore writerMutex = new Semaphore(1);
//        Semaphore exclusiveLock = new Semaphore(1);
        
        Shared.buffer.add(10);
        Shared.buffer.add(20);

        Thread readerThread1 = new Thread(new Reader(new Semaphore(1), new Semaphore(1)));
        Thread readerThread2 = new Thread(new Reader(new Semaphore(1), new Semaphore(1)));
        Thread readerThread3 = new Thread(new Reader(new Semaphore(1), new Semaphore(1)));
        Thread readerThread4 = new Thread(new Reader(new Semaphore(1), new Semaphore(1)));
        Thread writerThread1 = new Thread(new Writer(new Semaphore(1), new Semaphore(1),new Semaphore(1)));
        Thread writerThread2 = new Thread(new Writer(new Semaphore(1), new Semaphore(1),new Semaphore(1)));

       writerThread1.start();
       readerThread1.start();
       writerThread2.start();
       readerThread2.start();
       readerThread3.start();
       readerThread4.start();
        
      
    }
}


package readerWritter;


import java.util.concurrent.Semaphore;

class Reader implements Runnable {
//    private Semaphore mutex;
//    private Semaphore db;
   
    private String mode;

    public Reader(Semaphore mutex, Semaphore db) {
        Sema.mutex = mutex;
        Sema.db = db;
        mode = "Reader";
    }

    @Override
    public void run() {
        while (true)
        {
            try {
            //	System.out.println( mode + " " + Thread.currentThread().getId() + " is waiting.");
                Sema.mutex.acquire();
                Shared.readCount++;
                if (Shared.readCount == 1) {
                    Sema.db.acquire();
                }
                
                Sema.mutex.release();
        
                {
               
                	System.out.println("Data in Buffer : " + Shared.buffer);
                    System.out.println("Reader " + Thread.currentThread().getName() + " reads " + Shared.data);
                	Thread.sleep(2500);
                	
                }
              
                
               
                Sema.mutex.acquire();

                System.out.println("Reader  "+Thread.currentThread().getName() + " Leaving " );
                
                Shared.readCount--;
                
                if (Shared.readCount == 0) {
                    Sema.db.release();
                }
                Sema.mutex.release();
            } catch (InterruptedException e) {
                Thread.currentThread().interrupt();
            }
        }
    }
}


package readerWritter;


import java.util.concurrent.Semaphore;

class Reader implements Runnable {
//    private Semaphore mutex;
//    private Semaphore db;
   
    private String mode;

    public Reader(Semaphore mutex, Semaphore db) {
        Sema.mutex = mutex;
        Sema.db = db;
        mode = "Reader";
    }

    @Override
    public void run() {
        while (true)
        {
            try {
            //	System.out.println( mode + " " + Thread.currentThread().getId() + " is waiting.");
                Sema.mutex.acquire();
                Shared.readCount++;
                if (Shared.readCount == 1) {
                    Sema.db.acquire();
                }
                
                Sema.mutex.release();
        
                {
               
                	System.out.println("Data in Buffer : " + Shared.buffer);
                    System.out.println("Reader " + Thread.currentThread().getName() + " reads " + Shared.data);
                	Thread.sleep(2500);
                	
                }
              
                
               
                Sema.mutex.acquire();

                System.out.println("Reader  "+Thread.currentThread().getName() + " Leaving " );
                
                Shared.readCount--;
                
                if (Shared.readCount == 0) {
                    Sema.db.release();
                }
                Sema.mutex.release();
            } catch (InterruptedException e) {
                Thread.currentThread().interrupt();
            }
        }
    }
}



package readerWritter;

import java.util.concurrent.Semaphore;

class Writer implements Runnable {
//    private Semaphore db;
//    private Semaphore writerMutex;
    private static int writerCount = 0;
    private String mode;

    public Writer(Semaphore db, Semaphore writerMutex,Semaphore exclusivelock) {
        Sema.db = db;
        Sema.writerMutex = writerMutex;
        mode = "Writer";
        Sema.exclusiveLock = exclusivelock;
    }

    @Override
    public void run() {
   //     while (true)
        {
            try {
         
                Sema.writerMutex.acquire();
                writerCount++;
                if (writerCount == 1) {
                    Sema.db.acquire();
                }
                Sema.writerMutex.release();
                
                Sema.exclusiveLock.acquire();
           
              
                Shared.buffer.add((int) (Math.random() * 100));
             //   Shared.data++;
                Thread.sleep(1500);
                System.out.println("Thread "+Thread.currentThread().getName() + " has finished WRITING and Leaving");
               
          
                Sema.exclusiveLock.release();
                Sema.writerMutex.acquire();
                writerCount--;
                if (writerCount == 0) {
                    Sema.db.release();
                }
                Sema.writerMutex.release();
            } catch (InterruptedException e) {
                Thread.currentThread().interrupt();
            }
        }
    }
}