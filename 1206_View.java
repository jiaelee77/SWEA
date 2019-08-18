//1206. [S/W 문제해결 기본] 1일차 - View

import java.util.*;


public class Solution {


	static Scanner sc=new Scanner(System.in);
	static int buildings[]=new int[1000];
	static int result=0;
	
	public static void init() {
		
		for(int i=0;i<1000;i++) {
			buildings[i]=0;
		}
		
		result=0;
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		for(int tc=0;tc<10;tc++) {
			int t_len=0;
			t_len=sc.nextInt();
			
			init();
			
			for(int i=0;i<t_len;i++) {
				buildings[i]=sc.nextInt();
			}
		
			for(int i=2;i<t_len-2;i++) {
				
				//check left && right
				if(buildings[i]>buildings[i-1] && buildings[i]>buildings[i-2]
						&& buildings[i]>buildings[i+1] && buildings[i]>buildings[i+2]) {
					
					int max=0;
					if(buildings[i-2]>=max) max=buildings[i-2];
					if(buildings[i-1]>=max) max=buildings[i-1];
					if(buildings[i+1]>=max) max=buildings[i+1];
					if(buildings[i+2]>=max) max=buildings[i+2];
					
					result += (buildings[i]-max);
				}
			}
			
			System.out.println("#"+(tc+1)+" "+result);
			
		}

	}

}