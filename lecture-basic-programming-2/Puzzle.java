import java.util.ArrayList;
class State {
    int[][] board;
    State previous;
}

public class Puzzle { 
    public static void main(String[] args) {
        int[][] problem = {{0,1,2},{5,6,3},{4,7,8}};
        // int[][] problem = {{1,2,3},{4,0,5},{7,8,6}};
        int[][] destination = {{1,2,3},{4,5,6},{7,8,0}};
        ArrayList<State> evaluated = new ArrayList<State>();
        ArrayList<State> possibility = new ArrayList<State>();
        State problemState = new State();
        problemState.board = problem;
        evaluated.add(problemState);

        evaluate(evaluated, possibility);
        while(possibility.size() > 0 && !isEqual(evaluated.get(evaluated.size() - 1).board, destination)) {
            evaluate(evaluated, possibility);
        }
        State lastState = evaluated.get(evaluated.size() - 1);
        if (isEqual(lastState.board, destination)) {
            State state = lastState;
            String solution = "";
            while(state != null) {
                solution = getPrintedBoard(state.board) + solution;
                state = state.previous;
            }
            System.out.println("Solution:\n" + solution);
        } else {
            System.out.println("Solution not found");
        }
    }

    public static void evaluate(ArrayList<State> qEvaluated, ArrayList<State> qPossibility) {
        State lastEvaluatedState = qEvaluated.get(qEvaluated.size() - 1);
        // kiri
        int[][] leftBoard = moveLeft(lastEvaluatedState.board);
        if (!isBoardEvaluated(qEvaluated, leftBoard)) {
            State leftState = new State();
            leftState.board = leftBoard;
            leftState.previous = lastEvaluatedState;
            qPossibility.add(leftState);
        }
        // kanan
        int[][] rightBoard = moveRight(lastEvaluatedState.board);
        if (!isBoardEvaluated(qEvaluated, rightBoard)) {
            State rightState = new State();
            rightState.board = rightBoard;
            rightState.previous = lastEvaluatedState;
            qPossibility.add(rightState);
        }
        // atas
        int[][] upBoard = moveUp(lastEvaluatedState.board);
        if (!isBoardEvaluated(qEvaluated, upBoard)) {
            State upState = new State();
            upState.board = upBoard;
            upState.previous = lastEvaluatedState;
            qPossibility.add(upState);
        }
        // bawah
        int[][] downBoard = moveDown(lastEvaluatedState.board);
        if (!isBoardEvaluated(qEvaluated, downBoard)) {
            State downState = new State();
            downState.board = downBoard;
            downState.previous = lastEvaluatedState;
            qPossibility.add(downState);
        }
        // ambil dari possibility terdepan, pindahkan ke evaluated
        if (qPossibility.size() > 0) {
            State firstPossibility = qPossibility.get(0);
            qPossibility.remove(0);
            qEvaluated.add(firstPossibility);
        }
        // tampilkan
        /*
        System.out.println("Evaluated");
        printQueue(qEvaluated);
        System.out.println("Possibility");
        printQueue(qPossibility);
        */
    }

    public static int[][] moveDown(int[][] board) {
        int[][] newBoard = new int[3][3];
        int zeroRow = findZeroRow(board);
        int zeroCol = findZeroCol(board);
        for (int rowIndex=0; rowIndex < board.length; rowIndex++) {
            for (int colIndex=0; colIndex < board[rowIndex].length; colIndex++) {
                if (rowIndex == zeroRow && colIndex == zeroCol && zeroRow < 2) {
                    newBoard[rowIndex][colIndex] = board[rowIndex + 1][colIndex];
                } else if (rowIndex == zeroRow + 1 && colIndex == zeroCol && zeroRow < 2) {
                    newBoard[rowIndex][colIndex] = 0;
                } else {
                    newBoard[rowIndex][colIndex] = board[rowIndex][colIndex];
                }
            }
        }
        return newBoard;
    }

    public static int[][] moveUp(int[][] board) {
        int[][] newBoard = new int[3][3];
        int zeroRow = findZeroRow(board);
        int zeroCol = findZeroCol(board);
        for (int rowIndex=0; rowIndex < board.length; rowIndex++) {
            for (int colIndex=0; colIndex < board[rowIndex].length; colIndex++) {
                if (rowIndex == zeroRow && colIndex == zeroCol && zeroRow > 0) {
                    newBoard[rowIndex][colIndex] = board[rowIndex - 1][colIndex];
                } else if (rowIndex == zeroRow - 1 && colIndex == zeroCol && zeroRow > 0) {
                    newBoard[rowIndex][colIndex] = 0;
                } else {
                    newBoard[rowIndex][colIndex] = board[rowIndex][colIndex];
                }
            }
        }
        return newBoard;
    }

    public static int[][] moveRight(int[][] board) {
        int[][] newBoard = new int[3][3];
        int zeroRow = findZeroRow(board);
        int zeroCol = findZeroCol(board);
        for (int rowIndex=0; rowIndex < board.length; rowIndex++) {
            for (int colIndex=0; colIndex < board[rowIndex].length; colIndex++) {
                if (rowIndex == zeroRow && colIndex == zeroCol && zeroCol < 2) {
                    newBoard[rowIndex][colIndex] = board[rowIndex][colIndex+1];
                } else if (rowIndex == zeroRow && colIndex == zeroCol + 1 && zeroCol < 2) {
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

    public static String getPrintedBoard(int[][] board) {
        String result = "";
        for (int rowIndex=0; rowIndex < board.length; rowIndex++) {
            String row = "  ";
            for (int colIndex=0; colIndex < board[rowIndex].length; colIndex++) {
                row += board[rowIndex][colIndex] + " ";
            }
            result += row + "\n";
        }
        result += "\n";
        return result;
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
