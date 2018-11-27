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
        printTree();
        deleteNode(4);
        deleteNode(1);
        deleteNode(8);
        printTree();
    }

    public static void deleteNode(float data) {
        Node node = findNodeInTree(data);
        Node parent = findParentInTree(node.data);
        boolean nodeHavingChild = isHavingChild(node);
        boolean nodeIsRoot = isRoot(node);
        boolean nodeIsLeftChild = isLeftChild(node);
        boolean nodeIsRightChild = isRightChild(node);
        boolean nodeHaveLeftChild = isHavingLeftChild(node);
        boolean nodeHaveRightChild = isHavingRightChild(node);
        if (!nodeHavingChild) { // tidak punya anak
            if (nodeIsRoot) {     // dan adalah root
                root = null;
            } else if (nodeIsLeftChild) { // dan adalah anak kiri
                parent.left = null;
            } else if (nodeIsRightChild) { // dan adalah anak kanan
                parent.right = null;
            }
        } else if (nodeHaveLeftChild && nodeHaveRightChild) { // jika hanya punya anak kiri
        } else if (nodeHaveLeftChild) { // jika hanya punya anak kiri
            if (nodeIsRoot) {
                root = node.left;
            } else if (nodeIsLeftChild) {
                parent.left = node.left;
            } else if (nodeIsRightChild) {
                parent.right = node.left;
            }
        } else if (nodeHaveRightChild) { // jika hanya punya anak kanan
            if (nodeIsRoot) {
                root = node.right;
            } else if (nodeIsLeftChild) {
                parent.left = node.right;
            } else if (nodeIsRightChild) {
                parent.right = node.right;
            }
        }
    }

    public static boolean isRoot(Node node) {
        return node == root;
    }

    public static boolean isRightChild(Node node) {
        Node parent = findParentInTree(node.data);
        return parent != null && parent.right == node;
    }

    public static boolean isLeftChild(Node node) {
        Node parent = findParentInTree(node.data);
        return parent != null && parent.left == node;
    }

    public static boolean isHavingChild(Node node) {
        return isHavingRightChild(node) || isHavingRightChild(node);
    }

    public static boolean isHavingLeftChild(Node node) {
        return node.left != null;
    }

    public static boolean isHavingRightChild(Node node) {
        return node.right != null;
    }

    public static Node findParentInTree(float data) {
        return findParent(root, data);
    }

    public static Node findParent(Node node, float data) {
        if (node == null) {
            return null;
        }
        if ((node.left != null && node.left.data == data) || (node.right != null && node.right.data == data)) {
            return node;
        }
        Node result = findParent(node.left, data);
        if (result == null) {
            result = findParent(node.right, data);
        }
        return result;
    }


    public static Node findNodeInTree(float data) {
        return findNode(root, data);
    }

    public static Node findNode(Node node, float data) {
        if (node == null) {
            return null;
        }
        if (node.data == data) {
            return node;
        }
        Node result = findNode(node.left, data);
        if (result == null) {
            result = findNode(node.right, data);
        }
        return result;
    }

    public static void printTree() {
        System.out.println();
        printNode(root, "", "ROOT : ");
        System.out.println();
    }

    public static void printNode(Node node, String spaces, String prefix) {
        System.out.println(spaces + prefix + node.data);
        if (node.left != null) {
            printNode(node.left, spaces + "  ", "L: ");
        }
        if (node.right != null) {
            printNode(node.right, spaces + "  ", "R: ");
        }
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
