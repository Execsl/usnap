#define CWBegin(WhichCW) \
	LastCWSwap=LastCW; \
	LastCW=WhichCW; \
	CW[WhichCW].Restore();
#define CWEnd(WhichCW) \
	CW[WhichCW].Save(); \
	LastCW=LastCWSwap; \
	CW[LastCW].Restore();

int InitVirtualServer(void){
  /*
  ffblk FindRet;
  if (findfirst(UsersFile, &FindRet, 0))
    fclose(fopen(UsersFile, "wb"));
  if (findfirst(RecordsFile, &FindRet, 0))
    fclose(fopen(RecordsFile, "wb"));
  */
  return errno;
}

int InitEnv(void){
  randomize();

  gettextinfo(&Origin);
  ow=Origin.screenwidth;
  oh=Origin.screenheight;

  CW[Screen].x1=CW[Screen].y1=1;
  CW[Screen].x2=ow;
  CW[Screen].y2=oh;
  CW[Screen].Attr=0x07;

  CW[Title].x1=1;
  CW[Title].y1=1;
  CW[Title].x2=ow;
  CW[Title].y2=2;
  CW[Title].Attr=0x34;

  CW[Talking].x1=1;
  CW[Talking].y1=3;
  CW[Talking].x2=ow;
  CW[Talking].y2=17;
  CW[Talking].Attr=0x1f;

  CW[Input].x1=1;
  CW[Input].y1=18;
  CW[Input].x2=ow;
  CW[Input].y2=20;
  CW[Input].Attr=0xd;

  CW[Station].x1=1;
  CW[Station].y1=21;
  CW[Station].x2=ow;
  CW[Station].y2=22;
  CW[Station].Attr=0x74;

  CW[Status].x1=1;
  CW[Status].y1=23;
  CW[Status].x2=ow;
  CW[Status].y2=oh;
  CW[Status].Attr=0x59;

  Ucdos=IsUcdosResident()?1:0;
  InitVirtualServer();
  if (!StartInfo()) return 0;
  if (!InitUser()) return 0;
  strcpy(DefaultAction, (Ucdos)?"˵: ":" say: ");
  strcpy(DApre, "\""); strcpy(DAadd, "\"");
  CW[Screen].Clear(); CW[Screen].Save();
  CW[Title].Clear(); CW[Title].Save();
  CW[Talking].Clear(); CW[Talking].Save();
  CW[Input].Clear(); CW[Input].Save();
  CW[Station].Clear(); CW[Station].Save();
  CW[Status].Clear(); CW[Status].Save();
  return 1;
}

int IsUcdosResident(void){
  union REGS regs;
  regs.x.ax = 0xdb00;
  int86(0x2f,&regs,&regs);
  return regs.x.bx == 0x5450;
}

char* CurTime(void){
  char RetTime[100];
  time(&secs_now);
  time_now=localtime(&secs_now);
  if (Ucdos) strftime(RetTime, 100, "(%H��%M��%S��)@", time_now);
  else strftime(RetTime, 100, "(%H:%M:%S)@", time_now);
  return RetTime;
}

int GetCString(char *Dest){
  gets(Dest);
  return 1;
}

int PutCString(char *Source){
  int using=0;
  if (Source[0]=='%') using=10;
  if (using==10) {
    CWBegin(Station);
    textattr(CW[Station].Attr);
    Source++;
  }
  for (int pS=0; pS<strlen(Source); pS++){
    if (Source[pS]=='<') {
      TStringChain Leave;
      Leave.String = &((Byte*)Source)[pS];
      Leave.Count();
      if (Leave.WhereStr((Byte *)"<<", 1).s) {
	Word sb=_TRetWord.r;
	  Leave.String+=2;
	  if (Leave.WhereStr((Byte *)">>", 1).s) {
	    Word se=_TRetWord.r;
	    if (se>0) {
	      char *Info=new char[se+1];
	      Info[se]=0;
	      for (int ii=0; ii<se; ii++)
		Info[ii]=Source[pS+sb+2+ii];
	      int ATTR=(int)atol(Info);
	      delete Info;
	      if (ATTR) {
		textattr(ATTR%0x100);
		pS+=se+4;
	      } // if (ATTR)
	    } // se>sb+2
	  } // have >>
      } // have <<
      Leave.String = NULL;
    } // found <
    if (Source[pS]=='@') {
      cprintf("\n\r");
      continue;
    }
    if (Source[pS]) putch(Source[pS]);
  } //for
  if (using==10) {
    CWEnd(Station);
  }
  return 1;
} //putcstring

char* MakeTalk(char *_Talk){
int using=0;
  if (_Talk[0]=='%') using=10;
  if (using==10) {
    return _Talk+1;
  }
  strcpy(Tem, _Talk);
  strcpy(_Talk, User.Name);
  if (Tem[0]=='{'){
    strcat(_Talk, Tem+1);
  } else {
    strcat(_Talk, DefaultAction);
    strcat(_Talk, DApre);
    strcat(_Talk, Tem);
    strcat(_Talk, DAadd);
  }
  return _Talk;
}


char *GetSent(void){
  CWBegin(Input);
  CW[Input].Clear();
    PutCString(User.Name);
    PutCString(" : ");
    GetCString(Talks);
  CWEnd(Input);
  return Talks;
}

void CWin::Active(void) {
  window (x1, y1, x2, y2);
}
void CWin::Clear(void) {
  Active();
  textattr(Attr);
  clrscr();
}
void CWin::Save(void) {
  gettextinfo(&Last);
}
void CWin::Restore(void) {
  Active();
  gotoxy(Last.curx, Last.cury);
  textattr(Last.attribute);
}

int StartInfo(void){
  textattr(7);
  clrscr();
  switch(Ucdos){
    case 0:
      gotoxy (10,  1); PutCString("<<15>>Heaven Chat Station / Kernel Debug Version C      Made/DanSei");
      gotoxy (10,  2); PutCString("<<14>>                     --- Welcome ---");
      gotoxy (10,  3); PutCString("<<7>>     This program was produced for study netware first.");
      gotoxy (10,  4); PutCString("   i hope u can like it, and i would also made it more");
      gotoxy (10,  5); PutCString("   fun and interesting.");
      gotoxy (10,  6); PutCString("     If u have any problem or suggestion, please do not");
      gotoxy (10,  7); PutCString("   mind contact me, i will accept your advice if it is");
      gotoxy (10,  8); PutCString("   right.                      --- Author DanSei 98.9.12");
      gotoxy (1 , 10); PutCString("<<11>>================================================================================");

      gotoxy (10, 12); PutCString("<<4>>Agreement");
      gotoxy (10, 13); PutCString("<<12>>  Please consciously observe the following rules, ");
      gotoxy (10, 14); PutCString("  although you can do.");
      gotoxy (10, 15); PutCString("<<10>>    No.1   <<9>>I won't discuss over law.");
      gotoxy (10, 16); PutCString("<<10>>    No.2   <<9>>I won't discuss anything insulting others.");
      gotoxy (10, 17); PutCString("<<10>>    No.3   <<9>>I won't discuss anything bawdyness.");

      gotoxy (20, 20); PutCString("<<15>><Enter> Accept       <Esc> Not accept");
      break;
    case 1:
      gotoxy (10,  1); PutCString("<<15>>�� �� �� �� վ        ���ĵ��԰� C                ����/л����");
      gotoxy (10,  3); PutCString("<<14>>                 ---  ��ӭ��������  ---");
      gotoxy (10,  4); PutCString("<<7>>      �� �� �� �� �� �� ֻ �� �� �� �� ѧ ϰ �� ��.");
      gotoxy (10,  5); PutCString("   ϣ �� �� �� ϲ �� ��.   �� �� �� �� �� �� �� ��,  ��");
      gotoxy (10,  6); PutCString("   �� Ȥ,   �� �� �� �� Ҫ �� �� �� �� ��.");
      gotoxy (10,  7); PutCString("         �� �� �� �� ʲ ô �� �� �� �� ��,   �� �� �� ��");
      gotoxy (10,  8); PutCString("   �� �� �� �� ,  �� �� �� �� �� �� �� .");
      gotoxy (10,  9); PutCString("                                         --- ���� 98.9.12");
      gotoxy (1 , 10); PutCString("<<11>>================================================================================");

      gotoxy (10, 12); PutCString("<<4>>Э ��");
      gotoxy (10, 13); PutCString("<<12>>   �� �� �� �� �� �� �� Э ��");
      gotoxy (10, 15); PutCString("<<10>>      ��  <<9>>�� ̸ �� �� �� �� �� �� �� �� �� �� �� ��.");
      gotoxy (10, 16); PutCString("<<10>>      ��  <<9>>�� ̸ �� �� �� �� �� �� �� �� �� �� �� ��.");
      gotoxy (10, 17); PutCString("<<10>>      ��  <<9>>�� ̸ �� �� �� �� �� �� �� �� �� ��.");

      gotoxy (20, 20); PutCString("<<15>><�س�> ����       <Esc> ������");
      break;
  }
  if (getch()==13) return 1;
  return 0;
}

int InitUser(void){
  window (1, 11, 80, oh);
  clrscr ();
  window (1, 1, ow, oh);
  switch(Ucdos){
    case 0:
      gotoxy (10, 12); PutCString("<<15>>Login");
      gotoxy (10, 14); PutCString("<<13>>   Name     : <<43>>                                    ");
      gotoxy (10, 16); PutCString("<<13>>   Sex      : <<43>>                                    ");
      gotoxy (10, 18); PutCString("<<13>>   Like     : <<43>>                                    ");
      gotoxy (10, 20); PutCString("<<13>>   Leaving  : <<43>>                                    ");
      break;
    case 1:
      gotoxy (10, 12); PutCString("<<15>>ע ��");
      gotoxy (10, 14); PutCString("<<13>>   ע �� �� : <<43>>                                    ");
      gotoxy (10, 16); PutCString("<<13>>   �� ��    : <<43>>                                    ");
      gotoxy (10, 18); PutCString("<<13>>   �� ��    : <<43>>                                    ");
      gotoxy (10, 20); PutCString("<<13>>   �� ��    : <<43>>                                    ");
      break;
  }

  window (25, 14, 55, 14);
    if (!GetCString(User.Name)) {
      strcpy(User.Name, (Ucdos)?"����֮��":"Noname Horse");
      strcat(User.Name, ltoa(random(10000), Tem, 10));
    }
  window (25, 16, 55, 16);
    GetCString(User.sSex);
    if (!strcmp(User.sSex, "��")) strcpy(User.sSex, "����");
    else if (!strcmp(User.sSex, "Ů")) strcpy(User.sSex, "С��");
    else if (!strcmp(User.sSex, "male")) strcpy(User.sSex, "Mr. ");
    else if (!strcmpi(User.sSex, "female")) strcpy(User.sSex, "Miss ");
    else strcpy(User.sSex,(Ucdos)?"���������":"Fire Star Human");
  window (25, 18, 55, 18);
    if (!GetCString(User.Like))
      strcpy(User.Like,(Ucdos)?"������":"Leave blank");
  window (25, 20, 55, 20);
    if (!GetCString(User.Leave))
      strcpy(User.Leave,(Ucdos)?"��Һ�!":"Hello, everyone!");

  Users=fopen(UsersFile, "ab");
  if (!Users)
    NoVS();
  else {
    VSOK();
    fseek(Users, 0, SEEK_END);
    fwrite(&User, sizeof(UserDesc), 1, Users);
    fclose(Users);
  }

  return 1;
}

void LoginFrame(void){
  CW[Station].Clear();
    strcpy(Talks, "%");
    time(&secs_now);
    time_now=localtime(&secs_now);
    if (Ucdos) {
      strcat(Talks, User.Name);
      strcat(Talks, User.sSex);
      strcat(Talks, "��");
      strftime(Tem, 200, "%Y��%m��%d�� %Hʱ%M��%S��", time_now);
      strcat(Talks, Tem);
      strcat(Talks, "��������, ˵\"");
      strcat(Talks, User.Leave);
      strcat(Talks, "\"@");
      PutCString(Talks);
    } else {
      strcat(Talks, User.sSex);
      strcat(Talks, User.Name);
      strcat(Talks, " has come heaven at ");
      strftime(Tem, 200, "%b %d, %Y %H:%M:%S, ", time_now);
      strcat(Talks, Tem);
      strcat(Talks, "Said, \"");
      strcat(Talks, User.Leave);
      strcat(Talks, "\"@");
    }
    PutCString(Talks);

    Records=fopen(RecordsFile, "ab");
    if (!Records)
      NoVS();
    else {
      VSOK();
      fseek(Records, 0, SEEK_END);
      fwrite(Talks, 300, 1, Records);
      fclose(Records);
    }
    Getting=fopen(GettingFile, "wb");
    if (!Getting)
      NoVS();
    else {
      VSOK();
      Tem[0]=random(0x80);
      Tem[1]=random(0x80);
      Tem[2]=random(0x80);
      Tem[3]=random(0x80);
      fwrite(Tem, 4, 1, Getting);
      fwrite(Talks, 300, 1, Getting);
      fclose(Getting);
    }

  CW[Station].Save();

  CWBegin(Talking)
  CW[Talking].Clear();
    if (Ucdos) strcpy(Talks, "��Һ�, �Ҹ�����!");
    else strcpy(Talks, "Hi, everyone, I just logged-in!");
    MakeTalk(Talks);
    strcat(Talks, CurTime());
    PutCString(Talks);
  CWEnd(Talking)
  LastCW=Talking;
  Records=fopen(RecordsFile, "ab");
  if (!Records)
    NoVS();
  else {
    VSOK();
    fseek(Records, 0, SEEK_END);
    fwrite(Talks, 300, 1, Records);
    fclose(Records);
  }
  Getting=fopen(GettingFile, "cb");
  if (!Getting)
    NoVS();
  else {
    VSOK();
    Tem[0]=random(0x80);
    Tem[1]=random(0x80);
    Tem[2]=random(0x80);
    Tem[3]=random(0x80);
    fwrite(Tem, 4, 1, Getting);
    fwrite(Talks, 300, 1, Getting);
    fclose(Getting);
  }
}

void LogoutFrame(void){
  CWBegin(Talking);
    if (Ucdos) strcpy(Talks, "������, �ݰ�!");
    else strcpy(Talks, "Byebye! I just logged-off!");
    MakeTalk(Talks);
    strcat(Talks, CurTime());
    PutCString(Talks);

    Records=fopen(RecordsFile, "ab");
    if (!Records)
      NoVS();
    else {
      VSOK();
      fseek(Records, 0, SEEK_END);
      fwrite(Talks, 300, 1, Records);
      fclose(Records);
    }
    Getting=fopen(GettingFile, "wb");
    if (!Getting)
      NoVS();
    else {
      Tem[0]=random(0x80);
      Tem[1]=random(0x80);
      Tem[2]=random(0x80);
      Tem[3]=random(0x80);
      fwrite(Tem, 4, 1, Getting);
      fwrite(Talks, 300, 1, Getting);
      fclose(Getting);
    }
  CWEnd(Talking);
  CW[Screen].Restore();
}

void VSOK(void){
  CWBegin(Status);
    PutCString((Ucdos)?"���ӵ����������.@":"Success in linking virtual server.@");
  CWEnd(Status);
}
void NoVS(void){
  CWBegin(Status);
    switch (errno) {
      case EINVFNC:
	PutCString((Ucdos)?"����������ڲ�����!@":"Inside virtual server errno!@");
	break;
      case ENOFILE:
	PutCString((Ucdos)?"���������δ�ҵ�!@":"Can't find virtual server!@");
	break;
      case ENOPATH:
	PutCString((Ucdos)?"�������ӵ����������!@":"Can't connect to virtual server!@");
	break;
      case ECONTR:
	PutCString((Ucdos)?"����������ƻ�!@":"Virtual Server has been destroyed!@");
	break;
      case EINVMEM:
	PutCString((Ucdos)?"������������!@":"Virtual Server overflowed!@");
	break;
      case EINVDAT:
	PutCString((Ucdos)?"������������ݴ�!@":"Virtual Server Data Error!@");
	break;
      case EINVACC:
	PutCString((Ucdos)?"���ܷ������������!@":"Couldn't access virtual server!@");
	break;
      case EINVDRV:
	PutCString((Ucdos)?"��û�з��������������Ȩ��!@":"You have no rights to access virtual server!@");
	break;
      case ECURDIR:
	PutCString((Ucdos)?"����������Ͽ�!@":"Virtual Server broken!@");
	break;
      case EACCES:
	PutCString((Ucdos)?"��������������Դ���!@":"Virtual Server protected error!@");
	break;
      case EEXIST:
	PutCString((Ucdos)?"�������������!@":"Overwrites virtual server!@");
	break;
      default:
	PutCString((Ucdos)?"����������ڲ�����!@":"Virtual Server Intenal Error!@");
    }
  CWEnd(Status);
}

void SetTimer(void){
  disable();
  OldTimer=getvect(0x1c);
  setvect(0x1c, Timer);
  enable();
}

void RestoreTimer(void){
  disable();
  setvect(0x1c, OldTimer);
  enable();
}

void interrupt Timer(...){
  Interval++;
  Interval%=IntervalConstant;
  if (!Interval) ChatTimer();
  (*OldTimer)();
}

int ChatWorking = 0;
void ChatTimer(void){
  if (ChatWorking) return;
  ChatWorking = 1;
  rGetting=fopen(GettingFile, "rb");
  if (!rGetting) {
    NoVS();
  } else {
    VSOK();
    fread(Tem, 4, 1, rGetting);
    fread(Talks, 300, 1, rGetting);
    fclose(rGetting);
    if (Tem[3]!=(LastID&0xff)) {
      // Test if myself's talking
      int c, dif=0;
      for (c=0; c<strlen(User.Name); c++)
	if (User.Name[c]!=Talks[c]) dif=1;
      if (!dif) return;
      //((DWord)Tem[0]<<24+(DWord)Tem[1]<<16+(DWord)Tem[2]<<8+Tem[3])!=LastID) {
      //LastID=(DWord)(Tem[0]<<24)+(DWord)(Tem[1]<<16)+(DWord)(Tem[2]<<8)+(DWord)(Tem[3]);
      LastID=Tem[3];
      CWBegin(Talking)
	PutCString("<<30>>");
	PutCString(Talks);
      CWEnd(Talking)
    } // if no duplicate
  }
  ChatWorking = 0;
  return;
}