import java.util.Scanner;

class FactorialThread extends Thread {
    public FactorialThread(int number) {
        long factorial = 1;
        for (int i = 1; i <= number; i++) {
            factorial *= i;
        }
        System.out.println("Factorial of " + number + " is: " + factorial);
    }
}

class SumThread extends Thread {
    public SumThread(int number) {
        int sum = 0;
        for (int i = 1; i <= number; i++) {
            sum += i;
        }
        System.out.println("Sum of numbers up to " + number + " is: " + sum);
    }
}

public class MultiThreadExample {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);

        System.out.print("Enter a number: ");
        int number = s.nextInt();

        FactorialThread factorialThread = new FactorialThread(number);
        SumThread sumThread = new SumThread(number);

        factorialThread.start();
        sumThread.start();

        s.close();
    }
}
