#include<cstdio>
#include<string.h>

int main(){
	int TC;
	int arr[10001];
	int index = -1;
	scanf("%d", &TC);
	for(int i=1; i<=TC; i++){
		char s[10];
		scanf("%s", &s);
		if(!strcmp(s, "push")){
			int n;
			index++;
			scanf("%d", &n);
			arr[index] = n;
		}
		else if(!strcmp(s, "top")){
			if(index == -1){
				printf("-1\n");
				continue;
			}
			printf("%d\n", arr[index]);
		}
		else if(!strcmp(s, "size")){
			printf("%d\n", index+1);
		}
		else if(!strcmp(s, "empty")){
			int result = index == -1 ? 1 : 0;
			printf("%d\n", result);
		}
		else if(!strcmp(s, "pop")){
			if(index == -1){
				printf("-1\n");
				continue;
			}
			printf("%d\n", arr[index]);
			arr[index] = 0;
			index--;
		}
	}
	return 0;
}