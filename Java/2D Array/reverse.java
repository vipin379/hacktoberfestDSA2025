public class reverse {
   
    public static void main(String[] args) {
        int[][] matrix = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}
        };
        
        System.out.println("Original Matrix:");
        displayMatrix(matrix);
        
        // Reverse each row
        reverseRows(matrix);
        System.out.println("\nAfter reversing each row:");
        displayMatrix(matrix);
        
        // Reverse the entire matrix (row order)
        reverseEntireMatrix(matrix);
        System.out.println("\nAfter reversing entire matrix:");
        displayMatrix(matrix);
    }
    
    // Method to reverse each row individually
    public static void reverseRows(int[][] matrix) {
        for (int i = 0; i < matrix.length; i++) {
            int left = 0;
            int right = matrix[i].length - 1;
            
            while (left < right) {
                // Swap elements
                int temp = matrix[i][left];
                matrix[i][left] = matrix[i][right];
                matrix[i][right] = temp;
                
                left++;
                right--;
            }
        }
    }
    
    // Method to reverse the order of rows
    public static void reverseEntireMatrix(int[][] matrix) {
        int top = 0;
        int bottom = matrix.length - 1;
        
        while (top < bottom) {
            // Swap entire rows
            int[] temp = matrix[top];
            matrix[top] = matrix[bottom];
            matrix[bottom] = temp;
            
            top++;
            bottom--;
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

