/*[------------------------------------------]
 *\	 /----------------/\---------------
 * \    /|_______    |   /  \  |   |_______
 *  \  / 	|    |  /----\ |          |
 *   \/	 --------    | /      \|    -------
 *[------------------------------------------]*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include "color.h"

void delay(int NOS) {

	int MS = 1000 * NOS;

	clock_t ST = clock();

	while(clock() < ST + MS);

}

void CLEAR_D(int MSS) {

	delay(MSS);
	system("clear;");

}


void ES_Test() {

	printf("\033[0;31m");
	printf(":: ERROR color test:\t\t\t[Success]");

	printf("\033[0;32m");
	printf("\n:: SUCCESS color test:\t\t\t[Success]\n\n");
	printf("\033[0m");

	delay(500);

}

void usage() {

	char *str[128];	

	FILE *fp;

	fp = fopen("/proc/uptime", "r");

	if(!(fp)) {
		
		printf("\033[0;31m");
		printf(":: ");

		printf("\033[0m");
		printf("cannot open uptime\n");
		exit(1);

	} else if(fp != NULL) {
		
		printf("\033[0;32m");	
		printf(":: read cpu uptime:\t\t\t[Success]\n");
		printf("\033[0m");

	}

	char line[256];

	fscanf(fp, "%[^\n]", str);
	printf("%s\n\n", str);

	fclose(fp);

	delay(500);

}

void info() {
	
	int LN = 1;

	FILE *fp2;

	int count = 0;

	fp2 = fopen("/proc/cpuinfo", "r");

	if(!(fp2)) {
	
		printf("\033[0;31m");
		printf(":: ");

		printf("\033[0m");
		printf("cannot open CpuInfo\n");
	
	}

	if(fp2 != NULL) {
	
		printf("\033[0;32m");	
		printf(":: read cpu info:\t\t\t[Success]\n");
		printf("\033[0m");

	
	}

	delay(100);
	
	FILE *GPU;
	char line900[128];

	GPU = popen("/bin/lspci | grep VGA", "r");
	
	if(!(GPU)) {
	
		printf(":: popen failed");

	}	
	
	FILE *UT;
	char line1000[128];
	
	UT = popen("/bin/uptime", "r");

	if(!(UT)) {

		printf(":: popen failed");

	}
	
	FILE *LIP;
	char line1100[128];
	int LN500 = 10;
	int count1000 = 0;

	LIP = popen("/bin/ip rout list | grep wlan0 | grep kernel", "r");

	if(!(LIP)) {

		printf(":: popen failed");

	}

	FILE *fp3;
	int LN2 = 0;
	int count2 = 0;

	fp3 = fopen("/proc/version", "r");

	if(!(fp3)) {
	
		printf("\033[0;31m");
		printf(":: ");

		printf("\033[0m");
		printf("cannot open Kernel Info\n");

		FILE *fo2;
	
	}

	if(fp3 != NULL) {
	
		printf("\033[0;32m");	
		printf(":: read Kernel:\t\t\t\t[Success]\n");
		printf("\033[0m");

	
	}
	
	FILE *fp4;
	int LN3 = 0;
	int LN4 = 1;
	int count3 = 0;

	fp4 = fopen("/proc/meminfo", "r");

	if(!(fp4)) {
	
		printf("\033[0;31m");
		printf(":: ");

		printf("\033[0m");
		printf("cannot open Memory Info\n");
	
	}

	if(fp3 != NULL) {
	
		printf("\033[0;32m");	
		printf(":: read Memory:\t\t\t\t[Success]\n");
		printf("\033[0m");

	
	}
	delay(100);
	
	// Timezone file is not on all systems, will fix later
	/*FILE *fp5;
	int LN5 = 0;
	int count4 = 0;

	fp5 = fopen("/etc/timezone", "r");

	if(!(fp5)) {
	
		printf("\033[0;31m");
		printf(":: ");

		printf("\033[0m");
		printf("cannot open TimeZone\n");

	
	}

	if(fp5 != NULL) {
	
		printf("\033[0;32m");	
		printf(":: read TimeZone:\t\t\t[Success]\n");
		printf("\033[0m");

	
	}*/

	FILE *fp6;
	int LN6 = 0;
	int count7 = 0;

	fp6 = fopen("/etc/hostname", "r");

	if(!(fp6)) {
		
		printf("\033[0;31m");
		printf(":: ");

		printf("\033[0m");
		printf("cannot open HostName\n");


	}

	if(fp6 != NULL) {
	
		printf("\033[0;32m");	
		printf(":: read hostname:\t\t\t[Success]\n");
		printf("\033[0m");

	
	}


	CLEAR_D(1000);
	
	printf("[%s-%s-%s-%s-%s-%s-%s-%s-%s-%s-%s-%s-%s-", RED, GREEN, RED, GREEN, RED, GREEN, RED, GREEN, RED, GREEN, RED, GREEN, RED);
	printf("%s-%s-%s-%s-%s-%s-%s-%s-%s-%s-%s-%s-%s-", RED, GREEN, RED, GREEN, RED, GREEN, RED, GREEN, RED, GREEN, RED, GREEN, RED);
	printf("%s-%s-%s-%s-%s-%s-%s-%s-%s-%s-%s-%s-%s-", RED, GREEN, RED, GREEN, RED, GREEN, RED, GREEN, RED, GREEN, RED, GREEN, RED);
	printf("%s-%s-%s-%s-%s-%s-%s-%s-%s-%s-%s-%s-%s-%s]", RED, GREEN, RED, GREEN, RED, GREEN, RED, GREEN, RED, GREEN, RED, GREEN, RED, RESET);
	char line2[256];
	
	while(fgets(line2, sizeof line2, fp2) != NULL) {
			
		if(count == LN) {
			
			printf("%s", RED);
			printf("\n CPU: ");
			printf("%s", RESET);
			printf("%s", &line2[13]);
			fclose(fp2);
		} else {
			count++;
		}
	}
	if(fp2 == NULL) {
	
		printf("\033[0;34m");
		printf(" CPU: ");
		printf("\033[0m");
		printf("NONE\n");

	}

	fclose(fp2);
	
	//GPU
        while(fgets(line900, sizeof line900, GPU) != NULL) {
		
		printf("%s", GREEN);
		printf(" Video:");
		printf("%s", RESET);
                printf(" %s", &line900[60]);

        }
	pclose(GPU);

	char line4[256];
	
	while(fgets(line4, sizeof line4, fp4) != NULL) {
			
		if(count3 == LN3) {
			
			printf("%s", GREEN);
			printf(" Memory Total: ");
			printf("\033[0m");
			printf("%s", &line4[16]);
			break;

		} else {
			count3++;
		}

	} 
	if(fp4 == NULL) {
		
		printf("\033[0;35m");
		printf(" Memory Total: ");
		printf("\033[0m");
		printf("NONE\n");
	}

	fclose(fp4);
	
	while(fgets(line1000, sizeof line1000, UT) != NULL) {
		
		int length2 = 9;
		int length3 = 9;
	
		printf("%s", RED);
		printf(" Uptime: ");
		printf("%s", RESET);
		printf("%*.*s hours\n", length3, length3, &line1000[13]);

		printf("%s", GREEN);
                printf(" Time: ");
                printf("%s", RESET);
                printf("%*.*s\n\n", length2, length2, &line1000[1]);

	}
	pclose(UT);

	char line3[256];

	while(fgets(line3, sizeof line3, fp3) != NULL) {
		
		if(count2 == LN2) {
			
			int length = 50;

			printf("%s", RED);
			printf(" KERNEL: ");
			printf("%s", RESET);
			printf("%*.*s\n", length, length, &line3);

		} else {
			count2++;
		}
	
	}
	if(fp3 == NULL) {
		
		printf("%s", PURPLE);
		printf(" Kernel: ");
		printf("%s", RESET);
		printf("NONE\n");
	}
	fclose(fp3);
	char line5[256];
	
	//for timezone (line: 182)
	/*while(fgets(line5, sizeof line5, fp5) != NULL) {
		
		
		if(count4 == LN5) {

			printf("\033[0;34m");
			printf("\n TimeZone: ");
			printf("\033[0m");
			printf("%s\n", &line5);
			fclose(fp5);
		} else {
			count++;
		}
	}*/
	/*if(fp5 == NULL) {
		
		printf("\033[0;34m");
		printf(" TimeZone: ");
		printf("\033[0m");
		printf("NONE\n");
	}*/
	while(fgets(line1100, sizeof line1100, LIP) != NULL) {
			
			int length99 = 12;			

			printf("%s", GREEN);
			printf(" Local IP:");
			printf("%s", RESET);
			printf("%*.*s\n", length99, length99, &line1100[50]);
	}
	pclose(LIP);		

	char line6[256];

	while(fgets(line6, sizeof line6, fp6) != NULL) {
		
		
		if(count7 == LN6) {

			printf("%s", RED);
			printf(" HostName: ");
			printf("%s", RESET);
			printf("%s\n", &line6);
			fclose(fp6);
		} else {
			count++;
		}
	}
	
	if(fp6 == NULL) {
		
		printf("\033[0;34m");
		printf(" HostName: ");
		printf("\033[0m");
		printf("NONE\n");
	}

	printf("[%s-%s-%s-%s-%s-%s-%s-%s-%s-%s-%s-%s-%s-", RED, GREEN, RED, GREEN, RED, GREEN, RED, GREEN, RED, GREEN, RED, GREEN, RED);
	printf("%s-%s-%s-%s-%s-%s-%s-%s-%s-%s-%s-%s-%s-", GREEN, RED, GREEN, RED, GREEN, RED, GREEN, RED, GREEN, RED, GREEN, RED, GREEN);
	printf("%s-%s-%s-%s-%s-%s-%s-%s-%s-%s-%s-%s-%s-", RED, GREEN, RED, GREEN, RED, GREEN, RED, GREEN, RED, GREEN, RED, GREEN, RED);
	printf("%s-%s-%s-%s-%s-%s-%s-%s-%s-%s-%s-%s-%s-%s]\n", GREEN, RED, GREEN, RED, GREEN, RED, GREEN, RED, GREEN, RED, GREEN, RED, GREEN, RESET);

}

void logo() {

        printf("%s", BRED);
        printf(" ???  ??? ????????? ????????? ???-??? ??????????????????\n");
        printf("%s", BGREEN);
        printf(" ???????????? ?????????  ??? ??????-?????? ??? ?????????\n");
        printf("%s", BRED);
        printf("  ??????  ?????????  ??? ???   ??? ??? ?????????\n");
        printf("%s", RESET);

}


int main() {
	
	logo();
	ES_Test();
	
	usage();
	info();

	return 0;
}
