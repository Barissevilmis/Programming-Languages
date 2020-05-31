%{
#include "20945-hw4.h"
#include <stdio.h>
#include <stdlib.h>
  void yyerror(const char *s){//called by yyparse on error
    printf("%s\n", s);
  }
  
  ELEMENTlist *elementlist(ELEMENTlist*,ELEMENT *);
  ELEMENTlist *meetinglist(ELEMENTlist*,ELEMENT *);
  ELEMENTlist *classlist(ELEMENTlist*,ELEMENT *);
  ELEMENTlist *courselist(ELEMENTlist*,ELEMENT *);
  ELEMENTlist *itemlist(ELEMENTlist*,ELEMENT *);
  ELEMENTlist *meetingAttrlist(ELEMENTlist*,ELEMENT *);
  ELEMENTlist *classAttrlist(ELEMENTlist*,ELEMENT *);
  ELEMENT *courseInit(ELEMENT *, ELEMENTlist *, ELEMENT *);
  ELEMENT *constraintInit(ELEMENT *, ELEMENTlist *, ELEMENT *);
  ELEMENT *courseStart(TagType, char [], int , ELEMENTlist *, TagType);
  ELEMENT *courseEnd(TagType, char [], int, TagType);
  ELEMENT *course(CourseType, char []);
  
  ELEMENT *classInit(ELEMENT *, ELEMENTlist *, ELEMENT *, ELEMENTlist *, ELEMENT *);
  ELEMENT *classStart(TagType, char [], int);
  ELEMENT *classEnd(TagType);
  ELEMENT *classClose(TagType, char [], int, TagType);
  ELEMENT *classInt(ClassType, int);
  ELEMENT *classStr(ClassType, char []);
	
  ELEMENT *meetingInit(ELEMENT *, ELEMENTlist *, ELEMENT *);
  ELEMENT *meetingStart(TagType, char [], int);
  ELEMENT *meetingEnd(TagType);
  ELEMENT *meetingDay(MeetingType, ELEMENT *);
  ELEMENT *meetingTime(MeetingType, char []);
  ELEMENT *day(DayType);
  
  ELEMENT *itemInit(ELEMENT *, ELEMENT *, ELEMENT *);
  ELEMENT *constraintStart(TagType, char [] ,int , TagType);
  ELEMENT *constraintEnd(TagType, char [],int, TagType);
  ELEMENT *itemStart(TagType, TagType);
  ELEMENT *itemEnd(TagType);
  ELEMENT *itemInt(ItemType, int);
  ELEMENT *itemStr(ItemType, char []);
  
  void CoursePrint(ELEMENT *);
  void ConstraintPrint(ELEMENT *);
  void ClassPring(ELEMENTlist *);
  void MeetingPrint(ELEMENTlist *);
  void TreePrint(ELEMENTlist *);
  
  int CourseAttrCheck(ELEMENT *);
  int CourseAttrListCheck(ELEMENT *);
  int ConstraintAttrCheck(ELEMENT  *);
  int ItemCheck(ELEMENT *, int);
  int ItemCRNCheck(int, int);
  int ItemCodeCheck(char [], int);
  int ClassAttrCheck(ELEMENT *);
  int ClassAttrListCheck(ELEMENT *, int);
  int MeetingAttrCheck(ELEMENT *);
  int MeetingIntermediateCheck(ELEMENT *);
  int MeetingAttrListCheck(ELEMENT *);
  ELEMENTlist * ReorderElements(ELEMENTlist *rootPtr);

  ELEMENTlist *rootPtr;

%}

%union {
  int value;
  char mystr[50];
  struct{
    int linenum;
    char strstr[50];
  }Token;
  ELEMENT *el;
  ELEMENTlist *ellst;
}

%token tOPEN tCLOSE tEND tCODE tNAME tTYPE tSECTION  tINSTRUCTOR tCRN  tCAPACITY tSELF tDAY tSTART tEND_A tMON  tTUE  tWED  tTHU  tFRI tITEM 
%token <value> tNUM;
%token <mystr> tSTRING;
%token <mystr> tTIME;
%token <Token> tCONSTRAINT;
%token <Token> tCLASS;
%token <Token> tCOURSE;
%token <Token> tMEETING;
%type <el> element;
%type <el> meeting;
%type <el> class;
%type <el> item;
%type <el> beginCourse;
%type <el> endCourse;
%type <el> beginClass;
%type <el> endClass;
%type <el> closeClass;
%type <el> beginConstraint;
%type <el> endConstraint;
%type <el> beginMeeting;
%type <el> endMeeting;
%type <el> beginItem;
%type <el> endItem;
%type <el> day;
%type <el> itemAttr;
%type <el> classAttr;
%type <el> courseAttr;
%type <el> meetingAttr;
%type <ellst> elementList;
%type <ellst> courseAttrList;
%type <ellst> classList;
%type <ellst> itemList;
%type <ellst> classAttrList;
%type <ellst> meetingAttrList;
%type <ellst> meetingList;

%start prog

%%

prog : elementList {rootPtr = $1;}
| {rootPtr = NULL;} ;
elementList :  element {$$ = elementlist(NULL,$1);}
| element elementList {$$ = elementlist($2,$1);};
element : beginCourse classList endCourse {$$ = courseInit($1, $2, $3);}
| beginConstraint itemList endConstraint {$$ = constraintInit($1, $2, $3);};
beginCourse : tOPEN tCOURSE courseAttrList tCLOSE {$$ = courseStart(OPEN, $2.strstr, $2.linenum, $3, CLOSE);};
endCourse : tEND tCOURSE tCLOSE {$$ = courseEnd(END, $2.strstr, $2.linenum, CLOSE);}; 
courseAttrList :  courseAttr {$$ = courselist(NULL,$1);}
| courseAttr  courseAttrList {$$ = courselist($2,$1);};
courseAttr : tCODE tSTRING {$$ = course(CODE, $2);}
| tNAME tSTRING {$$ = course(NAME, $2);}
| tTYPE tSTRING {$$ = course(TYPE, $2);};
classList : class {$$ = classlist(NULL,$1);}
| class classList {$$ = classlist($2,$1);};
class :  beginClass classAttrList endClass meetingList closeClass {$$ = classInit($1, $2, $3, $4, $5);};
beginClass  : tOPEN tCLASS {$$ = classStart(OPEN, $2.strstr, $2.linenum);};
endClass :  tCLOSE {$$ = classEnd(CLOSE);};
closeClass : tEND tCLASS tCLOSE {$$ = classClose(END, $2.strstr, $2.linenum, CLOSE);};
classAttrList :  classAttr {$$ = classAttrlist(NULL,$1);}
| classAttr classAttrList {$$ = classAttrlist($2,$1);};
classAttr : tSECTION tSTRING {$$ = classStr(SECTION, $2);}
| tINSTRUCTOR tSTRING {$$ = classStr(INSTRUCTOR, $2);}
| tCRN tNUM {$$ = classInt(CRN, $2);}
| tCAPACITY tNUM {$$ = classInt(CAPACITY, $2);};
meetingList : meeting {$$ = meetinglist(NULL,$1);}
| meeting  meetingList {$$ = meetinglist($2,$1);};
meeting : beginMeeting meetingAttrList endMeeting {$$ = meetingInit($1, $2, $3);};
beginMeeting :  tOPEN tMEETING {$$ = meetingStart(OPEN, $2.strstr, $2.linenum);};
endMeeting :tSELF {$$ = meetingEnd(SELF);};
meetingAttrList : meetingAttr {$$ = meetingAttrlist(NULL,$1);}
| meetingAttr meetingAttrList {$$ = meetingAttrlist($2,$1);};
meetingAttr : tDAY day {$$ = meetingDay(DAY, $2);}
| tSTART tTIME {$$ = meetingTime(START, $2);}
| tEND_A tTIME {$$ = meetingTime(END_A, $2);};
day : tMON {$$ = day(M);}
| tTUE {$$ = day(T);}
| tWED {$$ = day(W);}
| tTHU {$$ = day(R);}
| tFRI {$$ = day(F);};
beginConstraint : tOPEN tCONSTRAINT tCLOSE {$$ = constraintStart(OPEN, $2.strstr, $2.linenum, CLOSE);};
endConstraint : tEND tCONSTRAINT tCLOSE {$$ = constraintEnd(END, $2.strstr, $2.linenum, CLOSE);};
itemList :  item {$$ = itemlist(NULL,$1);}
| item itemList {$$ = itemlist($2,$1);};
item :  beginItem itemAttr endItem {$$ = itemInit($1, $2, $3);};
beginItem : tOPEN tITEM {$$ = itemStart(OPEN, ITEMTAG);};
endItem : tSELF {$$ = itemEnd(SELF);};
itemAttr: tCODE tSTRING {$$ = itemStr(CODE_I, $2);}
| tCRN tNUM {$$ = itemInt(CRN_I, $2);};

%%
 
void PrettyPrint(ELEMENTlist *rootPtr)
{
  if(rootPtr != NULL)
    {
      int error = 0;
      ELEMENTlist *temp = rootPtr;
      rootPtr = ReorderElements(temp);
      while(temp != NULL)
	{                                                                                                                                                   
	  error += CourseAttrCheck(temp -> child);
	  error += ClassAttrCheck(temp -> child);
	  error += MeetingAttrCheck(temp -> child);
	  error += ConstraintAttrCheck(temp -> child);
	  temp = temp -> node;
	}
      if(error == 0)
	TreePrint(rootPtr);
    }
}

int main()
{
  if(yyparse()){
    printf("ERROR\n");
    return 1;
  }
  else{
    PrettyPrint(rootPtr);
    return 0;
  }
}
