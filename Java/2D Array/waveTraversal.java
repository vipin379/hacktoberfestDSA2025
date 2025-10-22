public class waveTraversal {
   
    public static void main(String[] args) {
        int[][] matrix = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}
        };
        
        System.out.println("Original Matrix:");
        displayMatrix(matrix);
        
        System.out.println("\nColumn-wise Wave with Steps:");
        columnWiseWaveWithSteps(matrix);
    }
    
    public static void columnWiseWaveWithSteps(int[][] matrix) {
        int rows = matrix.length;
        int cols = matrix[0].length;
        
        for (int j = 0; j < cols; j++) {
            System.out.println("\nColumn " + j + ":");
            
            if (j % 2 == 0) {
                System.out.println("Moving TOP to BOTTOM");
                for (int i = 0; i < rows; i++) {
                    System.out.println("  Element at [" + i + "][" + j + "] = " + matrix[i][j]);
                }
            } else {
                System.out.println("Moving BOTTOM to TOP");
                for (int i = rows - 1; i >= 0; i--) {
                    System.out.println("  Element at [" + i + "][" + j + "] = " + matrix[i][j]);
                }
            }
        }
        
        // Final wave order
        System.out.print("\nFinal Wave Order: ");
        for (int j = 0; j < cols; j++) {
            if (j % 2 == 0) {
                for (int i = 0; i < rows; i++) {
                    System.out.print(matrix[i][j] + " ");
                }
            } else {
                for (int i = rows - 1; i >= 0; i--) {
                    System.out.print(matrix[i][j] + " ");
                }
            }
        }
    }
    
    public static void displayMatrix(int[][] matrix) {
        for (int i = 0; i < matrix.length; i++) {
            for (int j = 0; j < matrix[i].length; j++) {
                System.out.print(matrix[i][j] + " ");
            }
            System.out.println();
        }
    }
}

