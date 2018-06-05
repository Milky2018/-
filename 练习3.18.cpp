#include <stdio.h>

int yuan, fang, hua;
void numgo(int c);
void comment(void);
void quote(int c);

void main()
{
	int c;
	while((c=getchar())!=EOF){
		if(c=='/'){
			if((c=getchar())=='*')
				comment();
			else
				numgo(c);
		} else if (c=='\''||c=='"')
			quote(c);
		else
			numgo(c);
		if(hua<0){
			printf("lack of \"{\"\n");
			hua=0;
		}else if(fang<0){
			printf("lack of \"{\"\n");
			fang=0;
		}else if(yuan<0){
			printf("lack of \"(\"\n");
			yuan=0;
		}
		
	}
	if (hua>0) printf("lack of \"}\"\n");
	if (fang>0) printf("lack of \"]\"\n");
	if (yuan>0) printf("lack of \")\"\n");
}

void quote(int c)
{
	int d;
	while((d=getchar())!=c)
		if (d=='\\')
			getchar();
}

void comment()
{
	int c, d;
	c=getchar();
	d=getchar();
	while(c!='*'||d!='/'){
		c=d;
		d=getchar();
	}
}

void numgo(int c)
{
	if (c=='{') hua++;
	if (c=='}') hua--;
	if (c=='[') fang++;
	if (c==']') fang--;
	if (c=='(') yuan++;
	if (c==')') yuan--;
}