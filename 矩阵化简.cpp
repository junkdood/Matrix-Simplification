#include<stdio.h>
#include <math.h>

int main(){
	int total,t,n,m,i,r,I,rr,R;
	freopen("input.txt","r",stdin);
	FILE *fp=fopen("output.txt","w");
	scanf("%d",&total);
	fprintf(fp,"¾ØÕóÊý£º%d\n\n",total);
	double tt,z,bb;
	for(t=0;t<total;t++){
		bb=1;
		fprintf(fp,"¾ØÕó%d\n",t+1);
		scanf("%d %d",&n,&m);
		double a[n][m];
		double b[n][m];
		fprintf(fp,"ÐÐ£º%d ÁÐ£º%d\n",n,m);
		for(i=0;i<n;i++){
			for(r=0;r<m;r++){
				scanf("%lf",&a[i][r]);
			}
		}
		//ÊäÈëÊý×é 
		for(i=0;i<n;i++){
			for(r=0;r<n;r++){
				if(i==r){
					b[i][r]=1;
				}
				else{
					b[i][r]=0;
				}
			}
		}
		for(i=0,r=0;i<n;i++,r++){
			for(I=i+1;!(fabs(a[i][r]-0)>0.000001);I++){
				if(r>=m){
					break;
				}
				if(I>n-1){
					r++;
					I=i-1;
					continue;
				}
				for(R=0;R<m;R++){
					z=a[i][R];
					a[i][R]=a[I][R];
					a[I][R]=z;
					z=b[i][R];
					b[i][R]=b[I][R];
					b[I][R]=z;

				}
				bb=-bb;
			}
			//È·±£Ê×Ôª²»Îª0
			for(I=i;I<n;I++){
				tt=a[I][r];
				if(fabs(tt-0)>0.000001){
					for(R=0;R<m;R++){
						a[I][R]=a[I][R]/tt;
						b[I][R]=b[I][R]/tt;
					}
					bb=bb*tt;
				}
			}
			//Ê×ÔªÏÂ·½ËùÓÐÊý¾ÝÉèÎª1
			for(I=i+1;I<n;I++){
				if(fabs(a[I][r]-0)>0.000001){
					for(R=0;R<m;R++){
						a[I][R]=a[I][R]-a[i][R];
						b[I][R]=b[I][R]-b[i][R];
					}
				}
			}
			//ÔªÏÂ·½ËùÓÐÊý¾ÝÇåÁã
		}
		//»¯ÎªÖÐ¼äÌ¬
		fprintf(fp,"ÖÐ¼äÌ¬£º\n");
		for(i=0;i<n;i++){
			for(R=0;R<m-1;R++){
				 fprintf(fp,"%7.3f ",a[i][R]);
			}
			 fprintf(fp,"%7.3f\n",a[i][R]);
		}
		//Êä³öÖÐ¼äÌ¬ 
		for(i=n-1;i>=0;i--){
			for(R=0;R<m;R++){
				if(fabs(a[i][R]-1)<=0.000001){
					for(I=0;I<i;I++){
						tt=a[I][R];
						for(rr=0;rr<m;rr++){
							a[I][rr]=a[I][rr]-a[i][rr]*tt;
							b[I][rr]=b[I][rr]-b[i][rr]*tt;
						}
					}
					break;
				}
			}
		}
		//»Ø´ú
		fprintf(fp,"×îÖÕÌ¬£º\n");
		for(i=0;i<n;i++){
			for(R=0;R<m-1;R++){
				 fprintf(fp,"%7.3f ",a[i][R]);
			}
			 fprintf(fp,"%7.3f\n",a[i][R]);
		}
		if(m==n){
			fprintf(fp,"ÐÐÁÐÊ½£º%6.3f\n",bb*a[n-1][m-1]);
		}
		if(m==n&&!(fabs(a[n-1][m-1]-0)<=0.000001)){
			fprintf(fp,"Äæ¾ØÕó£º\n");
			for(i=0;i<n;i++){
				for(R=0;R<m-1;R++){
					fprintf(fp,"%7.3f ",b[i][R]);
				}
				fprintf(fp,"%7.3f\n",b[i][R]);
			}
		}
		fprintf(fp,"\n");
		//Êä³öÊý×é 
	}
	fclose(fp);
	return 0;
}
