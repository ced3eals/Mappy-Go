#include <stdlib.h>
#include <stdio.h>
#include <termios.h> 
#include <fcntl.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include "deplacements.h"

void my_delay(double i){    /*Pause l'application pour i seconds{*/
	clock_t start,end;
	start=clock();
	while(((end=clock())-start)<=i*CLOCKS_PER_SEC);
}

void msg_bvn(){
	char c;
	FILE * fic;
	fic = fopen("welcome.txt","r");

	while((c=fgetc(fic))!=EOF){
		printf("%c", c);
	}
}

void end(){
	int i;
	FILE * file;
	file = fopen ( "end_message.txt" , "r" );
	char line [ 1200 ]; /* or other suitable maximum line size */
	for(i=0; i<3;i++){
		while ( fgets ( line, sizeof line, file ) != NULL ) /* read a line */
		{
			my_delay(0.03);
			printf("%s", line); /* write the line */
		}
	}
	fclose ( file );	
}

void anim_bvn(){		
	printf("\033[30m");
	system("clear");
	msg_bvn();
	my_delay(0.7);
	printf("\033[33m");

	system("clear");
	msg_bvn();
	my_delay(0.7);
	printf("\033[35m");

	system("clear");
	msg_bvn();
	my_delay(0.7);
	printf("\033[31m");

	system("clear");
	msg_bvn();
	my_delay(0.7);
	printf("\033[32m");

	system("clear");
	msg_bvn();
	my_delay(0.7);
	printf("\033[00m");
}

int Menu(){
	int choix;
	system("clear");
	printf("\n\n\n\n\n\n\t\t\t\t\t\t\t ╔═════════════════════════════════════════════════════════════════════════════════════════╗\n");
	printf("\t\t\t\t\t\t\t ║			      ╦ ╦╔═╗╦  ╔═╗╔═╗╔╦╗╔═╗  ╔╦╗╔═╗               		   ║ \n");
	printf("\t\t\t\t\t\t\t ║			      ║║║║╣ ║  ║  ║ ║║║║║╣    ║ ║ ║                                ║ \n");
	printf("\t\t\t\t\t\t\t ║			      ╚╩╝╚═╝╩═╝╚═╝╚═╝╩ ╩╚═╝   ╩ ╚═╝                                ║ \n");    
	printf("\t\t\t\t\t\t\t ║                                                                                 	   ║ \n");
	printf("\t\t\t\t\t\t\t ║                                                                                 	   ║ \n");
	printf("\t\t\t\t\t\t\t ║");
	printf(RED "           ███╗   ███╗ █████╗ ██████╗ ██████╗ ██╗   ██╗  ██╗    ██████╗  ██████╗         " RESET); printf("║\n");
	printf("\t\t\t\t\t\t\t ║");
	printf(GRN "  	    ████╗ ████║██╔══██╗██╔══██╗██╔══██╗╚██╗ ██╔╝  ██║   ██╔════╝ ██╔═══██╗         " RESET ); printf("║\n");
	printf("\t\t\t\t\t\t\t ║");
	printf(ORANGE "  	    ██╔████╔██║███████║██████╔╝██████╔╝ ╚████╔╝████████╗██║  ███╗██║   ██║         " RESET); printf("║\n");
	printf("\t\t\t\t\t\t\t ║");
	printf(BLU "  	    ██║╚██╔╝██║██╔══██║██╔═══╝ ██╔═══╝   ╚██╔╝ ██╔═██╔═╝██║   ██║██║   ██║         " RESET); printf("║\n");
	printf("\t\t\t\t\t\t\t ║");
	printf(RED "  	    ██║ ╚═╝ ██║██║  ██║██║     ██║        ██║  ██████║  ╚██████╔╝╚██████╔╝         " RESET); printf("║\n");
	printf("\t\t\t\t\t\t\t ║");
	printf(RED "  	    ╚═╝     ╚═╝╚═╝  ╚═╝╚═╝     ╚═╝        ╚═╝  ╚═════╝   ╚═════╝  ╚═════╝          " RESET); printf("║\n");
	printf("\t\t\t\t\t\t\t ║                                							   ║\n"); 
	printf("\t\t\t\t\t\t\t ║						     				           ║\n");
	printf("\t\t\t\t\t\t\t ║         										   ║\n");
	printf("\t\t\t\t\t\t\t ║ 											   ║\n");
	printf("\t\t\t\t\t\t\t ║								               	    	   ║\n");
	printf("\t\t\t\t\t\t\t ║░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░║\n");
	printf("\t\t\t\t\t\t\t ║░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░1-Commencer░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░║\n");
	printf("\t\t\t\t\t\t\t ║░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░║\n");
	printf("\t\t\t\t\t\t\t ║▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓║\n");  
	printf("\t\t\t\t\t\t\t ║▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓2-Règles de Mappy&Go▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓║\n");
	printf("\t\t\t\t\t\t\t ║▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓║\n");
	printf("\t\t\t\t\t\t\t ║░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░║\n");
	printf("\t\t\t\t\t\t\t ║░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░3-Privacy Policy░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░║\n");
	printf("\t\t\t\t\t\t\t ║░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░║\n");
	printf("\t\t\t\t\t\t\t ║▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓║\n");  
	printf("\t\t\t\t\t\t\t ║▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓4-Carte▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓║\n");
	printf("\t\t\t\t\t\t\t ║▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓║\n");
	printf("\t\t\t\t\t\t\t ║░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░║\n");
	printf("\t\t\t\t\t\t\t ║░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░5-Quitter░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░║\n");
	printf("\t\t\t\t\t\t\t ║░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░║\n");
	printf("\t\t\t\t\t\t\t ╚═════════════════════════════════════════════════════════════════════════════════════════╝\n\n");
	printf("Quel est votre choix\n");
	scanf("%d",&choix);
	return choix;                           
}
char key_pressed() {
	struct termios oldterm, newterm;
	int oldfd;
	char c, result = 0;
	tcgetattr (STDIN_FILENO, &oldterm);
	newterm = oldterm;
	newterm.c_lflag &= ~(ICANON | ECHO);
	tcsetattr (STDIN_FILENO, TCSANOW, &newterm);
	oldfd = fcntl(STDIN_FILENO, F_GETFL, 0);
	fcntl (STDIN_FILENO, F_SETFL, oldfd | O_NONBLOCK);
	c = getchar();
	tcsetattr (STDIN_FILENO, TCSANOW, &oldterm);
	fcntl (STDIN_FILENO, F_SETFL, oldfd);
	if (c != EOF) {
		ungetc(c, stdin);
		result = getchar();
	}
	return result;
}

void affich_carte(char* fichier ){
	char b;
	FILE* fic = NULL;

	fic = fopen(fichier, "r");

	while((b = fgetc(fic)) != EOF){
		if( b == 'x'){
			printf(GRN "▓" RESET);
		}
		else if(b==':')
				printf(GRN "░" RESET);
			else if(b=='w')
				printf(ORANGE"▓" RESET);
			else if(b=='0')
				printf(ORANGE "🌟" RESET);
			else if(b == '.')
				printf(BLU "░" RESET);

			else if(b == 'z')
				printf(RED "▓" RESET);
			else if(b == 'r')
				printf(ORANGE "▓" RESET);
			else if(b == 'u')
				printf(GRN "▓" RESET);
		else if(b ==':'){
			printf(GRN "░" RESET);
		}
		else if(b =='X'){
			printf("👽");
		}
		else if(b == '.'){
			printf(BLU "░" RESET);
		}
		else if(b == ';'){
			printf( " ");
		}
		else if(b == ','){
			printf(GRN "░" RESET);
		}
		else if(b == 'l'){
			printf("░");
		}
		else if(b == 'z'){
			printf(RED "▓" RESET);
		}
		else if(b == 'w'){
			printf(ORANGE "▓" RESET);
		}
		else if(b == 'r'){
			printf(ORANGE "▓" RESET);
		}
		else if(b == 'u'){
			printf(GRN "▓" RESET);
		}

		else{
			printf("%c", b);
		}
	}
	fclose(fic);
}

void regles(){

	int i;
	FILE * file;
	file = fopen ( "regles.txt" , "r" );
	char line [ 1200 ];
	for(i=0; i<3;i++){
		while ( fgets ( line, sizeof line, file ) != NULL ) 
		{

			printf("%s", line); 
		}
	}
	fclose ( file );	
}

void auteurs(){
	system("clear");
	printf("\t\t\t\t\t\t\t    __        ___  ___     __   ___     __   __   __        ___ ___ \n");
	printf("\t\t\t\t\t\t\t   /  ` |__| |__  |__     |  \\ |__     |__) |__) /  \\    | |__   |  \n");
	printf("\t\t\t\t\t\t\t   \\__, |  | |___ |       |__/ |___    |    |  \\ \\__/ \\__/ |___  |  \n");
	printf("                                                                                      \n");                                                               
	printf(GRN " \t\t\t\t\t\t\t  _____         _      _         _____ ______ ____   ____   _____  ____  \n");
	printf(GRN " \t\t\t\t\t\t\t / ____|       | |    (_)       / ____|  ____|  _ \\ / __ \\ / ____|/ __ \\ \n");
	printf(GRN " \t\t\t\t\t\t\t| |     ___  __| |_ __ _  ___  | (___ | |__  | |_) | |  | | |  __| |  | |\n");
	printf(GRN " \t\t\t\t\t\t\t| |    / _ \\/ _` | '__| |/ __|  \\___ \\|  __| |  _ <| |  | | | |_ | |  | |\n");
	printf(GRN " \t\t\t\t\t\t\t| |___|  __/ (_| | |  | | (__   ____) | |____| |_) | |__| | |__| | |__| |\n");
	printf(GRN " \t\t\t\t\t\t\t \\_____\\___|\\__,_|_|  |_|\\___| |_____/|______|____/ \\____/ \\_____|\\____/ \n");
	printf(RESET"\n");
	printf("\n");
	printf("\t\t\t\t\t\t __   ___  __   __   __        __        __        ___    ___  ___  __               __       ____\n");
	printf("\t\t\t\t\t\t|__) |__  /__` |__) /  \\ |\\ | /__`  /\\  |__) |    |__      |  |__  /  ` |__| |\\ | | /  \\ |  | |__  \n");
	printf("\t\t\t\t\t\t|  \\ |___ .__/ |    \\__/ | \\| .__/ /~~\\ |__) |___ |___     |  |___ \\__, |  | | \\| | \\__X \\__/ |___ \n");
	printf("                                                                                                   \n");
	printf(ORANGE"\t\t\t\t\t\t  __  __       _   _     _              ____          _____  _____           _    _ _   _______ \n");
	printf(ORANGE"\t\t\t\t\t\t |  \\/  |     | | | |   (_)            |  _ \\   /\\   |  __ \\|  __ \\     /\\  | |  | | | |__   __|\n");
	printf(ORANGE"\t\t\t\t\t\t | \\  / | __ _| |_| |__  _  ___ _   _  | |_) | /  \\  | |__) | |__) |   /  \\ | |  | | |    | |   \n");
	printf(ORANGE"\t\t\t\t\t\t | |\\/| |/ _` | __| '_ \\| |/ _ \\ | | | |  _ < / /\\ \\ |  _  /|  _  /   / /\\ \\| |  | | |    | |   \n");
	printf(ORANGE"\t\t\t\t\t\t | |  | | (_| | |_| | | | |  __/ |_| | | |_) / ____ \\| | \\ \\| | \\ \\  / ____ \\ |__| | |____| |   \n");
	printf(ORANGE"\t\t\t\t\t\t |_|  |_|\\__,_|\\__|_| |_|_|\\___|\\__,_| |____/_/    \\_\\_|  \\_\\_|  \\_\\/_/    \\_\\____/|______|_|  \n");
	printf(RESET"\n\n");
	printf("\t\t\t\t\t\t\t    __   ___  __   __   __        __        __        ___  __                          \n");
	printf("\t\t\t\t\t\t\t   |__) |__  /__` |__) /  \\ |\\ | /__`  /\\  |__) |    |__  /__`                         \n");
	printf("\t\t\t\t\t\t\t   |  \\ |___ .__/ |    \\__/ | \\| .__/ /~~\\ |__) |___ |___ .__/                         \n");
	printf("                                                                                    \n");
	printf("\t\t\t\t\t\t __   ___  __     __           ___ ___     __   __        __          __        ___ \n");
	printf("\t\t\t\t\t\t|  \\ |__  /__` | / _` |\\ |    |__   |     / _` |__)  /\\  |__) |__| | /  \\ |  | |__  \n");
	printf("\t\t\t\t\t\t|__/ |___ .__/ | \\__> | \\|    |___  |     \\__> |  \\ /~~\\ |    |  | | \\__X \\__/ |___ \n");
	printf("                                                                                    \n");
	printf(BLU"\t\t\t\t\t   _____ _        _               _ _        __      __     _      ______ _   _ _______       _____ _   _ \n");
	printf(BLU"\t\t\t\t\t  / ____| |      | |             | (_)       \\ \\    / /\\   | |    |  ____| \\ | |__   __|/\\   |_   _| \\ | |\n");
	printf(BLU"\t\t\t\t\t | (___ | |_ __ _| |__   ___ _ __| |_ _ __    \\ \\  / /  \\  | |    | |__  |  \\| |  | |  /  \\    | | |  \\| |\n");
	printf(BLU"\t\t\t\t\t  \\___ \\| __/ _` |  '_ \\/ _ \\ '__| | | '_ \\    \\ \\/ / /\\ \\ | |    |  __| | . ` |  | | / /\\ \\   | | | . ` |\n");
	printf(BLU"\t\t\t\t\t  ____) | || (_| | |_) |  __/ |  | | | | | |    \\  / ____ \\| |____| |____| |\\  |  | |/ ____ \\ _| |_| |\\  |\n");
	printf(BLU"\t\t\t\t\t |_____/ \\__\\__,_|_.__/ \\___|_|  |_|_|_| |_|     \\/_/    \\_\\______|______|_| \\_|  |_/_/    \\_\\_____|_| \\_|\n");
	printf("                                                                                                                     \n");                                                                                               
	printf(RED"\t\t\t\t\t\t\t       _               _               __  __          _____ _____ _______ \n");
	printf(RED"\t\t\t\t\t\t\t      | |             | |             |  \\/  |   /\\   / ____|_   _|__   __|\n");
	printf(RED"\t\t\t\t\t\t\t      | | ___  _ __ __| | __ _ _ __   | \\  / |  /  \\ | |  __  | |    | |   \n");
	printf(RED"\t\t\t\t\t\t\t  _   | |/ _ \\| __/ _` |/ _` | _ \\  | |\\/| | / /\\ \\| | |_ | | |    | |   \n");
	printf(RED"\t\t\t\t\t\t\t | |__| | (_) | | | (_| | (_| | | | | | |  | |/ ____ \\ |__| |_| |_   | |   \n");
	printf(RED"\t\t\t\t\t\t\t  \\____/ \\___/|_|  \\__,_|\\__,_|_| |_| |_|  |_/_/    \\_\\_____|_____|  |_|                       \n"RESET);                   

}


int choix_type(){
int choix;
system("clear");
printf("\n\n\n\n\n\n\t\t\t\t\t\t\t ╔═════════════════════════════════════════════════════════════════════════════════════════╗\n");
printf("\t\t\t\t\t\t\t ║                                                                                         ║ \n");
printf("\t\t\t\t\t\t\t ║                                                                                         ║ \n");
printf("\t\t\t\t\t\t\t ║                                                                                         ║ \n");    
printf("\t\t\t\t\t\t\t ║                                                                                 	   ║ \n");
printf("\t\t\t\t\t\t\t ║                                                                                 	   ║ \n");
printf("\t\t\t\t\t\t\t ║");
printf(RED "           ███╗   ███╗ █████╗ ██████╗ ██████╗ ██╗   ██╗  ██╗    ██████╗  ██████╗         " RESET); printf("║\n");
printf("\t\t\t\t\t\t\t ║");
printf(GRN "  	    ████╗ ████║██╔══██╗██╔══██╗██╔══██╗╚██╗ ██╔╝  ██║   ██╔════╝ ██╔═══██╗         " RESET ); printf("║\n");
printf("\t\t\t\t\t\t\t ║");
printf(ORANGE "  	    ██╔████╔██║███████║██████╔╝██████╔╝ ╚████╔╝████████╗██║  ███╗██║   ██║         " RESET); printf("║\n");
printf("\t\t\t\t\t\t\t ║");
printf(BLU "  	    ██║╚██╔╝██║██╔══██║██╔═══╝ ██╔═══╝   ╚██╔╝ ██╔═██╔═╝██║   ██║██║   ██║         " RESET); printf("║\n");
printf("\t\t\t\t\t\t\t ║");
printf(RED "  	    ██║ ╚═╝ ██║██║  ██║██║     ██║        ██║  ██████║  ╚██████╔╝╚██████╔╝         " RESET); printf("║\n");
printf("\t\t\t\t\t\t\t ║");
printf(RED "  	    ╚═╝     ╚═╝╚═╝  ╚═╝╚═╝     ╚═╝        ╚═╝  ╚═════╝   ╚═════╝  ╚═════╝          " RESET); printf("║\n");
printf("\t\t\t\t\t\t\t ║                                							   ║\n"); 
printf("\t\t\t\t\t\t\t ║						     				           ║\n");
printf("\t\t\t\t\t\t\t ║         										   ║\n");
printf("\t\t\t\t\t\t\t ║ 											   ║\n");
printf("\t\t\t\t\t\t\t ║                                  Choix du Type de Chemin                                ║\n");
printf("\t\t\t\t\t\t\t ║░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░║\n");
printf("\t\t\t\t\t\t\t ║░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░1-Salarié(court et Facile)░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░║\n");
printf("\t\t\t\t\t\t\t ║░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░║\n");
printf("\t\t\t\t\t\t\t ║▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓║\n");  
printf("\t\t\t\t\t\t\t ║▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓2-Sportif de Haut niveau(Long et Difficile)▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓║\n");
printf("\t\t\t\t\t\t\t ║▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓║\n");
printf("\t\t\t\t\t\t\t ║░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░║\n");
printf("\t\t\t\t\t\t\t ║░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░3-Vélo(Long et Facile)░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░║\n");
printf("\t\t\t\t\t\t\t ║░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░║\n");
printf("\t\t\t\t\t\t\t ║▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓║\n");  
printf("\t\t\t\t\t\t\t ║▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓4-Sportif(Court et Difficile)▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓║\n");
printf("\t\t\t\t\t\t\t ║▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓║\n");
printf("\t\t\t\t\t\t\t ║░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░║\n");
printf("\t\t\t\t\t\t\t ║░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░5-Retour au Menu principal░░░░░░░░░░░░░░░░░░░░░░░░░░░░░║\n");
printf("\t\t\t\t\t\t\t ║░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░║\n");
printf("\t\t\t\t\t\t\t ║▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓║\n");  
printf("\t\t\t\t\t\t\t ║▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓6-Quitter▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓║\n");
printf("\t\t\t\t\t\t\t ║▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓║\n");
printf("\t\t\t\t\t\t\t ╚═════════════════════════════════════════════════════════════════════════════════════════╝\n\n");
printf("Quel est votre choix\n");
scanf("%d",&choix);
return choix;                           
}

//=============++DEBUT des choses IMPORTANTES

void definition_carte(){
	srand(time(NULL));
	FILE *fic; 
	fic=fopen("Terrain.txt","r");
	char c;
	int i,j;
	int tmp;
	tmp=rand()%6;
	if(tmp==0){
	x_depart = 45;
	y_depart = 38;
	}
	else if(tmp==1){
	x_depart = 43;
	y_depart = 14;
	}
	else if(tmp==2){
	x_depart = 35;
	y_depart = 34;
	}
	else if(tmp==3){
	x_depart = 58;
	y_depart = 25;
	}
	else if(tmp==4){
	x_depart = 59;
	y_depart = 7;
	}
	else if(tmp==5){
	x_depart = 30;
	y_depart = 26;
	}
	else if(tmp==6){
	x_depart = 10;
	y_depart = 21;
	}
	else{
	x_depart = 45;
	y_depart = 38;
	}

	printf("%d\n",tmp );
	for( i = 0; i < NBLIN; i++){
		for( j = 0; j < NBCOL; j++){
			c = fgetc(fic);
			if (c>='A' && c<='Z'){
				tab_num[i][j] = MUR;
			}
			if( c!='\n'){
				switch (c){
					case ' ':
						tab_num[i][j] = SOL;
						break;
					case 'x':
						tab_num[i][j] = SOL2;
						break;
					case 'w':
						tab_num[i][j] = SOL3;
						break;
					case ':':
						tab_num[i][j] = SOL1;
						break;
					case '.':
						tab_num[i][j] = MUR3;
						break;
					case ',':
						tab_num[i][j] = SOL;
						break;
					case 'z':
						tab_num[i][j] = FEU_R;
						break;
					case 'r':
						tab_num[i][j] = FEU_O;
						break;
					case 'u':
						tab_num[i][j] = FEU_V;
						break;
					case '=':
						tab_num[i][j] = MUR1;
						break;
					case '-':
						tab_num[i][j] = MURTI;
						break;
					case '|':
						tab_num[i][j] = MUR2;
						break;
					case '0':
						x_but = i;
						y_but = j;
						tab_num[i][j] = BUT;
						break;
					case 'X':
						//x_depart = i;
						//y_depart = j;
						tab_num[i][j] = SOL;
						break;
					case 'M':
						tab_num[i][j] = MUR_M;
						break;
					case 'A':
						tab_num[i][j] = MUR_A;
						break;
					case 'I':
						tab_num[i][j] = MUR_I;
						break;
					case 'S':
						tab_num[i][j] = MUR_S;
						break;
					case 'O':
						tab_num[i][j] = MUR_O;
						break;
					case 'N':
						tab_num[i][j] = MUR_N;
						break;
					case 'T':
						tab_num[i][j] = MUR_T;
						break;
					case 'H':
						tab_num[i][j] = MUR_H;
						break;
					case 'E':
						tab_num[i][j] = MUR_E;
						break;
					case 'U':
						tab_num[i][j] = MUR_U;
						break;
					case 'R':
						tab_num[i][j] = MUR_R;
						break;
					case 'W':
						tab_num[i][j] = MUR_W;
						break;
					case 'P':
						tab_num[i][j] = MUR_P;
						break;
					case 'K':
						tab_num[i][j] = MUR_K;
						break;

					case 'G':
						tab_num[i][j] = MUR_G;
						break;
					case 'F':
						tab_num[i][j] = MUR_F;
						break;

					case 'C':
						tab_num[i][j] = MUR_C;
						break;
					case 'Y':
						tab_num[i][j] = MUR_Y;
						break;
					case 'J':
						tab_num[i][j] = MUR_J;
						break;
					case 'D':
						tab_num[i][j] = MUR_D;
						break;
					case 'L':
						tab_num[i][j] = MUR_L;
						break;

					case 'B':
						tab_num[i][j] = MUR_B;
						break;
						case 'V':
						tab_num[i][j] = MUR_V;
						break;
				}
			}
			else{
				tab_num[i][j] = MUR2;
				break;
			}
		}
	}
	fclose(fic);
	maj_depart_x=x_depart;
	maj_depart_y=y_depart;
	for ( i = 0; i < NBLIN; i++){
		for ( j = 0; j < NBCOL; j++){
			tab[i][j]=tab_num[i][j];
			tab_trajet[i][j]=tab_num[i][j];
		}
	}
}

void affic_carte(){
	int i,j;
	for ( i = 0; i < NBLIN; i++){
		for ( j = 0; j < NBCOL; j++){
			if (i==maj_depart_x && j==maj_depart_y){
				printf("👽");
			}
			else if(tab[i][j]==MUR)
				printf("m");
			else if(tab[i][j]==MUR1)
				printf("=");
			else if(tab[i][j]==MURTI)
				printf("-");
			else if(tab[i][j]==MUR2)
				printf("|");
			else if(tab[i][j] == MUR_M)
				printf("M");
			else if(tab[i][j] == MUR_A)
				printf("A");
			else if(tab[i][j] == MUR_I)
				printf("I");
			else if(tab[i][j] == MUR_S)
				printf("S");
			else if(tab[i][j] == MUR_O)
				printf("O");
			else if(tab[i][j] == MUR_N)
				printf("N");
			else if(tab[i][j] == MUR_T)
				printf("T");
			else if(tab[i][j] == MUR_H)
				printf("H");
			else if(tab[i][j] == MUR_E)
				printf("E");
			else if(tab[i][j] == MUR_U)
				printf("U");
			else if(tab[i][j] == MUR_R)
				printf("R");
			else if(tab[i][j] == MUR_W)
				printf("W");
			else if(tab[i][j] == MUR_P)
				printf("P");
			else if(tab[i][j] == MUR_K)
				printf("K");
			else if(tab[i][j] == MUR_G)
				printf("G");
			else if(tab[i][j] == MUR_F)
				printf("F");
			else if(tab[i][j] == MUR_C)
				printf("C");
			else if(tab[i][j] == MUR_Y)
				printf("Y");
			else if(tab[i][j] == MUR_J)
				printf("J");
			else if(tab[i][j] == MUR_D)
				printf("D");
			else if(tab[i][j] == MUR_L)
				printf("L");
			else if(tab[i][j] == MUR_B)
				printf("B");
			else if(tab[i][j] == MUR_V)
				printf("V");
			else if(tab[i][j]==SOL)
				printf(" ");
			else if(tab[i][j]==SOL1)
				printf(GRN "░" RESET);
			else if(tab[i][j]==SOL2)
				printf(GRN "▓" RESET);
			else if(tab[i][j]==SOL3)
				printf(ORANGE"▓" RESET);
			else if(tab[i][j]==0)
				printf(ORANGE "🌟" RESET);
			else if(tab[i][j] == MUR3)
				printf(BLU "░" RESET);

			else if(tab[i][j] == FEU_R)
				printf(RED "▓" RESET);
			else if(tab[i][j] == FEU_O)
				printf(ORANGE "▓" RESET);
			else if(tab[i][j] == FEU_V)
				printf(GRN "▓" RESET);
			else{
				continue;
			}
		}
		printf("\n");
	}
}

void affic_trajet(){
	int i,j;
	for ( i = 0; i < NBLIN; i++){
		for ( j = 0; j < NBCOL; j++){
			if (i==maj_depart_x && j==maj_depart_y){
				printf("👽");
			}
			else if(tab_trajet[i][j] == POINT)
				printf(RED "." RESET);
			else if(tab[i][j]==MUR)
				printf("m");
			else if(tab[i][j]==MUR1)
				printf("=");
			else if(tab[i][j]==MURTI)
				printf("-");
			else if(tab[i][j]==MUR2)
				printf("|");
			else if(tab[i][j] == MUR_M)
				printf("M");
			else if(tab[i][j] == MUR_A)
				printf("A");
			else if(tab[i][j] == MUR_I)
				printf("I");
			else if(tab[i][j] == MUR_S)
				printf("S");
			else if(tab[i][j] == MUR_O)
				printf("O");
			else if(tab[i][j] == MUR_N)
				printf("N");
			else if(tab[i][j] == MUR_T)
				printf("T");
			else if(tab[i][j] == MUR_H)
				printf("H");
			else if(tab[i][j] == MUR_E)
				printf("E");
			else if(tab[i][j] == MUR_U)
				printf("U");
			else if(tab[i][j] == MUR_R)
				printf("R");
			else if(tab[i][j] == MUR_W)
				printf("W");
			else if(tab[i][j] == MUR_P)
				printf("P");
			else if(tab[i][j] == MUR_K)
				printf("K");
			else if(tab[i][j] == MUR_G)
				printf("G");
			else if(tab[i][j] == MUR_F)
				printf("F");
			else if(tab[i][j] == MUR_C)
				printf("C");
			else if(tab[i][j] == MUR_Y)
				printf("Y");
			else if(tab[i][j] == MUR_J)
				printf("J");
			else if(tab[i][j] == MUR_D)
				printf("D");
			else if(tab[i][j] == MUR_L)
				printf("L");
			else if(tab[i][j] == MUR_B)
				printf("B");
			else if(tab[i][j] == MUR_V)
				printf("V");
			else if(tab[i][j]==SOL)
				printf(" ");
			else if(tab[i][j]==SOL1)
				printf(GRN "░" RESET);
			else if(tab[i][j]==SOL2)
				printf(GRN "▓" RESET);
			else if(tab[i][j]==SOL3)
				printf(ORANGE"▓" RESET);
			else if(tab[i][j]==0)
				printf(ORANGE "🌟" RESET);
			else if(tab[i][j] == MUR3)
				printf(BLU "░" RESET);

			else if(tab[i][j] == FEU_R)
				printf(RED "▓" RESET);
			else if(tab[i][j] == FEU_O)
				printf(ORANGE "▓" RESET);
			else if(tab[i][j] == FEU_V)
				printf(GRN "▓" RESET);
			else{
				continue;
			}
		}
		printf("\n");
	}
}

void remplirManhattan(){

	file f = creer_file_vide();//pour creer une file
	int x,y,valeur;

	x = x_but;
	y = y_but;
	//printf("%d %d\n",x,y );
	f = inserer(f,x,y,0); //inserer le point de depart, on peut le faire apparaitre aléatoirement en ne prenant que les 0
	while(!est_file_vide(f)){

		f = extraire(f,&x,&y,&valeur);

		if(tab_num[x][y] != MUR && tab_num[x][y] != MUR1){ 
			//Ajouter si case dispo

			if(x-1>=0 && tab_num[x-1][y]== -1 && tab_num[x-1][y]!=MUR && tab_num[x-1][y]!=MUR1 && tab_num[x-1][y]!=MUR2 && tab_num[x-1][y]!=MUR3 && tab_num[x-1][y]!=MURTI){
				f = inserer(f,x-1,y,valeur+1);
				tab_num[x-1][y]=valeur+1;
				//printf("x=%d y=%d\n",x-1,y );
			}
			if(x+1<NBLIN && tab_num[x+1][y]== -1 && tab_num[x+1][y]!=MUR && tab_num[x+1][y]!=MUR1 && tab_num[x+1][y]!=MUR2 && tab_num[x+1][y]!=MUR3 && tab_num[x+1][y]!=MURTI){
				f = inserer(f,x+1,y,valeur+1);
				tab_num[x+1][y]=valeur+1;
			}
			if(y-1>=0 && tab_num[x][y-1]== -1 && tab_num[x][y-1]!=MUR && tab_num[x][y-1]!=MUR1 && tab_num[x][y-1]!=MUR2 && tab_num[x][y-1]!=MUR3 && tab_num[x][y-1]!=MURTI){
				f = inserer(f,x,y-1,valeur+1);
				tab_num[x][y-1]=valeur+1;
			}
			if(x-1>=0 && tab_num[x-1][y]== SOL1 && tab_num[x-1][y]!=MUR && tab_num[x-1][y]!=MUR1 && tab_num[x-1][y]!=MUR2 && tab_num[x-1][y]!=MUR3 && tab_num[x-1][y]!=MURTI){
				f = inserer(f,x-1,y,valeur+2);
				tab_num[x-1][y]=valeur+2;
				//printf("x=%d y=%d\n",x-1,y );
			}
			if(x+1<NBLIN && tab_num[x+1][y]== SOL1 && tab_num[x+1][y]!=MUR && tab_num[x+1][y]!=MUR1 && tab_num[x+1][y]!=MUR2 && tab_num[x+1][y]!=MUR3 && tab_num[x+1][y]!=MURTI){
				f = inserer(f,x+1,y,valeur+2);
				tab_num[x+1][y]=valeur+2;
			}
			if(y-1>=0 && tab_num[x][y-1]== SOL1 && tab_num[x][y-1]!=MUR && tab_num[x][y-1]!=MUR1 && tab_num[x][y-1]!=MUR2 && tab_num[x][y-1]!=MUR3 && tab_num[x][y-1]!=MURTI){
				f = inserer(f,x,y-1,valeur+2);
				tab_num[x][y-1]=valeur+2;
			}
			if(x-1>=0 && tab_num[x-1][y]== SOL2 && tab_num[x-1][y]!=MUR && tab_num[x-1][y]!=MUR1 && tab_num[x-1][y]!=MUR2 && tab_num[x-1][y]!=MUR3 && tab_num[x-1][y]!=MURTI){
				f = inserer(f,x-1,y,valeur+3);
				tab_num[x-1][y]=valeur+3;
				//printf("x=%d y=%d\n",x-1,y );
			}
			if(x+1<NBLIN && tab_num[x+1][y]== SOL2 && tab_num[x+1][y]!=MUR && tab_num[x+1][y]!=MUR1 && tab_num[x+1][y]!=MUR2 && tab_num[x+1][y]!=MUR3 && tab_num[x+1][y]!=MURTI){
				f = inserer(f,x+1,y,valeur+3);
				tab_num[x+1][y]=valeur+2;
			}
			if(y-1>=0 && tab_num[x][y-1]== SOL2 && tab_num[x][y-1]!=MUR && tab_num[x][y-1]!=MUR1 && tab_num[x][y-1]!=MUR2 && tab_num[x][y-1]!=MUR3 && tab_num[x][y-1]!=MURTI){
				f = inserer(f,x,y-1,valeur+3);
				tab_num[x][y-1]=valeur+2; 
			}
			if(x-1>=0 && tab_num[x-1][y]== SOL3 && tab_num[x-1][y]!=MUR && tab_num[x-1][y]!=MUR1 && tab_num[x-1][y]!=MUR2 && tab_num[x-1][y]!=MUR3 && tab_num[x-1][y]!=MURTI){
				f = inserer(f,x-1,y,valeur+3);
				tab_num[x-1][y]=valeur+3;
				//printf("x=%d y=%d\n",x-1,y );
			}
			if(x+1<NBLIN && tab_num[x+1][y]== SOL3 && tab_num[x+1][y]!=MUR && tab_num[x+1][y]!=MUR1 && tab_num[x+1][y]!=MUR2 && tab_num[x+1][y]!=MUR3 && tab_num[x+1][y]!=MURTI){
				f = inserer(f,x+1,y,valeur+3);
				tab_num[x+1][y]=valeur+2;
			}
			if(y-1>=0 && tab_num[x][y-1]== SOL3 && tab_num[x][y-1]!=MUR && tab_num[x][y-1]!=MUR1 && tab_num[x][y-1]!=MUR2 && tab_num[x][y-1]!=MUR3 && tab_num[x][y-1]!=MURTI){
				f = inserer(f,x,y-1,valeur+3);
				tab_num[x][y-1]=valeur+2; 
			}
		}
	}
}

void remplirManhattan_mara(){

	file f = creer_file_vide();//pour creer une file
	int x,y,valeur;

	x = x_but;
	y = y_but;
	//printf("%d %d\n",x,y );
	f = inserer(f,x,y,0); //inserer le point de depart, on peut le faire apparaitre aléatoirement en ne prenant que les 0
	while(!est_file_vide(f)){

		f = extraire(f,&x,&y,&valeur);

		if(tab_num[x][y] != MUR && tab_num[x][y] != MUR1){ 
			//Ajouter si case dispo

			if(x-1>=0 && tab_num[x-1][y]== -1 && tab_num[x-1][y]!=MUR && tab_num[x-1][y]!=MUR1 && tab_num[x-1][y]!=MUR2 && tab_num[x-1][y]!=MUR3 && tab_num[x-1][y]!=MURTI){
				f = inserer(f,x-1,y,valeur+1);
				tab_num[x-1][y]=valeur+1;
				//printf("x=%d y=%d\n",x-1,y );
			}
			if(x+1<NBLIN && tab_num[x+1][y]== -1 && tab_num[x+1][y]!=MUR && tab_num[x+1][y]!=MUR1 && tab_num[x+1][y]!=MUR2 && tab_num[x+1][y]!=MUR3 && tab_num[x+1][y]!=MURTI){
				f = inserer(f,x+1,y,valeur+1);
				tab_num[x+1][y]=valeur+1;
			}
			if(y-1>=0 && tab_num[x][y-1]== -1 && tab_num[x][y-1]!=MUR && tab_num[x][y-1]!=MUR1 && tab_num[x][y-1]!=MUR2 && tab_num[x][y-1]!=MUR3 && tab_num[x][y-1]!=MURTI){
				f = inserer(f,x,y-1,valeur+1);
				tab_num[x][y-1]=valeur+1;
			}

			if(y+1>=0 && tab_num[x][y+1]== -1 && tab_num[x][y+1]!=MUR && tab_num[x][y+1]!=MUR1 && tab_num[x][y+1]!=MUR2 && tab_num[x][y+1]!=MUR3 && tab_num[x][y+1]!=MURTI){
				f = inserer(f,x,y+1,valeur+1);
				tab_num[x][y+1]=valeur+1;
			}



			if(x-1>=0 && tab_num[x-1][y]== SOL1 && tab_num[x-1][y]!=MUR && tab_num[x-1][y]!=MUR1 && tab_num[x-1][y]!=MUR2 && tab_num[x-1][y]!=MUR3 && tab_num[x-1][y]!=MURTI){
				f = inserer(f,x-1,y,valeur+2);
				tab_num[x-1][y]=valeur+2;
				//printf("x=%d y=%d\n",x-1,y );
			}
			if(x+1<NBLIN && tab_num[x+1][y]== SOL1 && tab_num[x+1][y]!=MUR && tab_num[x+1][y]!=MUR1 && tab_num[x+1][y]!=MUR2 && tab_num[x+1][y]!=MUR3 && tab_num[x+1][y]!=MURTI){
				f = inserer(f,x+1,y,valeur+2);
				tab_num[x+1][y]=valeur+2;
			}
			if(y-1>=0 && tab_num[x][y-1]== SOL1 && tab_num[x][y-1]!=MUR && tab_num[x][y-1]!=MUR1 && tab_num[x][y-1]!=MUR2 && tab_num[x][y-1]!=MUR3 && tab_num[x][y-1]!=MURTI){
				f = inserer(f,x,y-1,valeur+2);
				tab_num[x][y-1]=valeur+2;
			}

			if(y+1>=0 && tab_num[x][y+1]== SOL1 && tab_num[x][y+1]!=MUR && tab_num[x][y+1]!=MUR1 && tab_num[x][y+1]!=MUR2 && tab_num[x][y+1]!=MUR3 && tab_num[x][y+1]!=MURTI){
				f = inserer(f,x,y+1,valeur+2);
				tab_num[x][y+1]=valeur+2;
			}



			if(x-1>=0 && tab_num[x-1][y]== SOL2 && tab_num[x-1][y]!=MUR && tab_num[x-1][y]!=MUR1 && tab_num[x-1][y]!=MUR2 && tab_num[x-1][y]!=MUR3 && tab_num[x-1][y]!=MURTI){
				f = inserer(f,x-1,y,valeur+3);
				tab_num[x-1][y]=valeur+3;
				//printf("x=%d y=%d\n",x-1,y );
			}
			if(x+1<NBLIN && tab_num[x+1][y]== SOL2 && tab_num[x+1][y]!=MUR && tab_num[x+1][y]!=MUR1 && tab_num[x+1][y]!=MUR2 && tab_num[x+1][y]!=MUR3 && tab_num[x+1][y]!=MURTI){
				f = inserer(f,x+1,y,valeur+3);
				tab_num[x+1][y]=valeur+2;
			}
			if(y-1>=0 && tab_num[x][y-1]== SOL2 && tab_num[x][y-1]!=MUR && tab_num[x][y-1]!=MUR1 && tab_num[x][y-1]!=MUR2 && tab_num[x][y-1]!=MUR3 && tab_num[x][y-1]!=MURTI){
				f = inserer(f,x,y-1,valeur+3);
				tab_num[x][y-1]=valeur+2; 
			}
			if(y+1>=0 && tab_num[x][y+1]== SOL2 && tab_num[x][y+1]!=MUR && tab_num[x][y+1]!=MUR1 && tab_num[x][y+1]!=MUR2 && tab_num[x][y+1]!=MUR3 && tab_num[x][y+1]!=MURTI){
				f = inserer(f,x,y+1,valeur+3);
				tab_num[x][y+1]=valeur+2; 
			}



			if(x-1>=0 && tab_num[x-1][y]== SOL3 && tab_num[x-1][y]!=MUR && tab_num[x-1][y]!=MUR1 && tab_num[x-1][y]!=MUR2 && tab_num[x-1][y]!=MUR3 && tab_num[x-1][y]!=MURTI){
				f = inserer(f,x-1,y,valeur+3);
				tab_num[x-1][y]=valeur+3;
				//printf("x=%d y=%d\n",x-1,y );
			}
			if(x+1<NBLIN && tab_num[x+1][y]== SOL3 && tab_num[x+1][y]!=MUR && tab_num[x+1][y]!=MUR1 && tab_num[x+1][y]!=MUR2 && tab_num[x+1][y]!=MUR3 && tab_num[x+1][y]!=MURTI){
				f = inserer(f,x+1,y,valeur+3);
				tab_num[x+1][y]=valeur+3;
			}
			if(y-1>=0 && tab_num[x][y-1]== SOL3 && tab_num[x][y-1]!=MUR && tab_num[x][y-1]!=MUR1 && tab_num[x][y-1]!=MUR2 && tab_num[x][y-1]!=MUR3 && tab_num[x][y-1]!=MURTI){
				f = inserer(f,x,y-1,valeur+3);
				tab_num[x][y-1]=valeur+3; 
			}

			if(y+1>=0 && tab_num[x][y+1]== SOL3 && tab_num[x][y+1]!=MUR && tab_num[x][y+1]!=MUR1 && tab_num[x][y+1]!=MUR2 && tab_num[x][y+1]!=MUR3 && tab_num[x][y+1]!=MURTI){
				f = inserer(f,x,y+1,valeur+3);
				tab_num[x][y+1]=valeur+3; 
			}


		}
	}
}

void remplirManhattan_facile(){

	file f = creer_file_vide();//pour creer une file
	int x,y,valeur;

	x = x_but;
	y = y_but;
	//printf("%d %d\n",x,y );
	f = inserer(f,x,y,0); //inserer le point de depart, on peut le faire apparaitre aléatoirement en ne prenant que les 0
	while(!est_file_vide(f)){

		f = extraire(f,&x,&y,&valeur);

		if(tab_num[x][y] != MUR && tab_num[x][y] != MUR1){ 
			//Ajouter si case dispo

			if(x-1>=0 && tab_num[x-1][y]== -1 && tab_num[x-1][y]!=MUR && tab_num[x-1][y]!=MUR1 && tab_num[x-1][y]!=MUR2 && tab_num[x-1][y]!=MUR3 && tab_num[x-1][y]!=MURTI){
				f = inserer(f,x-1,y,valeur+1);
				tab_num[x-1][y]=valeur+1;
				//printf("x=%d y=%d\n",x-1,y );
			}
			if(x+1<NBLIN && tab_num[x+1][y]== -1 && tab_num[x+1][y]!=MUR && tab_num[x+1][y]!=MUR1 && tab_num[x+1][y]!=MUR2 && tab_num[x+1][y]!=MUR3 && tab_num[x+1][y]!=MURTI){
				f = inserer(f,x+1,y,valeur+1);
				tab_num[x+1][y]=valeur+1;
			}
			if(y-1>=0 && tab_num[x][y-1]== -1 && tab_num[x][y-1]!=MUR && tab_num[x][y-1]!=MUR1 && tab_num[x][y-1]!=MUR2 && tab_num[x][y-1]!=MUR3 && tab_num[x][y-1]!=MURTI){
				f = inserer(f,x,y-1,valeur+1);
				tab_num[x][y-1]=valeur+1;
			}
			if(x-1>=0 && tab_num[x-1][y]== SOL1 && tab_num[x-1][y]!=MUR && tab_num[x-1][y]!=MUR1 && tab_num[x-1][y]!=MUR2 && tab_num[x-1][y]!=MUR3 && tab_num[x-1][y]!=MURTI){
				f = inserer(f,x-1,y,valeur+2);
				tab_num[x-1][y]=valeur+2;
				//printf("x=%d y=%d\n",x-1,y );
			}
			if(x+1<NBLIN && tab_num[x+1][y]== SOL1 && tab_num[x+1][y]!=MUR && tab_num[x+1][y]!=MUR1 && tab_num[x+1][y]!=MUR2 && tab_num[x+1][y]!=MUR3 && tab_num[x+1][y]!=MURTI){
				f = inserer(f,x+1,y,valeur+2);
				tab_num[x+1][y]=valeur+2;
			}
			if(y-1>=0 && tab_num[x][y-1]== SOL1 && tab_num[x][y-1]!=MUR && tab_num[x][y-1]!=MUR1 && tab_num[x][y-1]!=MUR2 && tab_num[x][y-1]!=MUR3 && tab_num[x][y-1]!=MURTI){
				f = inserer(f,x,y-1,valeur+2);
				tab_num[x][y-1]=valeur+2;
			}
			if(x-1>=0 && tab_num[x-1][y]== SOL2 && tab_num[x-1][y]!=MUR && tab_num[x-1][y]!=MUR1 && tab_num[x-1][y]!=MUR2 && tab_num[x-1][y]!=MUR3 && tab_num[x-1][y]!=MURTI){
				f = inserer(f,x-1,y,valeur+3);
				tab_num[x-1][y]=valeur+3;
				//printf("x=%d y=%d\n",x-1,y );
			}
			if(x+1<NBLIN && tab_num[x+1][y]== SOL2 && tab_num[x+1][y]!=MUR && tab_num[x+1][y]!=MUR1 && tab_num[x+1][y]!=MUR2 && tab_num[x+1][y]!=MUR3 && tab_num[x+1][y]!=MURTI){
				f = inserer(f,x+1,y,valeur+3);
				tab_num[x+1][y]=valeur+2;
			}
			if(y-1>=0 && tab_num[x][y-1]== SOL2 && tab_num[x][y-1]!=MUR && tab_num[x][y-1]!=MUR1 && tab_num[x][y-1]!=MUR2 && tab_num[x][y-1]!=MUR3 && tab_num[x][y-1]!=MURTI){
				f = inserer(f,x,y-1,valeur+3);
				tab_num[x][y-1]=valeur+2; 
			}
			if(x-1>=0 && tab_num[x-1][y]== SOL3 && tab_num[x-1][y]!=MUR && tab_num[x-1][y]!=MUR1 && tab_num[x-1][y]!=MUR2 && tab_num[x-1][y]!=MUR3 && tab_num[x-1][y]!=MURTI){
				f = inserer(f,x-1,y,valeur+3);
				tab_num[x-1][y]=valeur+3;
				//printf("x=%d y=%d\n",x-1,y );
			}
			if(x+1<NBLIN && tab_num[x+1][y]== SOL3 && tab_num[x+1][y]!=MUR && tab_num[x+1][y]!=MUR1 && tab_num[x+1][y]!=MUR2 && tab_num[x+1][y]!=MUR3 && tab_num[x+1][y]!=MURTI){
				f = inserer(f,x+1,y,valeur+3);
				tab_num[x+1][y]=valeur+2;
			}
			if(y-1>=0 && tab_num[x][y-1]== SOL3 && tab_num[x][y-1]!=MUR && tab_num[x][y-1]!=MUR1 && tab_num[x][y-1]!=MUR2 && tab_num[x][y-1]!=MUR3 && tab_num[x][y-1]!=MURTI){
				f = inserer(f,x,y-1,valeur+3);
				tab_num[x][y-1]=valeur+2; 
			}
		}
	}
}

	/*file f = creer_file_vide();//pour creer une file
	int x,y,valeur;

	x = x_but;
	y = y_but;
	//printf("%d %d\n",x,y );
	f = inserer(f,x,y,0); //inserer le point de depart, on peut le faire apparaitre aléatoirement en ne prenant que les 0
	while(!est_file_vide(f)){
		 
		f = extraire(f,&x,&y,&valeur);

		if(tab_num[x][y] != MUR){ 
		//Ajouter si case dispo

			if(x-1>=0 && tab_num[x-1][y]== -1 && tab_num[x-1][y]!=MUR && tab_num[x-1][y]!=MUR1 && tab_num[x-1][y]!=MUR2 && tab_num[x-1][y]!=MUR3 && tab_num[x-1][y]!=MURTI){
				f = inserer(f,x-1,y,valeur+1);
				tab_num[x-1][y]=valeur+1;
				//printf("x=%d y=%d\n",x-1,y );
			}
			if(x+1<NBLIN && tab_num[x+1][y]== -1 && tab_num[x+1][y]!=MUR && tab_num[x+1][y]!=MUR1 && tab_num[x+1][y]!=MUR2 && tab_num[x+1][y]!=MUR3 && tab_num[x+1][y]!=MURTI){
				f = inserer(f,x+1,y,valeur+1);
				tab_num[x+1][y]=valeur+1;
			}
			if(y-1>=0 && tab_num[x][y-1]== -1 && tab_num[x][y-1]!=MUR && tab_num[x][y-1]!=MUR1 && tab_num[x][y-1]!=MUR2 && tab_num[x][y-1]!=MUR3 && tab_num[x][y-1]!=MURTI){
				f = inserer(f,x,y-1,valeur+1);
				tab_num[x][y-1]=valeur+1;
			}
			if(y+1<NBCOL && tab_num[x][y+1] == -1 && tab_num[x][y+1]!=MUR && tab_num[x][y+1]!=MUR1 && tab_num[x][y+1]!=MUR2 && tab_num[x][y+1]!=MUR3 && tab_num[x][y+1]!=MURTI){
				f = inserer(f,x,y+1,valeur+1);
				tab_num[x][y+1]=valeur+1;
			}
			
		}
	}*/


//Calculer et afficher le plus court chemin du départ à l'arrivée
void plusCourtChemin(){
	printf("Affichage du plus court chemin \n\n Position x, y et la valeur de la case courante\n");
	int x,y,xmin,ymin,min;
	x=x_depart;
	y=y_depart;

	xmin=x;
	ymin=y;
	min=tab_num[x][y];
	//printf("x=%d y=%d et min =%d\n",x,y,min); //pour afficher la position courante
	if(tab_num[x][y] != -1){
		while(tab_num[x][y] != 0){
			system("clear");
			affic_carte();
			my_delay(0.1);
			//tant que le but n'est pas arrivé
			if(x-1>=0 && tab_num[x-1][y] < min && tab_num[x-1][y]!=-2 && tab_num[x-1][y]!=MUR1 && tab_num[x-1][y]!=MUR2  && tab_num[x-1][y]!=MUR3  && tab_num[x-1][y]!=MURTI && tab_num[x-1][y]!=MUR_S && tab_num[x-1][y]!=MUR_T && tab_num[x-1][y]!=MUR_A && tab_num[x-1][y]!=MUR_D && tab_num[x-1][y]!=MUR_E && tab_num[x-1][y]!=MUR_F && tab_num[x-1][y]!=MUR_O){ //haut
				min = tab_num[x-1][y];
				xmin = x-1;
				ymin = y;
			} 

			if(x+1<NBLIN && tab_num[x+1][y] < min && tab_num[x+1][y]!=-2 && tab_num[x+1][y]!=MUR1 && tab_num[x+1][y]!=MUR2  && tab_num[x+1][y]!=MUR3 && tab_num[x+1][y]!=MURTI && tab_num[x+1][y]!=MUR_S && tab_num[x+1][y]!=MUR_T && tab_num[x+1][y]!=MUR_A && tab_num[x+1][y]!=MUR_D && tab_num[x+1][y]!=MUR_E && tab_num[x+1][y]!=MUR_F && tab_num[x+1][y]!=MUR_O){ //bas
				min = tab_num[x+1][y];
				xmin = x+1;
				ymin = y;
			}
			if(y-1>=0 && tab_num[x][y-1] < min && tab_num[x][y-1]!=-2 && tab_num[x][y-1]!=MUR1 && tab_num[x][y-1]!=MUR2  && tab_num[x][y-1]!=MUR3 && tab_num[x][y-1]!=MURTI && tab_num[x][y-1]!=MUR_S && tab_num[x][y-1]!=MUR_T && tab_num[x][y-1]!=MUR_A && tab_num[x][y-1]!=MUR_D && tab_num[x][y-1]!=MUR_E && tab_num[x][y-1]!=MUR_F && tab_num[x][y-1]!=MUR_O){ //gauche
				min = tab_num[x][y-1];
				xmin = x;
				ymin = y-1;
			}
			if(y+1<NBCOL && tab_num[x][y+1] < min && tab_num[x][y+1]!=-2 && tab_num[x][y+1]!=MUR1 && tab_num[x][y+1]!=MUR2  && tab_num[x][y+1]!=MUR3 && tab_num[x][y+1]!=MURTI && tab_num[x][y+1]!=MUR_S && tab_num[x][y+1]!=MUR_T && tab_num[x][y+1]!=MUR_A && tab_num[x][y+1]!=MUR_D && tab_num[x][y+1]!=MUR_E && tab_num[x][y+1]!=MUR_F && tab_num[x][y+1]!=MUR_O){ //droite
				min = tab_num[x][y+1];
				xmin = x;
				ymin = y+1;
			}
			int p;
			x=xmin;
			y=ymin;
			tab_trajet[x][y]=POINT;
			p=tab[x][y];
			tab[maj_depart_x][maj_depart_y]=p;
			maj_depart_x=x;
			maj_depart_y=y;
			cpt++;
		}
	}
	else{
		printf("Impossible à résoude !\n");
	}
}

void quitter(){
	system("killall play");
	system("play -q 'Goodbye.mp3' & ");
	usleep(900000);	
	system("clear");
	end();
	my_delay(2);
	system("killall play &");
	exit(-1);
}

int main(){
	char c;
	int choix,tmp=0,i,type;

	system("play -q 'Mu_1.mp3' & ");
	anim_bvn();
	do{
		if(tmp==1){
		system("play -q 'Mu_1.mp3' & ");}

	choix=Menu();
	
	switch(choix){
		case 1:
			system("killall play");
			system("play -q 'Mu_Regles.mp3' & ");

			type=choix_type();
			switch(type){
				case 1:
					definition_carte();
					system("clear");
					affic_carte();
					printf("Appuyer sur la touche Entrer pour commencer\n");
					getchar();
					do{
						c=key_pressed();}
					while(c!='\n');
					system("play -q 'Car Driving.mp3' &");
					remplirManhattan();
					plusCourtChemin();

					system("play -q 'Chemin_trouve.mp3' & ");
					system("clear");
					affic_trajet();
					printf("\t\t\t\t\tDISTANCE PARCOURUE ==> %d KM et %d calories brulées\n", cpt/6, cpt*8);
					printf("Revenir au menu principal Oui[1] Non[2]\n");
					scanf("%d",&i);
					if (i==1){
						system("killall play");
						tmp=1;
					}
					else{
						quitter();
					}
					break;

				case 2:
				definition_carte();
					printf("Appuyer Entrer pour continuer\n");
					system("clear");
					affic_carte();
					printf("Appuyer sur la touche Entrer pour commencer\n");
					getchar();
					do{
						c=key_pressed();}
					while(c!='\n');
					system("play -q 'Car Driving.mp3' &");
					
					remplirManhattan_mara();
					plusCourtChemin();
					system("play -q 'Chemin_trouve.mp3' & ");
					affic_trajet();
					printf("\t\t\t\t\tDISTANCE PARCOURUE ==> %d KM et %d calories brulées\n", cpt/6, cpt*8);
					printf("Revenir au menu principal Oui[1] Non[2]\n");
					scanf("%d",&i);
					if (i==1){
						system("killall play");
						tmp=1;
					}
					else{
						quitter();
					}
					break;

					case 3:
					definition_carte();
					printf("Appuyer Entrer pour continuer\n");
					system("clear");
					affic_carte();
					printf("Appuyer sur la touche Entrer pour commencer\n");
					getchar();
					do{
						c=key_pressed();}
					while(c!='\n');
					system("play -q 'Car Driving.mp3' &");
					
					remplirManhattan_facile();
					plusCourtChemin();
					system("play -q 'Chemin_trouve.mp3' & ");
					affic_trajet();
					printf("\t\t\t\t\tDISTANCE PARCOURUE ==> %d KM et %d calories brulées\n", cpt/6, cpt*8);
					printf("Revenir au menu principal Oui[1] Non[2]\n");
					scanf("%d",&i);
					if (i==1){
						system("killall play");
						tmp=1;
					}
					else{
						quitter();
					}
					break;

					case 4:
					definition_carte();
					printf("Appuyer Entrer pour continuer\n");
					system("clear");
					affic_carte();
					printf("Appuyer sur la touche Entrer pour commencer\n");
					getchar();
					do{
						c=key_pressed();}
					while(c!='\n');
					system("play -q 'Car Driving.mp3' &");
					remplirManhattan_mara();
					plusCourtChemin();
					system("play -q 'Chemin_trouve.mp3' & ");
					affic_trajet();
					printf("\t\t\t\t\tDISTANCE PARCOURUE ==> %d KM et %d calories brulées\n", cpt/6, cpt*8);
					printf("Revenir au menu principal Oui[1] Non[2]\n");
					scanf("%d",&i);
					if (i==1){
						system("killall play");
						tmp=1;
					}
					else{
						quitter();
					}
					break;



				case 5:
				system("killall play");
					tmp=1;
					break;

				case 6:
					quitter();
					break;

				default:
					printf("Choix inconnu\n");
					break;
			}
			system("killall play");
			break;

		case 2:
			system("clear");
			regles();
			printf("Revenir au menu principal Oui[1] Non[2]\n");
			scanf("%d",&i);
			if (i==1){
				//system("killall play");
				system("killall play");
				tmp=1;
				//exit(-1);
			}
			else{
				quitter();
			}
			break;

		case 3:
			auteurs();
			printf("\nRevenir au menu principal Oui[1] Non[2]\n");
			scanf("%d",&i);
			if (i==1){
				system("killall play");
				tmp=1;
			}
			else{
				quitter();
			}
			break;
		case 4:
			system("clear");
			affich_carte("Terrain.txt");
			printf("\nRevenir au menu principal Oui[1] Non[2]\n");
			scanf("%d",&i);
			if (i==1){
				system("killall play");
				tmp=1;
			}
			else{
				quitter();
			}
			break;
		case 5:
			quitter();
			break;

		default :
			printf("Choix érroné\n");
			break;
	}
} while(tmp==1);
	return 0;
}