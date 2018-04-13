import java.util.ArrayList;

class Node {
  String name;
  Node parent;
  ArrayList <Node> children;

  public Node(String name, Node parent) {
    this.name = name;
    this.children = new ArrayList<Node>();
    this.parent = parent;
    parent.children.add(this);
  }

  public Node(String name) {
    this.name = name;
    this.children = new ArrayList<Node>();
  }
}

public class Backtracking {
  public static void main (String[] args) {

    // init tree
    Node root = new Node("A");
    Node b = new Node("B", root); Node c = new Node("C", root); Node d = new Node("D", root);
    Node e = new Node("E", b); Node f = new Node("F", b);
    Node g = new Node("G", c); Node h = new Node("H", c);
    Node i = new Node("I", d); Node j = new Node("J", d);

    // define next, currentNode, and traversed
    ArrayList<Node>next = new ArrayList<Node>(); // either stack or queue
    ArrayList<Node>traversed = new ArrayList<Node>();
    Node currentNode = root;
    Node destinationNode = h;

    // DFS
    while(currentNode != destinationNode && currentNode != null) {
      for (Node child: currentNode.children) {
        next.add(child);
      }
      traversed.add(currentNode);
      if (next.size() > 0) {
        currentNode = next.get(next.size() - 1);
        next.remove(next.size() - 1);
      } else {
        currentNode = null;
      }
      // show the process
      printNodeArray(next, "next");
      if (currentNode != null) {
        printNode(currentNode, "current");
      }
      printNodeArray(traversed, "traversed");
    }
    printPath(currentNode, "path");

  }

  public static void printPath(Node node, String caption) {
    System.out.print(caption + ": ");
    String result = "";
    Node current = node;
    while(current != null) {
      result += current.name + " ";
      current = current.parent;
    }
    System.out.println(result);
  }

  public static void printNode(Node node, String caption) {
    System.out.println(caption + ": " + node.name);
  }

  public static void printNodeArray(ArrayList<Node> nodeList, String caption) {
    System.out.print(caption + ": ");
    for (Node node: nodeList) {
      System.out.print(node.name + " ");
    }
    System.out.println();
  }

}
