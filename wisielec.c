#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include "f_obrazek.c"//That function is drawing image.
#include "f_wyborGracza.c"//That function is letting player to choose game mode.
#include "f_stopka.c"//That function is printing ending.

/* [c] Jakub Mosakowski 12.2016
	Simple game: "Hangman - Wisielec"
*/
int main()
{
	char lit;
	char gracz1[20],gracz2[20],slowo[30];
	int i,il=0,licz,proba=10,flaga=0,flaga2=0,wybor1;

	for(i=0;i<200;i++)// Clearing screen.
		printf("\n");	
	for(i=0;i<30;i++)
		slowo[i]='_';
	printf("\n\n\t\t\tWitaj w grze \"Hangman - Wisielec\".\n");
	printf("\t\t\t\tŻyczę Ci dobrej zabawy!\n\n");
	wybor1=f_wyborGracza();
	if(wybor1==1){
	//tu wprowadzić funkcja do gry dla jednego gracza.
		printf("Naciśnij enter aby zakończyć.");
		while('\n'!=getchar());
	}
	else if(wybor1==2){
	for(i=0;i<200;i++)// Clearing screen.
		printf("\n");	
	printf("\nGracz numer 1 wymyśla hasło, gracz numer 2 je zgaduje.\n");
	printf("Podaj nazwę gracza numer 1:");
	scanf("%s",gracz1);
	while('\n'!=getchar());
	printf("Podaj nazwę gracza numer 2:");
	scanf("%s",gracz2);
	while('\n'!=getchar());
	printf("%s podaj jedno słowo, które będzie zgadywał/a %s:",gracz1,gracz2);

	do{//Checking input = is it letter or not.
		il=0;
		if(flaga==1 || flaga2==1)
			printf("Twoje słowo może zawierać tylko litery! Podaj je ponownie:");
		scanf("%s",slowo);
		flaga=0;
		flaga2=0;
		for(i=0;i<30;i++){
			if((slowo[i]>96 && slowo[i]<123) || (slowo[i]>64 && slowo[i]<91))
				il++;
			else if(slowo[i]!=0 && slowo[i]!='_'){
				flaga=1;
				for(i=0;i<30;i++)
					slowo[i]='_';
			}	
		}
		for(i=0;i<il;i++)
			if(slowo[i]=='_')
				flaga2=1;
	}while(flaga==1 || flaga2==1);
	char slowo2[il],pustaTab[il];

	for(i=0;i<il;i++){// From lower case to upper case.
		slowo[i]=toupper(slowo[i]);
		slowo2[i]=slowo[i];
		pustaTab[i]='_';
	}
	while('\n'!=getchar());

	for(i=0;i<200;i++)// Clearing screen.
		printf("\n");
	printf("%s masz %d prób.\n",gracz2,proba);
	printf("Ilość liter w słowie podanym przez gracza %s:%d.\nHasło: ",gracz1,il);
	for(i=0;i<il;i++)
		printf("%c",pustaTab[i]);
	printf("\n");
	while(proba>0)
	{
		printf("%s podaj jedną literę: ",gracz2);
		lit = getchar();
		while('\n'!=getchar());
		while(!((lit>96 && lit<123) || (lit>64 && lit<91))){//Checking input is it letter or not.
			printf("Możesz podawać tylko litery! Spróbuj ponownie:");
			lit = getchar();
			while('\n'!=getchar());
		}
		lit = toupper(lit);
		licz=0;
	
		for(i=0;i<il;i++)
		{
			
			if (slowo2[i]==lit)
			{
				licz=licz+1;
				pustaTab[i]=slowo2[i];
			}
		}
		if(licz<1)
		{
			printf("\nNie ma litery %c. \n",lit);
			proba=proba-1;
			f_obrazek(proba);
		}
		else
		{
			printf("\nLitera %c jest w wyrazie.\nIlość: %d\n",lit,licz);	
			f_obrazek(proba);
		}
		printf("Hasło: ");
		for(i=0;i<il;i++)
		{
			printf("%c",pustaTab[i]);
		}		
		if( strcmp(slowo,pustaTab)!=0 )
		{
			printf("\n\nZostało Ci %d prób.\n\n",proba);
			printf("-------------------------------------------------\n\n");
		}
		else
		{
			printf("\n\n-------------------------------------------------\n\n");
			printf("\nGratulacje, zgadłeś/aś!\n%s wygrywa!\n\n\n",gracz2);
			proba=-1;
		}
	}
	if(proba==0)
	{
		printf("\nHasło to: ");
		for(i=0;i<il;i++)
		{
			printf("%c",slowo2[i]);
		}
		printf("\n\n%s, niestety, nie udało Ci się zgadnąć :(.\nWygrywa %s!\n\n\n",gracz2,gracz1);
	}
		printf("Naciśnij enter aby zakończyć.");
		while('\n'!=getchar());
	}
		f_stopka();//POPRAW PRZESUNIĘCIE.
	return 0;
}	
