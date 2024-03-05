#include <stdio.h>
#include <stdlib.h>

void quiz();
void help();
void help_teacher();
void help_student();
void menu();
void view_results();
void reset_score();
void start();
void view_results_teacher();
void view_results_student();
void start_teacher();
void edit_quiz();

void add_quiz();


int curent_student_id;

struct quizes{

    char quiz_name[256];
    int questions_nr;
    int office_points;

    struct question{
        char question_text[256], a[50], b[50], c[50], d[50];
        char answer;
        int points;
    }questions[20];

}quiz_1={"Computer Programing C Quizz", 1, 10, {"Which of hte following are NOT relational operators?", "<", ">", "==", ">=", 'c', 10}};;

struct {
    char student_name[256];
    int student_score;
}student;



int main()
{
    int ch,n;
    char name[20];


    printf("\n\t\t --------------------  Welcome %s to C Program Quiz ----------------------------",name);
    printf("\n\n\t\t Here are some tips you might wanna know before playing:");
    printf("\n\t\t -------------------------------------------------------------------------");
    printf("\n\t\t >> There are 2 rounds in this Quiz,WARMUP ROUND & CHALLANGE ROUND");
    printf("\n\t\t >> In warmup round you will be asked total 3 questions to acomodate.");
    printf("\n\t\t >> Your game starts with CHALLANGE ROUND. In this round you will be asked");
    printf("\n\t\t    questions. Each right answer will be awarded.");
    printf("\n\t\t >> You will be given 4 options and you have to press A, B ,C or D for the");
    printf("\n\t\t    right option.");
    printf("\n\t\t >> You will be asked questions continuously, till right answers are given");
    printf("\n\t\t >> No negative marking for wrong answers!");
    printf("\n\n\t\t\t\t!!!!!!!!!!!!! ALL THE BEST !!!!!!!!!!!!!");
    printf("\nAre you ready? (1/0) : ");
    scanf("%d",&ch);

        menu();


}


void start_student(struct quizes quiz_1)
{
    int ch;
    printf("Name: ");
    scanf("%s",student.student_name);
    printf("\nStart quiz? (1/0) : ");
    scanf("%d",&ch);

    if(ch==1)
    {
        quiz();
    }
    else
    {
        menu();
    }
}


void menu()
{
    int ch;
    printf("\n\t\t\t________________________________________");

     printf("\n\t\t\t\t        WELCOME ");
     printf("\n\t\t\t\t          TO ");
     printf("\n\t\t\t\t       QUIZ ");
     printf("\n\t\t\t________________________________________");
     printf("\n\t\t\t________________________________________");
     printf("\n\t\t\t -> Press 1 to start as a student");
     printf("\n\t\t\t -> Press 2 to start as a teacher");
     printf("\n\t\t\t -> Press 3 for help");
     printf("\n\t\t\t -> Press 4 to quit");
     printf("\n\t\t\t________________________________________\n\n");
     printf("You selected: ");
        scanf("%d",&ch);
        switch(ch)
          {
              case 1:start_student(quiz_1);
                    break;
              case 2:start_teacher();
                    break;
              case 3:help();
                    break;
              case 4:break;
            default:printf("Sorry wrong option \n\n");
                    break;
          }

}
void help()
{
     printf("\n\n ************************* GAME HELP *************************");
     printf("\n -------------------------------------------------------------------------");
     printf("\n ...................... C program Quiz .............\n");
     printf("\n >> You will be given 4 options and you have to press 1, 2 ,3 or 4 for the");
     printf("\n    right option");
     printf("\n >> Each question will carry points");
     printf("\n >> You will be asked questions continuously.");
     printf("\n >> There is no negative marking for wrong answer");

    printf("\n\n ************************* BEST OF LUCK *************************\n\n");

    menu();

}
void quiz()
{
    char answer;
    printf("quiz: %s\n", quiz_1.quiz_name);
    fflush(stdin);
    for(int i=0;i<=quiz_1.questions_nr-1;i++)
    {
        printf("%s\n", quiz_1.questions[i].question_text);
        fflush(stdin);
        printf("a.%s\t b.%s\t c.%s\t d.%s\n",quiz_1.questions[i].a,quiz_1.questions[i].b, quiz_1.questions[i].c, quiz_1.questions[i].d);
        fflush(stdin);
        printf("Your answer is: \n");
        scanf("%c",&answer);
        fflush(stdin);
        if(quiz_1.questions[i].answer == answer)
            student.student_score += quiz_1.questions[i].points;
        fflush(stdin);
    }
    student.student_score += quiz_1.office_points;
    fflush(stdin);
    printf("ii bun");
    menu();



}
void start_teacher()
{
    int ch;
    printf("\n\t\t\t________________________________________");
    printf("\n\t\t\t\t        Teacher Menu ");
    printf("\n\t\t\t________________________________________");
    printf("\n\t\t\t________________________________________");
    printf("\n\t\t\t -> Press 1 to edit quiz");
    printf("\n\t\t\t -> Press 2 to view grades");
    printf("\n\t\t\t -> Press 3 for help");
    printf("\n\t\t\t -> Press 4 to quit");
    printf("\n\t\t\t________________________________________");
    printf("\nYou selected: ");
    scanf("%d",&ch);
    switch(ch)
          {
              case 1:edit_quiz();
                    break;
              case 2:view_results_teacher();
                    break;
              case 3:help_teacher();
                    break;
              case 4:break;
            default:printf("Sorry wrong option \n\n");
                    break;
          }

}

void view_results_teacher(){

    printf("%s\t %d points",student.student_name,student.student_score);
    menu();


}

void help_teacher(){

printf("\n\n *************************** HELP TEACHER ***************************");

menu();



}


void edit_quiz()
{
    int question_to_edit = 0;
    int nr_of_questions = 0;

    printf("quiz: %s\n", quiz_1.quiz_name);
    for(int i=0;i<=quiz_1.questions_nr-1;i++)
    {
        printf("%d %s\n",i+1, quiz_1.questions[i].question_text);
        printf("a.%s\t b.%s\t c.%s\t d.%s\n",quiz_1.questions[i].a,quiz_1.questions[i].b, quiz_1.questions[i].c, quiz_1.questions[i].d);

    }

    printf("Enter new quiz name: ");
    scanf("%s",quiz_1.quiz_name);
    fflush(stdin);

    printf("Enter the number of questions: ");
    scanf("%d",&nr_of_questions);
    quiz_1.questions_nr=nr_of_questions;
    fflush(stdin);

    for(int i=0;i<nr_of_questions;i++)
    {
        printf("new question: ");
        scanf("%s",quiz_1.questions[i].question_text);

        printf("A.");
        scanf("%s",quiz_1.questions[i].a);
        fflush(stdin);
        printf("B.");
        scanf("%s",quiz_1.questions[i].b);
        fflush(stdin);
        printf("C.");
        scanf("%s",quiz_1.questions[i].c);
        fflush(stdin);
        printf("D.");
        scanf("%s",quiz_1.questions[i].d);
        fflush(stdin);

        printf("Right answer: ");
        char ans;
        scanf("%c",&ans);
        quiz_1.questions[i].answer=ans;
        fflush(stdin);

        printf("Points (1-100): ");
        scanf("%d",&quiz_1.questions[i].points);
        fflush(stdin);


    }
    menu();


}
