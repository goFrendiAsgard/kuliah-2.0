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
        System.out.println(root.left.data); // 3
        System.out.println(root.right.data); // 8
        System.out.println(root.left.left.right.data); // 2
    }
    public static void addToTree(float number) {
        Node node = new Node();
        node.data = number;
        if (root == null) {
            root = node;
        } else {
            addToNode(root, node);
        }
    }
    public static void addToNode(Node parent, Node newNode) {
        if(newNode.data < parent.data) {
            if (parent.left == null) {
                parent.left = newNode;
            } else {
                addToNode(parent.left, newNode);
            }
        } else if (newNode.data > parent.data) {
            if (parent.right == null) {
                parent.right = newNode;
            } else {
                addToNode(parent.right, newNode);
            }
        }
    }
}
