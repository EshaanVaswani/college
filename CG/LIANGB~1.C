#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<graphics.h>

void main(){
	int gd = DETECT,gm;
	int xmin, xmax, ymin, ymax;
	int i,x1,y1,x2,y2;
	int p[4],q[4];
	float t,t1=0.0,t2=1.0;
	int dx,dy;
	clrscr();

	initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");

	printf("Enter window coordinates:");
	scanf("%d%d%d%d",&xmin,&ymin,&xmax,&ymax);

	printf("Enter coordinates of A:");
	scanf("%d%d",&x1,&y1);

	printf("Enter coordinates of B:");
	scanf("%d%d",&x2,&y2);

	line(x1,y1,x2,y2);

	rectangle(xmin,ymin,xmax,ymax);

	dx=x2-x1;
	dy=y2-y1;

	p[0]=-dx;
	p[1]=dx;
	p[2]=-dy;
	p[3]=dy;

	q[0]=x1-xmin;
	q[1]=xmax-x1;
	q[2]=y1-ymin;
	q[3]=ymax-y1;

	for(i=0;i<4;i++){
		t=q[i]/p[i];
		if(p[i]==0){
			printf("Line is parallel");
			if(q[i]<0){
				printf("Line is outside the boundary");
			} else {
				printf("Line is inside the boundary");
			}
		} else if(p[i]<0) {
			t1=max(0,t);
		} else {
			t2=min(1,t);
		}
	}

	if(t1>t2){
		printf("Line is invisible");
	}

	if(t1>0){
		x1=x1+(t1*dx);
		y1=y1+(t1*dy);
	}

	if(t2<1){
		x2=x1+(t2*dx);
		y2=x1+(t2*dy);
	}

	cleardevice();

	rectangle(xmin,ymin,xmax,ymax);
	line(x1,y1,x2,y2);

	getch();
}