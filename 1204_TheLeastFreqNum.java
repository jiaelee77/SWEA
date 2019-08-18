//1204. [S/W 문제해결 기본] 1일차 - 최빈수 구하기
import java.util.*;

public class Solution {

	
	
	static int tc=0;
	static int score[] = new int[101];
	
	
	
	public static void init() {
		
		
		for(int i=0;i<101;i++) {
			score[i]=0;
		}
		
	}
	public static void main(String[] args) {
		
		Scanner sc=new Scanner(System.in);

		int test_case=0;
		test_case=sc.nextInt();
		
		for(int t=0;t<test_case;t++) {
			init();
			
			tc=sc.nextInt();
		
			int temp=0;
			
			for(int i=0;i<1000;i++) {
				
				temp=sc.nextInt(); //System.out.print(temp+" ");
				score[temp]++;
				
			//	System.out.println(temp);
				
			}
			
			int max=-1;
			int result=-1;
			
			for(int i=0;i<101;i++) {
				if(score[i]>=max) {
					max=score[i];
					result=i;
				}
			}
			
			System.out.println("#"+tc+" "+result);
		}
		
		
		
		// TODO Auto-generated method stub

	}

}

