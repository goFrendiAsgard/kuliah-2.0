# https://github.com/goFrendiAsgard/kuliah-2.0/tree/master/workshop-tdd-basic

# Writing program without Unittest

```java
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
                case 2 : result = subs(n1, n2);
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
    public static int subs(int n1, int n2) {
        return n1 - n2;
    }
    public static int mult(int n1, int n2) {
        return n1 * n2;
    }
    public static int special(int n1, int n2) {
        return mult(add(n1, n2), subs(n1, n2));
    }
}
```

**Cons:**

* You can't make sure that the program is really working unless you run it
* You have to try all possible test-case manually
    - `+ 4 5`
    - `- 4 5`
    - `* 4 5`
    - `s 4 5`
* One simple change in a single line can make your entire program unusable

# TDD to the rescue

* TDD: Test Driven Development
* You write the test before writing anything else
* Why?
    - It enforce you to clearly clarify what you want to do
    - Testing is less painful
    - More confidence

# Let's do the TDD

```java
class MyTest {
    public static void main(String[] args) {
        test("add works", MyProgram.add(4, 5) == 9);
        test("sub works", MyProgram.sub(4, 5) == -1);
        test("mult works", MyProgram.mult(4, 5) == 20);
        test("special works", MyProgram.special(4, 5) == -9);
    }

    public static void test(String description, boolean statement) {
        if (!statement) {
            throw(new Error("[FAILED] " + description));
        }
        System.out.println("[PASS] " + description);
    }
}
```
* Run the test whenever you change anything
* Do refactoring only when all of your test passed
* Create unittest before doing anything else

# Unit-test Frameworks

* JUnit (Java)
* Mocha (Javascript)
* Jest (Javascript)
* unittest (Python)