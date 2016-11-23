#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max 30
struct naucnik{
	char ime[max];
	char prezime[max];
	unsigned bradova;
	char oblast[max];
	};
void ucitaj(char* ulaz,struct naucnik a[],int *brNaucnika);
void ispisi(char* izlaz,struct naucnik a[],int brNaucnika,int radovi);
void ukupnoradova(struct naucnik a[],int brNaucnika);
int main(int argc,char *argv[])
{
	int brNaucnika;
	struct naucnik a[max];
	char ulaz;
	char izlaz;
	unsigned radovi;
	strcpy(ulaz,argv[1]);
	strcpy(izlaz,argv[2]);
	radovi=atoi(argv[3]);
	
	ucitaj(ulaz,a,&brNaucnika);
	ispisi(izlaz,a,brNaucnika,radovi);
	ukupnoradova(a,brNaucnika);

	return 0;
}
void ucitaj(char* ulaz,struct naucnik a[],int *brNaucnika){
	FILE* f;
	int i;
	if((f=fopen(ulaz,"r"))==NULL){
	printf("Nije uspelo otvaranje datoteke\n");
	exit(EXIT_FAILURE);
	}
	while(fscanf(f,"%s",&a[i].ime)!=EOF && fscanf(f,"%s",&a[i].prezime)!=EOF && fscanf(f,"%d",&a[i].bradova)!=EOF && fscanf(f,"%s",&a[i].oblast)!=EOF)
	{
	i++;
	}
	*brNaucnika=i;
	fclose(f);
}
void ispisi(char* izlaz,struct naucnik a[],int brNaucnika,int radovi){
	FILE* f;
	if((f=fopen(izlaz,"w"))==NULL){
	printf("NIje uspelo otvaranje datoteke\n");
	exit(EXIT_FAILURE);
	}
	for(int i=0;i<brNaucnika;i++){
	if(a[i].bradova>radovi){
	fprintf(f,"%s %s %u %s \n",a[i].ime,a[i].prezime,a[i].bradova,a[i].oblast);}
	}
	fclose(f);
}
void ukupnoradova(struct naucnik a[],int brNaucnika){
		char uoblast[max];
		char izlaz2[max];
		int br;
		FILE* f;
		printf("Uneti oblast:");
		scanf("%s",uoblast);
		
		strcpy(izlaz2,uoblast);
		strcat(izlaz2,".txt");
		if((f=fopen(izlaz2,"w"))==NULL){
		printf("Nije uspelo otvaranje datoteke");
		exit(EXIT_FAILURE);
		}
		for(int i=0;i<brNaucnika;i++){
		if(!strcmp(a[i].oblast,uoblast)){
		br+=a[i].bradova;}
		}
		fprintf(f,"%d",br);
		fclose(f);
}







	
	
	
	
