//DATABASE MANAGEMENT SYSTEM FOR A COACHING INSTITUTE NAMED FIITJEE MADE BY AYUSH VERMA XII-A ROLL NO-12
#include<conio.h>
#include<string.h>
#include<fstream.h>
#include<stdio.h>
#include<process.h>
#include<iostream.h>
int minus=0;

class fiitjee 				//class name: fiitjee
{
				 //details:it controls overall functioning of fiitjee
	public:
	void aboutus();
	void programs();
	void facilities();
	void contactus();
	void enrolment();
	void turnover();




};
fiitjee f;

class student
{
	char address[50];
	char name[20];
     //	int ph[10];
	int id;
	public:
	int dur;
	char course;

	void getdata(int);
	void putdata(void);
	int getid(void);
	char* getname()
	{
		return(name);
	}
};


void student::getdata(int i)                 //function name:getdata
{
	cout<<"\n\n\tEnter your name:";      //data of the student
	gets(name);
	cout<<"\n\n\tEnter your address:";
	gets(address);

       id=i;



}

void student::putdata()
{
	cout<<id<<"\t"<<name<<"\t"<<address<<"\t";
	if(course==1)
		cout<<"IIT-JEE";
	else if(course==2)
		cout<<"FOUNDATIONS";
	else if(course==3)
		cout<<"NEET";
	else if(course==4)
		cout<<"OTHERS";
	if(dur==1)
		cout<<"\t1-YEAR\n";
	else if(dur==2)
		cout<<"\t2-YEAR\n";
	else if(dur==4)
		cout<<"\t4-YEAR\n";

	getch();

}
int student::getid()
{
	return(id);
}
student s;

int checkid()
{
   ifstream fin("student.dat",ios::binary);
   student s1;
   int flag=0,x;
   while(fin.read((char *)&s1,sizeof(s1)))
   {
	x=s1.getid();
	flag=1;
   }
   if(flag==0)
      x=1;
   else
   {
      ++x;
   }
   return x;
}


void write_file()
{       int pos;
	int i=checkid();
	s.getdata(i);              //copying records of student into a file
	ofstream afile("student.dat",ios::binary|ios::app);

       //	pos=afile.getg();
	afile.write((char*)&s,sizeof(s));

	afile.close();

}
void read_file()
{
	ifstream bfile("student.dat",ios::binary);
	cout<<"ID\tNAME\tADDRESS\tCOURSE\tDURATION\n";
	while(bfile.read((char*)&s,sizeof(s)))
	{

		s.putdata();
	}
	clrscr();
	bfile.close();
}
void search()
{

	int p=-1;
	int n;
	ifstream cfile("student.dat",ios::binary);
	cout<<"\n Enter ID of the student to be searched";
	cin>>n;
	while(cfile.read((char*)&s,sizeof(s)))
	{
		if(s.getid()==n)
		{
			s.putdata();
			p++;
		}
	}
	if(p==-1)
	{
		cout<<"Record not found!!!!!!!";

	}
       getch();
       cfile.close();

}
void modify()
{
	int p=-1,t=0,i;
	i=checkid()-1;
	int n;
	cout<<"\n Enter ID student to be modified";
	cin>>n;
	fstream dfile("student.dat",ios::binary|ios::in|ios::out);
	while(dfile.read((char*)&s,sizeof(s)))
	{
		t++;
		if(s.getid()==n)
		{
			s.getdata(i);
			dfile.seekp((t-1)*sizeof(s),ios::beg);
			dfile.write((char*)&s,sizeof(s));
			p++;
		}
	}
	if(p==-1)
	{
		cout<<"Record not found!!!!!!";
	}

	getch();
	dfile.close();
}
void Delete()
{
	extern int errno;
	char ch[20];
	int x;
	int n;
	ifstream efile("student.dat",ios::binary|ios::in);
	ofstream ffile("temp.dat",ios::binary);
	if(!efile)
	{
		cout<<"\nFile can't be opened";
		exit(0);
	}
	else
	{
	cout<<"\nEnter the ID of the student to be deleted:";
	cin>>n;
	while(efile.read((char*)&s,sizeof(s)))
	{
			if(s.getid()==n)
			{
				strcpy(ch,s.getname());
				minus=s.dur;
			}
			else
				ffile.write((char*)&s,sizeof(s));

		}
	}
	ffile.close();
	efile.close();
	remove("student.dat");                 //deleting record of a student
	x=rename("temp.dat","student.dat");
	if(x==0)
	{
		cout<<"student deleted!!!";
		cout<<"\n"<<ch<<" IS DELETED";
	}
	getch();




}
void fiitjee::turnover()
{
	ifstream fin("student.dat",ios::binary|ios::in);
	student s1;
	int yr1=0,yr2=0,yr4=0,turnover=0;
	int course[4]={0,0,0,0};
	while(fin.read((char*)&s1,sizeof(s1)))
	{
		if(s1.dur==1)
			yr1++;
		else if(s1.dur==2)
			yr2++;
		else if(s1.dur==4)
			yr4++;


		if(s1.course==1)
			course[0]++;
		else if(s1.course==2)
			course[1]++;
		else if(s1.course==3)
			course[2]++;
		else if(s1.course==4)
			course[3]++;



	}
		turnover=((1*yr1)+(2*yr2)+(4*yr4)-minus);
		cout<<"\n\tNUMBER OF STUDENT IN IIT JEE:"<<course[0];
		cout<<"\n\tNUMBER OF STUDENT IN FOUNDATION:"<<course[1];
		cout<<"\n\tNUMBER OF STUDENT IN NEET:"<<course[2];
		cout<<"\n\tNUMBER OF STUDENT IN OTHER EXAMS:"<<course[3];


		cout<<"\n\tTOTAL TURNOVER IS:"<<turnover<<"LACKS";


}
void fiitjee::aboutus()
{
	clrscr();
	cout<<"\t\t\t\t**FIITJEE LIMITED**"
	<<"\n\tFiitjee Institute is one of the most proclaimed institutes of INDIA.\n"
	<<"\tThe institute has not only employed experienced teacherswho have "
	<<"\n\tachieved great heights but also has the privilege of producing "
	<<"\n\tmany toppers and rankers who are currently studying in the best colleges"
	<<"\tworldwide."
	<<"\n\tAnanye Aggrawal(IIT BOMBAY), Himanshu Singh(JEE 2019 AIR 2)"
	<<"\n\tare a few names to say."
	<<"\n\n\tThe institute not only provides best professors but also the best"
	<<"\n\tinfrastructure for students to become top rankers."
	<<"\n\tFIITJEE was founded by founder chairman DK GOEL(IIT DELHI GRADUATE)in"
	<<"\n\t1992 as he realised the need of a proper study platform for"
	<<"\n\tyoung aspirants."
	<<"\n\n\tFIITJEE gives coaching for the following programs:-"
	<<"\n\n\t\Foundation Course\tKVPY,NTSE,JSTSE,OLYMPIADS & CBSE"
	<<"\n\tPrograms for IIT-JEE \NEET \JAM \CAT \UPSC \GATE";
	getch();
	clrscr();
	cout<<"\n\tThe institute provides doubt clearing sessions,rank improving workshops,"
	<<"\tARCHIVES(mains and advanced),mock tests,cp quizzes,all india test series,"
	<<"\tcomputer based tests etc."
	<<"\n\tFITTJEE also conducts scholarship tests, fortunate 40 programs and"
	<<"\n\tmany more......."
	<<"\n\n\tFITTJEE also has numerous centres all accross INDIA and even has its"
	<<"\n\tcentres in abroad(UAE)."
	<<"\n\tIt also provides canteens with lots of nutritious food items."
	<<"\n\n\tThere is also a 24 hour security in the institute."
	<<"\n\n\tThe institute also provides its students with various payments methods"
	<<"\n\t(full time,installments,yearly etc) so that they can easily pay once and"
	<<"\tstudy calmly here at fiitjee"
	<<"\n\n\n\t\t Hope you have a marvelous time in our institute!!!\n\n"
	<<"\n\n\n\n\t\t\t\t\*********\n\n\t\t";
	getch();


}
void fiitjee::programs()
{
	progmenu:
	clrscr();
	int b,e,f;
	char a,i,c,d;


	cout<<"\n\t\t\t\tFIITJEE LIMITED\n"<<"\t\t\t\t*************\n"<<"\t\t\t\t*************\n"<<"\t\t\t\t*************\n"<<"\tPrograms offered\n"<<endl;
	cout<<"\tA)IIT-JEE(1,2,4 year)\n\n\n";
	cout<<"\tB)Foundation (for class VI,VII,VIII,IX,X)\n\n\n";
	cout<<"\tC)MEDICAL ENTRANCE NEET (1,2,4 year)\n\n\n";
	cout<<"\tD)Other exams like:SAT,GATE,UPSC,JAM,CAT (2 YEAR)\n\n\n";
	cout<<"\tE)Exit\n\n\n";
	cout<<"\tKindly enter your choice:";
	cin>>a;
	if((a=='a')||(a=='A'))
	{
		iitjee:
		clrscr();
		cout<<"\n\t\t\t\t FIITJEE LIMITED\n";
		cout<<"\t\t\t\t\t******\n";
		cout<<"\t\t\t\t\t******\n";
		cout<<"\n\t\t\t\t****IIT-JEE****";
		cout<<"\n\tFITTJEE is known as the most premier institute for ITT-JEE coaching"
		<<"\n\tsince ages.It has the privilege of producing top rankers in its classes.";
		cout<<"\n\n\tPlease select the Duration of the course.\n";
		cout<<"\t\t\tA) 1 year extended\n";
		cout<<"\t\t\tB) 2 year\n";
		cout<<"\t\t\tC) 4 year\n";
		cout<<"\tKindly enter your choice:";
		cin>>i;
		if((i=='a')||(i=='A'))
		{
			cout<<"\t\tYour fees would be ''1LAKH'' for 1 year.";

			s.dur=1;
			s.course=1;

		}
		else if((i=='b')||(i=='B'))
		{
			cout<<"\t\tYour fees would be ''2lacs'' for 2 years.";
			s.dur=2;
			s.course=1;
		}
		else if((i=='c')||(i=='C'))
		{
			cout<<"\t\tYour fees would be ''4lacs'' for 4 years.";
			s.dur=4;
			s.course=1;
		}
		else
		{
			cout<<"\t You have entered wrong choice"
			<<"\n\tPress 1 too re-enter your choice:";
			cin>>b;
			if(b==1)
				goto iitjee;
			else
				goto progmenu;
		}
		cout<<"\n\n\n\tWould you like to join our institute?(press y-yes)";
		cin>>c;
		if((c=='y')||(c=='Y'))
		{
			Fiitjee:
			clrscr();
					//data of the candidate
			cout<<"\t\t\t\t*****\n";
			cout<<"\t\t\t\t*****\n";
			cout<<"\t****iit-jee****\n";
			write_file();
			cout<<"\n\tEnter suitable time shift(m-morning;e-evening)";
			cin>>d;
			if( ( (i=='a')||(i=='A') ) &&( (d=='m')||(d=='M') ) )
			{
				cout<<"\n\tYour timings are-	9 A.M to 1:30P.M ";
				cout<<"\n\tYour days are:- 	Monday,Wednesday,Friday";

			}
		   else if( ( (i=='a')||(i=='A') ) &&( (d=='e')||(d=='E') ) )
			{
				cout<<"\n\tYour timings are-	2 P.M to 6:30P.M ";
				cout<<"\n\tYour days are:- 	Monday,Wednesday,Friday";

			}
			else if(((i=='b')||(i=='B'))&&((d=='m')||(d=='M')))
			{
				cout<<"\n\tYour timings are-	9 A.M to 1:30P.M ";
				cout<<"\n\tYour days are:- 	Tuesday,Thursday,Saturday";

			}
			else if(((i=='b')||(i=='B'))&&((d=='e')||(d=='E')))
			{
				cout<<"\n\tYour timings are-	2 P.M to 6:30P.M ";
				cout<<"\n\tYour days are:-	 Tuesday,Thursday,Saturday ";

			}
			else if(((i=='c')||(i=='C'))&&((d=='m')||(d=='M')))
			{
				cout<<"\n\tyour timings are-	9 A.M to 1:30P.M ";
				cout<<"\n\tyour day is:- 	Sunday";

			}
			else if(((i=='c')||(i=='C'))&&((d=='e')||(d=='E')))
			{
				cout<<"\n\tyour timings are-	2 P.M to 8 P.M ";
				cout<<"\n\tyour day is:- 	Sunday";

			}
			else
			{
				cout<<"\n\t you have entered a wrong choice";
				cout<<"\n\t press 1 to continue:";
				cin>>e;
				if(e==1)
					goto Fiitjee;
				else
					goto Fiitjee;
			}
			//data of concerned faculty

			cout<<"\n\n\t Faculty (IIT-JEE):";
			cout<<"\n\t\t Head      MR.RAMESH KAUSHIK";
			cout<<"\n\t\t Physics   MR.GOPAL SAHU";
			cout<<"\n\t\t Chemistry MR.LOKESH DIXIT";
			cout<<"\n\t\t Maths     MR.MANISH PANDEY";
			cout<<"\n\n\n\n\t\t\t Thank You for joining FITTJEE!!!";
			cout<<"\n\n\tPress 0 to continue:";
			cin>>f;
			if(f==0)
				goto progmenu;
			else
				goto progmenu;
			}

		}
		       else	if((a=='b')||(a=='B'))
			{
				foundation:
				clrscr();

			cout<<"\n\t\t\t\t FIITJEE LIMITED\n";
			cout<<"\t\t\t\t\t******\n";
			cout<<"\t\t\t\t\t******\n";
			cout<<"\n\t\t\t\t****FOUNDATION****";
			cout<<"\n\tFITTJEE is known as a gurukul for foundation courses as well."
			<<"It gives the beginners a new platform to enhance their skills in its foundation classes.";
			cout<<"\n\n\tPlease select the Duration of the course.\n";
			cout<<"\t\t\tA) 1 year extended\n";
			cout<<"\t\t\tB) 2 year\n";
			cout<<"\t\t\tC) 4 year\n";
			cout<<"\tKindly enter your choice:";

			cin>>i;
			if((i=='a')||(i=='A'))
		    {
			cout<<"\t\tYour fees would be ''1LAKH'' for 1 year.";
			s.dur=1;
			s.course=2;

		    }

			else if((i=='b')||(i=='B'))
		     {
			cout<<"\t\tYour fees would be ''2lacs'' for 2 years.";
			s.dur=2;
			s.course=2;
		     }

			else if((i=='c')||(i=='C'))
		      {
			cout<<"\t\tYour fees would be ''4lacs'' for 4 years.";
			s.dur=4;
			s.course=2;
		      }
		else
		{
			cout<<"\t You have entered wrong choice"
			<<"\n\tPress 1 too re-enter your choice:";
			cin>>b;
			if(b==1)
				goto foundation;
			else
				goto progmenu;
		}
		cout<<"\n\n\n\t Would you like to join our institute?(press y-yes):";
		cin>>c;
		if(c=='y')
		{
			Ffoundation:
			clrscr();
			//data of the candidate
			cout<<"\t\t\t\t*****\n";
			cout<<"\t\t\t\t*****\n";
			cout<<"\t\t\t****FOUNDATION****\n\n";
			write_file();
			cout<<"\n\n\n\tEnter suitable time shift(m-morning;e-evening):";
			cin>>d;

			if( ( (i=='a')||(i=='A') ) &&( (d=='m')||(d=='M') ) )
			{
				cout<<"\n\tYour timings are-	9 A.M to 1:30P.M ";
				cout<<"\n\tYour days are:- 	Monday,Wednesday,Friday";

			}
		   else if( ( (i=='a')||(i=='A') ) &&( (d=='e')||(d=='E') ) )
			{
				cout<<"\n\tYour timings are-	2 P.M to 6:30P.M ";
				cout<<"\n\tYour days are:- 	Monday,Wednesday,Friday";

			}
			else if(((i=='b')||(i=='B'))&&((d=='m')||(d=='M')))
			{
				cout<<"\n\tYour timings are-	9 A.M to 1:30P.M ";
				cout<<"\n\tYour days are:- 	Tuesday,Thursday,Saturday";

			}
			else if(((i=='b')||(i=='B'))&&((d=='e')||(d=='E')))
			{
				cout<<"\n\tYour timings are-	2 P.M to 6:30P.M ";
				cout<<"\n\tYour days are:- 	Tuesday,Thursday,Saturday ";

			}
			else if(((i=='c')||(i=='C'))&&((d=='m')||(d=='M')))
			{
				cout<<"\n\tYour timings are-	9 A.M to 1:30P.M ";
				cout<<"\n\tYour day is:- 	Sunday";

			}
			else if(((i=='c')||(i=='C'))&&((d=='e')||(d=='E')))
			{
				cout<<"\n\tYour timings are-	2 P.M to 8 P.M ";
				cout<<"\n\tYour day is:- 	Sunday";

			}
			else
			{

				cout<<"\n\n\t You have entered a wrong choice";
				cout<<"\n\n\t Press 1 to continue:";
				cin>>e;
				if(e==1)
					goto Ffoundation;
				else
					goto Ffoundation;
			}
			//data of concerned faculty

			cout<<"\n\n\t Faculty (FOUNDATION):"
			    <<"\n\t\t Head      MR.AMIT SINGH"
			    <<"\n\t\t Physics   MRS.PRIYA GUPTA"
			    <<"\n\t\t Chemistry MR.JAVED KHAN"
			    <<"\n\t\t Maths 	MR.SUNIL VERMA"
			    <<"\n\n\t Biology	MRS.PRIYANKA SHARMA"
			    <<"\n\n\t English	MR.GEORGE PAUL";
			cout<<"\n\n\n\n\t\t\t Thank You for joining FITTJEE!!!";
			cout<<"\n\n\tPress 0 to continue:";
			cin>>f;
			if(f==0)

				goto progmenu;
			else
				goto progmenu;


			}
			else
			goto progmenu;
			}
		     else  if((a=='c')||(a=='C'))
			{
				neet:
				clrscr();

				cout<<"\n\t\t\t\t FIITJEE LIMITED\n";
			cout<<"\t\t\t\t\t******\n";
		cout<<"\t\t\t\t\t******\n";
		cout<<"\n\t\t\t\t****MEDICAL****";
		cout<<"FITTJEE is known as a hub for medical preparations as well."
		    <<"It gives the aspirants a huge support to enhance their skills and rank in its neet classes";
		cout<<"\n\n\tPlease select the Duration of the course.\n";
		cout<<"\t\t\tA) 1 year extended\n";
		cout<<"\t\t\tB) 2 year\n";
		cout<<"\t\t\tC) 4 year\n";
		cout<<"\tKindly Enter your choice:";
				cin>>i;
				if((i=='a')||(i=='A'))
				{
					cout<<"Your fees would be 1LAKH for 1 year";
					s.dur=1;
					s.course=3;
				}
				else if((i=='b')||(i=='B'))
				{
					cout<<"Your fees would be 2Lacs for 2 years";
					s.dur=2;
					s.course=3;
				 }
				else if((i=='c')||(i=='C'))
				{
					cout<<"Your fees would be 4Lacs for 4 years";
					s.dur=4;
					s.course=3;
				 }
				else
				{
				cout<<"\t You have entered wrong choice\n"<<"\tPress 1 too re-enter your choice:";
				cin>>b;
				if(b==1)

					goto neet;
				else
					goto progmenu;
		}
		cout<<"\n\n\n\tWould you like to join our institute?(press y-yes):";
		cin>>c;
			if(c=='y')
		{
			Fneet:
			clrscr();
			//data of the candidate
			cout<<"\t\t*****\n";
			cout<<"\t\t*****\n";
			cout<<"\t**NEET****\n\n";
			cout<<"\t\t*****\n";
			cout<<"\t\t*****\n";
			write_file();
			cout<<"\n\tEnter suitable time shift(m-morning;e-evening):";
			cin>>d;
			if( ( (i=='a')||(i=='A') ) &&( (d=='m')||(d=='M') ) )
			{
				cout<<"\n\tYour timings are-	9 A.M to 1:30P.M ";
				cout<<"\n\tYour days are:- 	Monday,Wednesday,Friday";

			}
		   else if( ( (i=='a')||(i=='A') ) &&( (d=='e')||(d=='E') ) )
			{
				cout<<"\n\tYour timings are-	2 P.M to 6:30P.M ";
				cout<<"\n\tYour days are:- 	Monday,Wednesday,Friday";

			}
			else if(((i=='b')||(i=='B'))&&((d=='m')||(d=='M')))
			{
				cout<<"\n\tYour timings are-	9 A.M to 1:30P.M ";
				cout<<"\n\tYour days are:- 	Tuesday,Thursday,Saturday";

			}
			else if(((i=='b')||(i=='B'))&&((d=='e')||(d=='E')))
			{
				cout<<"\n\tYour timings are-	2 P.M to 6:30P.M ";
				cout<<"\n\tYour days are:-	 Tuesday,Thursday,Saturday ";

			}
			else if(((i=='c')||(i=='C'))&&((d=='m')||(d=='M')))
			{
				cout<<"\n\tyour timings are-	9 A.M to 1:30P.M ";
				cout<<"\n\tyour day is:- 	Sunday";

			}
			else if(((i=='c')||(i=='C'))&&((d=='e')||(d=='E')))
			{
				cout<<"\n\tyour timings are-	2 P.M to 8 P.M ";
				cout<<"\n\tyour day is:- 	Sunday";

			}

			else
			{
				cout<<"\n\n\t You have entered a wrong choice";
				cout<<"\n\n\t Press 1 to continue:";
				cin>>e;
				if(e==1)
				goto Fneet;
					else
					goto Fneet;
			}
			//data of concerned faculty

			cout<<"\n\n\t faculty( NEET ):"
			    <<"\n\t\t Head	MR.PARMINDER SINGH"
			    <<"\n\t\t Physics 	MRS.ABHAY GUPTA"
			    <<"\n\t\t Chemistry MR.NAITIK KASHYAP"
			    <<"\n\n\t Biology 	MRS.NEHA ARORA";
			cout<<"\n\n\n\n\t\t\t Thank You for joining fiitjee!!!";
			cout<<"\n\n\tpress 0 to continue:";
			cin>>f;
			if(f==0)

				goto progmenu;
			else
				goto progmenu;


			}
			else
			goto progmenu;
			}
		    else	if((a=='d')||(a=='D'))
			{
				otherexams:
				clrscr();
				cout<<"\n\n\n\t\t\t\t FIITJEE LIMITED\n";
				cout<<"\t\t\t\t******\n";
				cout<<"\t\t\t\t******\n";
				cout<<"\t\t****OTHEREXAMS****\n";
				cout<<"\t FITTJEE is also famous for other preparations as well.It gives the\n"<<"\n\tstudents proper coaching for exams like SAT,GATE,UPSC,JAM,CAT";
				cout<<"\t\t\tEXAMS:--\n";
				cout<<"\t\t\tA) SAT,GATE\n";
				cout<<"\t\t\tB) UPSC\n";
				cout<<"\t\t\tC)CAT,JAM\n";
				cout<<"Enter your choice:";

				cin>>i;
				if((i=='a')||(i=='A'))
				{
					cout<<"Your fees would be 1LAKH for 1 year";
					s.dur=1;
					s.course=4;
				}
				else if((i=='b')||(i=='B'))
				{
					cout<<"Your fees would be 2Lacs for 2 years";
					s.dur=2;
					s.course=4;
				 }
				else if((i=='c')||(i=='C'))
				{
					cout<<"Your fees would be 4Lacs for 4 years";
					s.dur=4;
					s.course=4;
				 }
				else
				{
			cout<<"\t you have entered wrong choice\n"<<"\tpress 1 too re-enter your choice";
			cin>>b;
			if(b==1)

				goto otherexams;
			else
				goto progmenu;
		}
		cout<<"\n\n\n\t Would you like to join our institute?(press y-yes):";
		cin>>c;
		if(c=='y')
		{
			Fotherexams:
			clrscr();
			//data of the candidate
			cout<<"\t\t\t\t*****\n";
			cout<<"\t\t\t\t*****\n";
			cout<<"\t\t\t**OTHEREXAMS****\n\n";
			write_file();
			cout<<"\n\tEnter suitable time shift(m-morning;e-evening):";
			cin>>d;

		       if( ( (i=='a')||(i=='A') ) &&( (d=='m')||(d=='M') ) )
			{
				cout<<"\n\tYour timings are-	9 A.M to 1:30P.M ";
				cout<<"\n\tYour days are:- 	Monday,Wednesday,Friday";

			}
		   else if( ( (i=='a')||(i=='A') ) &&( (d=='e')||(d=='E') ) )
			{
				cout<<"\n\tYour timings are-	2 P.M to 6:30P.M ";
				cout<<"\n\tYour days are:- 	Monday,Wednesday,Friday";

			}
			else if(((i=='b')||(i=='B'))&&((d=='m')||(d=='M')))
			{
				cout<<"\n\tYour timings are-	9 A.M to 1:30P.M ";
				cout<<"\n\tYour days are:- 	Tuesday,Thursday,Saturday";

			}
			else if(((i=='b')||(i=='B'))&&((d=='e')||(d=='E')))
			{
				cout<<"\n\tYour timings are-	2 P.M to 6:30P.M ";
				cout<<"\n\tYour days are:- 	Tuesday,Thursday,Saturday ";

			}
			else if(((i=='c')||(i=='C'))&&((d=='m')||(d=='M')))
			{
				cout<<"\n\tYour timings are-	9 A.M to 1:30P.M ";
				cout<<"\n\tYour day is:- 	Sunday";

			}
			else if(((i=='c')||(i=='C'))&&((d=='e')||(d=='E')))
			{
				cout<<"\n\tYour timings are-	2 P.M to 8 P.M ";
				cout<<"\n\tYour day is:- 	Sunday";

			}

			else
			{
				cout<<"\n\n\t you have entered a wrong choice";
				cout<<"\n\n\t press 1 to continue";
				cin>>e;
				if(e==1)
					goto Fotherexams;
			     else
					goto Fotherexams;
			}
			//data of concerned faculty

			cout<<"\n\n\t faculty(OTHEREXAMS):"
				<<"\n\t\t Head		MR.MADHAV GHOSH"
				<<"\n\t\tSAT/GATE 	MR.ROHAN VATS"
				<<"\n\t\t UPSC 		MR.RANJAN KUMAR"
				<<"\n\t\t CAT/JAM 	MR.SANJAY KHURANA";
			cout<<"\n\n\n\n\t\t\t thank you for joining fiitjee!!!";
			cout<<"\n\n\tpress 0 to continue";
			cin>>f;
			if(f==0)

				goto progmenu;
			else
				goto progmenu;


			}
			else
				goto progmenu;
			}
		 }
		 void fiitjee::facilities()
		 {
			clrscr();

				cout<<"\t\t\t\tFIITJEE LIMITED\n";
				cout<<"\t\t\t\t*************\n";
				cout<<"\t\t\t\t****Facilities****\n";
				cout<<"\tThese are the following facilities provided by our institute:-\n";
				cout<<"\t1)CANTEEN/STATIONERY SHOPS\n"
				    <<"\tthe canteen here is owned by haldiram's and is open 24-hours\n"
				    <<"\tand provides lots of tasty and nutritious food items at very\n"
				    <<"\taffordable prices for the young aspirants.The stationery shops\n"
				    <<"\tare owned by classmate's and provide best quality books and stationery"
				    <<"\n\tfor children.\n";
				cout<<"\n\t2)SECURITY/PARKING/CLEANLINESS\n"
				    <<"\tthe whole institute is under CCTV surveillance and guarded by CRPF"
				    <<"\n\tforces making purely safe for your child.The parking here can"
				    <<"\n\taccomodate every kind of vehicle and is also taken care by security"
				    <<"\n\tguards.Cleanliness is given uttermost importance\n";
				cout<<"\n\t3)DCC/AITS/PRACICE TESTS\n"
				    <<"\tThe doubt clearing classes(DCC) provide students best way to clear"
				    <<"\n\ttheir doubts almost daily various tests like AITS,CP QUIZZES,CBT TESTS"
				    <<"\n\t,PHASE TESTS, MYPAT,ETC make students enhance their performance"
				    <<"\n\tand see their weak areas\n";
				cout<<"\n\t4)WELL-EQUIPPED CLASSROOMS\n"
				    <<"\tThe fiitjee classrooms are well-equipped with fully air-conditioned"
				    <<"\n\trooms, water coolers, wooden desks and proper white board so that"
				    <<"\n\tstudents can learn maximum.\n";
				cout<<"\t\t\t\t*************\n";
			getch();
		 }

		 void fiitjee::contactus()
		 {
		       clrscr();
		       cout<<"\n"<<"\t\t\t________________\n"<<"\t\t\t*             *\n"<<"\t\t\t*                *\n"<<"\t\t\t****************\n"<<"\t\t\t*CONTACT US*\n"<<"\nFIITJEE LIMITED\n"<<"\t\t\t***********\n"<<"\t\t\t*             *\n"<<"\t\t\t____________\n\n\n\n\n";
		       cout<<"\t\t\tHEAD OFFICE:-\n"<<"\t\t\tFIITJEE LIMITED\n"<<"\t\t\t29-A,Kalu Sarai, Sarvapriya Vihar\n"<<"\t\t\tNear Hauz Khas Metro Station\n"<<"\t\t\t Delhi-110016\n"<<"\t\t\tPh No-011-49383471\n\n\n\n";
		       //data of heads of paricular deptt
		       cout<<"\t1)IIT-JEE HEAD                  2)FOUNDATION HEAD\n"<<"\tMr.Ramesh Kaushik                 Mr.Amit Singh\n"<<"\t79,Azad Appts,Delhi-92            54-A Block,Mayur Vihar\n"<<"\tPh No-9971441647                  Ph No-9946763123\n\n\n"<<"\t3)NEET HEAD                     4)OTHER EXAMS HEAD\n"<<"\tMr.Parminder Singh                 Mr.Madhav Ghosh\n"<<"\t93,Jai Appts,Delhi-72              12-C Block,Chander Vihar\n"<<"\tPh No-9834567834                   Ph No-9868231658\n\n\n\n";
		       cout<<"\t\t\t OUR ALL INDIA TOLL FREE NUMBER:--\n"<<"\t\t\t 1800-11-4242";
		       getch();
		 }
		 void fiitjee::enrolment()
		 {
			void write_file();
			void read_file();
			void search();
			void modify();
			void Delete();
			int d;
			char a,b,c;
			Fenrolment:
			clrscr();

				clrscr();
				cout<<"\tFIITJEE LIMITED\n"<<"\t*************\n"<<"\t*************\n"<<"\t_____________\n"<<"\t|ENROLMENT|\n"<<"\t_____________\n\n"<<"\t*************\n"<<"\t*************\n"<<"\tFOR ADMINISTRATOR ONLY\n"<<"\t*************\n"<<"\t* * * * * * *\n";
				do
				{
					cout<<"\n\t\tA).ADD STUDENTS\n";
					cout<<"\n\t\tB).READ STUDENTS\n";
					cout<<"\n\t\tC).SEARCH STUDENTS\n";
					cout<<"\n\t\tD).MODIFY STUDENTS\n";
					cout<<"\n\t\tE).DELETE STUDENTS\n";
					cout<<"\n\t\tF).STUDENTS IN DIFFERNET COURSE\n";
					cout<<"\n\t\tG).EXIT\n";
					cout<<"\n\t\tEnter your selection";
					cin>>c;
					if((c=='a')||(c=='A'))
	{
	progmenu:
	clrscr();
	int b,e,f;
	char a,i,c,d;


	cout<<"\n\t\t\t\tFIITJEE LIMITED\n"<<"\t\t\t\t*************\n"<<"\t\t\t\t*************\n"<<"\t\t\t\t*************\n"<<"\tPrograms offered\n"<<endl;
	cout<<"\tA)IIT-JEE(1,2,4 year)\n\n\n";
	cout<<"\tB)Foundation (for class VI,VII,VIII,IX,X)\n\n\n";
	cout<<"\tC)MEDICAL ENTRANCE NEET (1,2,4 year)\n\n\n";
	cout<<"\tD)Other exams like:SAT,GATE,UPSC,JAM,CAT (2 YEAR)\n\n\n";
	cout<<"\tE)Exit\n\n\n";
	cout<<"\tKindly enter your choice:";
	cin>>a;
	if((a=='a')||(a=='A'))
	{
		iitjee:
		clrscr();
		cout<<"\n\t\t\t\t FIITJEE LIMITED\n";
		cout<<"\t\t\t\t\t******\n";
		cout<<"\t\t\t\t\t******\n";
		cout<<"\n\t\t\t\t****IIT-JEE****";
		cout<<"\n\tFITTJEE is known as the most premier institute for ITT-JEE coaching"
		<<"\n\tsince ages.It has the privilege of producing top rankers in its classes.";
		cout<<"\n\n\tPlease select the Duration of the course.\n";
		cout<<"\t\t\tA) 1 year extended\n";
		cout<<"\t\t\tB) 2 year\n";
		cout<<"\t\t\tC) 4 year\n";
		cout<<"\tKindly enter your choice:";
		cin>>i;
		if((i=='a')||(i=='A'))
		{
			cout<<"\t\tYour fees would be ''1LAKH'' for 1 year.";

			s.dur=1;
			s.course=1;

		}
		else if((i=='b')||(i=='B'))
		{
			cout<<"\t\tYour fees would be ''2lacs'' for 2 years.";
			s.dur=2;
			s.course=1;
		}
		else if((i=='c')||(i=='C'))
		{
			cout<<"\t\tYour fees would be ''4lacs'' for 4 years.";
			s.dur=4;
			s.course=1;
		}
		else
		{
			cout<<"\t You have entered wrong choice"
			<<"\n\tPress 1 too re-enter your choice:";
			cin>>b;
			if(b==1)
				goto iitjee;
			else
				goto progmenu;
		}
		cout<<"\n\n\n\tWould you like to join our institute?(press y-yes)";
		cin>>c;
		if((c=='y')||(c=='Y'))
		{
			Fiitjee:
			clrscr();
					//data of the candidate
			cout<<"\t\t\t\t*****\n";
			cout<<"\t\t\t\t*****\n";
			cout<<"\t****iit-jee****\n";
			write_file();
			cout<<"\n\tEnter suitable time shift(m-morning;e-evening)";
			cin>>d;
			if( ( (i=='a')||(i=='A') ) &&( (d=='m')||(d=='M') ) )
			{
				cout<<"\n\tYour timings are-	9 A.M to 1:30P.M ";
				cout<<"\n\tYour days are:- 	Monday,Wednesday,Friday";

			}
		   else if( ( (i=='a')||(i=='A') ) &&( (d=='e')||(d=='E') ) )
			{
				cout<<"\n\tYour timings are-	2 P.M to 6:30P.M ";
				cout<<"\n\tYour days are:- 	Monday,Wednesday,Friday";

			}
			else if(((i=='b')||(i=='B'))&&((d=='m')||(d=='M')))
			{
				cout<<"\n\tYour timings are-	9 A.M to 1:30P.M ";
				cout<<"\n\tYour days are:- 	Tuesday,Thursday,Saturday";

			}
			else if(((i=='b')||(i=='B'))&&((d=='e')||(d=='E')))
			{
				cout<<"\n\tYour timings are-	2 P.M to 6:30P.M ";
				cout<<"\n\tYour days are:-	 Tuesday,Thursday,Saturday ";

			}
			else if(((i=='c')||(i=='C'))&&((d=='m')||(d=='M')))
			{
				cout<<"\n\tyour timings are-	9 A.M to 1:30P.M ";
				cout<<"\n\tyour day is:- 	Sunday";

			}
			else if(((i=='c')||(i=='C'))&&((d=='e')||(d=='E')))
			{
				cout<<"\n\tyour timings are-	2 P.M to 8 P.M ";
				cout<<"\n\tyour day is:- 	Sunday";

			}
			else
			{
				cout<<"\n\t you have entered a wrong choice";
				cout<<"\n\t press 1 to continue:";
				cin>>e;
				if(e==1)
					goto Fiitjee;
				else
					goto Fiitjee;
			}
			//data of concerned faculty

			cout<<"\n\n\t Faculty (IIT-JEE):";
			cout<<"\n\t\t Head      MR.RAMESH KAUSHIK";
			cout<<"\n\t\t Physics   MR.GOPAL SAHU";
			cout<<"\n\t\t Chemistry MR.LOKESH DIXIT";
			cout<<"\n\t\t Maths     MR.MANISH PANDEY";
			cout<<"\n\n\n\n\t\t\t Thank You for joining FITTJEE!!!";
			cout<<"\n\n\tPress 0 to continue:";
			cin>>f;
			if(f==0)
				goto progmenu;
			else
				goto progmenu;
			}

		}
		       else	if((a=='b')||(a=='B'))
			{
				foundation:
				clrscr();

			cout<<"\n\t\t\t\t FIITJEE LIMITED\n";
			cout<<"\t\t\t\t\t******\n";
			cout<<"\t\t\t\t\t******\n";
			cout<<"\n\t\t\t\t****FOUNDATION****";
			cout<<"\n\tFITTJEE is known as a gurukul for foundation courses as well."
			<<"It gives the beginners a new platform to enhance their skills in its foundation classes.";
			cout<<"\n\n\tPlease select the Duration of the course.\n";
			cout<<"\t\t\tA) 1 year extended\n";
			cout<<"\t\t\tB) 2 year\n";
			cout<<"\t\t\tC) 4 year\n";
			cout<<"\tKindly enter your choice:";

			cin>>i;
			if((i=='a')||(i=='A'))
		    {
			cout<<"\t\tYour fees would be ''1LAKH'' for 1 year.";
			s.dur=1;
			s.course=2;

		    }

			else if((i=='b')||(i=='B'))
		     {
			cout<<"\t\tYour fees would be ''2lacs'' for 2 years.";
			s.dur=2;
			s.course=2;
		     }

			else if((i=='c')||(i=='C'))
		      {
			cout<<"\t\tYour fees would be ''4lacs'' for 4 years.";
			s.dur=4;
			s.course=2;
		      }
		else
		{
			cout<<"\t You have entered wrong choice"
			<<"\n\tPress 1 too re-enter your choice:";
			cin>>b;
			if(b==1)
				goto foundation;
			else
				goto progmenu;
		}
		cout<<"\n\n\n\t Would you like to join our institute?(press y-yes):";
		cin>>c;
		if(c=='y')
		{
			Ffoundation:
			clrscr();
			//data of the candidate
			cout<<"\t\t\t\t*****\n";
			cout<<"\t\t\t\t*****\n";
			cout<<"\t\t\t****FOUNDATION****\n\n";
			write_file();
			cout<<"\n\n\n\tEnter suitable time shift(m-morning;e-evening):";
			cin>>d;

			if( ( (i=='a')||(i=='A') ) &&( (d=='m')||(d=='M') ) )
			{
				cout<<"\n\tYour timings are-	9 A.M to 1:30P.M ";
				cout<<"\n\tYour days are:- 	Monday,Wednesday,Friday";

			}
		   else if( ( (i=='a')||(i=='A') ) &&( (d=='e')||(d=='E') ) )
			{
				cout<<"\n\tYour timings are-	2 P.M to 6:30P.M ";
				cout<<"\n\tYour days are:- 	Monday,Wednesday,Friday";

			}
			else if(((i=='b')||(i=='B'))&&((d=='m')||(d=='M')))
			{
				cout<<"\n\tYour timings are-	9 A.M to 1:30P.M ";
				cout<<"\n\tYour days are:- 	Tuesday,Thursday,Saturday";

			}
			else if(((i=='b')||(i=='B'))&&((d=='e')||(d=='E')))
			{
				cout<<"\n\tYour timings are-	2 P.M to 6:30P.M ";
				cout<<"\n\tYour days are:- 	Tuesday,Thursday,Saturday ";

			}
			else if(((i=='c')||(i=='C'))&&((d=='m')||(d=='M')))
			{
				cout<<"\n\tYour timings are-	9 A.M to 1:30P.M ";
				cout<<"\n\tYour day is:- 	Sunday";

			}
			else if(((i=='c')||(i=='C'))&&((d=='e')||(d=='E')))
			{
				cout<<"\n\tYour timings are-	2 P.M to 8 P.M ";
				cout<<"\n\tYour day is:- 	Sunday";

			}
			else
			{

				cout<<"\n\n\t You have entered a wrong choice";
				cout<<"\n\n\t Press 1 to continue:";
				cin>>e;
				if(e==1)
					goto Ffoundation;
				else
					goto Ffoundation;
			}
			//data of concerned faculty

			cout<<"\n\n\t Faculty (FOUNDATION):"
			    <<"\n\t\t Head      MR.AMIT SINGH"
			    <<"\n\t\t Physics   MRS.PRIYA GUPTA"
			    <<"\n\t\t Chemistry MR.JAVED KHAN"
			    <<"\n\t\t Maths 	MR.SUNIL VERMA"
			    <<"\n\n\t Biology	MRS.PRIYANKA SHARMA"
			    <<"\n\n\t English	MR.GEORGE PAUL";
			cout<<"\n\n\n\n\t\t\t Thank You for joining FITTJEE!!!";
			cout<<"\n\n\tPress 0 to continue:";
			cin>>f;
			if(f==0)

				goto progmenu;
			else
				goto progmenu;


			}
			else
			goto progmenu;
			}
		     else  if((a=='c')||(a=='C'))
			{
				neet:
				clrscr();

				cout<<"\n\t\t\t\t FIITJEE LIMITED\n";
			cout<<"\t\t\t\t\t******\n";
		cout<<"\t\t\t\t\t******\n";
		cout<<"\n\t\t\t\t****MEDICAL****";
		cout<<"FITTJEE is known as a hub for medical preparations as well."
		    <<"It gives the aspirants a huge support to enhance their skills and rank in its neet classes";
		cout<<"\n\n\tPlease select the Duration of the course.\n";
		cout<<"\t\t\tA) 1 year extended\n";
		cout<<"\t\t\tB) 2 year\n";
		cout<<"\t\t\tC) 4 year\n";
		cout<<"\tKindly Enter your choice:";
				cin>>i;
				if((i=='a')||(i=='A'))
				{
					cout<<"Your fees would be 1LAKH for 1 year";
					s.dur=1;
					s.course=3;
				}
				else if((i=='b')||(i=='B'))
				{
					cout<<"Your fees would be 2Lacs for 2 years";
					s.dur=2;
					s.course=3;
				 }
				else if((i=='c')||(i=='C'))
				{
					cout<<"Your fees would be 4Lacs for 4 years";
					s.dur=4;
					s.course=3;
				 }
				else
				{
				cout<<"\t You have entered wrong choice\n"<<"\tPress 1 too re-enter your choice:";
				cin>>b;
				if(b==1)

					goto neet;
				else
					goto progmenu;
		}
		cout<<"\n\n\n\tWould you like to join our institute?(press y-yes):";
		cin>>c;
			if(c=='y')
		{
			Fneet:
			clrscr();
			//data of the candidate
			cout<<"\t\t*****\n";
			cout<<"\t\t*****\n";
			cout<<"\t**NEET****\n\n";
			cout<<"\t\t*****\n";
			cout<<"\t\t*****\n";
			write_file();
			cout<<"\n\tEnter suitable time shift(m-morning;e-evening):";
			cin>>d;
			if( ( (i=='a')||(i=='A') ) &&( (d=='m')||(d=='M') ) )
			{
				cout<<"\n\tYour timings are-	9 A.M to 1:30P.M ";
				cout<<"\n\tYour days are:- 	Monday,Wednesday,Friday";

			}
		   else if( ( (i=='a')||(i=='A') ) &&( (d=='e')||(d=='E') ) )
			{
				cout<<"\n\tYour timings are-	2 P.M to 6:30P.M ";
				cout<<"\n\tYour days are:- 	Monday,Wednesday,Friday";

			}
			else if(((i=='b')||(i=='B'))&&((d=='m')||(d=='M')))
			{
				cout<<"\n\tYour timings are-	9 A.M to 1:30P.M ";
				cout<<"\n\tYour days are:- 	Tuesday,Thursday,Saturday";

			}
			else if(((i=='b')||(i=='B'))&&((d=='e')||(d=='E')))
			{
				cout<<"\n\tYour timings are-	2 P.M to 6:30P.M ";
				cout<<"\n\tYour days are:-	 Tuesday,Thursday,Saturday ";

			}
			else if(((i=='c')||(i=='C'))&&((d=='m')||(d=='M')))
			{
				cout<<"\n\tyour timings are-	9 A.M to 1:30P.M ";
				cout<<"\n\tyour day is:- 	Sunday";

			}
			else if(((i=='c')||(i=='C'))&&((d=='e')||(d=='E')))
			{
				cout<<"\n\tyour timings are-	2 P.M to 8 P.M ";
				cout<<"\n\tyour day is:- 	Sunday";

			}

			else
			{
				cout<<"\n\n\t You have entered a wrong choice";
				cout<<"\n\n\t Press 1 to continue:";
				cin>>e;
				if(e==1)
				goto Fneet;
					else
					goto Fneet;
			}
			//data of concerned faculty

			cout<<"\n\n\t faculty( NEET ):"
			    <<"\n\t\t Head	MR.PARMINDER SINGH"
			    <<"\n\t\t Physics 	MRS.ABHAY GUPTA"
			    <<"\n\t\t Chemistry MR.NAITIK KASHYAP"
			    <<"\n\n\t Biology 	MRS.NEHA ARORA";
			cout<<"\n\n\n\n\t\t\t Thank You for joining fiitjee!!!";
			cout<<"\n\n\tpress 0 to continue:";
			cin>>f;
			if(f==0)

				goto progmenu;
			else
				goto progmenu;


			}
			else
			goto progmenu;
			}
		    else	if((a=='d')||(a=='D'))
			{
				otherexams:
				clrscr();
				cout<<"\n\n\n\t\t\t\t FIITJEE LIMITED\n";
				cout<<"\t\t\t\t******\n";
				cout<<"\t\t\t\t******\n";
				cout<<"\t\t****OTHEREXAMS****\n";
				cout<<"\t FITTJEE is also famous for other preparations as well.It gives the\n"<<"\n\tstudents proper coaching for exams like SAT,GATE,UPSC,JAM,CAT";
				cout<<"\t\t\tEXAMS:--\n";
				cout<<"\t\t\tA) SAT,GATE\n";
				cout<<"\t\t\tB) UPSC\n";
				cout<<"\t\t\tC)CAT,JAM\n";
				cout<<"Enter your choice:";

				cin>>i;
				if((i=='a')||(i=='A'))
				{
					cout<<"Your fees would be 1LAKH for 1 year";
					s.dur=1;
					s.course=4;
				}
				else if((i=='b')||(i=='B'))
				{
					cout<<"Your fees would be 2Lacs for 2 years";
					s.dur=2;
					s.course=4;
				 }
				else if((i=='c')||(i=='C'))
				{
					cout<<"Your fees would be 4Lacs for 4 years";
					s.dur=4;
					s.course=4;
				 }
				else
				{
			cout<<"\t you have entered wrong choice\n"<<"\tpress 1 too re-enter your choice";
			cin>>b;
			if(b==1)

				goto otherexams;
			else
				goto progmenu;
		}
		cout<<"\n\n\n\t Would you like to join our institute?(press y-yes):";
		cin>>c;
		if(c=='y')
		{
			Fotherexams:
			clrscr();
			//data of the candidate
			cout<<"\t\t\t\t*****\n";
			cout<<"\t\t\t\t*****\n";
			cout<<"\t\t\t**OTHEREXAMS****\n\n";
			write_file();
			cout<<"\n\tEnter suitable time shift(m-morning;e-evening):";
			cin>>d;

		       if( ( (i=='a')||(i=='A') ) &&( (d=='m')||(d=='M') ) )
			{
				cout<<"\n\tYour timings are-	9 A.M to 1:30P.M ";
				cout<<"\n\tYour days are:- 	Monday,Wednesday,Friday";

			}
		   else if( ( (i=='a')||(i=='A') ) &&( (d=='e')||(d=='E') ) )
			{
				cout<<"\n\tYour timings are-	2 P.M to 6:30P.M ";
				cout<<"\n\tYour days are:- 	Monday,Wednesday,Friday";

			}
			else if(((i=='b')||(i=='B'))&&((d=='m')||(d=='M')))
			{
				cout<<"\n\tYour timings are-	9 A.M to 1:30P.M ";
				cout<<"\n\tYour days are:- 	Tuesday,Thursday,Saturday";

			}
			else if(((i=='b')||(i=='B'))&&((d=='e')||(d=='E')))
			{
				cout<<"\n\tYour timings are-	2 P.M to 6:30P.M ";
				cout<<"\n\tYour days are:- 	Tuesday,Thursday,Saturday ";

			}
			else if(((i=='c')||(i=='C'))&&((d=='m')||(d=='M')))
			{
				cout<<"\n\tYour timings are-	9 A.M to 1:30P.M ";
				cout<<"\n\tYour day is:- 	Sunday";

			}
			else if(((i=='c')||(i=='C'))&&((d=='e')||(d=='E')))
			{
				cout<<"\n\tYour timings are-	2 P.M to 8 P.M ";
				cout<<"\n\tYour day is:- 	Sunday";

			}

			else
			{
				cout<<"\n\n\t you have entered a wrong choice";
				cout<<"\n\n\t press 1 to continue";
				cin>>e;
				if(e==1)
					goto Fotherexams;
			     else
					goto Fotherexams;
			}
			//data of concerned faculty

			cout<<"\n\n\t faculty(OTHEREXAMS):"
				<<"\n\t\t Head		MR.MADHAV GHOSH"
				<<"\n\t\tSAT/GATE 	MR.ROHAN VATS"
				<<"\n\t\t UPSC 		MR.RANJAN KUMAR"
				<<"\n\t\t CAT/JAM 	MR.SANJAY KHURANA";
			cout<<"\n\n\n\n\t\t\t thank you for joining fiitjee!!!";
			cout<<"\n\n\tpress 0 to continue";
			cin>>f;
			if(f==0)

				goto progmenu;
			else
				goto progmenu;


			}
			else
				goto progmenu;
			}
	}


					else if((c=='b')||(c=='B'))
						read_file();
					else if((c=='c')||(c=='C'))
						search();
					else if((c=='d')||(c=='D'))
						modify();
					else if((c=='e')||(c=='E'))
						Delete();
					else if((c=='f')||(c=='F'))
						turnover();
					else if((c=='g')||(c=='G'))
						exit(0);

					else
					{
						cout<<"Wrong choice entered";
						getch();
						goto Fenrolment;
					}

				  }while((c!='b')||(c!='B'));
		 }
	void main()
	{       char choice;
		clrscr();
			cout<<"\n\n\n\t\t\t\t   12TH PROJECT"
			    <<"\n\n\t\t\tBY AYUSH VERMA && HEMONESH"
			    <<"\n\n\t\t\t\tSESSION: 2019-2020";
			getch();
			clrscr();



			clrscr();
			char h;
			char x,j;
		cout<<"\t\tWHO ARE YOU:\n\n\n";
		cout<<"\t  A) STUDENT\n\n\n";
		cout<<"\t  B) ADMINISTRATOR\n\n\n";
		cout<<"\t  C) EXIT\n\n\n";
		cin>>choice;
		if((choice=='a')||(choice=='A'))
		{
			mainmenus:

			cout<<"\n\t************************\n"<<"\t * __________________ *\n"<<"\t * _________________ *\n"<<"\t*                 *\n"<<" F I I T J E E  L I M I T E D  \n"<<"\t * ______________ *\n"<<"\t * ____________________*\n"<<"\t   *                      *  \n";
			cout<<"\t * FIITJEE LIMITED, 29-A, KALU SARAI\n"<<"\t\t SARVAPRIYA VIHAR, NEAR HAUZ KHAS METRO STATION\n"<<"\t\t PH NO-011-49383471 * \n";
			cout<<"\t *__________________*\n"<<"\t_______________________\n"<<"\t *                *\n"<<"\t******************\n\n\n\n";
			cout<<"\t\t WELCOME TO FIITJEE LIMITED !!!!!!\n\n\n\n";
			cout<<"\t  A) ABOUT US\n\n\n";
			cout<<"\t  B) PROGRAMS OFFERED\n\n\n";
			cout<<"\t  C) FACILITIES\n\n\n";
			cout<<"\t  D) CONTACT US\n\n\n";
			cout<<"\t  E) EXIT\n\n";
			cout<<"\t  ENTER YOUR CHOICE:";
			cin>>h;
		}
		else if((choice=='B')||(choice=='b'))
		{
			       f.enrolment();
		}
		else if((choice=='c')||(choice=='C'))
			exit(0);

		if(h=='a'||h=='A')
				f.aboutus();
			if(h=='b'||h=='B')
				f.programs();
			if(h=='c'||h=='C')
				f.facilities();
			if(h=='d'||h=='D')
				f.contactus();
			if(h=='e'||h=='E')
				exit(0);
			else //if(h!=1&&h!=2&&h!=3&&h!=5&&h!=4&&h!=6)
				goto mainmenus;

			getch();
}















