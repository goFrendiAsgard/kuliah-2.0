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