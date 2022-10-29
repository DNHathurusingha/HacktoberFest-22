import java.util.Scanner;

public class MatrixMultiplication {
	
  //method to display the result array
	public static void Display(int [][] a)
	{
		for (int i = 0; i < a.length; i++) {
			for (int j = 0; j < a[0].length; j++) {
				
				System.out.print(a[i][j]+" "); 
				
			}
			System.out.println();
		}
	}
	
  //main method
public static void main(String[] args) {
		

		//instantiating Scanner object
		Scanner scn = new Scanner(System.in);
		
  //size of 1st array
                System.out.println("Enter the size of 1st array i.e row & col");
		int r1 = scn.nextInt();
		int c1 = scn.nextInt();
		
		int [][] oneArray = new int[r1][c1]; 
		
  //input of 1st array
  		System.out.println("Enter the element of 1st array");
		for (int i = 0; i < oneArray.length; i++) {
			for (int j = 0; j < oneArray[0].length; j++) {
				
				oneArray[i][j] = scn.nextInt(); 
				
			}
		}
		
  
    //size of 2nd array
    		System.out.println("Enter the size of 2nd array i.e row & col");
		int r2 = scn.nextInt();
		int c2 = scn.nextInt();
		
		int [][] twoArray = new int[r2][c2]; 
		
  //input of 2nd array
  		System.out.println("Enter the element of 2nd array");
		for (int i = 0; i < twoArray.length; i++) {
			for (int j = 0; j < twoArray[0].length; j++) {
				
				twoArray[i][j] = scn.nextInt(); 
				
			}
		}
		
  //base case
		if(c1 != r2)
		{
			System.out.println("Invalid input");
			return;
		}
		
  //new array to store the result array
		int [][] prdArray = new int[r1][c2]; 
		
  //multiplication of 3 arrays
		for (int i = 0; i < prdArray.length; i++) {
			for (int j = 0; j < prdArray[0].length; j++) {
				
				for(int k = 0; k<c1 ; k++)
				{
					prdArray[i][j] = prdArray[i][j] + oneArray[i][k] * twoArray[k][j];
				}
				
			}
		}
		
  //calling display method
		Display(prdArray);
	
}

}
