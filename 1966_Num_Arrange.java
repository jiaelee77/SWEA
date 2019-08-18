//1966. 숫자를 정렬하자


import java.util.*;


public class Solution {
	
	static Scanner sc= new Scanner(System.in);
	static int arr[]=new int[50];
	public static void main(String args[]) throws Exception{
		
		int T=0;
		
		T=sc.nextInt();
		
		for(int tc=1;tc<=T;tc++) {
			int n;
			n=sc.nextInt();
			
			for(int i=0;i<n;i++) arr[i]=sc.nextInt();

			for(int c=n;c>1;c--) {
				for(int i=0;i<c-1;i++) {
					if(arr[i]>arr[i+1]) {
						int temp=0;
						temp=arr[i];
						arr[i]=arr[i+1];
						arr[i+1]=temp;
					}
					
				}
			}
			System.out.print("#"+tc+ " ");
			for(int i=0;i<n;i++) System.out.print(arr[i]+" ");
			System.out.println();
		}
	}
}