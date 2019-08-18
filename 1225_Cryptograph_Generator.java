//1225. [S/W 문제해결 기본] 7일차 - 암호생성기

import java.util.Scanner;

public class Solution {
	
	static Scanner sc=new Scanner(System.in);
	static int[] q=new int[8];
	
	
	
	public static void main(String args[]) throws Exception {
		
		
		for(int t=1;t<=10;t++ ) {
	
			
			int tc=sc.nextInt();
			

			for(int i=0;i<8;i++) {
				q[i]=sc.nextInt();
			}

			
			boolean isFinish=false;
			
			while(isFinish==false) {
				
				int minus=1;
				//System.out.print("new");
		
				for(int c=0;c<5;c++) {//1 cycle
					
					int temp=0;
					
					temp=q[0];
					
					for(int i=1;i<8;i++) {
						q[i-1]=q[i];
						
					}

					if((temp-minus) <=0) {
						q[7]=0;
						isFinish=true;
						break;
					}
					else {
						q[7]= (temp-minus);
					}

					minus++;

				}
			}
			
			
			System.out.print("#"+tc+" ");
			
			for(int i=0;i<8;i++) System.out.print(q[i]+" ");
			System.out.println();
			
		}
	}

}