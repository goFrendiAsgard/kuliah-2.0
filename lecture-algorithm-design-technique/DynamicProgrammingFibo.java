import java.util.HashMap;
public class DynamicProgrammingFibo {

  static long fibo (long number) {
    if (number < 3) {
      return 1;
    }
    return fibo(number - 1) + fibo(number - 2);
  }

  static HashMap<Long,Long> memo = new HashMap<Long,Long>();
  static long fiboDynamic (long number) {
    Long value = memo.get(number);
    if (value != null) {
      return value;
    }
    if (number < 3) {
      value = (long)1;
    } else {
      value = fiboDynamic(number - 1) + fiboDynamic(number - 2);
    }
    memo.put(number, value);
    return value;
  }

  public static void main (String[] args) {
    System.out.println("fiboDynamic(20) " + fiboDynamic(20));
    System.out.println("fibo(20) " + fibo(20));
    System.out.println("fiboDynamic(50) " + fiboDynamic(50));
    System.out.println("fibo(50) " + fibo(50));
  }

}
