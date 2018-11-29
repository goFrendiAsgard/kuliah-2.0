class Node {
    double data;
    Node left;
    Node right;
}

public class BinaryTreeC {
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
        addToTree(6.5);
        System.out.println(root.data); // 5
        System.out.println(root.left.data); // 3
        System.out.println(root.right.data); // 8
        System.out.println(root.left.left.right.data); // 2

        Node parentOfRootLeft = findParentInTree(root.left);
        System.out.println(parentOfRootLeft.data); // 5

        Node parentOfRootLeftLeftRight = findParentInTree(root.left.left.right);
        System.out.println(parentOfRootLeftLeftRight.data); // 1

        Node parentOfRoot = findParent(root, root);
        System.out.println(parentOfRoot);

        printTree(); // complete tree

        deleteFromTree(root.left.left); // delete 1
        deleteFromTree(root.right.right); // delete 9
        deleteFromTree(root);

        printTree(); // complete tree after 1 & 9 deleted
    }

    public static void deleteFromTree(Node node) {
        Node parent = findParentInTree(node);
        if(!isHaveChild(node)) { // kalau node yang dihapus nggak punya anak
            if (node == root) { // dan node yang dihapus adalah root
                root = null;
            } else { // dan node yang dihapus bukan root
                deleteFromParent(parent, node);
            }
        } else if (isHaveLeftChild(node) && !isHaveRightChild(node)) { // punya anak kiri doang
            if (node == root) { // dan dia root
                root = node.left;
            } else if (isLeftChild(node)) { // dan dia sendiri anak kiri
                parent.left = node.left;
            } else { // tapi dia sendiri anak kanan
                parent.right = node.left;
            }
        } else if (isHaveRightChild(node) && !isHaveLeftChild(node)) { // punya anak kanan doang
            if (node == root) { // dan dia root
                root = node.right;
            } else if (isLeftChild(node)) { // tapi dia sendiri anak kiri
                parent.left = node.right;
            } else { // dan dia sendiri anak kanan
                parent.right = node.right;
            }
        } else { // punya dua anak
            // cari kandidat
            Node candidate = node.right;
            while(candidate.left != null) {
                candidate = candidate.left;
            }
            // jadikan anaknya kandidat sebagai pengganti kandidat
            Node candidateParent = findParentInTree(candidate);
            candidateParent.left = candidate.right;
            // kandidat menggantikan node yang dihapus
            candidate.left = node.left;
            candidate.right = node.right;
            if (node == root) { // dan yang dihapus root
                root = candidate;
            } else if (isLeftChild(node)) { // dan dia sendiri anak kiri
                parent.left = candidate;
            } else { // dan dia sendiri anak kanan
                parent.right = candidate;
            }
        }
    }

    public static void deleteFromParent(Node parent, Node node) {
        if (parent != null) {
            if (parent.left == node) {
                parent.left = null;
            } else if (parent.right == node) {
                parent.right = null;
            }
        }
    }

    public static boolean isLeftChild(Node node) {
        Node parent = findParentInTree(node);
        return parent != null && parent.left == node;
    }

    public static boolean isRightChild(Node node) {
        Node parent = findParentInTree(node);
        return parent != null && parent.right == node;
    }

    public static boolean isHaveLeftChild(Node node) {
        return node.left != null;
    }

    public static boolean isHaveRightChild(Node node) {
        return node.right != null;
    }

    public static boolean isHaveChild(Node node) {
        return isHaveRightChild(node) || isHaveLeftChild(node);
    }

    public static Node findParentInTree(Node node) {
        return findParent(root, node);
    }

    public static Node findParent(Node ancestor, Node node) {
        if (ancestor.left == node || ancestor.right == node) {
            return ancestor;
        }
        Node parent = null;
        if (ancestor.left != null) {
            parent = findParent(ancestor.left, node);
        }
        if (parent == null && ancestor.right != null) {
            parent = findParent(ancestor.right, node);
        }
        return parent;
    }

    public static void printTree() {
        System.out.println();
        printNode(root, "", "Root: ");
        System.out.println();
    }

    public static void printNode(Node node, String prefix, String label) {
        if (node != null) {
            System.out.println(prefix + label + node.data);
            if (node.left != null) {
                printNode(node.left, prefix + " ", "L: ");
            }
            if (node.right != null) {
                printNode(node.right, prefix + " ", "R: ");
            }
        }
    }

    public static void addToTree(double number) {
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
