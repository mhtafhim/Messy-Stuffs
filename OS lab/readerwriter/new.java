import java.util.concurrent.Semaphore;
import java.util.LinkedList;

public class ReaderWriter {
    static int readCount = 0;
    static Semaphore m = new Semaphore(1);
    static Semaphore w = new Semaphore(1);
    static LinkedList<Integer> buffer = new LinkedList<>();

    static class Read implements Runnable {
        @Override
        public void run() {
            try {
                // Acquire Section
                m.acquire();
                readCount++;
                if (readCount == 1) {
                    w.acquire();
                }
                m.release();

                // Reading section
                System.out.println("Reader " + Thread.currentThread().getName() + " is reading");
                System.out.println("Data in Buffer : " + buffer);
                Thread.sleep(1500);
                System.out.println("Reader " + Thread.currentThread().getName() + " has finished reading");

                // Leaving section
                m.acquire();
                readCount--;
                if(readCount == 0) {
                    w.release();
                }
                m.release();
            } catch (InterruptedException e) {
                System.out.println(e.getMessage());
            }
        }
    }

    static class Write implements Runnable {
        @Override
        public void run() {
            try {
                w.acquire();
                System.out.println("Writer " + Thread.currentThread().getName() + " is writing");
                buffer.add((int) (Math.random() * 100));
                System.out.println("Data in Buffer after writing: " + buffer);
                Thread.sleep(2500);
                System.out.println("Writer " + Thread.currentThread().getName() + " has finished writing");
                w.release();
            } catch (InterruptedException e) {
                System.out.println(e.getMessage());
            }
        }
    }

    public static void main(String[] args) throws Exception {
        Read read = new Read();
        Write write = new Write();
        Thread t1 = new Thread(read);
        t1.setName("thread1");
        Thread t2 = new Thread(read);
        t2.setName("thread2");
        Thread t3 = new Thread(write);
        t3.setName("thread3");
        Thread t4 = new Thread(read);
        t4.setName("thread4");
        t1.start();
        t2.start();
        t3.start();
        t4.start();
    }
}
