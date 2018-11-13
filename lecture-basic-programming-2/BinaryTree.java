class Node {
    float data;
    Node left;
    Node right;
}

public class BinaryTree {
    static Node root;
    public static void main(String[] args) {
        addToTree(5);
        addToTree(8);
        addToTree(7);
        addToTree(6);
        addToTree(9);
        addToTree(3);
        addToTree(4);
        addToTree(1);
        addToTree(2);
        System.out.println(root.data); // 5
        System.out.println(root.left.left.right.data); // 2
    }
    public static void addToTree(float number) {
        // TODO: your implementation
    }
}
