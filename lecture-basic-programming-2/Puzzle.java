import java.util.ArrayList;
class State {
    int[][] board;
    State previous;
}

public class Puzzle {

    public static void main(String[] args) {
        int[][] problem = {{1,2,3},{4,0,5},{7,8,6}};
        int[][] destination = {{1,2,3},{4,5,6},{7,8,0}};
        ArrayList<State> evaluated = new ArrayList<State>();
        ArrayList<State> possibility = new ArrayList<State>();
        State problemState = new State();
        problemState.board = problem;
        evaluated.add(problemState);

        evaluate(evaluated, possibility);
        System.out.println("Evaluated");
        printQueue(evaluated);
        System.out.println("Possibility");
        printQueue(possibility);
    }

    public static void evaluate(ArrayList<State> qEvaluated, ArrayList<State> qPossibility) {
        State lastEvaluatedState = qEvaluated.get(qEvaluated.size() - 1);
        // kiri
        int[][] leftBoard = moveLeft(lastEvaluatedState.board);
        if (!isBoardEvaluated(qEvaluated, leftBoard)) {
            State leftState = new State();
            leftState.board = leftBoard;
            qPossibility.add(leftState);
        }
        // kanan
        int[][] rightBoard = moveRight(lastEvaluatedState.board);
        if (!isBoardEvaluated(qEvaluated, rightBoard)) {
            State rightState = new State();
            rightState.board = rightBoard;
            qPossibility.add(rightState);
        }
    }

    public static int[][] moveRight(int[][] board) {
        int[][] newBoard = new int[3][3];
        int zeroRow = findZeroRow(board);
        int zeroCol = findZeroCol(board);
        for (int rowIndex=0; rowIndex < board.length; rowIndex++) {
            for (int colIndex=0; colIndex < board[rowIndex].length; colIndex++) {
                if (rowIndex == zeroRow && colIndex == zeroCol && zeroCol < 3) {
                    newBoard[rowIndex][colIndex] = board[rowIndex][colIndex+1];
                } else if (rowIndex == zeroRow && colIndex == zeroCol + 1 && zeroCol < 3) {
                    newBoard[rowIndex][colIndex] = 0;
                } else {
                    newBoard[rowIndex][colIndex] = board[rowIndex][colIndex];
                }
            }
        }
        return newBoard;
    }

    public static int[][] moveLeft(int[][] board) {
        int[][] newBoard = new int[3][3];
        int zeroRow = findZeroRow(board);
        int zeroCol = findZeroCol(board);
        for (int rowIndex=0; rowIndex < board.length; rowIndex++) {
            for (int colIndex=0; colIndex < board[rowIndex].length; colIndex++) {
                if (rowIndex == zeroRow && colIndex == zeroCol && zeroCol > 0) {
                    newBoard[rowIndex][colIndex] = board[rowIndex][colIndex-1];
                } else if (rowIndex == zeroRow && colIndex == zeroCol - 1 && zeroCol > 0) {
                    newBoard[rowIndex][colIndex] = 0;
                } else {
                    newBoard[rowIndex][colIndex] = board[rowIndex][colIndex];
                }
            }
        }
        return newBoard;
    }

    public static boolean isBoardEvaluated(ArrayList<State> qEvaluated, int[][] board) {
        for (int index=0; index < qEvaluated.size(); index++) {
            if (isEqual(board, qEvaluated.get(index).board)) {
                return true;
            }
        }
        return false;
    }

    public static boolean isEqual(int[][] board1, int[][] board2) {
        for (int rowIndex=0; rowIndex < board1.length; rowIndex++) {
            for (int colIndex=0; colIndex < board1[rowIndex].length; colIndex++) {
                if (board1[rowIndex][colIndex] != board2[rowIndex][colIndex]) {
                    return false;
                }
            }
        }
        return true;
    }

    public static int findZeroCol(int[][] board) {
        for (int rowIndex=0; rowIndex < board.length; rowIndex++) {
            for (int colIndex=0; colIndex < board[rowIndex].length; colIndex++) {
                if (board[rowIndex][colIndex] == 0) {
                    return colIndex;
                }
            }
        }
        return -1;
    }

    public static int findZeroRow(int[][] board) {
        for (int rowIndex=0; rowIndex < board.length; rowIndex++) {
            for (int colIndex=0; colIndex < board[rowIndex].length; colIndex++) {
                if (board[rowIndex][colIndex] == 0) {
                    return rowIndex;
                }
            }
        }
        return -1;
    }

    public static void printQueue(ArrayList<State> queue) {
        for (int index=0; index<queue.size(); index++) {
            printBoard(queue.get(index).board);
        }
    }

    public static void printBoard(int[][] board) {
        for (int rowIndex=0; rowIndex < board.length; rowIndex++) {
            String row = "  ";
            for (int colIndex=0; colIndex < board[rowIndex].length; colIndex++) {
                row += board[rowIndex][colIndex] + " ";
            }
            System.out.println(row);
        }
        System.out.println("");
    }
}
