//Starting with basic input and display of 2D Array.

import java.util.Scanner;

public class basic {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Step 1: Get array dimensions from user
        System.out.print("Enter number of rows: ");
        int rows = scanner.nextInt();
        System.out.print("Enter number of columns: ");
        int cols = scanner.nextInt();
        
        // Step 2: Create 2D array
        int[][] matrix = new int[rows][cols];
        
        // Step 3: Take input from user
        System.out.println("Enter the elements of the matrix:");
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                System.out.print("Enter element at position [" + i + "][" + j + "]: ");
                matrix[i][j] = scanner.nextInt();
            }
        }
        
        // Step 4: Display the matrix
        System.out.println("\nYour 2D Array:");
        displayMatrix(matrix);
        
        scanner.close();
    }
    
    // Method to display 2D array
    public static void displayMatrix(int[][] matrix) {
        for (int i = 0; i < matrix.length; i++) {
            for (int j = 0; j < matrix[i].length; j++) {
                System.out.print(matrix[i][j] + " ");
            }
            System.out.println();
        }
    }
}