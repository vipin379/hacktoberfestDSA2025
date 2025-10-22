public class rotate {
   
    public static void main(String[] args) {
        int[][] matrix = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}
        };
        
        System.out.println("Original Matrix:");
        displayMatrix(matrix);
        
        // Rotate 90 degrees clockwise
        int[][] rotated = rotate90Clockwise(matrix);
        System.out.println("\nAfter 90° clockwise rotation:");
        displayMatrix(rotated);
    }
    
    public static int[][] rotate90Clockwise(int[][] matrix) {
        int rows = matrix.length;
        int cols = matrix[0].length;
        
        // Create new array for rotated matrix
        int[][] rotated = new int[cols][rows];
        
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                // The magic formula for 90° clockwise rotation
                rotated[j][rows - 1 - i] = matrix[i][j];
            }
        }
        return rotated;
    }
    
    // Bonus: In-place rotation for square matrices
    public static void rotate90ClockwiseInPlace(int[][] matrix) {
        int n = matrix.length;
        
        // Step 1: Transpose the matrix
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }
        
        // Step 2: Reverse each row
        for (int i = 0; i < n; i++) {
            int left = 0, right = n - 1;
            while (left < right) {
                int temp = matrix[i][left];
                matrix[i][left] = matrix[i][right];
                matrix[i][right] = temp;
                left++;
                right--;
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

