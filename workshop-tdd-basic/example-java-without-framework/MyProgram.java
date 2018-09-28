import java.util.Scanner;

public class MyProgram {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int operation = 0;
        do {
            operation = input.nextInt();
            if (operation == 5) {
                break;
            }
            int n1 = input.nextInt();
            int n2 = input.nextInt();
            int result = 0;
            switch(operation) {
                case 1 : result = add(n1, n2);
                case 2 : result = sub(n1, n2);
                case 3 : result = mult(n1, n2);
                case 4 : result = special(n1, n2);
            }
            System.out.println(result);
        } while (operation != 5);
        input.close();
    }

    public static int add(int n1, int n2) {
        return n1 + n2;
    }
    public static int sub(int n1, int n2) {
        return n1 - n2;
    }
    public static int mult(int n1, int n2) {
        return n1 * n2;
    }
    public static int special(int n1, int n2) {
        return mult(add(n1, n2), sub(n1, n2));
    }
}