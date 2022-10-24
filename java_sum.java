import java.util.Scanner;

public class test6
{
	public static void main(String args[])
	{
	Scanner one = new Scanner(System.in);
	double num1, num2, total;

	System.out.println("Enter first number");
	num1 = one.nextInt();

	System.out.println("Enter secont number");
	num2 = one.nextInt();

	total=num1+num2;

	System.out.print("Answer is " + total);
	}
}
