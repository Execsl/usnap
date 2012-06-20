#include <stdio.h>
#include <conio.h>
#include <string.h>
#include "ploader.c"

#include <math.h>
#include <alloc.h>
#include <bios.h>
#include <io.h>

#define DELAY1	500
#define POS	(24 * 160 + 0 * 2)

#define TCOUNT	(4 * 18)
#define SCOUNT	6

int ucdos = 0;
int quick = 0;

void Begin_Chinese(), Begin_English();
void End_OK_Chinese(), End_OK_English();
void Help_Chinese(), Help_English();
void End_Error_Chinese(), End_Error_English();

void interrupt (*old1c)(...);

void interrupt new1c(...) {
  static char *Ts, *T = quick == 1 ?
	"TOPCROAKCHKREFERCHKREFERCHKREFER�ҿ�����������ü�����ü������" :
	"TOPCROAKCLRCOUNTADJTIMERWELLDONE�ҿ����������������ʱ�䱣��״̬";
  static int i, count, index = 0;
  static char far *s;
  s = (char far *)MK_FP(0xB800, POS);
  if (++count % TCOUNT == 0)
    Ts = T + (ucdos << 5) + 8 * (index++ % 4);
  if (count % SCOUNT == 0)
    for (i = 0; i < 8; i++) s[i + i] = Ts[i];
}

void main(int argc, char **argv) {
  WORD r;
  char cmdline[256];

  asm {
    push ax
    mov ax, 0xDB00
    int 0x2F
    pop ax
  }
  ucdos = _BX == 0x5450;

  if (strcmp(argv[1], "/?") == 0) {
    if (ucdos == 1)
      Help_Chinese();
    else
      Help_English();
    return;
  }

  if (strcmp(argv[1], "/!") == 0) {
    argv[1][0] = '\0';
    quick = 1;
  }

  strcpy(cmdline, *++argv);
  while (*argv && *++argv) {
    strcat(cmdline, " ");
    strcat(cmdline, *argv);
  }
  if (ucdos == 1) Begin_Chinese(); else Begin_English();
  old1c = getvect(0x1C);

  setvect(0x1C, new1c);
  ExternalProgram ep("basrun71.lib", cmdline);
  r = ep.LoadAndExecute();
  if (r == 0) if (ucdos == 1) End_OK_Chinese(); else End_OK_English();
  else if (ucdos == 1) End_Error_Chinese(); else End_Error_English();
  setvect(0x1C, old1c);
}

void Begin_Chinese() {
	textcolor(YELLOW); cprintf("Quick Basic 7.10        �ѿǽ��ܳ���1.0    פ���ڴ�\n\r");
	textcolor(LIGHTBLUE); cprintf("�����������ȫЭ��      л����/�ҿ�����\n\r");
        textcolor(WHITE); cprintf("ִ��\"QB /!\"�鿴�ѿǰ�QB7.1����\n\r"); 
        textcolor(LIGHTGREEN); cprintf("������Կ......\n\r");
        if (!quick) delay(DELAY1);
	cprintf("װ�����......\n\r");
	textcolor(LIGHTGRAY);
	cprintf("\
\n\r");
}

void Begin_English() {
	textcolor(YELLOW); cprintf("Quick Basic 7.10        Unshell decryptor 1.00	Resident memory\n\r");
	textcolor(LIGHTBLUE); cprintf("cybersoft security association  DanSei/TopCroak Software\n\r");
        textcolor(WHITE); cprintf("Enter \"QB /?\" see help\n\r");
        textcolor(LIGHTGREEN); cprintf("Generating Key ......\n\r");
        if (!quick) delay(DELAY1);
	cprintf("Loading ......\n\r");
	textcolor(LIGHTGRAY);
	cprintf("\n\r");
}

void End_OK_Chinese() {
	textcolor(WHITE);
	cprintf("�����˳�!\n\r");
	textcolor(LIGHTGRAY);
	cprintf("\n\r");
}

void End_OK_English() {
	textcolor(WHITE);
	cprintf("Normal Exit!\n\r");
	textcolor(LIGHTGRAY);
	cprintf("\n\r");
}

void Help_Chinese() {
        printf("\
�ѿǽ���Quick Basic 7.10�÷�����\n\r-\n\r\
  QB /? /! /AH /B /C:n {/Ea | /Es} /E:n /G /H /K:[file] /L [����]\n\r\
     /MBF /NOF[RILLS] /NOHI [/RUN] BAS�ļ��� /CMD �ִ�\n\r\n\r\
  /? �鿴������\n\r\
  /! �������� (��������ӿ�����, ���ܻᵼ��QB�����ÿ�ʱ����һ���΢����Ȩ�ַ�\n\r\
               ����, ��������ѭ��. �����������ӿⲻ����ִ�����. )\n\r\
  ����ѡ��ο���׼QB����. "); 
}

void Help_English() {
        printf("\
Unshelled decrypted Quick Basic 7.10 Help\n\r-\n\r\
  QB /? /! /AH /B /C:n {/Ea | /Es} /E:n /G /H /K:[file] /L [lib]\n\r\
     /MBF /NOF[RILLS] /NOHI [/RUN] <BAS File> /CMD string\n\r\n\r\
  /? View this help\n\r\
  /! quick launch (No indirect ref. this may cause lots of Microsoft Software\n\r\
               Warning windows, and get into died. It's actually no problem\n\r\
               if you only do little programming without libs referring. )\n\r\
  See other standard QB commandline reference. "); 
}

void End_Error_Chinese() {
	textcolor(WHITE);
	cprintf("�������г���!\n\r");
	textcolor(LIGHTGRAY);
	cprintf("\n\r");
}

void End_Error_English() {
	textcolor(WHITE);
	cprintf("Fail in running!\n\r");
	textcolor(LIGHTGRAY);
	cprintf("\n\r");
}