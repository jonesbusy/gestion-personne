CC=g++
RM=rm

OBJ=PersonVector.o Date.o ErrorPersonVector.o Student.o Professor.o ParserPerson.o AskProfessor.o AskStudent.o FactoryPersonProfessorStudent.o CompareComportementLastNameAsc.o CompareComportementLastNameDesc.o CompareComportementFirstNameAsc.o CompareComportementFirstNameDesc.o CompareComportementDateAsc.o CompareComportementDateDesc.o CompareComportementSalaryAsc.o CompareComportementSalaryDesc.o CompareComportementNpaAsc.o CompareComportementNpaDesc.o CheckPersonProfessorStudent.o Person.o Option.o Menu.o main.o

OUT=GestionPersonne

all: $(OBJ)
	$(CC) $(OBJ) -o $(OUT)
Date.o: Date.cpp Date.h
	$(CC) -c Date.cpp

PersonVector.o: PersonVector.cpp PersonVector.h
	$(CC) -c PersonVector.cpp

ErrorPersonVector.o: ErrorPersonVector.cpp ErrorPersonVector.h
	$(CC) -c ErrorPersonVector.cpp

Person.o : Person.cpp Person.h
	$(CC) -c Person.cpp

Student.o: Student.cpp Student.h
	$(CC) -c Student.cpp

Professor.o: Professor.cpp Professor.h
	$(CC) -c Professor.cpp

ParserPerson.o : ParserPerson.cpp ParserPerson.h
	$(CC) -c ParserPerson.cpp

AskProfessor.o : AskComportement/AskProfessor.cpp AskComportement/AskProfessor.h I_AskPerson.h
	$(CC) -c AskComportement/AskProfessor.cpp

AskStudent.o : AskComportement/AskStudent.cpp AskComportement/AskStudent.h I_AskPerson.h
	$(CC) -c AskComportement/AskStudent.cpp

FactoryPersonProfessorStudent.o : FactoryPersonProfessorStudent.cpp FactoryPersonProfessorStudent.h
	$(CC) -c FactoryPersonProfessorStudent.cpp

CompareComportementLastNameAsc.o : CompareComportement/CompareComportementLastNameAsc.cpp CompareComportement/CompareComportementLastNameAsc.h I_CompareComportement.h
	$(CC) -c CompareComportement/CompareComportementLastNameAsc.cpp

CompareComportementLastNameDesc.o : CompareComportement/CompareComportementLastNameDesc.cpp CompareComportement/CompareComportementLastNameDesc.h I_CompareComportement.h
	$(CC) -c CompareComportement/CompareComportementLastNameDesc.cpp

CompareComportementFirstNameAsc.o : CompareComportement/CompareComportementFirstNameAsc.cpp CompareComportement/CompareComportementFirstNameAsc.h I_CompareComportement.h
	$(CC) -c CompareComportement/CompareComportementFirstNameAsc.cpp

CompareComportementFirstNameDesc.o : CompareComportement/CompareComportementFirstNameDesc.cpp CompareComportement/CompareComportementFirstNameDesc.h I_CompareComportement.h
	$(CC) -c CompareComportement/CompareComportementFirstNameDesc.cpp

CompareComportementDateAsc.o : CompareComportement/CompareComportementDateAsc.cpp CompareComportement/CompareComportementDateAsc.h I_CompareComportement.h
	$(CC) -c CompareComportement/CompareComportementDateAsc.cpp

CompareComportementDateDesc.o : CompareComportement/CompareComportementDateDesc.cpp CompareComportement/CompareComportementDateDesc.h I_CompareComportement.h
	$(CC) -c CompareComportement/CompareComportementDateDesc.cpp

CompareComportementSalaryAsc.o : CompareComportement/CompareComportementSalaryAsc.cpp CompareComportement/CompareComportementSalaryAsc.h I_CompareComportement.h
	$(CC) -c CompareComportement/CompareComportementSalaryAsc.cpp

CompareComportementSalaryDesc.o : CompareComportement/CompareComportementSalaryDesc.cpp CompareComportement/CompareComportementSalaryAsc.h I_CompareComportement.h
	$(CC) -c CompareComportement/CompareComportementSalaryDesc.cpp

CompareComportementNpaAsc.o : CompareComportement/CompareComportementNpaAsc.cpp CompareComportement/CompareComportementNpaAsc.h I_CompareComportement.h
	$(CC) -c CompareComportement/CompareComportementNpaAsc.cpp

CompareComportementNpaDesc.o : CompareComportement/CompareComportementNpaDesc.cpp CompareComportement/CompareComportementNpaAsc.h I_CompareComportement.h
	$(CC) -c CompareComportement/CompareComportementNpaDesc.cpp

Menu.o : Menu/Menu.cpp Menu/Menu.h
	$(CC) -c Menu/Menu.cpp

Option.o : Menu/Option.cpp Menu/Option.h
	$(CC) -c Menu/Option.cpp

CheckPersonProfessorStudent.o : CheckPersonProfessorStudent.cpp CheckPersonProfessorStudent.h I_CheckPerson.h
	$(CC) -c CheckPersonProfessorStudent.cpp

main.o : main.cpp
	$(CC) -c main.cpp

clean: 
	$(RM) $(OBJ)

