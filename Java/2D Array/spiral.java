public class spiral {
    
    public static void main(String[] args) {
        // Rectangular matrix (3x5)
        int[][] matrix = {
            {1, 2, 3, 4, 5},
            {6, 7, 8, 9, 10},
            {11, 12, 13, 14, 15}
        };
        
        System.out.println("Original Matrix (3x5):");
        displayMatrix(matrix);
        
        System.out.println("\nSpiral Traversal:");
        printSpiral(matrix);
        
        // Generate spiral for rectangular matrix
        System.out.println("\n\nGenerated Spiral (4x3):");
        int[][] rectSpiral = generateRectangularSpiral(4, 3);
        displayMatrix(rectSpiral);
    }
    
    public static int[][] generateRectangularSpiral(int rows, int cols) {
        int[][] matrix = new int[rows][cols];
        int value = 1;
        
        int top = 0, bottom = rows - 1;
        int left = 0, right = cols - 1;
        
        while (top <= bottom && left <= right) {
            // Right →
            for (int i = left; i <= right; i++) {
                matrix[top][i] = value++;
            }
            top++;
            
            // Down ↓
            for (int i = top; i <= bottom; i++) {
                matrix[i][right] = value++;
            }
            right--;
            
            // Left ←
            if (top <= bottom) {
                for (int i = right; i >= left; i--) {
                    matrix[bottom][i] = value++;
                }
                bottom--;
            }
            
            // Up ↑
            if (left <= right) {
                for (int i = bottom; i >= top; i--) {
                    matrix[i][left] = value++;
                }
                left++;
            }
        }
        
        return matrix;
    }
    
    public static void printSpiral(int[][] matrix) {
        if (matrix.length == 0) return;
        
        int rows = matrix.length;
        int cols = matrix[0].length;
        
        int top = 0, bottom = rows - 1;
        int left = 0, right = cols - 1;
        
        while (top <= bottom && left <= right) {
            // Right
            for (int i = left; i <= right; i++) {
                System.out.print(matrix[top][i] + " ");
            }
            top++;
            
            // Down
            for (int i = top; i <= bottom; i++) {
                System.out.print(matrix[i][right] + " ");
            }
            right--;
            
            // Left
            if (top <= bottom) {
                for (int i = right; i >= left; i--) {
                    System.out.print(matrix[bottom][i] + " ");
                }
                bottom--;
            }
            
            // Up
            if (left <= right) {
                for (int i = bottom; i >= top; i--) {
                    System.out.print(matrix[i][left] + " ");
                }
                left++;
            }
        }
    }
    
    public static void displayMatrix(int[][] matrix) {
        for (int i = 0; i < matrix.length; i++) {
            for (int j = 0; j < matrix[i].length; j++) {
                System.out.printf("%3d ", matrix[i][j]);
            }
            System.out.println();
        }
    }
}

