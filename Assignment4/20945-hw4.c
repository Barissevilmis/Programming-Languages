#include "20945-hw4.h"
//#include "20945-hw4.tab.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//CRN and Code arrays

char codeArr[200][50];
int crnArr[200];
int crnIndex = 0;
int codeIndex = 0;
unsigned int count = 0;
 

ELEMENTlist *elementlist(ELEMENTlist *node,ELEMENT *child)
{
  ELEMENTlist *ele = (ELEMENTlist *)(malloc(sizeof(ELEMENTlist)));
  ele -> node = node;
  ele -> child = child;
  return (ele);
}
ELEMENTlist *courselist(ELEMENTlist *node,ELEMENT *child)
{

  ELEMENTlist *ele = (ELEMENTlist *)(malloc(sizeof(ELEMENTlist)));
  ele -> node = node;
  ele -> child = child;
  return (ele);
}

ELEMENTlist *meetinglist(ELEMENTlist *node,ELEMENT *child)
{

  ELEMENTlist *ele = (ELEMENTlist *)(malloc(sizeof(ELEMENTlist)));
  ele -> node = node;
  ele -> child = child;
  return (ele);
}

ELEMENTlist *itemlist(ELEMENTlist *node,ELEMENT *child)
{

  ELEMENTlist *ele = (ELEMENTlist *)(malloc(sizeof(ELEMENTlist)));
  ele -> node = node;
  ele -> child = child;
  return (ele);
}

ELEMENTlist *classlist(ELEMENTlist *node,ELEMENT *child)
{

  ELEMENTlist *ele = (ELEMENTlist *)(malloc(sizeof(ELEMENTlist)));
  ele -> node = node;
  ele -> child = child;
  return (ele);
}

ELEMENTlist *meetingAttrlist(ELEMENTlist *node,ELEMENT *child)
{

  ELEMENTlist *ele = (ELEMENTlist *)(malloc(sizeof(ELEMENTlist)));
  ele -> node = node;
  ele -> child = child;
  return (ele);
}

ELEMENTlist *classAttrlist(ELEMENTlist *node,ELEMENT *child)
{

  ELEMENTlist *ele = (ELEMENTlist *)(malloc(sizeof(ELEMENTlist)));
  ele -> node = node;
  ele -> child = child;
  return (ele);
}

ELEMENT *courseInit(ELEMENT *cs, ELEMENTlist *el, ELEMENT *ce)
{
  ELEMENT *ele = (ELEMENT *)(malloc(sizeof(ELEMENT)));
  ele -> thisNodeType = courseInitt;
  ele -> item = (ELEMENTexpr *)(malloc(sizeof(ELEMENTexpr)));
  ele -> item -> iptr.item1 = cs;
  ele -> item -> iptr.item2 = el;
  ele -> item -> iptr.item3 = ce;

  return (ele);
}

ELEMENT *constraintInit(ELEMENT *cs, ELEMENTlist *el, ELEMENT *ce)
{
  ELEMENT *ele = (ELEMENT *)(malloc(sizeof(ELEMENT)));
  ele -> thisNodeType = constraintInitt;
  ele -> item = (ELEMENTexpr *)(malloc(sizeof(ELEMENTexpr)));
  ele -> item -> iptr.item1 = cs;
  ele -> item -> iptr.item2 = el;
  ele -> item -> iptr.item3 = ce;
 
  return (ele);
}

ELEMENT *classInit(ELEMENT *cs, ELEMENTlist *el, ELEMENT *ce, ELEMENTlist * el2, ELEMENT *cl)
{
  ELEMENT *ele = (ELEMENT *)(malloc(sizeof(ELEMENT)));
  ele -> thisNodeType = classInitt;
  ele -> item = (ELEMENTexpr *)(malloc(sizeof(ELEMENTexpr)));
  ele -> item -> miptr.item1 = cs;
  ele -> item -> miptr.item2 = el;
  ele -> item -> miptr.item3 = ce;
  ele -> item -> miptr.item4 = el2;
  ele -> item -> miptr.item5 = cl;

  return (ele);
}


ELEMENT *itemInit(ELEMENT *cs, ELEMENT *el, ELEMENT *ce)
{
  ELEMENT *ele = (ELEMENT *)(malloc(sizeof(ELEMENT)));
  ele -> thisNodeType = itemInitt;
  ele -> item = (ELEMENTexpr *)(malloc(sizeof(ELEMENTexpr)));
  ele -> item -> itemptr.item1 = cs;
  ele -> item -> itemptr.item2 = el;
  ele -> item -> itemptr.item3 = ce;

  return (ele);
}

ELEMENT *meetingInit(ELEMENT *cs, ELEMENTlist *el, ELEMENT *ce)
{
  ELEMENT *ele = (ELEMENT *)(malloc(sizeof(ELEMENT)));
  ele -> thisNodeType = meetingInitt;
  ele -> item = (ELEMENTexpr *)(malloc(sizeof(ELEMENTexpr)));
  ele -> item -> iptr.item1 = cs;
  ele -> item -> iptr.item2 = el;
  ele -> item -> iptr.item3 = ce;

  return (ele);
}

ELEMENT *courseStart(TagType tag1, char str[], int val, ELEMENTlist *ele, TagType tag3)
{
  ELEMENT *courseB = (ELEMENT *)(malloc(sizeof(ELEMENT)));
  courseB -> thisNodeType = courseStartt;
  courseB -> item = (ELEMENTexpr *)(malloc(sizeof(ELEMENTexpr)));
  courseB -> item -> cbptr.open = tag1;
  strcpy(courseB -> item -> cbptr.course, str);
  courseB -> item -> cbptr.child = ele;
  courseB -> item -> cbptr.close = tag3;
  courseB -> item -> cbptr.line = val;
  return (courseB);
}

ELEMENT *courseEnd(TagType tag1, char str[], int val, TagType tag3)
{
  ELEMENT *courseE = (ELEMENT *)(malloc(sizeof(ELEMENT)));
  courseE -> thisNodeType = courseEndd;
  courseE -> item = (ELEMENTexpr *)(malloc(sizeof(ELEMENTexpr)));
  courseE -> item -> ceptr.end = tag1;
  strcpy(courseE -> item -> ceptr.course, str);
  courseE -> item -> ceptr.line = val;
  courseE -> item -> ceptr.close = tag3;
  return (courseE);
}

ELEMENT *course(CourseType ce, char ch[])
{
  ELEMENT *cour = (ELEMENT *)(malloc(sizeof(ELEMENT)));
  cour -> thisNodeType = coursee;
  cour -> item = (ELEMENTexpr *)(malloc(sizeof(ELEMENTexpr)));
  cour -> item -> cptr.item = ce;
  strcpy(cour -> item -> cptr.str, ch);
  strcpy(codeArr[codeIndex], ch);
  codeIndex++;
  return (cour);
}

ELEMENT *classStart(TagType tag1,  char str[], int val)
{
  ELEMENT *cs = (ELEMENT *)(malloc(sizeof(ELEMENT)));
  cs -> thisNodeType = classStartt;
  cs -> item = (ELEMENTexpr *)(malloc(sizeof(ELEMENTexpr)));
  cs -> item -> clsptr.open = tag1;
  strcpy(cs -> item -> clsptr.class, str);
  cs -> item -> clsptr.line = val;
  return (cs);
}

ELEMENT *classEnd(TagType tag1)
{
  ELEMENT *ce = (ELEMENT *)(malloc(sizeof(ELEMENT)));
  ce -> thisNodeType = classEndd;
  ce -> item = (ELEMENTexpr *)(malloc(sizeof(ELEMENTexpr)));
  ce -> item ->  cleptr.close = tag1;
  return (ce);
}

ELEMENT *classClose(TagType tag1, char str[], int val, TagType tag3)
{
  ELEMENT *cc = (ELEMENT *)(malloc(sizeof(ELEMENT)));
  cc -> thisNodeType = classClosee;
  cc -> item = (ELEMENTexpr *)(malloc(sizeof(ELEMENTexpr)));
  cc -> item ->  clcptr.end = tag1;
  strcpy(cc -> item -> clcptr.class, str);
  cc -> item -> clcptr.line = val;
  cc -> item ->  clcptr.close = tag3;
  return (cc);
}

ELEMENT *classInt(ClassType ct, int value)
{
  ELEMENT *ci = (ELEMENT *)(malloc(sizeof(ELEMENT)));
  ci -> thisNodeType = classIntt;
  ci -> item = (ELEMENTexpr *)(malloc(sizeof(ELEMENTexpr)));
  ci -> item -> cliptr.item = ct;
  ci -> item -> cliptr.val = value;
  crnArr[crnIndex] = value;
  crnIndex++;
  return (ci);
}


ELEMENT *classStr(ClassType ct, char string[])
{
  ELEMENT *cs = (ELEMENT *)(malloc(sizeof(ELEMENT)));
  cs -> thisNodeType = classStrr;
  cs -> item = (ELEMENTexpr *)(malloc(sizeof(ELEMENTexpr)));
  cs -> item -> clstrptr.item = ct;
  strcpy(cs -> item -> clstrptr.str, string);
  return (cs);
}

ELEMENT *meetingStart(TagType tag1, char str[], int val)
{
  ELEMENT *ms = (ELEMENT *)(malloc(sizeof(ELEMENT)));
  ms -> thisNodeType = meetingStartt;
  ms -> item = (ELEMENTexpr *)(malloc(sizeof(ELEMENTexpr)));
  ms -> item -> msptr.open = tag1;
  strcpy(ms -> item -> msptr.meeting, str);
  ms -> item -> msptr.line = val;
  return (ms);
}

ELEMENT *meetingEnd(TagType tag1)
{
  ELEMENT *me = (ELEMENT *)(malloc(sizeof(ELEMENT)));
  me -> thisNodeType = meetingEndd;
  me -> item = (ELEMENTexpr *)(malloc(sizeof(ELEMENTexpr)));
  me -> item -> meptr.end = tag1;
  return (me);
}

ELEMENT *meetingDay(MeetingType mt, ELEMENT *d)
{
  ELEMENT *md = (ELEMENT *)(malloc(sizeof(ELEMENT)));
  md -> thisNodeType = meetingDayy;
  md -> item = (ELEMENTexpr *)(malloc(sizeof(ELEMENTexpr)));
  md -> item -> mdptr.item = mt;
  md -> item -> mdptr.day = d;
  return (md);
}

ELEMENT *meetingTime(MeetingType mtype, char string[])
{
  ELEMENT *mt = (ELEMENT *)(malloc(sizeof(ELEMENT)));
  mt -> thisNodeType = meetingTimee;
  mt -> item = (ELEMENTexpr *)(malloc(sizeof(ELEMENTexpr)));
  mt -> item -> mtptr.item = mtype;
  strcpy(mt -> item -> mtptr.time, string);
  return (mt);
}

ELEMENT *day(DayType d)
{
  ELEMENT *dd  = (ELEMENT *)(malloc(sizeof(ELEMENT)));
  dd -> thisNodeType = dayy;
  dd -> item = (ELEMENTexpr *)(malloc(sizeof(ELEMENTexpr)));
  dd -> item -> dptr.day = d;
  return (dd);
}

ELEMENT *constraintStart(TagType tag1, char str[], int val, TagType tag3)
{
  ELEMENT *ce = (ELEMENT *)(malloc(sizeof(ELEMENT)));
  ce -> thisNodeType = constraintStartt;
  ce -> item = (ELEMENTexpr *)(malloc(sizeof(ELEMENTexpr)));
  ce -> item -> cosptr.open = tag1;
  strcpy(ce -> item -> cosptr.constraint, str);
  ce -> item -> cosptr.line = val;
  ce -> item -> cosptr.close = tag3;
  return (ce);
}

ELEMENT *constraintEnd(TagType tag1, char str[], int val, TagType tag3)
{
  ELEMENT *ce = (ELEMENT *)(malloc(sizeof(ELEMENT)));
  ce -> thisNodeType = constraintEndd;
  ce -> item = (ELEMENTexpr *)(malloc(sizeof(ELEMENTexpr)));
  ce -> item -> coeptr.end = tag1;
  strcpy(ce -> item -> coeptr.constraint, str);
  ce -> item -> coeptr.line = val;
  ce -> item -> coeptr.close = tag3;
  return (ce);
}


ELEMENT *itemStart(TagType tag1, TagType tag2)
{
  ELEMENT *iS = (ELEMENT *)(malloc(sizeof(ELEMENT)));
  iS -> thisNodeType = itemStartt;
  iS -> item = (ELEMENTexpr *)(malloc(sizeof(ELEMENTexpr)));
  iS -> item -> isptr.open = tag1;
  iS -> item -> isptr.item = tag2;
  return (iS);
}

ELEMENT *itemEnd(TagType tag1)
{
  ELEMENT *ie = (ELEMENT *)(malloc(sizeof(ELEMENT)));
  ie -> thisNodeType = itemEndd;
  ie -> item = (ELEMENTexpr *)(malloc(sizeof(ELEMENTexpr)));
  ie -> item -> ieptr.self = tag1;
  return (ie);
}

ELEMENT *itemInt(ItemType it, int val)
{
  ELEMENT *ii = (ELEMENT *)(malloc(sizeof(ELEMENT)));
  ii -> thisNodeType = itemIntt;
  ii -> item = (ELEMENTexpr *)(malloc(sizeof(ELEMENTexpr)));
  ii -> item -> iiptr.item = it;
  ii -> item -> iiptr.val = val;
  return (ii);
}

ELEMENT *itemStr(ItemType it, char string[])
{
  ELEMENT *iS = (ELEMENT *)(malloc(sizeof(ELEMENT)));
  iS -> thisNodeType = itemStrr;
  iS -> item = (ELEMENTexpr *)(malloc(sizeof(ELEMENTexpr)));
  iS -> item -> istrptr.item = it;
  strcpy(iS -> item -> istrptr.str,string);
  return (iS);
}

int CourseAttrListCheck(ELEMENT *rootPtr)
{
  ELEMENT *temp = rootPtr;
  if(temp -> thisNodeType == coursee)
    {
      if(temp -> item -> cptr.item == CODE)
	return 1;
      else if(temp -> item -> cptr.item == TYPE)
	return 2;
      else if(temp -> item -> cptr.item == NAME)
	return 3;   
    }
  return 0;
}


int CourseAttrCheck(ELEMENT *rootPtr)
{
  ELEMENT *temp = rootPtr;
  int error = 0;
  if(temp -> thisNodeType == courseInitt)
    error += CourseAttrCheck(temp -> item -> iptr.item1);
  else if(temp -> thisNodeType == courseStartt)
    {
      int line = temp -> item -> cbptr.line;
      int code = 0;
      int type = 0;
      int name = 0;
      ELEMENTlist *tptr = temp -> item -> cbptr.child;
      while(tptr != NULL)
	{
	  int a = CourseAttrListCheck(tptr -> child);
	  if(a == 1)
	    code++;
	  else if(a == 2)
	    type++;
	  else if(a == 3)
	    name++;
	  tptr = tptr -> node;
	}
      if(code > 1 || code < 1)
	{
	  printf("ERROR: course element at line %d has %d occurrences of code\n", line, code);
	  error += 1;
	}
      if(type > 1 || type < 1)
	{
	  printf("ERROR: course element at line %d has %d occurrences of type\n", line, type);
	  error += 1;
	}
      if(name > 1 || name < 1)
	{
	  printf("ERROR: course element at line %d has %d occurrences of name\n", line, name);     
	  error = 1;
	}
    }
  return error;
}

int ItemCodeCheck(char code[], int line)
{
  int error = 0;
  int mask = 0;
  int ii = 0;
  for(ii; ii < codeIndex; ii++)
    {
      if(!strcmp(code, codeArr[ii]))
	{
	  mask = 1;
	  break;
	}	
    } 
  if(!mask)
    {
      printf("ERROR: constraint at line %d refers to an undefined code=%s\n", line, code);
      error += 1;
    }
}

int ItemCRNCheck(int crn, int line)
{
  int mask = 0;
  int ii = 0;
  int error = 0;
  for(ii ; ii < crnIndex; ii++) 
    {
      if(crnArr[ii] == crn)
	{
	  mask = 1;
	  break;
	}
    }
  if(!mask)
    {
      printf("ERROR: constraint at line %d refers to an undefined crn=%d\n", line, crn);
      error += 1;
    }
  return error;
}


int ItemCheck(ELEMENT *rootPtr, int line)
{
  int error = 0;
  ELEMENT *temp = rootPtr;
  if(temp -> thisNodeType == itemIntt)
    error += ItemCRNCheck(temp -> item -> iiptr.val, line);
  else if(temp -> thisNodeType == itemStrr)
    error += ItemCodeCheck(temp -> item -> istrptr.str, line);
  return error;
}

int ConstraintAttrCheck(ELEMENT *rootPtr)
{
  int error = 0;
  ELEMENT *temp = rootPtr;
  static int line = 0;
  if(temp -> thisNodeType == constraintInitt)
    {
      ELEMENTlist *tptr = temp -> item -> iptr.item2;
      while(tptr != NULL)
	{
	  line = temp -> item -> iptr.item1 -> item -> cosptr.line; 
	  error += ConstraintAttrCheck(tptr -> child);
	  tptr = tptr -> node;
	}
    }
  else if(temp -> thisNodeType == itemInitt)
    {
      ELEMENT *tptr2 = temp -> item -> itemptr.item2;
      error += ItemCheck(tptr2, line);
    }
  return error;
}

int ClassAttrListCheck(ELEMENT *rootPtr)
{
  ELEMENT *temp = rootPtr;
  if(temp -> thisNodeType == classStrr)
    {
      if(temp -> item -> clstrptr.item == SECTION)
	return 1;
      else if(temp -> item -> clstrptr.item == INSTRUCTOR)
	return 2;
      else if(temp -> item -> clstrptr.item == CRN)
	return 3;
      else if(temp -> item -> clstrptr.item == CAPACITY)
	return 4;
    }
  else if(temp -> thisNodeType == classIntt)
    {
      if(temp -> item -> cliptr.item == SECTION)
	return 1;
      else if(temp -> item -> cliptr.item == INSTRUCTOR)
	return 2;
      else if(temp -> item -> cliptr.item == CRN)
	return 3;
      else if(temp -> item -> cliptr.item == CAPACITY)
	return 4;
    }
  return 0;
}

int ClassAttrCheck(ELEMENT *rootPtr)
{
  ELEMENT *temp = rootPtr;
  int error = 0;
  if(temp -> thisNodeType == courseInitt)
    {
      ELEMENTlist *tptr = temp -> item -> iptr.item2;
      while(tptr != NULL)
	{
	  error += ClassAttrCheck(tptr -> child);
	  tptr = tptr -> node;
	}
    }
  else if(temp -> thisNodeType == classInitt)
    {
      int section = 0;
      int instructor = 0;
      int crn = 0;
      int capacity = 0;
      ELEMENTlist *tptr2 = temp -> item -> miptr.item2;
      int line = temp -> item -> miptr.item1 -> item -> clsptr.line;
      while(tptr2 != NULL)
	{
	  int a = ClassAttrListCheck(tptr2 -> child);
	  if(a == 1)
	    section++;
	  else if(a == 2)
	    instructor++;
	  else if(a == 3)
	    crn++;
	  else if(a == 4)
	    capacity++;
	  tptr2 = tptr2 -> node;
	}
      if(section > 1 || section < 1)
	{
	  printf("ERROR: class element at line %d has %d occurrences of section\n", line, section);
	  error += 1;
	}
      if(instructor > 1 ||  instructor < 1)
	{
	  printf("ERROR: class element at line %d has %d occurrences of instructor\n", line, instructor);
	  error += 1;
	}
      if(crn > 1 || crn < 1)
	{
	  printf("ERROR: class element at line %d has %d occurrences of crn\n", line, crn);
	  error += 1;
	}
      if(capacity > 1 || capacity < 1)
	{
	  printf("ERROR: class element at line %d has %d occurrences of capacity\n", line, capacity);
	  error += 1;
	}
    }
  return error;
}

int MeetingAttrListCheck(ELEMENT *rootPtr)
{
  ELEMENT *temp = rootPtr;
  if(temp -> thisNodeType == meetingTimee)
    {
      if(temp -> item -> mtptr.item == START)
	return 1;
      else if(temp -> item -> mtptr.item == END_A)
	return 2;
      else if(temp -> item -> mtptr.item == DAY)
	return 3;
    }
  else if(temp -> thisNodeType == meetingDayy)
    {
      if(temp -> item -> mdptr.item == START)
	return 1;
      else if(temp -> item -> mdptr.item == END_A)
	return 2;
      else if(temp -> item -> mdptr.item == DAY)
	return 3;
    }
  return 0;
}

int MeetingIntermediateCheck(ELEMENT *rootPtr)
{
  ELEMENT *temp = rootPtr;
  if(temp -> thisNodeType == meetingInitt)
    {
      int error = 0;
      int start = 0;
      int end_a = 0;
      int day = 0;
      ELEMENTlist *tptr3 = temp -> item -> iptr.item2;      
      int line = temp -> item -> iptr.item1 -> item -> msptr.line;
      while(tptr3 != NULL)
	{
	  int a = MeetingAttrListCheck(tptr3 -> child);
	  if(a == 1)
	    start++;
	  else if(a == 2)
	    end_a++;
	  else if(a == 3)
	    day++;
	  tptr3 = tptr3 -> node;
	}
      if(start > 1 || start < 1)
	{
	  printf("ERROR: meeting element at line %d has %d occurrences of start\n", line, start);
	  error += 1;
	}
      if(end_a > 1 ||  end_a < 1)
	{
	  printf("ERROR: meeting element at line %d has %d occurrences of end\n", line, end_a);
	  error += 1;
	}
      if(day > 1 || day < 1)
	{
	  printf("ERROR: meeting element at line %d has %d occurrences of day\n", line, day);
	  error += 1;
	}
      return error;
    }
}

int MeetingAttrCheck(ELEMENT *rootPtr)
{
  ELEMENT *temp = rootPtr;
  int error = 0;
  if(temp -> thisNodeType == courseInitt)
    {
      ELEMENTlist *tptr = temp -> item -> iptr.item2;
      while(tptr != NULL)
	{
	  error += MeetingAttrCheck(tptr -> child);
	  tptr = tptr -> node;
	}
    }
  else if(temp -> thisNodeType == classInitt)
    {
      ELEMENTlist *tptr2 = temp -> item -> miptr.item4;
      while(tptr2 != NULL)
	{
	  error += MeetingIntermediateCheck(tptr2 -> child);
	  tptr2 = tptr2 -> node;
	}
    }
  return error;
}

void ConstraintPrint(ELEMENT *ptr)
{
  ELEMENT *temp = ptr;
  ELEMENTlist *itemlist = temp -> item -> iptr.item2;
  printf("<constraint>\n");
  while(itemlist != NULL)
    {
      printf("\t<item");
      if(itemlist -> child -> item -> itemptr.item2 -> thisNodeType == itemIntt)
	{
	  printf(" crn=%d", itemlist -> child -> item -> itemptr.item2 -> item -> iiptr.val);
	}
      if(itemlist -> child -> item -> itemptr.item2 -> thisNodeType == itemStrr)
	{
	  printf(" code=%s",itemlist -> child -> item -> itemptr.item2 -> item -> istrptr.str);
	}
      printf("/>\n");
      itemlist = itemlist -> node;
    }
  printf("</constraint>\n");
}

void MeetingPrint(ELEMENTlist *ptr)
{
  ELEMENTlist *temp = ptr;
  while(temp != NULL)
    {
      printf("\t\t<meeting");
      ELEMENTlist *meeting = temp -> child -> item -> iptr.item2;
      while(meeting != NULL)
	{
	  if(meeting -> child -> thisNodeType == meetingTimee)
	    {
	      if(meeting -> child -> item -> mtptr.item == START)
		printf(" start=%s",meeting -> child -> item -> mtptr.time);
	      else if(meeting -> child -> item -> mtptr.item == END_A)
		printf(" end=%s",meeting -> child -> item -> mtptr.time);
	    }
	  if(meeting -> child -> thisNodeType == meetingDayy)
	    {
	      if(meeting -> child -> item -> mdptr.item == DAY)
		{
		  if(meeting -> child -> item -> mdptr.day -> item -> dptr.day == M)	  
		    printf(" day=M");	  
		  else if(meeting -> child -> item -> mdptr.day -> item -> dptr.day == T)	  
		    printf(" day=T");	  
		  else if(meeting -> child -> item -> mdptr.day -> item -> dptr.day == W)	  
		    printf(" day=W");	  
		  else if(meeting -> child -> item -> mdptr.day -> item -> dptr.day == R)	  
		    printf(" day=R");	  
		  else if(meeting -> child -> item -> mdptr.day -> item -> dptr.day == F)	  
		    printf(" day=F");	  
		}
		
	    }
	  meeting = meeting -> node;
	}
      printf(">\n");
      temp = temp -> node;
    }
}

void ClassPrint(ELEMENTlist *ptr)
{
  ELEMENTlist *temp = ptr;
  while(temp != NULL)
    {
      printf("\t<class");
      ELEMENTlist *class = temp -> child -> item -> miptr.item2;
      while(class != NULL)
	{
	  if(class -> child -> thisNodeType == classStrr)
	    {
	      if(class -> child -> item -> clstrptr.item == SECTION)
		printf(" section=%s",class -> child -> item -> clstrptr.str);
	      else if(class -> child -> item -> clstrptr.item == INSTRUCTOR)
		printf(" instructor=%s",class -> child ->  item -> clstrptr.str);
	    }
	  if(class -> child -> thisNodeType == classIntt)
	    {
	      if(class -> child -> item -> cliptr.item == CRN)
		printf(" crn=%d",class -> child -> item -> cliptr.val);	  
	      else if(class -> child -> item -> cliptr.item == CAPACITY)
		printf(" capacity=%d",class -> child -> item -> cliptr.val);	  
	    }
	  class = class -> node;
	}
      printf(">\n");
      MeetingPrint(temp -> child -> item -> miptr.item4);
      printf("\t</class>\n");
      temp = temp -> node;
    }
  
}

void CoursePrint(ELEMENT *ptr)
{
  ELEMENTlist *elemlist = ptr -> item -> iptr.item1 -> item -> cbptr.child;
  printf("<course");
  while(elemlist != NULL)
    {
      if(elemlist -> child -> item -> cptr.item == CODE)
	printf(" code=%s",elemlist -> child -> item -> cptr.str);
      else if(elemlist -> child -> item -> cptr.item == TYPE)
	printf(" type=%s",elemlist -> child -> item -> cptr.str);
      else if(elemlist -> child -> item -> cptr.item == NAME)
	printf(" name=%s",elemlist -> child -> item -> cptr.str);	  
      elemlist = elemlist -> node;
    }
  printf(">\n");
  ClassPrint(ptr -> item -> iptr.item2);
  printf("</course>\n");
  
}

void TreePrint(ELEMENTlist *rootPtr)
{
  ELEMENTlist *temp = rootPtr;
  while(temp != NULL)
    {
      if(temp -> child -> thisNodeType == courseInitt)
	CoursePrint(temp -> child);
      else if(temp -> child -> thisNodeType == constraintInitt)
	ConstraintPrint(temp -> child);
      temp = temp -> node;
    }
}


ELEMENTlist * ReorderElements(ELEMENTlist *rootPtr)
{
  if(rootPtr != NULL)
    {
      ELEMENTlist *temp = rootPtr;
      ELEMENTlist *temp_next = rootPtr -> node;
      ELEMENTlist *prev = temp;
      while(temp_next != NULL)
	{
	  if(temp -> child -> thisNodeType == constraintInitt && temp_next -> child -> thisNodeType == courseInitt)
	    {
	      temp -> node = temp_next -> node;
	      temp_next -> node = temp;
	      prev -> node = temp_next;
	      temp = rootPtr;
	      temp_next = rootPtr -> node;
	      prev = temp;
	    }
	  else
	    {
	      prev = temp;
	      temp = temp -> node;
	      temp_next = temp_next -> node;
	    }
	}
    
      temp = rootPtr;
      return (rootPtr);
    }
  else
    return NULL;
}

