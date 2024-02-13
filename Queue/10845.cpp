#include<cstdio>
#include<string.h>

int main(){
	int TC;
	int arr[10001];
	int start = 0;
	int end = -1;
	scanf("%d", &TC);
	for(int i=1; i<=TC; i++){
		char s[10];
		scanf("%s", &s);
		if(!strcmp(s, "push")){
			int n;
			end++;
			scanf("%d", &n);
			arr[end] = n;
		}
		else if(!strcmp(s, "front")){
			if(start > end){
				printf("-1\n");
				continue;
			}
			printf("%d\n", arr[start]);
		}
		else if(!strcmp(s, "back")){
			if(start > end){
				printf("-1\n");
				continue;
			}
			printf("%d\n", arr[end]);
		}		
		else if(!strcmp(s, "size")){
			printf("%d\n", end-start+1);
		}
		else if(!strcmp(s, "empty")){
			int result =  end-start == -1 ? 1 : 0;
			printf("%d\n", result);
		}
		else if(!strcmp(s, "pop")){
			if(end-start == -1){
				printf("-1\n");
				continue;
			}
			printf("%d\n", arr[start]);
			arr[start] = 0;
			start++;
		}
	}
	return 0;
}